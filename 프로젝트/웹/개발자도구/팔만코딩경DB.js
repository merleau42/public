// 팔만코딩경 DB에서 'Duplicate' 누르면 가벼운 페이지가 등장. 스크롤을 끝까지 내려서 1306개의 항목을 모두 로딩시키고 아래 코드를 실행.
// 팔만코딩경 DB를 평범한 테이블 <태그>로 변경하기.
`<html>\n<table border="1" style="border-collapse : collapse">\n<tr>\n\t<th>작성자</th>\n\t<th>제목</th>\n\t<th>소개</th>\n\t<th>주제</th>\n</tr>\n`+

    // 모든 행을 가져오기
    [...document.querySelectorAll('.notion-table-view-row')]
        // 모든 행에 대해서 다음을 실행
        .map(row=>
                // 각 행의 모든 열을 가져오기
                (rewind=[...row.querySelectorAll('[data-col-index]')])
                
                // 필요한 열만 남기기 (0제목/1주제/2이름/3태그/4소개)
                .filter(col=>[0,1,4,5,7].includes(col.attributes['data-col-index'].value*1))
                
                // 엘리멘트를 문자열로 변환하기, 필요없는 개행 없애기
                .map(col => col.innerText.replace(/\n/g,', '))

                // 모든 열에 순서 표식을 남기고, 아스키 순으로 정렬하기. 원하는 순서로 열을 재배치하기 (0이름/1제목/2소개/3주제/4태그)
                .map((col,i) => `${[1,3,0,4,2][i]}####${col}`)
                .toSorted()

                // 순서 표식 없애기
                .map(col => col.replace(/\d####/g,''))
    
                // 제목의 하이퍼링크 보존하기
                .reduce((s,c,i) => [...s,
                    i==1 ? `<a href="${rewind[0].querySelector('a').href}">${c}</a>` : c], [])

                // [주제 분류]랑 [태그 분류]셀을 통합하고, 중복 제거하기
                .map((col,i,a)=> i!=3 ? col
                : ([...new Set((col+','+a[i+1]).toLowerCase().split(/ *, */))]+'').replace(/^,|,$|(,)([^$])/g,'$1 $2')).slice(0,4)
                            
                // 모든 열을 td <태그>로 감싸기
                .map(col => `\t<td>${col}</td>\n`)
            
                // 모든 열을 결합해서 하나의 행 문자열로 만들기
                .join('')
            )
        // 행을 tr 태그로 감싸기
        .map(row => `<tr>\n${row}</tr>`)

        // 행을 결합해서 하나의 문자열로 만들기
        .join('\n')

// <태그> 닫기.
+'\n</table></html>'

// 출력 결과를 파일로 저장하기. 마지막으로 \\n은 개행문자로, \\t은 탭문자로 바꾸어주면 완성.
