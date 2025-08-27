// This script manages the state of tabs that are part of the metaverse.

const tabStates = {}; // tabId -> { mode: 'host'/'viewer', roomId, serverUrl, name }

// Listen for messages from popup or content scripts
chrome.runtime.onMessage.addListener((message, sender, sendResponse) => {
	const tabId = sender.tab?.id;

	switch (message.type) {
		// Store the tab's state when it becomes a host or viewer
		case "STORE_TAB_STATE":
			if (tabId) {
				tabStates[tabId] = {
					mode: message.mode,
					roomId: message.roomId,
					serverUrl: message.serverUrl,
					name: message.name,
				};
				console.log(
					`State stored for tab ${tabId}:`,
					tabStates[tabId],
				);
			}
			break;

		// When a content script is loaded (e.g., after navigation),
		// provide it with its stored state so it can re-initialize.
		case "REQUEST_TAB_STATE":
			if (tabId && tabStates[tabId]) {
				sendResponse(tabStates[tabId]);
			} else {
				sendResponse(null); // No state found for this tab
			}
			break;

		// Clear the tab's state when the metaverse is closed
		case "CLEAR_TAB_STATE":
			if (tabId && tabStates[tabId]) {
				delete tabStates[tabId];
				console.log(`State cleared for tab ${tabId}`);
			}
			break;

		// Handle request from content script to capture the visible tab
		case "CAPTURE_TAB":
			if (tabId) {
				chrome.tabs.captureVisibleTab(
					sender.tab.windowId,
					{ format: "jpeg", quality: 80 },
					(dataUrl) => {
						if (chrome.runtime.lastError) {
							sendResponse({
								success: false,
								error: chrome.runtime.lastError.message,
							});
						} else {
							sendResponse({ success: true, dataUrl: dataUrl });
						}
					},
				);
			}
			// Return true to indicate that we will send a response asynchronously
			return true;
	}
	// Return true for other async cases if any
	return true;
});

// Clean up the state when a tab is closed
chrome.tabs.onRemoved.addListener((tabId) => {
	if (tabStates[tabId]) {
		delete tabStates[tabId];
		console.log(`State cleared for closed tab ${tabId}`);
	}
});
