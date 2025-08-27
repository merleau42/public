const { Server } = require("socket.io");

const io = new Server(3000, {
	cors: {
		origin: "*",
	},
});

const rooms = {}; // In-memory store for room data: { roomId: { host: socket.id, mascots: { socket.id: mascotData } } }

io.on("connection", (socket) => {
	console.log(`User connected: ${socket.id}`);

	/**
	 * Creates a new room and assigns the creator as the host.
	 * @param {Function} callback - Acknowledges room creation and returns the new room ID.
	 */
	socket.on("createRoom", (callback) => {
		const roomId = Math.random().toString(36).substring(2, 8).toUpperCase();
		socket.join(roomId);
		rooms[roomId] = {
			host: socket.id,
			mascots: {},
		};
		// Add host's mascot
		rooms[roomId].mascots[socket.id] = {
			x: 100,
			y: 100,
			type: "emoji:🐥",
			name: "Host",
		};
		console.log(`Room created: ${roomId} by host ${socket.id}`);
		callback({ roomId });
	});

	/**
	 * Joins an existing room as a viewer.
	 * @param {Object} data - { roomId, name }
	 * @param {Function} callback - Acknowledges success or failure and returns initial room state.
	 */
	socket.on("joinRoom", ({ roomId, name }, callback) => {
		const room = rooms[roomId];
		if (room) {
			socket.join(roomId);
			// Add viewer's mascot
			room.mascots[socket.id] = {
				x: 200,
				y: 100,
				type: "emoji:🦊",
				name: name || `User-${socket.id.slice(0, 4)}`,
			};
			console.log(`User ${socket.id} joined room ${roomId}`);

			// Notify other users in the room about the new user
			socket
				.to(roomId)
				.emit("userJoined", {
					id: socket.id,
					mascot: room.mascots[socket.id],
				});
			// Send the complete room state (including all mascots) to the new user
			callback({ success: true, roomState: room });
		} else {
			callback({ success: false, message: "Room not found" });
		}
	});

	/**
	 * Relays a captured screen frame from the host to all viewers in a room.
	 * @param {Object} data - { roomId, frame }
	 */
	socket.on("broadcastFrame", ({ roomId, frame }) => {
		const room = rooms[roomId];
		// Ensure the sender is the host of the room
		if (room && room.host === socket.id) {
			socket.to(roomId).emit("receiveFrame", frame);
		}
	});

	/**
	 * Updates a user's mascot data and broadcasts it to others in the room.
	 * @param {Object} data - { roomId, mascotData }
	 */
	socket.on("mascotUpdate", ({ roomId, mascotData }) => {
		const room = rooms[roomId];
		if (room && room.mascots[socket.id]) {
			room.mascots[socket.id] = {
				...room.mascots[socket.id],
				...mascotData,
			};
			socket
				.to(roomId)
				.emit("mascotUpdated", {
					id: socket.id,
					mascotData: room.mascots[socket.id],
				});
		}
	});

	/**
	 * Handles user disconnection, cleaning up rooms and notifying other users.
	 */
	socket.on("disconnect", () => {
		console.log(`User disconnected: ${socket.id}`);
		for (const roomId in rooms) {
			const room = rooms[roomId];
			if (room.host === socket.id) {
				// Host disconnected, notify viewers and destroy the room
				console.log(
					`Host of room ${roomId} disconnected. Closing room.`,
				);
				io.to(roomId).emit("roomClosed");
				delete rooms[roomId];
				return;
			}

			if (room.mascots[socket.id]) {
				// A viewer disconnected
				delete room.mascots[socket.id];
				io.to(roomId).emit("userLeft", { id: socket.id });
				console.log(`Viewer ${socket.id} left room ${roomId}`);
				return;
			}
		}
	});
});

console.log("Server is listening on port 3000");
