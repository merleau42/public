// 26.03.22 13:00 버전

const CARET_GUARD = "\u200B";
const watchLogs = [];

document.addEventListener("DOMContentLoaded", () => {
	initializeAllGroups();
	ensureInitialRecord();
	initializeAllStopwatches();
	bindGlobalEvents();
	bindHoverActions();
	startGlobalTicker();
	updateRowGroupFractions();
	recalculateAllRecords();
	renderLogList();
});

function bindGlobalEvents() {
	document.addEventListener("click", (event) => {
		const headerPlusBtn = event.target.closest(".sub-cell.plus");
		if (headerPlusBtn) {
			handleAddColumn(headerPlusBtn);
			return;
		}

		if (event.target.closest("#theme-toggle-btn")) {
			toggleDarkMode();
			return;
		}

		if (event.target.closest("#log-open-btn")) {
			openOverlayModal("log-modal");
			renderLogList();
			return;
		}

		if (event.target.closest("#help-open-btn")) {
			openOverlayModal("help-modal");
			return;
		}

		if (event.target.closest("#log-close-btn")) {
			closeOverlayModal("log-modal");
			return;
		}

		if (event.target.closest("#help-close-btn")) {
			closeOverlayModal("help-modal");
			return;
		}

		const watchToggle = event.target.closest(".watch-toggle");
		if (watchToggle) {
			const recordRow = watchToggle.closest(".record-row");
			if (recordRow) {
				const wasRunning = recordRow.dataset.running === "true";
				toggleStopwatch(recordRow);
				recalculateRecord(recordRow);

				if (wasRunning) {
					appendStopLog(recordRow);
				}
			}
			watchToggle.blur();
			return;
		}

		const watchTime = event.target.closest(".watch-time");
		if (watchTime) {
			beginWatchTimeEdit(watchTime);
			return;
		}

		const addBtn = event.target.closest(".add-btn");
		if (addBtn) {
			const recordRow = addBtn.closest(".record-row");
			if (recordRow) insertRecordBelow(recordRow);
			addBtn.blur();
			closeAllWatchActions();
			return;
		}

		const resetBtn = event.target.closest(".reset-btn");
		if (resetBtn) {
			const recordRow = resetBtn.closest(".record-row");
			if (recordRow) resetRecordForReuse(recordRow);
			resetBtn.blur();
			closeAllWatchActions();
			return;
		}

		const deleteBtn = event.target.closest(".delete-btn");
		if (deleteBtn) {
			const recordRow = deleteBtn.closest(".record-row");
			if (recordRow) deleteRecord(recordRow);
			deleteBtn.blur();
			closeAllWatchActions();
			return;
		}

		const valueTargetBtn = event.target.closest(".value-target-btn");
		if (valueTargetBtn) {
			const valueCell = valueTargetBtn.closest(".value-cell");
			if (valueCell) openValueTargetModal(valueCell);
			return;
		}

		const valueTargetOption = event.target.closest(".value-target-option");
		if (valueTargetOption) {
			applyValueTargetSelection(valueTargetOption.dataset.targetKey, valueTargetOption.dataset.targetLabel);
			return;
		}

		const editableCell = event.target.closest(".value-cell");
		if (editableCell && !editableCell.classList.contains("readonly-cell")) {
			const textEl = editableCell.querySelector('.cell-text[contenteditable="true"]');
			if (textEl && !event.target.closest(".value-target-btn")) {
				prepareCaretAnchor(textEl);
				// focusEditableText(textEl); // 이 줄을 제거했습니다.
				return;
			}
		}

		if (event.target.id === "value-target-close-btn" || event.target.closest(".value-target-backdrop")) {
			closeValueTargetModal();
			return;
		}

		if (event.target.closest("#log-modal .overlay-backdrop")) {
			closeOverlayModal("log-modal");
			return;
		}

		if (event.target.closest("#help-modal .overlay-backdrop")) {
			closeOverlayModal("help-modal");
			return;
		}

		if (!event.target.closest(".watch-cell")) {
			closeAllWatchActions();
		}
	});

	document.addEventListener("focusin", (event) => {
		const editable = event.target.closest('[contenteditable="true"]');
		if (!editable) return;
		prepareCaretAnchor(editable);
	});

	document.addEventListener("input", (event) => {
		const editable = event.target.closest('[contenteditable="true"]');
		if (!editable) return;

		const recordRow = editable.closest(".record-row");
		if (recordRow) {
			recalculateRecord(recordRow);
			return;
		}

		if (editable.closest(".group")) {
			recalculateAllRecords();
		}
	});

	document.addEventListener("blur", (event) => {
		const editable = event.target.closest('[contenteditable="true"]');
		if (!editable) return;
		cleanupCaretGuard(editable);
	}, true);

	document.addEventListener("keydown", (event) => {
		const watchTime = event.target.closest(".watch-time.editing");
		if (!watchTime) return;

		if (event.key === "Enter") {
			event.preventDefault();
			commitWatchTimeEdit(watchTime);
			return;
		}

		if (event.key === "Escape") {
			event.preventDefault();
			cancelWatchTimeEdit(watchTime);
		}
	});

	document.addEventListener("focusout", (event) => {
		const watchTime = event.target.closest(".watch-time.editing");
		if (!watchTime) return;
		commitWatchTimeEdit(watchTime);
	});

	document.addEventListener("change", (event) => {
		const toggle = event.target.closest(".apply-toggle");
		if (toggle) {
			recalculateAllRecords();
		}
	});
}

