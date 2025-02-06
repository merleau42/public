//: ■■■■■■■■■■■■■■■■[ 입출력 ]■■■■■■■■■■■■■■■■
//! 양식
/*  14581 */	log(`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`);

//! 반복해서 출력
/*  9316 */	range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`))
/* 26766 */	log( 문자열.repeat(input()) );		// 문자열을 통째로 출력하는게 forEach(log) 보다 빠름

//: ■■■■■■■■■■■■■■■[ 사칙연산 ]■■■■■■■■■■■■■■■■
//! 사칙연산
/* 10869 */	[a,b]=input(' ').map(x=>x*1); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n');

//: ■■■■■■■■■■■■■■■■[ 문자열 ]■■■■■■■■■■■■■■■■
//! 아스키코드
input().ascii().map(x => ascii(x^32)).log('')		// 아스키코드 반대로 출력

//! 비교
/*  4101 */	input('\n').slice(0,-1).map(x=>x.split(' ')).forEach(([a,b])=>(+a>+b ? 'Yes' : 'No').log());
/* 10871 */	[_, x, ...seq]=input(/\W/); seq.filter(e => +e < +x).log(' ');
/* 10807 */	[_, seq, [v]] = input2('\n', ' '); seq.filter(e => +e==+v).length.log();

//! 길이 비교
/*  4999 */	[a, b] = input('\n'); log(a.length >= b.length ? 'go' : 'no');

//: ■■■■■■■■■■■■■■■■■[ 탐색 ]■■■■■■■■■■■■■■■■■
//! 존재 확인
/* 26209 */	input(' ').some(x => +x > 1).if('F', 'S').log();

//: ■■■■■■■■■■■■■■■■■[ 순서 ]■■■■■■■■■■■■■■■■■
//! 아스키 비교
/*  4999 */	[a, b] = input('\n'); log(a <= b ? 'go' : 'no');

//: ■■■■■■■■■■■■■■■■[ 케이스 ]■■■■■■■■■■■■■■■■
//! 조건에 따라서 알맞은 메시지 출력
['n','N'].includes(input()).if('Naver D2', 'Naver Whale').log()
log(x<425?"Violet":x<450?"Indigo":x<495?"Blue":x<570?"Green":x<590?"Yellow":x<620?"Orange":x<=780?"Red":"")
[[], [12,1600], [11,894], [11,1327], '...', [6,556], [6,773]][input()*1].log('');

//! 행렬
/* 모든 셀  */ matrix(Mi, Mi, (i,j) => '*' ).log(['\n', '']);
/* 대각선↙ */ matrix(Mi, Mi, (i,j) => (j == Mi - i - 1) ? '*' : ' ').log(['\n', '']); 
/* 대각선↘ */ matrix(Mi, Mi, (i,j) => (j == i) 		 ? '*' : ' ').log(['\n', '']);

//! 해석 기하
matrix(Mi, Mi, (i,j) => (j <= Mi - i - 1) && (j >= i) || (j >= Mi - i - 1) && (j <= i) ? '*' : ' ').log(['\n', '']);	// 별찍기 모래시계
