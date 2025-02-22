//: ■■■■■■■■■■■■■■■■[ 입출력 ]■■■■■■■■■■■■■■■■
//> 런타임 에러 (EACCES) 발생시 readFileSync(...) 에 임시로 0을 기입해서 제출
//> 입력이 주어질 때마다 끊어서 출력하든, 모든 입력이 주어진 후 한 번에 출력하든 정답 여부에는 영향을 주지 않음
//! 입력 형식
[a, b] = input('양식'); log(a*1 + b*1); // 공백(' ', 1000), 개행('\n', 2558)
input('\n', ' ').slice(추출).map(([a,b])=>a*1 + b*1).log('\n'); //테케수(1): 10950, 종료기호(0,-1): 10952
input('\n', ' ').map(([a, b])=>a*1 + b*1).log('\n'); // 테케갯수없이끝까지(10951)

//! 출력 형식
`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`.log(); //14581
input('\n').slice(1).map(x=>`${x} ${x}`).log('\n'); //26574

//! 반복 출력
input('\n', ' ').slice(1).map(([a,b],i)=>`Case #${i+1}: ${a} + ${b} = ${a*1 + b*1}`).log('\n'); //11022
range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`)); //9316


//: ■■■■■■■■■■■■■■■[ 사칙연산 ]■■■■■■■■■■■■■■■■
//! 사칙연산
[k, q, r, b, n, p] = input(' '); log(1-k, 1-q, 2-r, 2-b, 2-n, 8-p); //3003
(input(' ').map(Number).reduce((s,c)=>s + c*c, 0)%10).log(); //2475
[a, b] = input(' '); abs(a-b).log(); //2420, 절댓값 구하기
[W, H] = input(' '); log( (W*H / 2).toFixed(1) ); //29751, 삼각형의 넓이
[t, _, ...b] = input('\n', ' '); (t == b.map(([p, n])=>p*n).sum()).if('Yes', 'No').log() //25304

//! 나눗셈, 몫과 나머지, 부동소수점
[a, b]=input(' ').map(Number); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n'); //10869
(round(input() / 1.1)).log() //30030

//! 큰 수 계산
//> Number 리터럴과 BigInt의 사칙연산이 유발되는 경우, Number 리터럴에 n을 붙여 BigInt 끼리의 연산으로 바꿔주기
[a, b] = input(' ').map(BigInt); `${(a + b)}`.log(); //15740
[a, b] = input(' ').map(BigInt); log(`${a/b}`); log(`${a%b}`); //1271
[a, b] = input('\n').map(BigInt); log(`${a+b}`); log(`${a-b}`); log(`${a*b}`); //2338
log(  `${BigInt(input()) % 20000303n}`  ); //14928
input('\n').slice(0,-1).map(BigInt).map(x => !(x%42n) ? '당첨' : '재시도').log('\n'); //30664

//! 공식에 대입, 공식 세우기
//_	브론즈5
N = input(); [N*0.78, N*0.8 + N*0.2*0.78].log(' ') //20492
input('\n', ' ').map(([T, F, S, P, C]) => 6*T + 3*F + 2*S + 1*P + 2*C).log(' '); //24736
[n1, n2, n12] = input(' ').map(Number); log( floor((n1+1)*(n2+1)/(n12+1) - 1) ); //18301
[a, b] = input(' ').map(Number); log( (a+b)*(a-b) ); //15964
[경가, 경성, 자가] = input(' '); log(3 * 자가 * (경성/경가)); //26082
[a, b, c] = input('\n').map(BigInt); log( `${(b - c)/a}` ); //24309
input('\n', ' ').slice(1).mapleaves(Number).map(([a,b,x]) => a * (x - 1) + b).log('\n'); //30007
[a, b] = input(' '); ((a-9)*60 + b*1).log() //26307
[a,b, c,d] = input(' '); log(a*b + c*d); //8370
//_ 브론즈4
m.map(x => x - d*v).log(' '); //2845


//: ■■■■■■■■■■■■■■■■[ 인덱싱 ]■■■■■■■■■■■■■■■■
[a,b] = input(''); log(Number(a==b)) //27324, 10의 자리숫자와 1의 자리 숫자가 동일한지 비교
"WelcomeToSMUPC"[(input() - 1)%14].log() //29699
[str, n] = input('\n'); str[n-1].log(); //27866
input('\n').slice(1).map(x=>x[0] + x.at(-1)).log('\n'); //9086
//_ 브론즈4
[a, c] = input('\n', ' '); [c[0] - a[2],  c[1] / a[1],  c[2] - a[0]].log(' '); //17256

//! 존재 배열
input().ascii(-97).reduce((exist, ch) => {exist[ch]++; return exist}, vector(26)).log(' '); //10808

//: ■■■■■■■■■■■■■■■■[ 문자열 ]■■■■■■■■■■■■■■■■
//> 문자열을 통째로 출력하는게 forEach(log) 보다 빠름
//! 문자열 반복
'하트'.repeat(+input()).log(); //26766, 
'long '.repeat(+input()/4).concat('int').log(); //25314

//! 아스키코드
input().ascii().map(x => ascii(x^32)).log('')		// 아스키코드 반대로 출력
lines.map(str => str.filter(ch => 'aeiouAEIOU'.includes(ch)).length).log('\n'); //1264 모음의 갯수

//! 비교
input('\n').slice(0,-1).map(x=>x.split(' ')).forEach(([a,b])=>(+a>+b ? 'Yes' : 'No').log()); //4101

//! 길이 비교
[a, b] = input('\n'); log(a.length >= b.length ? 'go' : 'no'); //4999
input('\n').slice(1).map(x => 6 <= x.length && x.length <= 9 ? 'yes' : 'no').log('\n') //25372

//! 영역 추출
input('\n')[1].slice(-5).log() //21964

//! 포함 여부-갯수 확인
input('\n').slice(1).map(s=>s.endsWith('.') ? s : s+'.').log('\n') //26560
(input().Match(/[MOBIS]/g).unique().toSorted().join('')=='BIMOS') ? log('YES') : log('NO'); //28074
input().Match(/DKSH/g).length.log()

//! 좌우 반전
input('\n').slice(1).map(x=>x.toReversed()).log('\n', '') //11945, 11365

//! 합산
[a, b, c] = input(' '); str.reduce((s,c)=>s*1 + c*1).log() //11720

//: ■■■■■■■■■■■■■■■■[ 정수론 ]■■■■■■■■■■■■■■■■
//>	나머지 연산은, 덧셈/뺄셈/곱셈에 대해서 분배 법칙이 성립
//> 400의 배수이거나, 100의 배수가 아니면서 4의 배수이면 윤년
//! 년도, 나이, 주년
(input() - 543).log(); //18108, 불기 연도를 서기 연도로 변환

//! 배수 판정
//> !(A%B) --- A가 B의 배수이다.	!!(A%B) --- A가 B의 배수가 아니다
log(+(!(year % 400) || !!(year % 100) && !(year % 4))); //2753

//! 수학 공식
log(  (N*(N+1))/2  ); //8393, 1부터 N까지의 합

//! 분수 표현
[a, b] = input(' '); log( b-a, b ); //16430

//! 몫과(floor) 나머지(%)
[s, w] = input('\n').map(Number); ((w - s + 24)%24).log() //29863
x = input(); log(1 * (x % 7 == 2)) //31611, 오늘이 일요일이라면, X일 이후에는 화요일인지 판정
N = input(); log( "V".repeat(floor(N/5)) + "I".repeat(N%5) ) //27219

//! 올림(ceil), 반올림(round), 내림(floor), 버림(trunc)
//_ 브론즈5
a = input(); ceil(a/5).log(); //15727
//_ 브론즈4
log( l - max( ceil(b / d), ceil(a / c) ) ); //5532

//: ■■■■■■■■■■■■■■■■■[ 진법 ]■■■■■■■■■■■■■■■■■
//! 고정 기수 표기법
//> (ABCDE)r  ==  Ar⁴ + Br³ + Cr² + Dr¹ + E  <===>  [A, B, C, D, E]  ==  notate(r)
(now.reduce((s,c)=>s*60 + c) + elt).notate(60, 3).update(0, x=>x%24).log(' '); //2530, [시/분/초] ⇔ 초


//: ■■■■■■■■■■■■■■■■[ 방정식 ]■■■■■■■■■■■■■■■■
//! 연립방정식
[x, y] = input('\n').map(BigInt); [(x + y) / 2n, (x - y) / 2n].log('\n')

//: ■■■■■■■■■■■■■■■■[ 조합론 ]■■■■■■■■■■■■■■■■
//! 순열에 번호매기기
N = input(); (2 * (N.includes('7')) + !(N % 7)).log(); //30224

//! 파스칼 삼각형
(2**input()).log(); //녹색거탑, 24723

//: ■■■■■■■■■■■■■■■■■[ 수열 ]■■■■■■■■■■■■■■■■■
//! 시그마 표현
N = +input(); [range(N+1).sum(), range(N+1).sum()**2, range(N+1).map(x=>x**3).sum()].log('\n') //28701

//! 포함 여부-갯수 확인
input(' ').some(x => +x > 1).if('F', 'S').log(); //26209
seq.filter(x => x==tar).length.log(); //10807
log( seq.filter(x=>!(x%2)).length > seq.filter(x=>!!(x%2)).length ? 'Happy' : 'Sad' ) //29163

//! 크기 비교
[a,b] = input(' ').map(Number); log(a>b ? '>' : a==b ? '==' : '<'); //1330
input('\n', ' ').slice(0,-1).map(([a,b])=>+a > +b ? 'Yes' : 'No').log('\n'); //4101
[_, x, ...seq]= input(/\W/); seq.filter(e => +e < +x).log(' '); //10871
[버거, 음료] = input('\n').map(Number).chunk(3); log(min(...버거) + min(...음료) - 50); //B4, 5548

//! 분류중
range(1, input()*1+1).toReversed().log('\n') //2742, N부터 1까지 거꾸로출력

//! 평균
input('\n').map(x=>x<40 ? 40 : x).average().log() //10039

//! 합, 누적합, 구간합
//_ 브론즈5
input('\n').slice(0,-1).map(N => range(+N+1).sum()).log('\n'); //5341, 1부터 N까지의 합
[seq]=input('\n', ' ').slice(1); log(seq.sum() > 0 ? 'Right' : seq.sum() == 0 ? 'Stay' : 'Left'); //28938
//_ 브론즈4
input('\n', ' ').map(seq => seq.sum())._max().log(); //5596, 각 수열의 합 중에서 최댓값

//! 팩토리얼
facto(input()).log(); //27433, 1부터 N까지의 곱

//! 수열간 연산

//: ■■■■■■■■■■■■■■■■■[ 집합 ]■■■■■■■■■■■■■■■■■
//! 포함 관계
input('\n').every(x=>['원소1','원소2','원소3','원소4'].includes(x)).if('No', 'Yes').log() //29731


//: ■■■■■■■■■■■■■■■■[ 조건문 ]■■■■■■■■■■■■■■■■
//! 많은 조건 분기, 조건문 최적화
(a>=b ? b>=c ? b : a>=c ? c : a : b<=c ? b : a<=c ? c: a).log(); //6840
(n > b ? 'Bus' : a < b ? 'Bus' : a == b ? 'Anything' : a > b ? 'Subway' : '').log() //브5, 28113

//! 정렬을 통한 전처리
[a, b, c] = input(' ').map(Number).toSorted(); //2480
(a==b && b==c) ? log(10000 + a*1000) : (a==b || b==c || a==c) ? log(1000 + b*100) : log(max(a,b,c)*100);

//! 논리식
[T, S] = input(' ').map(Number); ((12<=T && T<=16 && !S) ? 320 : 280).log(); //27294


//: ■■■■■■■■■■■■■■■■■[ 정렬 ]■■■■■■■■■■■■■■■■■
//! 아스키 오름차순
[a, b] = input('\n'); log(a <= b ? 'go' : 'no'); //4999

//! 정수 오름차순
input(' ').toSorted((a,b)=>a - b).log(' ') //2752

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

//! 배열 선형화, 행우선/열우선
//> 2차원 좌표를 1차원 좌표로 매핑


//: ■■■■■■■■■■■■■■■■[ 방정식 ]■■■■■■■■■■■■■■■■
//! 1차 방정식
[a, b, c] = input('\n').map(BigInt); log( `${(b - c)/a}` ); //24309


//: ■■■■■■■■■■■■■■■■[ 기하학 ]■■■■■■■■■■■■■■■■
//! 평면기하
//! 사분면
log(  (x>0 && y>0) ? 1 : (x<0 && y>0) ? 2 : (x<0 && y<0) ? 3 : (x>0 && y<0) ? 4 : 0  );
//! 도형
input('\n').map(x=>x**3).log('') //24082, 정육면체의 부피

//! N각형
a+b+c != 180 ? '에러' : (a==b && b==c) ? '정삼각형' : (a==b || b==c || a==c) ? '이등변' : '부등변' //10101


//< ■■■■■■■■■■■■■■■■■[ 노트 ]■■■■■■■■■■■■■■■■■
//: 브론즈5, 28113
//	n  > b ---> 걸어서 지하철 잡을 수 없다, 버스를 탄다
//	n <= b ---> 걸어서 지하철 잡을 수 있다, 버스랑 지하철 중에 먼저 오는 것을 탄다
//		a  < b ---> 버스를 탄다
//		a == b ---> 아무거나 탄다
//		a  > b ---> 지하철을 탄다
(n > b ? 'Bus' : a < b ? 'Bus' : a == b ? 'Anything' : a > b ? 'Subway' : '').log()
//: 브론즈4, 5532
//	L == 남은방학
//	ceil(B / D) == 수학 소요시간
//	ceil(A / C) == 국어 소요시간
//	숙제하는 날 == max(수학, 국어)
//	노는 날 == 남은 방학 - 숙제하는 날