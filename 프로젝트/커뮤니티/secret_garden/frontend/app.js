const API_BASE = 'https://api.밍밍.store';
let token = sessionStorage.getItem("vaultToken") || "";
let pendingFileId = null;

const $ = (sel) => document.querySelector(sel);

function setAuth(t) {
	token = t;
	sessionStorage.setItem("vaultToken", t);
}

function authedFetch(url, opts = {}) {
	return fetch(API_BASE + url, {
		...opts,
		headers: {
			"Content-Type": "application/json",
			...(opts.headers || {}),
			...(token ? { Authorization: `Bearer ${token}` } : {}),
		},
	});
}

async function login() {
	const pw = $("#pw").value;
	const res = await fetch(API_BASE + "/api/auth/login", {
		method: "POST",
		headers: { "Content-Type": "application/json" },
		body: JSON.stringify({ password: pw }),
	});
	const data = await res.json();
	if (!res.ok) return alert(data.error || "로그인 실패");
	setAuth(data.token);
	$("#login").classList.add("hidden");
	$("#main").classList.remove("hidden");
	loadPosts();
}

async function loadPosts() {
	const res = await authedFetch("/api/posts");
	const data = await res.json();
	if (!res.ok) return alert(data.error || "불러오기 실패");
	const wrap = $("#posts");
	wrap.innerHTML = "";
	for (const p of data.items) {
		const el = document.createElement("div");
		el.className = "card";
		el.innerHTML = `<h3>${escapeHtml(p.title)}</h3>
						<p>${nl2br(escapeHtml(p.body))}</p>
						<div class="muted">${new Date(p.created_at).toLocaleString()}</div>
						<div>${(p.files || [])
									.map(
										(f) =>
											`<button data-file='${f.id}'>파일 보기: ${escapeHtml(
												f.original_name || f.path
											)}</button>`
									)
									.join(" ")}</div>
						<div style="margin-top:8px;" class="row">
						<input data-cid='${p.id}' placeholder="댓글" />
						<button data-cbtn='${p.id}'>등록</button>
						</div>
						<ul>${(p.comments || [])
									.map(
										(c) =>
											`<li>${escapeHtml(c.body)} <span class='muted'>${new Date(
												c.created_at
											).toLocaleString()}</span></li>`
									)
									.join("")}</ul>`;
		wrap.appendChild(el);
	}
	// 파일 버튼 핸들러
	wrap.querySelectorAll("button[data-file]").forEach((btn) => {
		btn.addEventListener("click", async () => {
			const id = btn.getAttribute("data-file");
			const res = await authedFetch(`/api/files/${id}/url`);
			const data = await res.json();
			if (!res.ok) return alert(data.error || "URL 생성 실패");
			window.open(data.url, "_blank");
		});
	});

	// 댓글 등록 핸들러
	wrap.querySelectorAll("button[data-cbtn]").forEach((btn) => {
		btn.addEventListener("click", async () => {
			const postId = btn.getAttribute("data-cbtn");
			const input = wrap.querySelector(`input[data-cid='${postId}']`);
			const body = input.value.trim();
			if (!body) return;
			const res = await authedFetch(`/api/posts/${postId}/comments`, {
				method: "POST",
				body: JSON.stringify({ body }),
			});
			const data = await res.json();
			if (!res.ok) return alert(data.error || "댓글 실패");
			input.value = "";
			loadPosts();
		});
	});
}

$("#loginBtn").addEventListener("click", login);
$("#pw").addEventListener("keydown", (e) => {
	if (e.key === "Enter") login();
});

$("#uploadBtn").addEventListener("click", async () => {
	const file = $("#file").files[0];
	if (!file) return alert("파일을 선택하세요");
	const fd = new FormData();
	fd.append("file", file);
	const res = await fetch(API_BASE + "/api/upload", {
		method: "POST",
		headers: token ? { Authorization: `Bearer ${token}` } : {},
		body: fd,
	});
	const data = await res.json();
	if (!res.ok) return alert(data.error || "업로드 실패");
	pendingFileId = data.id;
	$("#uploadInfo").textContent = `업로드됨: ${
		data.original_name || data.path
	}`;
});

$("#postBtn").addEventListener("click", async () => {
	const title = $("#title").value.trim();
	const body = $("#body").value.trim();
	if (!title || !body) return alert("제목/내용 필요");

	const res = await authedFetch("/api/posts", {
		method: "POST",
		body: JSON.stringify({ title, body }),
	});
	const post = await res.json();
	if (!res.ok) return alert(post.error || "등록 실패");

	if (pendingFileId) {
		await authedFetch(`/api/files/${pendingFileId}/attach`, {
			method: "POST",
			body: JSON.stringify({ post_id: post.id }),
		});
		pendingFileId = null;
		$("#uploadInfo").textContent = "";
		$("#file").value = "";
	}

	$("#title").value = "";
	$("#body").value = "";
	loadPosts();
});
function escapeHtml(s) {
	return s.replace(
		/[&<>"]/g,
		(c) => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;" }[c])
	);
}
function nl2br(s) {
	return s.replace(/\n/g, "<br/>");
}

if (token) {
	$("#login").classList.add("hidden");
	$("#main").classList.remove("hidden");
	loadPosts();
}
