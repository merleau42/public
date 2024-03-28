// 팔만코딩경 DB에서 'Duplicate' 누르면 가벼운 페이지가 등장. 스크롤을 끝까지 내려서 1306개의 항목을 모두 로딩시키고 아래 코드를 실행.
// [제목] 셀의 댓글 갯수 없애기
[...document.querySelectorAll('[role=graphics-symbol]')].map(x=>x.parentNode.remove());

// 팔만코딩경 DB를 평범한 테이블 <태그>로 변경하기.
`<tbody>\n`+
	// 모든 행을 가져오기
	[...document.querySelectorAll('.notion-table-view-row')]
		// 모든 행에 대해서 다음을 실행
		.map(row=>
				// 각 행의 모든 열을 가져오기
				(rewind=[...row.querySelectorAll('[data-col-index]')])

				// 필요한 열만 남기기 (0제목/1주제/2이름/3태그/4소개)
				.filter(col=>[0,1,4,5,7].includes(col.attributes['data-col-index'].value*1))

				// 엘리멘트의 텍스트 추출하기, 필요없는 개행 없애기
				.map(col => col.innerText.replace(/\n/g,', '))

				// 원하는 순서로 열을 재배치하기 (0이름/1제목/2소개/3주제/4태그)
				// 모든 열에 순서 표식을 남기고, 아스키 순으로 정렬하기
				.map((col,i) => `${[1,3,0,4,2][i]}####${col}`)
				.toSorted()

				// 순서 표식 없애기
				.map(col => col.replace(/\d####/g,''))

				// 셀에 포함된 <소괄호>가 html 태그로 인식되지 않도록 변경하기
				.map(col => col.replace(/</,'<:').replace(/>/,':>'))

				// [제목]에 하이퍼링크 추가하기
				.reduce((s,c,i) => [...s,
					i==1 ? `<a href="${rewind[0].querySelector('a').href}">${c}</a>` : c], [])

				// [주제 분류]랑 [태그 분류]셀을 통합하고, 중복 제거하기
				.map((col,i,a)=> i!=3 ? col
				: ([...new Set((col+','+a[i+1]).toLowerCase().split(/ *, */))]+'').replace(/^,|,$|(,)([^$])/g,'$1 $2')).slice(0,4)

				// [이름] 혹은 [분류] 비었다면 - 으로 표기
				.reduce((s,c,i) => [...s, (i==0||i==3)&&!c ? '-' : c], [])

				// 모든 열을 <td>로 감싸기
				.map(col => `<td>${col}</td>\n`)

				// 모든 열을 결합해서 하나의 행 문자열로 만들기
				.join('')
			)
		// [메모] 열 추가하기
		.map(row => `${row}<td><input class="memo"></input></td>`)

		// 행을 <tr>로 감싸기
		.map((row,i) => `<tr idx="${i}">\n${row}\n</tr>`)

		// 행을 결합해서 하나의 문자열로 만들기
		.join('\n')
// <태그> 닫기.
+'\n</tbody>'

// 출력 결과를 파일로 저장하고 \\n을 개행 문자로 바꾸어주면 완성.
