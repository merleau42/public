//: ■■■■■■■■■■■■■■■■[ 입출력 ]■■■■■■■■■■■■■■■■
//> 런타임 에러 (EACCES) 발생시 readFileSync( ) 에 임시로 0을 기입해서 제출
//> 입력이 주어질 때마다 끊어서 출력하든, 모든 입력이 주어진 후 한 번에 출력하든 정답 여부에는 영향을 주지 않음
//! 출력 형식
`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`.log(); //14581
input('\n').slice(1).map(x=>`${x} ${x}`).log('\n'); //26574

//! 반복 출력
input('\n', ' ').slice(1).map(([a, b], i)=>`Case #${i+1}: ${a*1 + b*1}`).log('\n'); //11021
range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`)); //9316

//! 입력 형식
[a, b] = input('양식'); log(a*1 + b*1); // 공백(' ', 1000), 개행('\n', 2558)
input('\n', ' ').slice(추출).map(([a,b])=>a*1 + b*1).log('\n'); //테케수(1): 10950, 종료기호(0,-1): 10952
input('\n', ' ').map(([a, b])=>a*1 + b*1).log('\n'); // 테케갯수없이끝까지(10951)

//: ■■■■■■■■■■■■■■■[ 사칙연산 ]■■■■■■■■■■■■■■■■
//! 사칙연산
[a,b]=input(' ').map(Number); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n'); //10869
input('\n', ' ').slice(1).map(([a,b])=>a*1 + b*1).log('\n'); //10950, 각 행에서 두 수의 합을 출력

//: ■■■■■■■■■■■■■■■■[ 문자열 ]■■■■■■■■■■■■■■■■
//> 문자열을 통째로 출력하는게 forEach(log) 보다 빠름
//! 문자열 반복
'하트'.repeat(+input()).log(); //26766, 
'long '.repeat(+input()/4).concat('int').log(); //25314

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

//! 좌우 반전
input('\n').slice(1).map(x=>x.toReversed()).log('\n', '') //11945

//: ■■■■■■■■■■■■■■■■[ 정수론 ]■■■■■■■■■■■■■■■■
//>	나머지 연산은, 덧셈과 곱셈에 대해서 분배 법칙이 성립
//> 400의 배수이거나, 100의 배수가 아니면서 4의 배수이면 윤년
//! 배수 판정
log(+(!(year % 400) || !!(year % 100) && !(year % 4))); //2753, !(A%B) 배수아니다, !!(A%B) 배수이다

//! 수학 공식
log(  (N*(N+1))/2  ); //8393, 1부터 N까지의 합

//: ■■■■■■■■■■■■■■■■■[ 수열 ]■■■■■■■■■■■■■■■■■
//! 포함 여부-갯수 확인
input(' ').some(x => +x > 1).if('F', 'S').log(); //26209
[_, seq, tar] = input('\n'); seq.split(' ').filter(x => +x==+tar).length.log(); //10807

//! 크기 비교
[a,b] = input(' ').map(Number); log(a>b ? '>' : a==b ? '==' : '<'); //1330
input('\n', ' ').slice(0,-1).map(([a,b])=>+a > +b ? 'Yes' : 'No').log('\n'); //4101
[_, x, ...seq]= input(/\W/); seq.filter(e => +e < +x).log(' '); //10871

//! 분류중
range(1, input()*1+1).toReversed().log('\n') //2742, N부터 1까지 거꾸로출력
range(N+1).sum().log() //8393, 1부터 N까지의 합

//: ■■■■■■■■■■■■■■■■[ 조건문 ]■■■■■■■■■■■■■■■■
//! 중첩 조건문
[a,b,c] = input('\n').map(Number); log(a>=b ? b>=c ? b : a>=c ? c : a : b<=c ? b : a<=c ? c: a); //6840

//: ■■■■■■■■■■■■■■■■■[ 순서 ]■■■■■■■■■■■■■■■■■
//! 아스키 비교  (4999, )
[a, b] = input('\n'); log(a <= b ? 'go' : 'no');

//: ■■■■■■■■■■■■■■■■[ 케이스 ]■■■■■■■■■■■■■■■■
//! 조건에 따라서 알맞은 메시지 출력
['n','N'].includes(input()).if(it, 'Naver D2', 'Naver Whale').log(); //24883
log(x<425?"Violet":x<450?"Indigo":x<495?"Blue":x<570?"Green":x<590?"Yellow":x<620?"Orange":"");
[[], [12,1600], [11,894], [11,1327], '...', [6,556], [6,773]][input()*1].log('');
seq.sum().if('OK', ['Soongsil', 'Korea', 'Hanyang'][seq.mini()], e=> +e>=100).log();

//! 키값에 대응하는 메시지 출력
keys = input('\n'); keys.forEach(key => ({"키A": "값X", "키B": "값Y", "키C": "값Z"})[key].log());

//! 자료 분석
input('\n',' ').slice(0,-1).forEach(([n,a,w])=>`${n} ${['Junior','Senior'][a>17|w>=80]}`.log()); //2083

//: ■■■■■■■■■■■■■■■■[ 반복문 ]■■■■■■■■■■■■■■■■
//! 미분류
N=input(); range(1,10).map(i => `${N} * ${i} = ${+N*i}`).log('\n');

//: ■■■■■■■■■■■■■■■■■[ 행렬 ]■■■■■■■■■■■■■■■■■
//! 행렬
/* 평면채우기 */ matrix(Mi, Mi, (i,j) => '*' ).log(['\n', '']);
/* 주대각행렬 */ matrix(Mi, Mi, (i,j) => (j == i)			? '*' : ' ').log('\n', '');
/* 반대각행렬 */ matrix(Mi, Mi, (i,j) => (j == Mi - i - 1)	? '*' : ' ').log('\n', ''); 

//: ■■■■■■■■■■■■■■■■[ 평면기하 ]■■■■■■■■■■■■■■■■
//! 사분면
log(  (x>0 && y>0) ? 1 : (x<0 && y>0) ? 2 : (x<0 && y<0) ? 3 : (x>0 && y<0) ? 4 : 0  );