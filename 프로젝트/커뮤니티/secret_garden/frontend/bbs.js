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
	console.log("Loading posts...");
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
		console.log("Processing post:", p.title, "ID:", p.id);
		console.log("Post files:", p.files);

		const el = document.createElement("div");
		el.className = "card";
		
		const postHeader = document.createElement('div');
		postHeader.className = 'post-header';
		postHeader.innerHTML = `
			<h3 class="post-title">${escapeHtml(p.title)}</h3>
			<div class="post-meta">
				<span>${new Date(p.created_at).toLocaleString()}</span>
				<button class="delete-text-button" data-del-id="${p.id}">삭제</button>
			</div>
		`;
		
		const postContent = document.createElement('div');
		postContent.className = 'post-content hidden';
		
		const fileAttachmentsHtml = await Promise.all((p.files || []).map(async f => {
			console.log("Fetching URL for file:", f.original_name || f.path, "ID:", f.id);
			const urlRes = await authedFetch(`/api/files/${f.id}/url`);
			const urlData = await urlRes.json();
			console.log("File URL response:", urlRes.ok, urlData);

			if (!urlRes.ok) {
				console.error("Failed to get file URL:", urlData.error);
				return `<span>파일 URL을 가져올 수 없습니다: ${escapeHtml(f.original_name || f.path)}</span>`;
			}
			const fileUrl = urlData.url;
			const fileName = escapeHtml(f.original_name || f.path);
			const isImage = /\.(jpg|jpeg|png|gif|webp|bmp)$/i.test(fileName);
			
			let fileHtml = '';
			if (isImage) {
				fileHtml += `<img src="${fileUrl}" alt="${fileName}" style="max-width: 100%; height: auto; display: block; margin-top: 10px;">`;
			}
			fileHtml += `<p><a href="${fileUrl}" target="_blank">${fileName}</a></p>`;
			console.log("Generated file HTML:", fileHtml);
			return fileHtml;
		}));

		postContent.innerHTML = `
			<p>${nl2br(escapeHtml(p.body))}</p>
			<div>
				${fileAttachmentsHtml.join("")}
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
	$("#password").value = ""; // Reset password field
	$("#file").value = "";
	$("#uploadInfo").textContent = "";
}

async function createPost() {
	const title = $("#title").value.trim();
	const password = $("#password").value.trim(); // Get password
	const body = $("#body").value.trim();
	if (!title || !body || !password) return alert("제목, 내용, 비밀번호를 모두 입력해주세요.");

	let pendingFileId = null;
	const file = $("#file").files[0];

	if (file) {
		$("#uploadInfo").textContent = "파일 업로드 중...";
		console.log("Uploading file:", file.name);
		const fd = new FormData();
		fd.append("file", file);
		const res = await fetch(API_BASE + "/api/upload", {
			method: "POST",
			headers: token ? { Authorization: `Bearer ${token}` } : {},
			body: fd,
		});
		
		const data = await res.json();
		console.log("File upload response:", res.ok, data);
		if (!res.ok) {
			$("#uploadInfo").textContent = "";
			return alert(data.error || "파일 업로드 실패");
		}
		pendingFileId = data.id;
		console.log("Pending file ID:", pendingFileId);
	}

	const postPayload = { title, body, password }; // Include password in payload
	if(pendingFileId) {
		postPayload.file_id = pendingFileId;
	}

	console.log("Creating post with payload:", postPayload);
	const res = await authedFetch("/api/posts", {
		method: "POST",
		body: JSON.stringify(postPayload),
	});

	if (!res.ok) {
		const post = await res.json();
		console.error("Post creation failed:", post.error);
		return alert(post.error || "게시물 등록 실패");
	}
	console.log("Post created successfully.");
	
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
		const password = prompt('게시물 삭제를 위해 비밀번호를 입력하세요:');
		if (password === null) return; // User cancelled the prompt

		const res = await authedFetch(`/api/posts/${id}`, {
			method: 'DELETE',
			body: JSON.stringify({ password })
		});
		if (res.ok) {
			loadPosts();
		} else {
			const data = await res.json();
			alert(data.error || '삭제 실패');
		}
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