function bindHoverActions() {
	document.addEventListener("mouseover", (event) => {
		const watchCell = event.target.closest(".watch-cell");
		if (!watchCell) return;
		openWatchActions(watchCell);
	});

	document.addEventListener("mouseover", (event) => {
		if (event.target.closest(".watch-cell")) return;
		closeAllWatchActions();
	});
}

function toggleDarkMode() {
	document.body.classList.toggle("dark-mode");
}

function openOverlayModal(modalId) {
	const modal = document.getElementById(modalId);
	if (!modal) return;
	modal.classList.remove("hidden");
}

function closeOverlayModal(modalId) {
	const modal = document.getElementById(modalId);
	if (!modal) return;
	modal.classList.add("hidden");
}

function renderLogList() {
	const logList = document.getElementById("log-list");
	if (!logList) return;

	logList.innerHTML = "";

	if (!watchLogs.length) {
		const empty = document.createElement("div");
		empty.className = "log-empty";
		empty.textContent = "아직 기록이 없습니다.";
		logList.appendChild(empty);
		return;
	}

	watchLogs
		.slice()
		.reverse()
		.forEach((logText) => {
			const item = document.createElement("div");
			item.className = "log-item";
			item.textContent = logText;
			logList.appendChild(item);
		});
}

function appendStopLog(recordRow) {
	const now = new Date();
	const hh = String(now.getHours()).padStart(2, "0");
	const mm = String(now.getMinutes()).padStart(2, "0");
	const timeLabel = `[${hh}:${mm}]`;

	const elapsedMs = Number(recordRow.dataset.elapsedMs || "0");
	const durationLabel = formatElapsedShort(elapsedMs);

	const changes = getMainChangeSummary(recordRow);
	const effs = getMainEfficiencySummary(recordRow);

	const logText = `${timeLabel} ${durationLabel}, 　 획득(${changes}), 　 효율(${effs})`;
	watchLogs.push(logText);
	renderLogList();
}

function getMainChangeSummary(recordRow) {
	const headerMap = getMainHeaderMap();
	const startCells = getRecordDataRowCells(recordRow, "main", 0);
	const endCells = getRecordDataRowCells(recordRow, "main", 1);

	const parts = headerMap.map((item, index) => {
		const startText = getEditableText(startCells[index]);
		const endText = getEditableText(endCells[index]);

		if (!startText || !endText) return null;

		const startValue = parseNumeric(startText);
		const endValue = parseNumeric(endText);
		const diff = endValue - startValue;

		return `${item.label} ${formatSignedNumber(diff)}`;
	}).filter(Boolean);

	return parts.length ? parts.join(", ") : "없음";
}

function getMainEfficiencySummary(recordRow) {
	const headerMap = getMainHeaderMap();
	const effCells = getRecordDataRowCells(recordRow, "main", 2);

	const parts = headerMap.map((item, index) => {
		const effText = getEditableText(effCells[index]);
		if (!effText) return null;
		const effValue = parseNumeric(effText);
		return `${item.label} ${formatSignedNumber(effValue)}`;
	}).filter(Boolean);

	return parts.length ? parts.join(", ") : "없음";
}

function formatSignedNumber(num) {
	if (!Number.isFinite(num)) return "0";
	const absText = formatNumber(Math.abs(num));
	return num > 0 ? `+${absText}` : num < 0 ? `-${absText}` : "0";
}

function formatElapsedShort(ms) {
	const totalSec = Math.floor(ms / 1000);
	const min = Math.floor(totalSec / 60);
	const sec = totalSec % 60;
	return `${min}분 ${sec}초`;
}

function prepareCaretAnchor(editable) {
	if (!editable) return;

	const plain = getPlainEditableText(editable);
	if (plain !== "") return;

	if ((editable.textContent || "") === CARET_GUARD) return;
	editable.textContent = CARET_GUARD;
}

