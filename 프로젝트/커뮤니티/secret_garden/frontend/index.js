const API_BASE = 'https://api.xn--2g3ba.store';
let token = sessionStorage.getItem("vaultToken") || "";

const $ = (sel) => document.querySelector(sel);

function setAuth(t) {
	token = t;
	sessionStorage.setItem("vaultToken", t);
}

// This function remains in app.js for login only
async function login() {
	const pw = $("#pw").value;
	if (!pw) return alert("비밀번호를 입력하세요.");
	
	const res = await fetch(API_BASE + "/api/auth/login", {
		method: "POST",
		headers: { "Content-Type": "application/json" },
		body: JSON.stringify({ password: pw }),
	});
	
	const data = await res.json();
	if (res.ok) {
		setAuth(data.token);
		window.location.href = "bbs.html"; // Redirect to BBS page
	} else {
		alert(data.error || "비밀번호가 틀렸습니다.");
	}
}

// Event Listeners for login page
$("#loginBtn").addEventListener("click", login);
$("#pw").addEventListener("keydown", (e) => {
	if (e.key === 'Enter') login();
});

// If a token exists and is valid, directly go to bbs.html
// Otherwise, stay on login page
if (token) {
	authedFetch('/api/posts').then(res => {
		if (res.ok) {
			window.location.href = "bbs.html";
		} else {
			sessionStorage.removeItem("vaultToken");
			token = "";
			// Stay on login page
		}
	});
}
