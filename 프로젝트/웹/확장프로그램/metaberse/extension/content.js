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

	/**
	 * Primary entry point. Checks for a pre-existing state in the background script.
	 * If found, re-initializes the metaverse. Otherwise, waits for a message from the popup.
	 */
	function initialize() {
		console.log("Tab Metaverse: Initializing...");
		// Ask the background script if we already have a state for this tab
		chrome.runtime.sendMessage({ type: "REQUEST_TAB_STATE" }, (response) => {
			if (response && response.mode) {
				console.log(
					"Tab Metaverse: Found existing state, re-initializing.",
					response,
				);
				// Re-initialize using the state from the background script
				setup(response);
			} else {
				console.log(
					"Tab Metaverse: No existing state. Waiting for popup message.",
				);
				// Listen for the initial setup message from the popup
				chrome.runtime.onMessage.addListener(
					handlePopupMessage,
				);
			}
		});
	}

	/**
	 * Handles the one-time initialization message from the popup.
	 */
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
				roomId: message.roomId, // Will be null for hosts initially
				name: message.name,
			};
			setup(initialState);
			// Important: Remove the listener after first use to avoid re-initialization
			chrome.runtime.onMessage.removeListener(handlePopupMessage);
		}
		return true;
	}

	/**
	 * Sets up the UI, connects to the socket server, and starts the appropriate mode.
	 * @param {object} initialState - The initial state for the tab.
	 */
	function setup(initialState) {
		state = { ...state, ...initialState };
		if (!state.serverUrl || !state.mode) {
			console.error("Tab Metaverse: Missing server URL or mode.", state);
			return;
		}

		// The 'io' function is now available directly because popup.js injected it.
		createUI();
		connectToServer();
	}

	// =================================================================================
	// UI and Canvas
	// =================================================================================

	function createUI() {
		const host = document.createElement("div");
		host.id = "__tab_metaverse_root__";
		host.style.position = "fixed";
		host.style.top = "0";
		host.style.left = "0";
		host.style.width = "100%";
		host.style.height = "100%";
		host.style.zIndex = "2147483647";
		host.style.pointerEvents = "none";

		const shadow = host.attachShadow({ mode: "open" });
		document.documentElement.appendChild(host);

		const style = document.createElement("style");
		style.textContent = `
            :host { all: initial; }
            #metaverse-ui {
                position: absolute;
                left: 0;
                top: 0;
                width: 100vw;
                height: 100vh;
                pointer-events: auto;
            }
            #broadcast-image {
                position: absolute;
                top: 0;
                left: 0;
                width: 100%;
                height: 100%;
                object-fit: contain;
                opacity: 0.9;
                pointer-events: none;
            }
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
			console.log(`Tab Metaverse: Connected to server with ID: ${socket.id}`);
			if (state.mode === "host") {
				socket.emit("createRoom", (response) => {
					state.roomId = response.roomId;
					console.log(
						`Tab Metaverse: Room created with ID: ${state.roomId}`,
					);
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
							console.log(
								`Tab Metaverse: Joined room ${state.roomId}`,
								state.mascots,
							);
							storeStateInBackground();
						} else {
							console.error(
								"Tab Metaverse: Failed to join room.",
								response.message,
							);
							teardown();
						}
					},
				);
			}
		});

		// Common event listeners
		socket.on("userJoined", ({ id, mascot }) => {
			state.mascots[id] = mascot;
			console.log("User joined:", id, mascot);
		});
		socket.on("userLeft", ({ id }) => {
			delete state.mascots[id];
			console.log("User left:", id);
		});
		socket.on("mascotUpdated", ({ id, mascotData }) => {
			if (state.mascots[id]) {
				Object.assign(state.mascots[id], mascotData);
			}
		});
		socket.on("roomClosed", () => {
			console.log("Tab Metaverse: Room closed by host.");
			alert("The host has closed the room.");
			teardown();
		});

		// Viewer-specific event
		if (state.mode === "viewer") {
			socket.on("receiveFrame", (frame) => {
				broadcastImage.src = frame;
			});
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
			// Note: This uses a theoretical chrome.tabs.captureVisibleTab API.
			// In a real extension, this would be more complex and require background script communication.
			const frame = await captureVisibleTab();
			const lowQualityFrame = await downscaleImage(frame, 0.5, "image/jpeg", 0.7);
			socket.emit("broadcastFrame", {
				roomId: state.roomId,
				frame: lowQualityFrame,
			});
		} catch (error) {
			console.error("Tab Metaverse: Error capturing frame:", error);
			// Stop broadcasting if permission is denied
			if (error.message.includes("permission")) {
				clearInterval(captureInterval);
			}
		}
	}

	// Helper to capture the visible tab content. Requires permissions.
	function captureVisibleTab() {
		return new Promise((resolve, reject) => {
			chrome.runtime.sendMessage({ type: "CAPTURE_TAB" }, (response) => {
				if (response.success) {
					resolve(response.dataUrl);
				} else {
					reject(new Error(response.error));
				}
			});
		});
	}

	// =================================================================================
	// Mascot Drawing and Physics
	// =================================================================================

	function tick() {
		// (For brevity, mascot physics and movement logic is simplified)
		// A full implementation would handle local input and broadcast updates.
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

	/**
	 * Stores the current state in the background script for persistence.
	 */
	function storeStateInBackground() {
		chrome.runtime.sendMessage({
			type: "STORE_TAB_STATE",
			...state,
		});
	}

	/**
	 * Cleans up all resources, intervals, and UI elements.
	 */
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