function cleanupCaretGuard(editable) {
	if (!editable) return;

	const cleaned = getPlainEditableText(editable);
	const current = editable.textContent || "";
	if (current === cleaned) return;

	editable.textContent = cleaned;
}

function getPlainEditableText(editable) {
	if (!editable) return "";
	return (editable.textContent || "").replace(/\u200B/g, "").trim();
}

function focusEditableText(textEl) {
	textEl.focus();

	const selection = window.getSelection();
	const range = document.createRange();
	range.selectNodeContents(textEl);
	range.collapse(false);
	selection.removeAllRanges();
	selection.addRange(range);
}

function beginWatchTimeEdit(timeEl) {
	if (timeEl.classList.contains("editing")) return;

	const recordRow = timeEl.closest(".record-row");
	if (!recordRow) return;

	recordRow.dataset.editingTime = "true";
	timeEl.dataset.beforeEdit = timeEl.textContent;
	timeEl.classList.add("editing");
	timeEl.setAttribute("contenteditable", "true");

	prepareCaretAnchor(timeEl);
	focusEditableText(timeEl);
}

function commitWatchTimeEdit(timeEl) {
	if (!timeEl.classList.contains("editing")) return;

	const recordRow = timeEl.closest(".record-row");
	if (!recordRow) return;

	cleanupCaretGuard(timeEl);

	const parsedMs = parseElapsedText(timeEl.textContent);
	const safeMs = parsedMs == null ? getElapsedMs(recordRow) : parsedMs;

	recordRow.dataset.elapsedMs = String(safeMs);
	recordRow.dataset.editingTime = "false";

	if (recordRow.dataset.running === "true") {
		recordRow.dataset.startedAt = String(Date.now());
	} else {
		recordRow.dataset.startedAt = "";
	}

	timeEl.removeAttribute("contenteditable");
	timeEl.classList.remove("editing");

	renderStopwatch(recordRow);
	recalculateRecord(recordRow);
}

function cancelWatchTimeEdit(timeEl) {
	if (!timeEl.classList.contains("editing")) return;

	const recordRow = timeEl.closest(".record-row");
	if (!recordRow) return;

	timeEl.textContent = timeEl.dataset.beforeEdit || timeEl.textContent;
	timeEl.removeAttribute("contenteditable");
	timeEl.classList.remove("editing");
	recordRow.dataset.editingTime = "false";

	renderStopwatch(recordRow);
}

function parseElapsedText(text) {
	if (typeof text !== "string") return null;

	const cleaned = text.replace(/\s+/g, " ").trim();
	if (!cleaned) return null;

	let min = 0;
	let sec = 0;
	let matched = false;

	const minMatch = cleaned.match(/(\d+)\s*분/);
	if (minMatch) {
		min = Number(minMatch[1]);
		matched = true;
	}

	const secMatch = cleaned.match(/(\d+)\s*초/);
	if (secMatch) {
		sec = Number(secMatch[1]);
		matched = true;
	}

	if (!matched) {
		const colonMatch = cleaned.match(/^(\d+)\s*:\s*(\d{1,2})$/);
		if (colonMatch) {
			min = Number(colonMatch[1]);
			sec = Number(colonMatch[2]);
			matched = true;
		}
	}

	if (!matched) {
		const justNumber = cleaned.match(/^\d+$/);
		if (justNumber) {
			sec = Number(cleaned);
			matched = true;
		}
	}

	if (!matched) return null;
	if (!Number.isFinite(min) || !Number.isFinite(sec) || min < 0 || sec < 0) return null;

	return (min * 60 + sec) * 1000;
}

function openWatchActions(watchCell) {
	document.querySelectorAll(".watch-cell.actions-open").forEach((cell) => {
		if (cell !== watchCell) cell.classList.remove("actions-open");
	});
	watchCell.classList.add("actions-open");
}

function closeAllWatchActions() {
	document.querySelectorAll(".watch-cell.actions-open").forEach((cell) => {
		cell.classList.remove("actions-open");
	});
}

function initializeAllGroups() {
	document.querySelectorAll(".group").forEach((groupEl) => {
		const subGrid = groupEl.querySelector(".sub-grid");
		const cols = subGrid ? subGrid.children.length : 4;
		setGroupColumnCount(groupEl.dataset.group, cols);
	});
	refreshAllGridBorders();
}

function ensureInitialRecord() {
	const recordsEl = document.getElementById("records");
	if (!recordsEl) return;
	if (recordsEl.querySelector(".record-row")) return;

	const mainCols = getHeaderColumnCount("main");
	const gainCols = getHeaderColumnCount("gain");
	const loseCols = getHeaderColumnCount("lose");

	const recordRow = buildRecordRow(mainCols, gainCols, loseCols);
	recordsEl.appendChild(recordRow);

	initializeStopwatchState(recordRow);
	renderStopwatch(recordRow);

	setGroupColumnCount("main", mainCols);
	setGroupColumnCount("gain", gainCols);
	setGroupColumnCount("lose", loseCols);
	refreshAllGridBorders();
}

