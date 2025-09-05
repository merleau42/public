const API_BASE = 'https://api.xn--2g3ba.store';
let token = sessionStorage.getItem("vaultToken") || "";

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

function logout() {
	sessionStorage.removeItem("vaultToken");
	token = "";
	window.location.href = "index.html"; // Redirect to login page
}

async function loadPosts() {
	const res = await authedFetch("/api/posts");
	const data = await res.json();
	if (!res.ok) {
		// If token is invalid, redirect to login
		if (res.status === 401) {
			logout();
			return;
		}
		return alert(data.error || "불러오기 실패");
	}

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

function openModal() {
	$("#modal").classList.remove("hidden");
}

function closeModal() {
	$("#modal").classList.add("hidden");
	// Reset form fields
	$("#title").value = "";
	$("#body").value = "";
	$("#file").value = "";
	$("#uploadInfo").textContent = "";
}

async function createPost() {
	const title = $("#title").value.trim();
	const body = $("#body").value.trim();
	if (!title || !body) return alert("제목과 내용을 모두 입력해주세요.");

	let pendingFileId = null;
	const file = $("#file").files[0];

	if (file) {
		$("#uploadInfo").textContent = "파일 업로드 중...";
		const fd = new FormData();
		fd.append("file", file);
		const res = await fetch(API_BASE + "/api/upload", {
			method: "POST",
			headers: token ? { Authorization: `Bearer ${token}` } : {},
			body: fd,
		});
		
		const data = await res.json();
		if (!res.ok) {
			$("#uploadInfo").textContent = "";
			return alert(data.error || "파일 업로드 실패");
		}
		pendingFileId = data.id;
	}

	const postPayload = { title, body };
	if(pendingFileId) {
		postPayload.file_id = pendingFileId;
	}

	const res = await authedFetch("/api/posts", {
		method: "POST",
		body: JSON.stringify(postPayload),
	});

	if (!res.ok) {
		const post = await res.json();
		return alert(post.error || "게시물 등록 실패");
	}
	
	closeModal();
	loadPosts();
}


// Event Listeners
$("#logoutBtn").addEventListener("click", logout);
$("#newPostBtn").addEventListener("click", openModal);
$("#postBtn").addEventListener("click", createPost);

// Close modal when clicking on the overlay
$("#modal").addEventListener("click", (e) => {
	if (e.target === $("#modal")) {
		closeModal();
	}
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
	if (s === null || s === undefined) return '';
	return s.replace(/[&<>"]/g, c => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;", '"': "&quot;" }[c]));
}
function nl2br(s) {
	return s.replace(/\n/g, "<br/>");
}

// Initial check for BBS page
if (token) {
	authedFetch('/api/posts').then(res => {
		if (res.ok) {
			loadPosts();
		} else {
			logout(); // If token is invalid, go to login
		}
	});
} else {
	logout(); // If no token, go to login
}
