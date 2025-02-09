//: ■■■■■■■■■■■■■■■■[ 입출력 ]■■■■■■■■■■■■■■■■
//! 양식
`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`.log(); //14581
input('\n').slice(1).map(x=>`${x} ${x}`).log('\n'); //26574

//! 반복해서 출력 (9316, 26766, )
range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`))
log( 문자열.repeat(input()) );		// 문자열을 통째로 출력하는게 forEach(log) 보다 빠름

//: ■■■■■■■■■■■■■■■[ 사칙연산 ]■■■■■■■■■■■■■■■■
//! 사칙연산 (10869, )
[a,b]=input(' ').map(x=>x*1); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n');

//: ■■■■■■■■■■■■■■■■[ 문자열 ]■■■■■■■■■■■■■■■■
//! 아스키코드
input().ascii().map(x => ascii(x^32)).log('')		// 아스키코드 반대로 출력

//! 비교
input('\n').slice(0,-1).map(x=>x.split(' ')).forEach(([a,b])=>(+a>+b ? 'Yes' : 'No').log()); //4101

//! 길이 비교
[a, b] = input('\n'); log(a.length >= b.length ? 'go' : 'no'); //4999

//! 영역 추출
input('\n')[1].slice(-5).log() //21964

//! 포함 여부-갯수 확인
input('\n').slice(1).map(s=>s.endsWith('.') ? s : s+'.').log('\n') //26560
(input().Match(/[MOBIS]/g).unique().toSorted().join('')=='BIMOS') ? log('YES') : log('NO'); //28074
input().Match(/DKSH/g).length.log()

//! 분류중
input('\n').slice(0, -1).forEach((_,i) => `Case ${i+1}: Sorting... done!`.log()) //23235

//! 좌우 반전
input('\n').slice(1).map(x=>x.toReversed()).log('\n', '') //11945

//: ■■■■■■■■■■■■■■■■■[ 수열 ]■■■■■■■■■■■■■■■■■
//! 포함 여부-갯수 확인
input(' ').some(x => +x > 1).if('F', 'S').log(); //26209
[_, seq, tar] = input('\n'); seq.split(' ').filter(x => +x==+tar).length.log(); //10807

//! 크기 비교
[_, x, ...seq]= input(/\W/); seq.filter(e => +e < +x).log(' '); //10871

//: ■■■■■■■■■■■■■■■■■[ 순서 ]■■■■■■■■■■■■■■■■■
//! 아스키 비교  (4999, )
[a, b] = input('\n'); log(a <= b ? 'go' : 'no');

//: ■■■■■■■■■■■■■■■■[ 케이스 ]■■■■■■■■■■■■■■■■
//! 조건에 따라서 알맞은 메시지 출력
['n','N'].includes(input()).if(it, 'Naver D2', 'Naver Whale').log(); //24883
log(x<425?"Violet":x<450?"Indigo":x<495?"Blue":x<570?"Green":x<590?"Yellow":x<620?"Orange":"");
[[], [12,1600], [11,894], [11,1327], '...', [6,556], [6,773]][input()*1].log('');
keys = input('\n'); keys.forEach(key => ({"ab": "204", "xx": "207", "wa": "303"})[key].log());
seq.sum().if('OK', ['Soongsil', 'Korea', 'Hanyang'][seq.mini()], e=> +e>=100).log();

//! 자료 분석
input('\n',' ').slice(0,-1).forEach(([n,a,w])=>`${n} ${['Junior','Senior'][a>17|w>=80]}`.log()); //2083

//: ■■■■■■■■■■■■■■■■■[ 행렬 ]■■■■■■■■■■■■■■■■■
//! 행렬
/* 평면채우기 */ matrix(Mi, Mi, (i,j) => '*' ).log(['\n', '']);
/* 주대각행렬 */ matrix(Mi, Mi, (i,j) => (j == i)			? '*' : ' ').log('\n', '');
/* 반대각행렬 */ matrix(Mi, Mi, (i,j) => (j == Mi - i - 1)	? '*' : ' ').log('\n', ''); 

//! 해석 기하
