document.addEventListener("DOMContentLoaded", () => {
	const createBtn = document.getElementById("createBtn");
	const joinBtn = document.getElementById("joinBtn");
	const roomIdInput = document.getElementById("roomIdInput");
	const nameInput = document.getElementById("nameInput");
	const statusEl = document.getElementById("status");

	// ==================================================================
	// IMPORTANT: Replace this with your actual Render server URL
	// 중요: 이 부분을 실제 Render 서버 URL로 교체하세요
	const SERVER_URL = "https://YOUR_RENDER_URL_HERE";
	// ==================================================================

	/**
	 * Injects the necessary scripts and sends an initialization message.
	 * @param {object} message - The message to send to the content script.
	 */
	function initializeMetaverse(message) {
		chrome.tabs.query({ active: true, currentWindow: true }, (tabs) => {
			const activeTab = tabs[0];
			if (!activeTab.id) {
				statusEl.textContent = "Error: Could not find active tab.";
				return;
			}

			// Inject the socket.io library first, then our content script.
			// They will share the same isolated world.
			chrome.scripting.executeScript(
				{
					target: { tabId: activeTab.id },
					files: ["socket.io.min.js", "content.js"],
				},
				() => {
					// After injection, send the init message.
					// A small delay ensures the content script's listener is ready.
					setTimeout(() => {
						chrome.tabs.sendMessage(activeTab.id, message);
						window.close(); // Close the popup
					}, 150);
				},
			);
		});
	}

	// Create Room button handler
	createBtn.addEventListener("click", () => {
		statusEl.textContent = "Creating room...";
		initializeMetaverse({
			type: "CREATE_ROOM_AND_HOST",
			serverUrl: SERVER_URL,
		});
	});

	// Join Room button handler
	joinBtn.addEventListener("click", () => {
		const roomId = roomIdInput.value.trim().toUpperCase();
		const name = nameInput.value.trim();
		if (!roomId) {
			statusEl.textContent = "Please enter a Room ID.";
			return;
		}
		if (!name) {
			statusEl.textContent = "Please enter your name.";
			return;
		}

		statusEl.textContent = `Joining room ${roomId}...`;
		initializeMetaverse({
			type: "JOIN_ROOM_AS_VIEWER",
			serverUrl: SERVER_URL,
			roomId,
			name,
		});
	});
});
