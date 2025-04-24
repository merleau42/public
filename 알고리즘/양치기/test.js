{/* <div id="editModal" style="display:none;" class="modal">
<div class="modal-content">
	<h3>문제 수정</h3>
	<label>요약</label><textarea id="editSummary"></textarea><br>
	<label>해답</label><textarea id="editSolution"></textarea><br>
	<label>태그 (쉼표, !는 메인)</label><input type="text" id="editTags"><br>
	<button id="saveEdit">저장</button>
	<button id="cancelEdit">취소</button>
</div>
</div> */}

QQ('.editCard').forEach(editCard => {
	editCard.addEventListener('click', () => {
		const 해당카드 = editCard.closest('.card');
		const 문제정보 = DB.problems.find(p => p.id == 해당카드.dataset.id);

		// 모달에 데이터 표시
		Q('#editModal').style.display = 'flex';
		Q('#editModal').dataset.id = 문제정보.id;
		Q('#editSummary').value = 문제정보.summary;
		Q('#editSolution').value = 문제정보.solution1 || '';
		Q('#editTags').value = 문제정보.tags.join(', ');
	});
});


Q('#saveEdit').addEventListener('click', () => {
	const id = Q('#editModal').dataset.id;
	const prob = DB.problems.find(p => p.id == id);
	if (!prob) return;

	// 데이터 수정
	prob.summary = Q('#editSummary').value.trim();
	prob.solution1 = Q('#editSolution').value.trim();
	prob.tags = Q('#editTags').value.split(',').map(t => t.trim()).filter(t => t);

	// DOM 요소 찾기
	const card = QQ('.card').find(c => c.dataset.id === id);
	if (!card) return;

	const content = card.querySelector('.content');
	const summaryEl = content.querySelector('.summary');
	summaryEl.textContent = prob.summary;

	const solutionEl = card.querySelector('.solution');
	solutionEl.textContent = prob.solution1;

	// 태그 박스 초기화 후 재구성
	const tagbox = card.querySelector('.tagbox');
	tagbox.querySelectorAll('.tag').forEach(e => e.remove());

	const 주 = prob.tags.filter(t => t.endsWith('!')).map(t => t.slice(0, -1));
	const 부 = prob.tags.filter(t => !t.endsWith('!'));
	if (prob.tags.length === 0) 부.push('미분류');

	주.forEach(tag => tagbox.appendChild(createElement('span', 'tag main-tag', `#${tag}`)));
	부.forEach(tag => tagbox.appendChild(createElement('span', 'tag sub-tag', `#${tag}`)));

	Q('#editModal').style.display = 'none';
});


Q('#cancelEdit').addEventListener('click', () => {
	Q('#editModal').style.display = 'none';
});

// 모달 바깥 클릭 시 닫기
Q('#editModal').addEventListener('click', e => {
	if (e.target.id === 'editModal') Q('#editModal').style.display = 'none';
});