function initializeAllStopwatches() {
	document.querySelectorAll(".record-row").forEach((recordRow) => {
		initializeStopwatchState(recordRow);
		renderStopwatch(recordRow);
	});
}

function initializeStopwatchState(recordRow) {
	if (recordRow.dataset.elapsedMs == null) recordRow.dataset.elapsedMs = "0";
	if (recordRow.dataset.running == null) recordRow.dataset.running = "false";
	if (recordRow.dataset.startedAt == null) recordRow.dataset.startedAt = "";
	if (recordRow.dataset.editingTime == null) recordRow.dataset.editingTime = "false";
}

function toggleStopwatch(recordRow) {
	initializeStopwatchState(recordRow);

	const isRunning = recordRow.dataset.running === "true";
	const now = Date.now();

	if (isRunning) {
		const startedAt = Number(recordRow.dataset.startedAt || "0");
		const elapsedMs = Number(recordRow.dataset.elapsedMs || "0");
		recordRow.dataset.elapsedMs = String(elapsedMs + Math.max(0, now - startedAt));
		recordRow.dataset.running = "false";
		recordRow.dataset.startedAt = "";
	} else {
		recordRow.dataset.running = "true";
		recordRow.dataset.startedAt = String(now);
	}

	renderStopwatch(recordRow);
}

function renderStopwatch(recordRow) {
	const timeEl = recordRow.querySelector(".watch-time");
	if (!timeEl) return;
	if (timeEl.classList.contains("editing")) return;

	const elapsedMs = getElapsedMs(recordRow);
	timeEl.textContent = formatElapsed(elapsedMs);

	if (recordRow.dataset.running === "true") {
		timeEl.classList.add("running");
	} else {
		timeEl.classList.remove("running");
	}
}

function getElapsedMs(recordRow) {
	initializeStopwatchState(recordRow);

	const base = Number(recordRow.dataset.elapsedMs || "0");
	if (recordRow.dataset.running !== "true") return base;

	const startedAt = Number(recordRow.dataset.startedAt || "0");
	return base + Math.max(0, Date.now() - startedAt);
}

function formatElapsed(ms) {
	const totalSec = Math.floor(ms / 1000);
	const min = Math.floor(totalSec / 60);
	const sec = totalSec % 60;
	return `${String(min).padStart(2, "0")}분 ${String(sec).padStart(2, "0")}초`;
}

function startGlobalTicker() {
	setInterval(() => {
		document.querySelectorAll('.record-row[data-running="true"]').forEach((recordRow) => {
			if (recordRow.dataset.editingTime === "true") return;
			renderStopwatch(recordRow);
			recalculateRecord(recordRow);
		});
	}, 1000);
}

function handleAddColumn(plusBtn) {
	const groupEl = plusBtn.closest(".group");
	if (!groupEl) return;

	const groupName = groupEl.dataset.group;
	if (!groupName) return;

	addHeaderColumn(groupEl);
	addRecordColumns(groupName);
	updateGroupFromHeader(groupName);
	refreshAllGridBorders();
	updateRowGroupFractions();
	recalculateAllRecords();
}

function addHeaderColumn(groupEl) {
	const subGrid = groupEl.querySelector(".sub-grid");
	if (!subGrid) return;

	const newHeaderCell = document.createElement("div");
	newHeaderCell.className = "sub-cell";
	newHeaderCell.setAttribute("contenteditable", "true");
	newHeaderCell.textContent = "";

	subGrid.appendChild(newHeaderCell);
}

function addRecordColumns(groupName) {
	const recordGroups = document.querySelectorAll(`.record-group[data-group="${groupName}"]`);

	recordGroups.forEach((recordGroup) => {
		const recordGrid = recordGroup.querySelector(".record-grid");
		if (!recordGrid) return;

		const rows = Number(recordGroup.dataset.rows || 3);
		const currentCols = getCurrentColumnCount(recordGrid, rows);

		for (let row = rows - 1; row >= 0; row--) {
			const insertIndex = (row + 1) * currentCols;
			const newCell = createRecordValueCell(groupName, row);
			const refNode = recordGrid.children[insertIndex] || null;
			recordGrid.insertBefore(newCell, refNode);
		}
	});
}

function updateGroupFromHeader(groupName) {
	const headerGroup = document.querySelector(`.group[data-group="${groupName}"]`);
	if (!headerGroup) return;

	const subGrid = headerGroup.querySelector(".sub-grid");
	if (!subGrid) return;

	const cols = subGrid.children.length;
	setGroupColumnCount(groupName, cols);
}

