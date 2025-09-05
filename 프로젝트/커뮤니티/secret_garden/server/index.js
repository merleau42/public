import "dotenv/config";
import express from "express";
import cors from "cors";
import morgan from "morgan";
import jwt from "jsonwebtoken";
import bcrypt from "bcrypt";
import multer from "multer";
import { supabase } from "./supabase.js";
import rateLimit from "express-rate-limit";

const app = express();
const PORT = process.env.PORT || 8080;
const BUCKET = process.env.SUPABASE_BUCKET;
const JWT_SECRET = process.env.JWT_SECRET;
const FRONTEND_ORIGIN = process.env.FRONTEND_ORIGIN;

app.use(morgan("tiny"));
app.use(express.json());
app.use(
	cors({
		origin: FRONTEND_ORIGIN,
		credentials: false, // 토큰을 헤더로 쓰므로 쿠키 불필요
		methods: ["GET", "POST", "DELETE"],
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
	const { data, error } = await supabase
		.from("posts")
		.select("*")
		.order("created_at", { ascending: false });
	if (error) return res.status(500).json({ error: error.message });

	// 게시글별 댓글/파일도 같이 내려주기(간단 버전)
	const ids = data.map((p) => p.id);
	const [{ data: comments }, { data: files }] = await Promise.all([
		supabase.from("comments").select("*").in("post_id", ids),
		supabase.from("files").select("*").in("post_id", ids),
	]);

	const map = Object.fromEntries(
		ids.map((id) => [id, { comments: [], files: [] }])
	);
	comments?.forEach((c) => map[c.post_id]?.comments.push(c));
	files?.forEach((f) => map[f.post_id]?.files.push(f));

	const merged = data.map((p) => ({ ...p, ...map[p.id] }));
	res.json({ items: merged });
});

app.post("/api/posts", auth, async (req, res) => {
	const { title, body } = req.body || {};
	if (!title || !body)
		return res.status(400).json({ error: "title/body required" });
	const { data, error } = await supabase
		.from("posts")
		.insert({ title, body })
		.select("*")
		.single();
	if (error) return res.status(500).json({ error: error.message });
	res.json(data);
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
	const filename = `${Date.now()}-${req.file.originalname}`;

	const { error: upErr } = await supabase.storage
		.from(BUCKET)
		.upload(filename, req.file.buffer, {
			contentType: req.file.mimetype,
			upsert: false,
		});
	if (upErr) return res.status(500).json({ error: upErr.message });

	// 파일 메타 저장(아직 post_id 없음)
	const { data, error } = await supabase
		.from("files")
		.insert({
			path: filename,
			mime_type: req.file.mimetype,
			size_bytes: req.file.size,
			original_name: req.file.originalname,
		})
		.select("*")
		.single();
	if (error) return res.status(500).json({ error: error.message });

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
	if (ferr || !file) return res.status(404).json({ error: "file not found" });
	const { data: urlData, error } = await supabase.storage
		.from(BUCKET)
		.createSignedUrl(file.path, 60 * 5); // 5분 유효
	if (error) return res.status(500).json({ error: error.message });
	res.json({ url: urlData.signedUrl });
});

// 삭제(선택): 게시글/댓글/파일 제거 API도 같은 패턴으로 추가 가능

app.listen(PORT, () => {
	console.log("server on :", PORT);
});
