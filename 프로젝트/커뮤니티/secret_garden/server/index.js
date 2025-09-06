import "dotenv/config";
import express from "express";
import cors from "cors";
import morgan from "morgan";
import jwt from "jsonwebtoken";
import bcrypt from "bcrypt";
import multer from "multer";
import { supabase } from "./supabase.js";
import rateLimit from "express-rate-limit";
import path from "path";

const app = express();
app.set('trust proxy', 1);
const PORT = process.env.PORT || 8080;
const BUCKET = process.env.SUPABASE_BUCKET;
const JWT_SECRET = process.env.JWT_SECRET;
const FRONTEND_ORIGIN = process.env.FRONTEND_ORIGIN;

app.use(morgan("tiny"));
app.use(express.json());

const allowedOrigins = [
	"https://xn--2g3ba.store", // punycode(브라우저가 실제로 찍는 Origin)
	"https://밍밍.store", // 가독성 위해 함께 허용(선택)
	process.env.FRONTEND_ORIGIN, // 환경변수로도 주입 가능
].filter(Boolean);

// 프리플라이트: 반드시 200으로 바로 응답 (리다이렉트 금지)
app.options("*",
	cors({
		origin: (origin, cb) => {
			if (!origin) return cb(null, true); // curl 등 Origin 없는 요청 허용
			cb(null, allowedOrigins.includes(origin));
		},
		credentials: false,
	})
);

// 실제 요청에 대한 CORS
app.use(
	cors({
		origin: (origin, cb) => {
			if (!origin) return cb(null, true);
			cb(null, allowedOrigins.includes(origin));
		},
		credentials: false,
	})
);

// 로그인 시도 제한 (브루트포스 방지)
const loginLimiter = rateLimit({
	windowMs: 15 * 60 * 1000,
	max: 20,
	standardHeaders: true,
	legacyHeaders: false,
});

function signToken() {
	return jwt.sign({ role: "vault-admin" }, JWT_SECRET, { expiresIn: "6h" });
}

function auth(req, res, next) {
	const auth = req.headers.authorization || "";
	const token = auth.startsWith("Bearer ") ? auth.slice(7) : null;
	if (!token) return res.status(401).json({ error: "missing token" });
	try {
		const payload = jwt.verify(token, JWT_SECRET);
		req.user = payload;
		next();
	} catch (e) {
		return res.status(401).json({ error: "invalid token" });
	}
}

// === Auth ===
app.post("/api/auth/login", loginLimiter, async (req, res) => {
	const { password } = req.body || {};
	if (!password) return res.status(400).json({ error: "password required" });
	const ok = await bcrypt.compare(password, process.env.ACCESS_PASSWORD_HASH);
	if (!ok) return res.status(401).json({ error: "wrong password" });
	const token = signToken();
	res.json({ token, expiresIn: 21600 }); // 6h
});

// === Posts ===
app.get("/api/posts", auth, async (req, res) => {
	console.log("Server: Fetching posts...");
	const { data, error } = await supabase
		.from("posts")
		.select("*")
		.order("created_at", { ascending: false });
	if (error) {
		console.error("Server: Error fetching posts:", error.message);
		return res.status(500).json({ error: error.message });
	}
	console.log("Server: Posts fetched. Count:", data.length, "Data:", data);

	// 게시글별 댓글/파일도 같이 내려주기(간단 버전)
	const ids = data.map((p) => p.id);
	console.log("Server: Post IDs for fetching comments and files:", ids);

	const [{ data: comments }, { data: files }] = await Promise.all([
		supabase.from("comments").select("*").in("post_id", ids),
		supabase.from("files").select("*").in("post_id", ids),
	]);

	console.log("Server: Files fetched. Count:", files ? files.length : 0, "Files data:", files);

	// Generate signed URLs for files
	const filesWithSignedUrls = await Promise.all(
		files.map(async (file) => {
			const { data: urlData, error: urlError } = await supabase.storage
				.from(BUCKET)
				.createSignedUrl(file.path, 60 * 60 * 24); // 24시간 유효
			if (urlError) {
				console.error("Server: Error generating signed URL for file", file.path, ":", urlError.message);
				return { ...file, url: null }; // Return file with null URL on error
			}
			return { ...file, url: urlData.signedUrl };
		})
	);

	const map = Object.fromEntries(
		ids.map((id) => [id, { comments: [], files: [] }])
	);
	comments?.forEach((c) => map[c.post_id]?.comments.push(c));
	filesWithSignedUrls?.forEach((f) => map[f.post_id]?.files.push(f));

	const merged = data.map((p) => ({ ...p, ...map[p.id] }));
	console.log("Server: Merged data before sending to client:", merged);

	res.json({ items: merged });
});

app.post("/api/posts", auth, async (req, res) => {
	const { title, body, password, file_id } = req.body || {};
	if (!title || !body || !password)
		return res.status(400).json({ error: "title, body, and password required" });

	const passwordHash = await bcrypt.hash(password, 10); // Hash the password

	const { data: post, error } = await supabase
		.from("posts")
		.insert({ title, body, password: passwordHash }) // Store the hashed password
		.select("*")
		.single();
	if (error) {
		console.error("Server: Error creating post:", error.message);
		return res.status(500).json({ error: error.message });
	}
	console.log("Server: Post created successfully. Post ID:", post.id);

	// If a file_id is provided, attach it to the newly created post
	if (file_id) {
		console.log("Server: Attaching file ID", file_id, "to post ID", post.id);
		const { error: attachError } = await supabase
			.from("files")
			.update({ post_id: post.id })
			.eq("id", file_id);
		if (attachError) {
			console.error("Server: Failed to attach file to post:", attachError.message);
		}
		console.log("Server: File attachment process completed for file ID", file_id);
	}

	res.json(post);
});