function setGroupColumnCount(groupName, cols) {
	const headerGrid = document.querySelector(`.group[data-group="${groupName}"] .sub-grid`);
	if (headerGrid) headerGrid.style.setProperty("--cols", cols);

	document.querySelectorAll(`.record-group[data-group="${groupName}"] .record-grid`).forEach((grid) => {
		grid.style.setProperty("--cols", cols);
	});
}

function getCurrentColumnCount(recordGrid, rows) {
	const totalCells = recordGrid.children.length;
	return Math.max(1, totalCells / rows);
}

function refreshAllGridBorders() {
	document.querySelectorAll(".record-grid").forEach((grid) => {
		refreshRecordGridBorders(grid);
	});

	document.querySelectorAll(".sub-grid").forEach((grid) => {
		refreshHeaderGridBorders(grid);
	});
}

function refreshHeaderGridBorders(grid) {
	const cells = Array.from(grid.children);
	cells.forEach((cell) => cell.classList.remove("no-left-border"));
	cells.forEach((cell, index) => {
		if (index === 0) cell.classList.add("no-left-border");
	});
}

function refreshRecordGridBorders(grid) {
	const cells = Array.from(grid.children);
	const cols = Number(getComputedStyle(grid).getPropertyValue("--cols")) || inferCols(grid);

	cells.forEach((cell) => {
		cell.classList.remove("no-left-border", "no-top-border");
	});

	cells.forEach((cell, index) => {
		const colIndex = index % cols;
		const rowIndex = Math.floor(index / cols);

		if (colIndex === 0) cell.classList.add("no-left-border");
		if (rowIndex === 0) cell.classList.add("no-top-border");
	});
}

function inferCols(grid) {
	const total = grid.children.length;
	return total % 3 === 0 ? total / 3 : 4;
}

function updateRowGroupFractions() {
	const mainCols = getHeaderColumnCount("main");
	const gainCols = getHeaderColumnCount("gain");
	const loseCols = getHeaderColumnCount("lose");

	const headerRow = document.querySelector(".header-row");
	if (headerRow) {
		headerRow.style.setProperty("--main-fr", `${mainCols}fr`);
		headerRow.style.setProperty("--gain-fr", `${gainCols}fr`);
		headerRow.style.setProperty("--lose-fr", `${loseCols}fr`);
	}

	document.querySelectorAll(".record-row").forEach((recordRow) => {
		recordRow.style.setProperty("--main-fr", `${mainCols}fr`);
		recordRow.style.setProperty("--gain-fr", `${gainCols}fr`);
		recordRow.style.setProperty("--lose-fr", `${loseCols}fr`);
	});
}

function insertRecordBelow(sourceRecordRow) {
	const mainCols = getHeaderColumnCount("main");
	const gainCols = getHeaderColumnCount("gain");
	const loseCols = getHeaderColumnCount("lose");

	const copiedGainValueRow = getRowValuesFromRecord(sourceRecordRow, "gain", 1);
	const copiedLoseValueRow = getRowValuesFromRecord(sourceRecordRow, "lose", 1);
	const copiedGainTargets = getRowValueTargetsFromRecord(sourceRecordRow, "gain", 1);
	const copiedLoseTargets = getRowValueTargetsFromRecord(sourceRecordRow, "lose", 1);

	const recordRow = buildRecordRow(mainCols, gainCols, loseCols);
	sourceRecordRow.insertAdjacentElement("afterend", recordRow);

	fillValueRow(recordRow, "gain", 1, copiedGainValueRow);
	fillValueRow(recordRow, "lose", 1, copiedLoseValueRow);
	fillValueTargetsRow(recordRow, "gain", 1, copiedGainTargets);
	fillValueTargetsRow(recordRow, "lose", 1, copiedLoseTargets);

	initializeStopwatchState(recordRow);
	renderStopwatch(recordRow);

	setGroupColumnCount("main", mainCols);
	setGroupColumnCount("gain", gainCols);
	setGroupColumnCount("lose", loseCols);
	refreshAllGridBorders();
	updateRowGroupFractions();
	recalculateRecord(recordRow);
}

