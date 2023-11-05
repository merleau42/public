//솔브닥 태그별 문제수
[...document.querySelectorAll('td:nth-child(2)')]
.slice(2,20)
.reduce((s,c,i)=>[...s,
			[c.parentNode.querySelector('td').innerText,
			 p = c.innerText.replace(/,/,'')*1,
			 s[i][2] + p,
			 w = [4,5,6,7,8,  10,12,14,16,18,  22,26,30,34,38,  50,55,60][i],
			 Math.ceil(w*p/60),
			 s[i][5] + Math.ceil(w*p/60)]
		],[[0,0,0,0,0,0]])
.reduce((s,x)=>[...s,[`${x[0]}: ${x[1]}문제 (누적 ${x[2]}), 평균 ${x[3]}분, ${x[4]}시간 (누적 ${x[5]})`]])
.slice(6)
.reduce((s,c)=>s+c+'\n')

