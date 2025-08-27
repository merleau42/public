(() => {
	// Prevent double injection
	if (window.__TAB_METAVERSE_ACTIVE__) return;
	window.__TAB_METAVERSE_ACTIVE__ = true;

	console.log("Tab Metaverse: Content script running.");

	let socket;
	let state = {
		mode: null, // 'host' or 'viewer'
		roomId: null,
		serverUrl: null,
		name: null,
		myId: null,
		mascots: {},
	};

	let ui, canvas, ctx, broadcastImage;
	let captureInterval;

	// =================================================================================
	// Main Initialization Logic
	// =================================================================================

	function initialize() {
		console.log("Tab Metaverse: Initializing...");
		chrome.runtime.sendMessage({ type: "REQUEST_TAB_STATE" }, (response) => {
			if (response && response.mode) {
				console.log(
					"Tab Metaverse: Found existing state, re-initializing.",
					response,
				);
				setup(response);
			} else {
				console.log(
					"Tab Metaverse: No existing state. Waiting for popup message.",
				);
				chrome.runtime.onMessage.addListener(handlePopupMessage);
			}
		});
	}

	function handlePopupMessage(message, sender, sendResponse) {
		if (
			message.type === "CREATE_ROOM_AND_HOST" ||
			message.type === "JOIN_ROOM_AS_VIEWER"
		) {
			console.log(
				"Tab Metaverse: Received initialization message from popup.",
				message,
			);
			const initialState = {
				mode:
					message.type === "CREATE_ROOM_AND_HOST"
						? "host"
						: "viewer",
				serverUrl: message.serverUrl,
				roomId: message.roomId,
				name: message.name,
			};
			setup(initialState);
			chrome.runtime.onMessage.removeListener(handlePopupMessage);
		}
		return true;
	}

	function setup(initialState) {
		state = { ...state, ...initialState };
		if (!state.serverUrl || !state.mode) {
			console.error("Tab Metaverse: Missing server URL or mode.", state);
			return;
		}
		createUI();
		connectToServer();
	}

	// =================================================================================
	// UI and Canvas
	// =================================================================================

	function createUI() {
		const host = document.createElement("div");
		host.id = "__tab_metaverse_root__";
		host.style.cssText = `
			position: fixed; top: 0; left: 0; width: 100%; height: 100%;
			z-index: 2147483647; pointer-events: none;
		`;
		const shadow = host.attachShadow({ mode: "open" });
		document.documentElement.appendChild(host);

		const style = document.createElement("style");
		style.textContent = `
            :host { all: initial; font-family: ui-sans-serif, system-ui; }
            #metaverse-ui {
                position: absolute; left: 0; top: 0; width: 100vw; height: 100vh;
                pointer-events: auto;
            }
            #broadcast-image {
                position: absolute; top: 0; left: 0; width: 100%; height: 100%;
                object-fit: contain; opacity: 0.9; pointer-events: none;
            }
            #host-panel {
                position: absolute; top: 10px; left: 10px; background: rgba(0,0,0,0.7);
                color: white; padding: 8px 12px; border-radius: 8px; font-size: 14px;
                pointer-events: auto;
            }
            #host-panel span { font-weight: bold; color: #4ade80; }
        `;
		shadow.appendChild(style);

		ui = document.createElement("div");
		ui.id = "metaverse-ui";
		shadow.appendChild(ui);

		if (state.mode === "viewer") {
			broadcastImage = document.createElement("img");
			broadcastImage.id = "broadcast-image";
			ui.appendChild(broadcastImage);
		}

		canvas = document.createElement("canvas");
		canvas.id = "mascot-layer";
		ui.appendChild(canvas);
		ctx = canvas.getContext("2d");

		fitCanvas();
		window.addEventListener("resize", fitCanvas);
		requestAnimationFrame(tick);
	}

	function displayHostPanel() {
		if (state.mode !== "host" || !ui) return;
		let panel = ui.querySelector("#host-panel");
		if (!panel) {
			panel = document.createElement("div");
			panel.id = "host-panel";
			ui.appendChild(panel);
		}
		panel.innerHTML = `Hosting Room: <span>${state.roomId}</span>`;
	}

	function fitCanvas() {
		canvas.width = document.documentElement.clientWidth;
		canvas.height = document.documentElement.clientHeight;
	}

	// =================================================================================
	// Networking (Socket.IO)
	// =================================================================================

	function connectToServer() {
		socket = io(state.serverUrl);

		socket.on("connect", () => {
			state.myId = socket.id;
			console.log(`Tab Metaverse: Connected with ID: ${socket.id}`);
			if (state.mode === "host") {
				socket.emit("createRoom", (response) => {
					state.roomId = response.roomId;
					console.log(`Tab Metaverse: Room created: ${state.roomId}`);
					displayHostPanel(); // Display the panel with the new Room ID
					storeStateInBackground();
					startHosting();
				});
			} else {
				socket.emit(
					"joinRoom",
					{ roomId: state.roomId, name: state.name },
					(response) => {
						if (response.success) {
							state.mascots = response.roomState.mascots;
							console.log(`Tab Metaverse: Joined room ${state.roomId}`);
							storeStateInBackground();
						} else {
							console.error("Tab Metaverse: Failed to join room.", response.message);
							alert(`Error: ${response.message}`);
							teardown();
						}
					},
				);
			}
		});

		socket.on("userJoined", ({ id, mascot }) => (state.mascots[id] = mascot));
		socket.on("userLeft", ({ id }) => delete state.mascots[id]);
		socket.on("mascotUpdated", ({ id, mascotData }) => {
			if (state.mascots[id]) Object.assign(state.mascots[id], mascotData);
		});
		socket.on("roomClosed", () => {
			alert("The host has closed the room.");
			teardown();
		});

		if (state.mode === "viewer") {
			socket.on("receiveFrame", (frame) => (broadcastImage.src = frame));
		}
	}

	// =================================================================================
	// Host-Specific Logic
	// =================================================================================

	function startHosting() {
		if (captureInterval) clearInterval(captureInterval);
		captureInterval = setInterval(captureAndBroadcastFrame, 10000);
	}

	async function captureAndBroadcastFrame() {
		try {
			const frame = await captureVisibleTab();
			const lowQualityFrame = await downscaleImage(frame, 0.5, "image/jpeg", 0.7);
			socket.emit("broadcastFrame", { roomId: state.roomId, frame: lowQualityFrame });
		} catch (error) {
			console.error("Tab Metaverse: Error capturing frame:", error);
			if (error.message.includes("permission")) clearInterval(captureInterval);
		}
	}

	function captureVisibleTab() {
		return new Promise((resolve, reject) => {
			chrome.runtime.sendMessage({ type: "CAPTURE_TAB" }, (response) => {
				if (response && response.success) resolve(response.dataUrl);
				else reject(new Error((response && response.error) || "Capture failed"));
			});
		});
	}

	// =================================================================================
	// Mascot Drawing and Physics
	// =================================================================================

	function tick() {
		ctx.clearRect(0, 0, canvas.width, canvas.height);
		for (const id in state.mascots) {
			const m = state.mascots[id];
			drawEmoji(m.type.split(":")[1], m.x, m.y, 64);
			drawName(m.name, m.x, m.y + 40);
		}
		requestAnimationFrame(tick);
	}

	function drawEmoji(emoji, x, y, size) {
		ctx.font = `${size}px serif`;
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		ctx.fillText(emoji, x, y);
	}
	function drawName(name, x, y) {
		ctx.font = "14px ui-sans-serif, system-ui";
		ctx.textAlign = "center";
		ctx.textBaseline = "top";
		ctx.fillStyle = "white";
		ctx.strokeStyle = "black";
		ctx.lineWidth = 2;
		ctx.strokeText(name, x, y);
		ctx.fillText(name, x, y);
	}

	// =================================================================================
	// State Management & Cleanup
	// =================================================================================

	function storeStateInBackground() {
		chrome.runtime.sendMessage({ type: "STORE_TAB_STATE", ...state });
	}

	function teardown() {
		console.log("Tab Metaverse: Tearing down.");
		if (socket) socket.disconnect();
		if (captureInterval) clearInterval(captureInterval);
		const root = document.getElementById("__tab_metaverse_root__");
		if (root) root.remove();
		chrome.runtime.sendMessage({ type: "CLEAR_TAB_STATE" });
		window.__TAB_METAVERSE_ACTIVE__ = false;
	}

	// =================================================================================
	// Utility Functions
	// =================================================================================

	function downscaleImage(dataUrl, scale, mimeType, quality) {
		return new Promise((resolve) => {
			const img = new Image();
			img.onload = () => {
				const canvas = document.createElement("canvas");
				canvas.width = img.width * scale;
				canvas.height = img.height * scale;
				const ctx = canvas.getContext("2d");
				ctx.drawImage(img, 0, 0, canvas.width, canvas.height);
				resolve(canvas.toDataURL(mimeType, quality));
			};
			img.src = dataUrl;
		});
	}

	// --- Start the process ---
	initialize();
})();