function buildRecordRow(mainCols, gainCols, loseCols) {
	const recordRow = document.createElement("div");
	recordRow.className = "record-row";

	recordRow.innerHTML = `
		<div class="watch-cell">
			<div class="watch-inner">
				<button type="button" class="watch-toggle" aria-label="스톱워치 시작 또는 일시정지">⏱</button>
				<div class="watch-time" aria-label="경과 시간 수정 가능">00분 00초</div>
			</div>

			<div class="watch-actions" aria-label="레코드 작업">
				<button type="button" class="watch-action-btn add-btn" aria-label="아래에 레코드 추가">➕</button>
				<button type="button" class="watch-action-btn reset-btn" aria-label="조건부 재사용">♻</button>
				<button type="button" class="watch-action-btn delete-btn" aria-label="레코드 삭제">❌</button>
			</div>
		</div>

		<div class="record-group" data-group="main" data-rows="3">
			<div class="record-grid"></div>
		</div>

		<div class="record-group" data-group="gain" data-rows="3">
			<div class="record-grid"></div>
		</div>

		<div class="record-group" data-group="lose" data-rows="3">
			<div class="record-grid"></div>
		</div>
	`;

	fillRecordGrid(
		recordRow.querySelector('.record-group[data-group="main"] .record-grid'),
		"main",
		["시작", "종료", "효율"],
		mainCols
	);

	fillRecordGrid(
		recordRow.querySelector('.record-group[data-group="gain"] .record-grid'),
		"gain",
		["수량", "가치", "합계"],
		gainCols
	);

	fillRecordGrid(
		recordRow.querySelector('.record-group[data-group="lose"] .record-grid'),
		"lose",
		["수량", "가치", "합계"],
		loseCols
	);

	return recordRow;
}

function fillRecordGrid(grid, groupName, rowLabels, cols) {
	if (!grid) return;

	grid.innerHTML = "";
	grid.style.setProperty("--cols", cols);

	rowLabels.forEach((label, rowIndex) => {
		const labelCell = document.createElement("div");
		labelCell.className = "cell label-cell";
		labelCell.textContent = label;
		grid.appendChild(labelCell);

		for (let i = 1; i < cols; i++) {
			grid.appendChild(createRecordValueCell(groupName, rowIndex));
		}
	});
}

function createRecordValueCell(groupName, rowIndex) {
	const valueCell = document.createElement("div");
	valueCell.className = "cell value-cell";

	const isGainOrLose = groupName === "gain" || groupName === "lose";
	const isValueRow = rowIndex === 1;
	const isTotalRow = isGainOrLose && rowIndex === 2;
	const isMainEffRow = groupName === "main" && rowIndex === 2;

	const textSpan = document.createElement("div");
	textSpan.className = "cell-text";

	if (!(isTotalRow || isMainEffRow)) {
		textSpan.setAttribute("contenteditable", "true");
	}

	valueCell.appendChild(textSpan);

	if (isTotalRow || isMainEffRow) {
		valueCell.classList.add("readonly-cell", "computed-cell");
		return valueCell;
	}

	if (isGainOrLose && isValueRow) {
		valueCell.classList.add("value-target-cell");

		const targetBtn = document.createElement("button");
		targetBtn.type = "button";
		targetBtn.className = "value-target-btn";
		targetBtn.textContent = "⚙";

		const badge = document.createElement("span");
		badge.className = "value-target-badge";

		valueCell.appendChild(targetBtn);
		valueCell.appendChild(badge);
	}

	return valueCell;
}

function getHeaderColumnCount(groupName) {
	const subGrid = document.querySelector(`.group[data-group="${groupName}"] .sub-grid`);
	return subGrid ? subGrid.children.length : 4;
}

function getRowValuesFromRecord(recordRow, groupName, rowIndex) {
	const recordGrid = recordRow.querySelector(`.record-group[data-group="${groupName}"] .record-grid`);
	if (!recordGrid) return [];

	const cols = Number(getComputedStyle(recordGrid).getPropertyValue("--cols")) || inferCols(recordGrid);
	const cells = Array.from(recordGrid.children);
	const start = rowIndex * cols;

	const values = [];
	for (let i = start + 1; i < start + cols; i++) {
		values.push(getEditableText(cells[i]));
	}
	return values;
}

function getRowValueTargetsFromRecord(recordRow, groupName, rowIndex) {
	const recordGrid = recordRow.querySelector(`.record-group[data-group="${groupName}"] .record-grid`);
	if (!recordGrid) return [];

	const cols = Number(getComputedStyle(recordGrid).getPropertyValue("--cols")) || inferCols(recordGrid);
	const cells = Array.from(recordGrid.children);
	const start = rowIndex * cols;

	const values = [];
	for (let i = start + 1; i < start + cols; i++) {
		values.push({
			key: cells[i]?.dataset.targetKey || "",
			label: cells[i]?.dataset.targetLabel || ""
		});
	}
	return values;
}

function fillValueRow(recordRow, groupName, rowIndex, values) {
	const rowCells = getRecordDataRowCells(recordRow, groupName, rowIndex);
	rowCells.forEach((cell, index) => {
		setEditableText(cell, values[index] ?? "");
	});
}

