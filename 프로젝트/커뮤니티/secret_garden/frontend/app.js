const API_BASE = 'https://api.xn--2g3ba.store';
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
	while (true) {
		const pw = prompt("비밀번호를 입력하세요.");
		if (!pw) continue;
		
		const res = await fetch(API_BASE + "/api/auth/login", {
			method: "POST",
			headers: { "Content-Type": "application/json" },
			body: JSON.stringify({ password: pw }),
		});
		
		if (res.ok) {
			const data = await res.json();
			setAuth(data.token);
			$("#login").classList.add("hidden");
			$("#main").classList.remove("hidden");
			loadPosts();
			break;
		} else {
			alert("비밀번호가 틀렸습니다.");
		}
	}
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
		
		const postHeader = document.createElement('div');
		postHeader.className = 'post-header';
		postHeader.innerHTML = `
			<h3 class="post-title">${escapeHtml(p.title)}</h3>
			<div class="post-meta">
				<span>${new Date(p.created_at).toLocaleString()}</span>
				<button data-del-id="${p.id}" style="margin-left: 8px;">삭제</button>
			</div>
		`;
		
		const postContent = document.createElement('div');
		postContent.className = 'post-content hidden';
		postContent.innerHTML = `
			<p>${nl2br(escapeHtml(p.body))}</p>
			<div>
				${(p.files || []).map(f => 
					`<button data-file='${f.id}'>
						파일 보기: ${escapeHtml(f.original_name || f.path)}
					</button>`
				).join(" ")}
			</div>
		`;
		
		postHeader.addEventListener('click', (e) => {
			if (e.target.tagName !== 'BUTTON') {
				postContent.classList.toggle('hidden');
			}
		});

		el.appendChild(postHeader);
		el.appendChild(postContent);
		wrap.appendChild(el);
	}
}

$("#loginBtn").addEventListener("click", login);

$("#newPostBtn").addEventListener("click", () => {
	$("#writerCard").classList.toggle("hidden");
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
	$("#writerCard").classList.add("hidden");
	loadPosts();
});

$("#posts").addEventListener('click', async (e) => {
	if (e.target.matches('button[data-del-id]')) {
		const id = e.target.getAttribute('data-del-id');
		if (!confirm('정말 삭제하시겠습니까?')) return;
		
		const res = await authedFetch(`/api/posts/${id}`, { method: 'DELETE' });
		if (res.ok) {
			loadPosts();
		} else {
			const data = await res.json();
			alert(data.error || '삭제 실패');
		}
	}
	
	if (e.target.matches('button[data-file]')) {
		const id = e.target.getAttribute("data-file");
		const res = await authedFetch(`/api/files/${id}/url`);
		const data = await res.json();
		if (!res.ok) return alert(data.error || "URL 생성 실패");
		window.open(data.url, "_blank");
	}
});


function escapeHtml(s) {
	if (s === null || s === undefined) {
		return '';
	}
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
