git init
git remote add origin https://github.com/smallbut/dev.git
git rm -r --cached .
g1t add .
g1t status
g1t comm1t -m "메시지"
git branch -M main
g1t push

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


5280의 애너그램 중 30의 배수를 만족하는 최댓값
-입력 자릿수 N > 100000

// 완전탐색
number.anagrams.filter(30의배수).filter(max)

// 조건을 활용한 그리디
number.filter(30의배수).anagrams.filter(max)