function fillValueTargetsRow(recordRow, groupName, rowIndex, targets) {
	const rowCells = getRecordDataRowCells(recordRow, groupName, rowIndex);
	rowCells.forEach((cell, index) => {
		const target = targets[index];
		if (!target) return;
		setValueTarget(cell, target.key || "", target.label || "");
	});
}

function clearRowValues(recordRow, groupName, rowIndex) {
	const rowCells = getRecordDataRowCells(recordRow, groupName, rowIndex);
	rowCells.forEach((cell) => {
		setEditableText(cell, "");
		if (cell.classList.contains("value-target-cell")) {
			setValueTarget(cell, "", "");
		}
	});
}

function clearAllRows(recordRow, groupName) {
	for (let rowIndex = 0; rowIndex < 3; rowIndex++) {
		clearRowValues(recordRow, groupName, rowIndex);
	}
}

function resetRecordForReuse(recordRow) {
	clearRowValues(recordRow, "gain", 0);
	clearRowValues(recordRow, "lose", 0);

	const startCells = getRecordDataRowCells(recordRow, "main", 0);
	const endCells = getRecordDataRowCells(recordRow, "main", 1);
	const hasAnyEndValue = endCells.some((cell) => getEditableText(cell) !== "");

	if (hasAnyEndValue) {
		startCells.forEach((startCell, index) => {
			setEditableText(startCell, getEditableText(endCells[index]));
		});
		endCells.forEach((endCell) => {
			setEditableText(endCell, "");
		});
	} else {
		clearAllRows(recordRow, "main");
	}

	recordRow.dataset.elapsedMs = "0";
	recordRow.dataset.running = "false";
	recordRow.dataset.startedAt = "";
	recordRow.dataset.editingTime = "false";
	renderStopwatch(recordRow);
	recalculateRecord(recordRow);
}

function deleteRecord(recordRow) {
	const rows = document.querySelectorAll(".record-row");
	if (rows.length <= 1) {
		resetRecordForReuse(recordRow);
		closeAllWatchActions();
		return;
	}
	recordRow.remove();
	closeAllWatchActions();
}

function getRecordDataRowCells(recordRow, groupName, rowIndex) {
	const recordGrid = recordRow.querySelector(`.record-group[data-group="${groupName}"] .record-grid`);
	if (!recordGrid) return [];

	const cols = Number(getComputedStyle(recordGrid).getPropertyValue("--cols")) || inferCols(recordGrid);
	const cells = Array.from(recordGrid.children);
	const start = rowIndex * cols;

	return cells.slice(start + 1, start + cols);
}

function getMainHeaderMap() {
	const subGrid = document.querySelector('.group[data-group="main"] .sub-grid');
	if (!subGrid) return [];

	const cells = Array.from(subGrid.children).slice(1);
	return cells.map((cell, index) => ({
		key: `main-${index}`,
		label: getPlainEditableText(cell) || `항목${index + 1}`,
		index
	}));
}

function getEditableText(cell) {
	if (!cell) return "";
	const textEl = cell.querySelector(".cell-text");
	if (!textEl) return "";
	return getPlainEditableText(textEl);
}

function setEditableText(cell, text) {
	if (!cell) return;
	const textEl = cell.querySelector(".cell-text");
	if (!textEl) return;

	const nextText = text ?? "";
	const currentText = textEl.textContent ?? "";

	if (currentText === nextText) return;
	textEl.textContent = nextText;
}

function parseNumeric(text) {
	if (typeof text !== "string") return 0;
	const cleaned = text.replace(/,/g, "").trim();
	if (!cleaned) return 0;
	const num = Number(cleaned);
	return Number.isFinite(num) ? num : 0;
}

function formatNumber(num) {
	if (!Number.isFinite(num)) return "";
	if (Math.abs(num) < 1e-9) return "0";
	if (Math.abs(num % 1) < 1e-9) return String(Math.round(num));
	return num.toFixed(1).replace(/\.?0+$/, "");
}

function recalculateAllRecords() {
	document.querySelectorAll(".record-row").forEach((recordRow) => {
		recalculateRecord(recordRow);
	});
}

function recalculateRecord(recordRow) {
	recalculateGainLoseGroup(recordRow, "gain");
	recalculateGainLoseGroup(recordRow, "lose");
	recalculateMainEfficiencies(recordRow);
}