// New DELETE API for posts
app.delete("/api/posts/:id", auth, async (req, res) => {
	const { id } = req.params;
	const { password } = req.body || {};

	if (!password) {
		return res.status(400).json({ error: "password required for deletion" });
	}

	// 1. Fetch the post to get the stored password hash
	const { data: post, error: fetchError } = await supabase
		.from("posts")
		.select("password")
		.eq("id", id)
		.single();

	if (fetchError || !post) {
		return res.status(404).json({ error: "Post not found" });
	}

	// 2. Compare the provided password with the stored hash
	const passwordMatch = await bcrypt.compare(password, post.password);
	if (!passwordMatch) {
		return res.status(401).json({ error: "Incorrect password" });
	}

	// 3. If password matches, delete associated files from storage first
	const { data: filesToDelete, error: filesError } = await supabase
		.from("files")
		.select("path")
		.eq("post_id", id);

	if (filesError) {
		console.error("Error fetching files for deletion:", filesError.message);
		// Proceed with post deletion even if file fetch fails, or return error
		// For now, let's just log and proceed
	} else if (filesToDelete && filesToDelete.length > 0) {
		const filePaths = filesToDelete.map(f => f.path);
		const { error: storageDeleteError } = await supabase.storage
			.from(BUCKET)
			.remove(filePaths);

		if (storageDeleteError) {
			console.error("Error deleting files from storage:", storageDeleteError.message);
			// Decide whether to block post deletion or just log
			// For now, let's just log and proceed with database deletion
		}
	}

	// 4. Delete the post and associated comments/files from the database
	const { error: deleteError } = await supabase
		.from("posts")
		.delete()
		.eq("id", id);

	if (deleteError) {
		return res.status(500).json({ error: deleteError.message });
	}

	res.status(204).send(); // No content for successful deletion
});


app.post("/api/posts/:id/comments", auth, async (req, res) => {
	const { id } = req.params;
	const { body } = req.body || {};
	if (!body) return res.status(400).json({ error: "body required" });
	const { data, error } = await supabase
		.from("comments")
		.insert({ post_id: id, body })
		.select("*")
		.single();
	if (error) return res.status(500).json({ error: error.message });
	res.json(data);
});

// === Uploads ===
const upload = multer({ limits: { fileSize: 1024 * 1024 * 100 } }); // 100MB 예시

app.post("/api/upload", auth, upload.single("file"), async (req, res) => {
	if (!req.file) return res.status(400).json({ error: "file required" });
	
	console.log("Server: Original filename from multer:", req.file.originalname);

	const fileExtension = path.extname(req.file.originalname);
	const filename = `${Date.now()}${fileExtension}`;
	
	console.log("Server: Generated storage filename:", filename);

	const { error: upErr } = await supabase.storage
		.from(BUCKET)
		.upload(filename, req.file.buffer, {
			contentType: req.file.mimetype,
			upsert: false,
		});
	if (upErr) {
		console.error("Server: Error uploading file to storage:", upErr.message);
		return res.status(500).json({ error: upErr.message });
	}
	console.log("Server: File uploaded to storage:", filename);

	// 파일 메타 저장(아직 post_id 없음)
	const { data, error } = await supabase
		.from("files")
		.insert({
			path: filename,
			mime_type: req.file.mimetype,
			size_bytes: req.file.size,
			original_name: req.file.originalname, // Store original name for display
		})
		.select("*")
		.single();
	if (error) {
		console.error("Server: Error saving file metadata to DB:", error.message);
		return res.status(500).json({ error: error.message });
	}
	console.log("Server: File metadata saved to DB. File ID:", data.id);

	res.json(data);
});

app.post("/api/files/:id/attach", auth, async (req, res) => {
	const { id } = req.params;
	const { post_id } = req.body || {};
	if (!post_id) return res.status(400).json({ error: "post_id required" });
	const { data, error } = await supabase
		.from("files")
		.update({ post_id })
		.eq("id", id)
		.select("*")
		.single();
	if (error) return res.status(500).json({ error: error.message });
	res.json(data);
});

app.get("/api/files/:id/url", auth, async (req, res) => {
	const { id } = req.params;
	const { data: file, error: ferr } = await supabase
		.from("files")
		.select("*")
		.eq("id", id)
		.single();
	if (ferr || !file) {
		console.error("Server: File not found for URL request. ID:", id, "Error:", ferr ? ferr.message : "");
		return res.status(404).json({ error: "file not found" });
	}
	console.log("Server: Generating signed URL for file:", file.path);
	const { data: urlData, error } = await supabase.storage
		.from(BUCKET)
		.createSignedUrl(file.path, 60 * 5); // 5분 유효
	if (error) {
		console.error("Server: Error creating signed URL:", error.message);
		return res.status(500).json({ error: error.message });
	}
	console.log("Server: Signed URL generated successfully.");
	res.json({ url: urlData.signedUrl });
});

// === Test Route ===
app.get("/api/hello", (req, res) => {
	res.send("Hello, world!");
});

app.listen(PORT, () => {
	console.log("server on :", PORT);
});