function recalculateGainLoseGroup(recordRow, groupName) {
	const quantityCells = getRecordDataRowCells(recordRow, groupName, 0);
	const valueCells = getRecordDataRowCells(recordRow, groupName, 1);
	const totalCells = getRecordDataRowCells(recordRow, groupName, 2);

	totalCells.forEach((totalCell, index) => {
		const qty = parseNumeric(getEditableText(quantityCells[index]));
		const unitValue = parseNumeric(getEditableText(valueCells[index]));
		const total = qty * unitValue;
		setEditableText(totalCell, formatNumber(total));
		totalCell.classList.add("computed-cell", "readonly-cell");
	});
}

function recalculateMainEfficiencies(recordRow) {
	const startCells = getRecordDataRowCells(recordRow, "main", 0);
	const endCells = getRecordDataRowCells(recordRow, "main", 1);
	const effCells = getRecordDataRowCells(recordRow, "main", 2);

	const elapsedMs = getElapsedMs(recordRow);
	const elapsedHours = elapsedMs / 3600000;

	const baseEffs = startCells.map((startCell, index) => {
		const startText = getEditableText(startCell);
		const endText = getEditableText(endCells[index]);

		if (!startText || !endText) return null;
		if (elapsedHours <= 0) return null;

		const startValue = parseNumeric(startText);
		const endValue = parseNumeric(endText);
		return (endValue - startValue) / elapsedHours;
	});

	const headerMap = getMainHeaderMap();
	const finalEffs = [...baseEffs];

	["gain", "lose"].forEach((groupName) => {
		const applyToggle = document.querySelector(`.apply-toggle[data-group="${groupName}"]`);
		const shouldApply = applyToggle ? applyToggle.checked : true;
		if (!shouldApply) return;

		const sign = groupName === "gain" ? 1 : -1;
		const totalCells = getRecordDataRowCells(recordRow, groupName, 2);
		const valueCells = getRecordDataRowCells(recordRow, groupName, 1);

		totalCells.forEach((totalCell, index) => {
			const targetKey = valueCells[index]?.dataset.targetKey;
			if (!targetKey) return;

			const mainIndex = headerMap.find((item) => item.key === targetKey)?.index;
			if (mainIndex == null) return;
			if (finalEffs[mainIndex] == null) return;
			if (elapsedHours <= 0) return;

			const totalValue = parseNumeric(getEditableText(totalCell));
			finalEffs[mainIndex] += sign * (totalValue / elapsedHours);
		});
	});

	effCells.forEach((effCell, index) => {
		const value = finalEffs[index];
		setEditableText(effCell, value == null ? "" : formatNumber(value));
		effCell.classList.add("computed-cell", "readonly-cell");
	});
}

function openValueTargetModal(valueCell) {
	const modal = document.getElementById("value-target-modal");
	const list = document.getElementById("value-target-list");
	if (!modal || !list) return;

	modal.dataset.targetCellId = ensureTargetCellId(valueCell);
	list.innerHTML = "";

	const headerMap = getMainHeaderMap();
	headerMap.forEach((item) => {
		const btn = document.createElement("button");
		btn.type = "button";
		btn.className = "value-target-option";
		btn.dataset.targetKey = item.key;
		btn.dataset.targetLabel = item.label;
		btn.textContent = item.label;
		list.appendChild(btn);
	});

	const clearBtn = document.createElement("button");
	clearBtn.type = "button";
	clearBtn.className = "value-target-option";
	clearBtn.dataset.targetKey = "";
	clearBtn.dataset.targetLabel = "";
	clearBtn.textContent = "선택 해제";
	list.appendChild(clearBtn);

	modal.classList.remove("hidden");
}

function closeValueTargetModal() {
	const modal = document.getElementById("value-target-modal");
	if (!modal) return;
	modal.classList.add("hidden");
	modal.dataset.targetCellId = "";
}

function ensureTargetCellId(cell) {
	if (!cell.dataset.targetCellId) {
		cell.dataset.targetCellId = `target-cell-${Math.random().toString(36).slice(2, 10)}`;
	}
	return cell.dataset.targetCellId;
}

function applyValueTargetSelection(targetKey, targetLabel) {
	const modal = document.getElementById("value-target-modal");
	if (!modal) return;

	const targetCellId = modal.dataset.targetCellId;
	if (!targetCellId) return;

	const valueCell = document.querySelector(`[data-target-cell-id="${targetCellId}"]`);
	if (!valueCell) return;

	setValueTarget(valueCell, targetKey || "", targetLabel || "");
	closeValueTargetModal();

	const recordRow = valueCell.closest(".record-row");
	if (recordRow) recalculateRecord(recordRow);
}

function setValueTarget(valueCell, targetKey, targetLabel) {
	valueCell.dataset.targetKey = targetKey;
	valueCell.dataset.targetLabel = targetLabel;

	const badge = valueCell.querySelector(".value-target-badge");
	if (badge) {
		badge.textContent = targetLabel || "";
	}
}