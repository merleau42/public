//: ■■■■■■■■■■■■■■■■[ 입출력 ]■■■■■■■■■■■■■■■■
//> 런타임 에러 (EACCES) 발생시 readFileSync(...) 에 임시로 0을 기입해서 제출
//> 입력이 주어질 때마다 끊어서 출력하든, 모든 입력이 주어진 후 한 번에 출력하든 정답 여부에는 영향을 주지 않음

//! 입력 형식
[a, b] = input('구분자'); log(a*1 + b*1); // 공백(' ', 1000), 개행('\n', 2558), 기타('/', 20499)
input('\n', ' ').slice(추출).map(([a,b])=>a*1 + b*1).log('\n'); //테케수(1): 10950, 종료기호(0,-1): 10952
input('\n', ' ').map(([a, b])=>a*1 + b*1).log('\n'); // 테케갯수없이끝까지(10951)
input()._match(/\d+ \d+/g).map(x => x.split(' ').map(Number)).map(([x, y]) => [x+y, x*y]).log('\n', ' '); //18398

//! 출력 형식
`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`.log(); //14581
input('\n').slice(1).map(x=>`${x} ${x}`).log('\n'); //26574

//! 반복 출력
input('\n', ' ').slice(1).map(([a,b],i)=>`Case #${i+1}: ${a} + ${b} = ${a*1 + b*1}`).log('\n'); //11022
range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`)); //9316
//_ 브론즈4
input('\n').slice(1).map((str, i) => `${i+1}. ${str}`).log('\n'); //4470

//: ■■■■■■■■■■■■■■■■■[ 산술 ]■■■■■■■■■■■■■■■■■
//! 사칙연산
[k, q, r, b, n, p] = input(' '); log(1-k, 1-q, 2-r, 2-b, 2-n, 8-p); //3003
(input(' ').map(Number).reduce((s,c)=>s + c*c, 0)%10).log(); //2475
[a, b] = input(' '); abs(a-b).log(); //2420, 절댓값 구하기
[W, H] = input(' '); log( (W*H / 2).toFixed(1) ); //29751, 삼각형의 넓이
[t, _, ...b] = input('\n', ' '); (t == b.map(([p, n])=>p*n).sum()).if('Yes', 'No').log() //25304
[a, b] = input(' '); m = (b-a) / 400; log(1 / (1 + 10**m)); //17356, 거듭 제곱

//! 나눗셈, 몫과 나머지, 부동소수점
[a, b]=input(' ').map(Number); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n'); //10869
(round(input() / 1.1)).log() //30030

//! 유리수의 곱셈
//>	1 !== (0.3335) * 3과 같은 상황이 덜 빚어지도록 할 것
//> (p1/q1) * (p2/q2) -----> (p1 * p2) / q1 / q2
[p1,q1, p2,q2] = input(' ').map(Number); 넓이 = (p1 * p2) / q1 / q2 / 2;

//! 큰 수 계산
//> Number 리터럴과 BigInt의 사칙연산이 유발되는 경우, Number 리터럴에 n을 붙여 BigInt 끼리의 연산으로 바꿔주기
[a, b] = input(' ').map(BigInt); `${(a + b)}`.log(); //15740
[a, b] = input(' ').map(BigInt); log(`${a/b}`); log(`${a%b}`); //1271
[a, b] = input('\n').map(BigInt); log(`${a+b}`); log(`${a-b}`); log(`${a*b}`); //2338
log(  `${BigInt(input()) % 20000303n}`  ); //14928
input('\n').slice(0,-1).map(BigInt).map(x => !(x%42n) ? '당첨' : '재시도').log('\n'); //30664

//! 공식에 대입하기, 공식 세우기
//_	브론즈5
N = input(); [N*0.78, N*0.8 + N*0.2*0.78].log(' ') //20492
input('\n', ' ').map(([T, F, S, P, C]) => 6*T + 3*F + 2*S + 1*P + 2*C).log(' '); //24736
[n1, n2, n12] = input(' ').map(Number); log( floor((n1+1)*(n2+1)/(n12+1) - 1) ); //18301
[a, b] = input(' ').map(Number); log( (a+b)*(a-b) ); //15964
[a, b, c] = input('\n').map(BigInt); log( `${(b - c)/a}` ); //24309
input('\n', ' ').slice(1).mapleaves(Number).map(([a,b,x]) => a * (x - 1) + b).log('\n'); //30007
[a, b] = input(' '); ((a-9)*60 + b*1).log() //26307
[a,b, c,d] = input(' '); log(a*b + c*d); //8370
//_ 브론즈4
[t, p, d] = input(' ').mapleaves(Number); log( p * d/(2*t) ) //14924 폰 노이만과 파리
[a,b] = input('\n').chunk(3).map(([x,y,z]) => x*3 + y*2 + z*1); log( a > b ? 'A' : a < b ? 'B' : 'T' ); //17009

//: ■■■■■■■■■■■■■■■■[ 인덱싱 ]■■■■■■■■■■■■■■■■
[a,b] = input(''); log(Number(a==b)) //27324, 10의 자리숫자와 1의 자리 숫자가 동일한지 비교
[str, n] = input('\n'); str[n-1].log(); //27866
input('\n').slice(1).map(x=>x[0] + x.at(-1)).log('\n'); //9086
//_ 브론즈4
[a, c] = input('\n', ' '); [c[0] - a[2],  c[1] / a[1],  c[2] - a[0]].log(' '); //17256

//! 존재 배열, 맵, 해시 테이블
[..."MOBIS"].subsetOf( keys( input().reduce((exist, c) => {exist[c] = (exist[c]||0) + 1; return exist}, {}) ) ) ? log('YES') : log("NO"); //28074
입력.ascii(-97).reduce((exist, ch) => {exist[ch]++; return exist}, vector(26)).log(' '); //10808
입력.reduce((exist, c) => {exist[c]++; return exist}, vector(10)).reduce((s,c,i) => !(c%2) ? s : [...s, i], []).log('\n'); //28431
입력.reduce((map, c) => {abs(map.D - map.P) < 2 ? map[c]++ : ''; return map }, {D: 0, P: 0}).thru(map => `${map['D']}:${map['P']}`).log() //27918

//! 몫과 나머지, 주기성
//> 정수론 파트로

//: ■■■■■■■■■■■■■■■■[ 문자열 ]■■■■■■■■■■■■■■■■
//> 문자열을 통째로 출력하는게 forEach(log) 보다 빠름
//! 반복 문자열
"LoveisKoreaUniversity ".repeat(input()).slice(0,-1).log() //32929
'하트'.repeat(+input()).log(); //26766, 
'long '.repeat(+input()/4).concat('int').log(); //25314
input('\n').slice(1).map(n => '='.repeat(n)).log('\n') //13752
input('\n', ' ').slice(1).map(([n, str]) => str.repeat(+n)).log('\n'); //17010

//! 축약
input('\n').slice(1).map(str => str.reduce((acc, ch) => acc.at(-1) != ch ? [...acc, ch] : acc) ).log('\n', ''); //5357

//! 아스키코드, 유니코드
input().ascii().map(x => ascii(x^32)).log('') // 아스키코드 반대로 출력
lines.map(str => str.filter(ch => 'aeiouAEIOU'.includes(ch)).length).log('\n'); //1264 모음의 갯수
("가".ascii()*1 + input()*1 - 1).ascii().log() //11282, 유니코드에서 N번째의 한글 문자
log( input().ascii()[0] - "가".ascii()[0] + 1) //11283, 유니코드에서 몇 번째 한글 문자인지

//! 비교
input('\n').slice(0,-1).map(x=>x.split(' ')).forEach(([a,b])=>(+a>+b ? 'Yes' : 'No').log()); //4101

//! 길이 비교
[a, b] = input('\n'); log(a.length >= b.length ? 'go' : 'no'); //4999
input('\n').slice(1).map(x => 6 <= x.length && x.length <= 9 ? 'yes' : 'no').log('\n') //25372

//! 접두사, 접미사, 영역 추출, 특성 추출
input().slice(0,3).if('YES', 'NO', s=>s=="555").log(); //17863
input('\n').slice(1).map(s=>s.endsWith('.') ? s : s+'.').log('\n') //26560
input('\n')[1].slice(-5).log() //21964
input('\n').slice(1).map(str => +str.slice(2)).filter(x => x <= 90).length.log(); //21964

//! 포함 여부-갯수 확인
(input().Match(/[MOBIS]/g).unique().toSorted().join('')=='BIMOS') ? log('YES') : log('NO'); //28074
input().Match(/DKSH/g).length.log()

//! 좌우 반전
input('\n').slice(1).map(x=>x.toReversed()).log('\n', '') //11945, 11365

//! 합산
[a, b, c] = input(' '); str.reduce((s,c)=>s*1 + c*1).log() //11720

//! 정규표현식
input().replace(/10/g, '십').split('').map(x=>x=='십' ? 10 : +x).sum().log() //15873, 증명과 함께
input().replace(/0/g, 9).split('').sum().log() //15873, 증명과 함께
[a, b, c] = input(/\D+/).map(Number); log( ['NO', 'YES'][+(a + b == c)] ); //6810


//: ■■■■■■■■■■■■■■■[ 고정기수 ]■■■■■■■■■■■■■■■
//! 고정 기수 표기법
//> (ABCDE)r  ==  Ar⁴ + Br³ + Cr² + Dr¹ + E  <===>  [A, B, C, D, E]  ==  notate(r)
[(now.unbase(60)+elt)%86400].notate(60).leftpad(3).log(' '); //2530, [시/분/초] ⇔ 초
input('\n', ' ').map(line => line.chunk(3)).map(seqs => seqs.map(seq => seq.reduce((s,c)=>s*60 + c*1)))
.map(([a,b])=>b-a).map(x => x.notate(60, 3)).log('\n', ' '); //5575, [시/분/초] 끼리의 뺄셈
"*CBAABC*"[ input(' ').unbase(2) ].log(); //13623
input('\n').slice(0,-1).map(지수 => [1,1,1,1,1].unbase(지수, bound=false).toFixed(2) ).log('\n'); //4696

//! 진법
[n, r] = input(' '); [n].notate(r).encode().log(''); //11005, R진법을 10진법으로
[n, r] = input(' '); [...n].decode().unbase(r).log(); //2745, 10진법을 R진법으로
[[a, b] ,_ , n] = input('\n', ' '); [n.unbase(a)].notate(b).log(' '); //11576, A진법을 B진법으로
input('\n', ' ').slice(1).map(([i, x])=>[i, x.unbase(8), x.unbase(10), x.unbase(16)]).log('\n', ' '); //13877, R진법을 10진법으로

//: ■■■■■■■■■■■■■■■■[ 정수론 ]■■■■■■■■■■■■■■■■
//! 연도, 나이, 주년
만나이 = (금년 - 생년) - (금월 < 생월 || (금월 == 생월 && 금일 < 생일일)); //16199
연나이 = (금년 - 생년); //16199
한국나이 = (1 + 금년 - 생년); //16199
((m-1)*30 + d*1) > 48 ? 'After' : ((m-1)*30 + d*1) < 48 ? 'Before' : 'Special' //10768, 날짜를 일 수로

//! 시간, 년, 월, 일, 시, 분, 초
[일, 월, 시].update(0, x=>x-1).blend([1440, 60, 1], (i,j) => i*j).sum(); //5928, 날짜를 분으로
log( ( 시분초2.unbase(60) - 시분초1.unbase(60) + 86400) % 86400 ); //15080

//! 자리 올림

//! 기본 단위로 환원, 복합 단위로 재구성

//! 배수 판정, 양의 배수, 음의 배수
//> !(A%B) --- A가 B의 배수이다.	!!(A%B) --- A가 B의 배수가 아니다
//> 400의 배수이거나, 100의 배수가 아니면서 4의 배수이면 윤년
log(+(!(year % 400) || !!(year % 100) && !(year % 4))); //2753
input('\n').slice(1).map(x => !(x%2) ? `${x} is even` : `${x} is odd`).log('\n');

//! 특정 자리의 숫자로 배수 판정
log( (n < 5) ? [1,1,2,6,4][n] : 0 ); //8558

//! 수학 공식
log(  (N*(N+1))/2  ); //8393, 1부터 N까지의 합

//! 분수 표현
[a, b] = input(' '); log( b-a, b ); //16430

//! 몫과(floor) 나머지(%), 주기성
//> A를 B로 나눌 때, 피제수(A) = 제수(B) * 몫(Q) + 나머지(R) 으로 표현하고, 다음이 성립한다.
//> (0 <= 나머지 < 몫),  (0 <= 나머지 <= 피제수)
//>	나머지 연산은, 덧셈/뺄셈/곱셈을 분배 법칙처럼 전개하고 마지막으로 전체에 나머지 연산을 적용한 것과 같다
//> (ab + c - d) % M  ==  ( (ab)%M + c%M - d%M) % M
//> (ab) % M == (a%M)(b%M) % M
[s, w] = input('\n').map(Number); ((w - s + 24)%24).log() //29863
log( 1 * (x % 7 == 2) ) //31611, 오늘이 일요일이라면, X일 이후에는 화요일인지 판정
log( "V".repeat(floor(N/5)) + "I".repeat(N%5) ) //27219
"WelcomeToSMUPC"[(input() - 1)%14].log() //29699
[1,2,3,4,5,4,3,2][((input()-1) % 8)].log() //17362
"NESW"[input('\n').sum()%4].log(); //28295, 90도 풀이 버전 비교

//! 올림(ceil), 반올림(round), 내림(floor), 버림(trunc)
a = input(); ceil(a/5).log(); //15727
log( l - max( ceil(b / d), ceil(a / c) ) ); //5532
min(ceil(n/m1)*p1, ceil(n/m2)*p2).log() //15474

//! 자릿수
(picard(x => '' + x[0] * x.length, input())[1] == 'fixed' ? 'FA' : 'NFA').log(); //14395

//! 팩토리얼
facto(input()).log(); //27433, 1부터 N까지의 곱

//: ■■■■■■■■■■■■■■■■[ 점화식 ]■■■■■■■■■■■■■■■■
//! 반복 함수, 궤도, 고정점, 주기점
(picard(x => '' + x[0] * x.length, input())[1] == 'fixed' ? 'FA' : 'NFA').log(); //14395

//: ■■■■■■■■■■■■■■■■[ 조합론 ]■■■■■■■■■■■■■■■■
//! 순열에 번호매기기
N = input(); (2 * (N.includes('7')) + !(N % 7)).log(); //30224

//! 파스칼 삼각형
(2**input()).log(); //녹색거탑, 24723

//! 분류중
[n,m,k] = input(' '); log( n-abs(m-k) ); //16204

//: ■■■■■■■■■■■■■■■■■[ 람다 ]■■■■■■■■■■■■■■■■■
[x=>x*1, x=>x-500, x=>x*0.9, x=>x-2000, x=>x*0.75].slice(0, 1 + floor(출석/5)).map(f => f(가격))._min(0).log(); //25704


//: ■■■■■■■■■■■■■■■■■[ 배열 ]■■■■■■■■■■■■■■■■■
//! 영역 추출

//! 공집합
natural(N).reduce((s,c) => !(c%6) ? s.concat(c, 'Go!') : s.concat(c), [] ).concat(!(N%6) ? [] : 'Go!').log(' '); //5300

//: ■■■■■■■■■■■■■■■■■[ 수열 ]■■■■■■■■■■■■■■■■■
//! 시그마 표현
N = +input(); [range(N+1).sum(), range(N+1).sum()**2, range(N+1).map(x=>x**3).sum()].log('\n') //28701
seq.map(x => max(...seq) - x).sum().log() /* 또는 */ ( seq.length * max(...seq) - seq.sum() ).log()

//! 포함 여부-갯수 확인
input(' ').some(x => +x > 1).if('F', 'S').log(); //26209
list.filter(e => e==tar).length.log(); //10807
log( seq.filter(x=>!(x%2)).length > seq.filter(x=>!!(x%2)).length ? 'Happy' : 'Sad' ) //29163

//! 크기 비교
[a,b] = input(' ').map(Number); log(a>b ? '>' : a==b ? '==' : '<'); //1330
input('\n', ' ').slice(0,-1).map(([a,b])=>+a > +b ? 'Yes' : 'No').log('\n'); //4101
[_, x, ...seq]= input(/\W/); seq.filter(e => +e < +x).log(' '); //10871
[버거, 음료] = input('\n').map(Number).chunk(3); log(min(...버거) + min(...음료) - 50); //B4, 5548
natural(a,b).filter(x => abs(sol - x) <= diff).length.branch(self, ()=>'IMPOSSIBLE', len=>len).log(); //29736

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

//! 수열간 연산
[준비, 주문] = input('\n', ' '); 준비.blend(주문, (i,j) => j - i).filter(x => x > 0).sum().log(); //15059
[계획, 실천] = input('\n', ' ').slice(1).mapleaves(Number); 계획.blend(실천, (i,j) => i <= j).sum().log(); //30033

//! ISBN
"9780921418".concat(input().replace(/\n/g,'')).map((x,i)=> !(i%2) ? x*1 : x*3 ).sum() //6810

//! (단조) 증가, (단조) 감소 함수
seq.every((_,i,a) => (a[i-1] ??	 a[i])		==	a[i]) // 항등 수열, 6764
seq.every((_,i,a) => (a[i-1] ?? -Infinity)	<	a[i]) // 증가 수열(6764), 오름차순(4589)
seq.every((_,i,a) => (a[i-1] ?? +Infinity)	>	a[i]) // 감소 수열(6764), 내림차순(4589)

//! 멱급수, 등비 수열
input('\n').slice(0,-1).map(공비 => [1,1,1,1,1].unbase(공비, bound=false).toFixed(2) ).log('\n'); //등비수열의 합, 4696


//: ■■■■■■■■■■■■■■■■■[ 집합 ]■■■■■■■■■■■■■■■■■
//! 부분 집합
input('\n').every(x=>['원소1','원소2','원소3'].includes(x)); //29731

//! 공통 원소, 교집합
seqs.every(seq => seq.includes(tar)); //32941

//! 교집합의 원소의 갯수
//> 구간P:(a,b)와 구간Q:(c,d)의 교집합
최대 = min(b,d); 
최소 = max(a,c);
갯수 = max(0, 최대 - 최소 + 1);


//: ■■■■■■■■■■■■■■■■[ 조건문 ]■■■■■■■■■■■■■■■■
//! 많은 조건 분기, 조건문 최적화
//_	브론즈5
(a>=b ? b>=c ? b : a>=c ? c : a : b<=c ? b : a<=c ? c: a).log(); //6840
(n > b ? 'Bus' : a < b ? 'Bus' : a == b ? 'Anything' : a > b ? 'Subway' : '').log() //28113
//_ 브론즈4
(m < 2) ? 'Before' : (m > 2) ? 'After' : (d < 18) ? 'Before' : (d > 18) ? 'After' : 'Special'; //10768
(seq.sum() - 2*pr * (seq.sum() >= 2*pr)) == ( seq.sum() >= 2*pr ? seq.sum() - 2*pr : seq.sum() ); //14489
(m<3 ? 'NEWBIE!' : m<=n ? 'OLDBIE!' : 'TLE!').log(); //19944
max(...input(' ')).log(); //13597, 페어나 트리플 만들기
( (a==8) || (a==9) ) && ( (d==8) || (d==9) ) && (b==c); //16017, 최적화 해볼 것

//! 정렬을 통한 전처리
[a, b, c, d, ...z] = input(' ').map(Number).toSorted((a,b)=>a-b); //이하 공통
(a==b && b==c) ? log(10000 + a*1000) : (a==b || b==c || a==c) ? log(1000 + b*100) : log(max(a,b,c)*100); //2480
(a==b || b==c || a==c || a+b==c) ? log('S') : log('N'); //13580

//! 논리식
[T, S] = input(' ').map(Number); ((12<=T && T<=16 && !S) ? 320 : 280).log(); //27294

//! 불대수


//: ■■■■■■■■■■■■■■■■■[ 정렬 ]■■■■■■■■■■■■■■■■■
//! 아스키 오름차순
[a, b] = input('\n'); log(a <= b ? 'go' : 'no'); //4999

//! 정수 오름차순
input(' ').toSorted((a,b)=>a - b).log(' ') //2752

//! 정수 내림차순
[과학, 사회] = input('\n').map(Number).chunk(4);
[과학, 사회].map(seq => seq.toSorted((a,b)=>b-a).slice(0,-1).sum()).sum().log(); //11948

//! 순서쌍 비교
[w, x, y, z] = input(' ').map(Number).toSorted((a,b)=>b-a); log(abs(w + z - x - y)) //13866 합:합 최소차이

//: ■■■■■■■■■■■■■■■■[ 케이스 ]■■■■■■■■■■■■■■■■
//! 조건에 따라서 알맞은 메시지 출력
log(x<425?"Violet":x<450?"Indigo":x<495?"Blue":x<570?"Green":x<590?"Yellow":x<620?"Orange":"");
['n','N'].includes(input()).if('Naver D2', 'Naver Whale').log(); //24883
seq.sum().if('OK', ['Soongsil', 'Korea', 'Hanyang'][seq.mini()], e=> +e>=100).log();
(제한 < 속도) ? (속도 <= 제한 + 20) ? '$100.' : (속도 <= 제한 + 30) ? '$270.' : '$500.' : '과속 아님'; //6763
[-1,3,3,2,2,1,1][input('\n').filter(x => x=='W').length].log() //14038

//! 키값에 대응하는 메시지 출력
keys = input('\n'); keys.forEach(key => ({"키A": "값X", "키B": "값Y", "키C": "값Z"})[key].log());
[[], [12,1600], [11,894], [11,1327], '...', [6,556], [6,773]][input()*1].log('');

//! 자료 분석
input('\n',' ').slice(0,-1).forEach(([n,a,w])=>`${n} ${['Junior','Senior'][a>17|w>=80]}`.log()); //2083

//: ■■■■■■■■■■■■■■■■[ 반복문 ]■■■■■■■■■■■■■■■■
//! 미분류
N = input(); range(1,10).map(i => `${N} * ${i} = ${+N*i}`).log('\n');

//: ■■■■■■■■■■■■■■■■■[ 행렬 ]■■■■■■■■■■■■■■■■■
//! 행렬
/* 평면채우기 */ matrix(Mi, Mi, (i,j) => '*' ).log(['\n', '']);
/* 주대각행렬 */ matrix(Mi, Mi, (i,j) => (j == i)			? '*' : ' ').log('\n', '');
/* 반대각행렬 */ matrix(Mi, Mi, (i,j) => (j == Mi - i - 1)	? '*' : ' ').log('\n', '');

//! 배열 선형화, 행우선/열우선
//>	2차원 좌표  <---매핑--->  1차원 좌표
[r, c, index] = input(' '); [floor(index / c), floor(index % c)].log(' '); //14562, [0]▶(0,0) ~~ [rc-1]▶(r,c) 행우선 매핑

//: ■■■■■■■■■■■■■■■■■[ 대수 ]■■■■■■■■■■■■■■■■■
//! 1차 방정식
[a, b, c] = input('\n').map(BigInt); log( `${(b - c)/a}` ); //24309
[경가, 경성, 자가] = input(' '); log(3 * 자가 * (경성/경가)); //26082

//! 백분율
input('\n', ' ').map(([df, ig])=>df * (100 - ig)/100).map(x => +(x < 100)).log('\n') //25238

//! 연립방정식
[x, y] = input('\n').map(BigInt); [(x + y) / 2n, (x - y) / 2n].log('\n')

//! 비례식, 단위당 양, 단위 변환
input('\n', ' ').slice(1).map(([마릿수, 마리당_사료, 사료당_가격]) => "$" + (마릿수 * 마리당_사료 * 사료당_가격).toFixed(2) ).log('\n') //26575
log( 235.214583 / +input() ); //14065


//! 밀도, 부피, 질량
m.map(x => x - d*v).log(' '); //2845

//! 평균

//! 부등식
( (x < L) ? L : (L <= x && x <= R) ? x : R ).log(); //18414

//! 절대값
//> 조건문 분기나 min/max를 사용하지 않고, 절대값을 이용해서 풀어보기
[ a+abs(b), a-abs(b) ].log('\n'); //24075, A+B와 A-B중에서 큰 것과 작은 것

//: ■■■■■■■■■■■■■■■■[ 해석학 ]■■■■■■■■■■■■■■■■
//! 구간 함수, 누진세
[ori, fin, x, y, z] = input('\n').map(Number); range(ori, fin).map(tp=>tp<0 ? x : tp==0 ? (y+z) : tp>0 ? z : '').sum().log() //14470

//! min함수, max함수
min(max(x, L), R).log(); //18414
log( min(사용량, (이월 + 60))*1500 + max(사용량 - (이월 + 60), 0)*3000 ); //18330
[a,x, b,y, t] = input('\n').map(Number); log(  a + x*max(t-30, 0) * 21  ); log(  b + y*max(t-45, 0) * 21  ); //20233


//: ■■■■■■■■■■■■■■■■[ 중앙값 ]■■■■■■■■■■■■■■■■
//! 가중 중앙값
natural(seq.length).map(k => seq.map((N,i) => N  *  2*abs(i+1-k)).sum())._min().log();


//: ■■■■■■■■■■■■■■■■■[ 기하 ]■■■■■■■■■■■■■■■■■
//! 평면기하
//> 평행이동
[사람들, 사과] = input('\n', ' '); log( 1 + 사람들.indexOf( 사과[0] ) ); //13118


//! 사분면
log(  (x>0 && y>0) ? 1 : (x<0 && y>0) ? 2 : (x<0 && y<0) ? 3 : (x>0 && y<0) ? 4 : 0  );

//! N각형
a+b+c != 180 ? '에러' : (a==b && b==c) ? '정삼각형' : (a==b || b==c || a==c) ? '이등변' : '부등변' //10101

//! 삼각형
//> 세 변의 길이 (a, b, c)
a == b && b == c && c == a; // 정삼각형
[a, b, c] = input(' ').toSorted((a,b) => a - b); //  <--- a <= b <= c 이면,
c**2 == a**2 + b**2; //  <--- 직각 삼각형

//! 피타고라스
log(  (w+h) - sqrt(w**2 + h**2)  ); //20215

//! 측도: 면적, 넓이, 부피, 둘레
(4*sqrt(넓이)).log() //15610, 정사각형의 넓이 ---> 정사각형의 둘레 길이
[a*b*4, b*(n-a)*4, a*(n-b)*4, (n-a)*(n-b)*4]._max().log(); //17874
log( max(a, n-a) * max(b, n-b) * 4 ); //17874 ---- 일반화 가능
log( !(가로%2) || !(세로%2) ? 0 : min(가로, 세로) ); //8674

//! 원
(2*d + 2*r*3.141592).toFixed(6).log(); //16486, 원주의 길이
[v, c1, r, c2] = input(/\s+/); ['원형', '조각'][ Number( (v / c1) > (PI * r**2 / c2) ) ].log(); //16693
log( 2 * PI * sqrt( input() / PI ) );

//! 입체
input('\n').map(x=>x**3).log('') //24082, 정육면체의 부피

//: ■■■■■■■■■■■■■■■[ 상태 전이 ]■■■■■■■■■■■■■■■■
[a, b, A, B] = input(/\s/).map(Number); min(b+A, a+B).log(); //11943


//: ■■■■■■■■■■■■■■■[ 수학/미분류 ]■■■■■■■■■■■■■■■
//! 리비히 최소량의 법칙, 제약 요소, 병목 현상
//> 넘치는 요소가 아닌 가장 부족한 요소가 전체 성과를 결정한다
[치,콜,맥] = input(/\s/).map(Number); min(치, floor(콜/2)+맥).log() //25191
min(floor(s/2), floor(a/2)).log() //23825
[후라, 간장, 양념].map(x => min(x, 마리) ).sum().log(); //27110

//! 타일채우기
[N, W, H, L] = input(' ').map(Number); min(floor(W/L) * floor(H/L), N).log(); //19698
log( ceil(행/변) * ceil(열/변) ); //13136, CCTV 배치하기
input('\n', ' ').slice(1).mapleaves(Number).map(([R,C]) => floor(R*C / 2) ).log('\n'); //8760


//: ■■■■■■■■■■■■■■■■[ 분류중 ]■■■■■■■■■■■■■■■■
가게들.filter(([도착, 진열]) => 도착 <= 진열).map(([_, 진열]) => 진열)._min().log() //25377

//: ■■■■■■■■■■■■■■■■[ 다양성 ]■■■■■■■■■■■■■■■■
[0,0,0,1,1,2,2][+input(' ').sum()].log(); //18408

//: ■■■■■■■■■■■■[ 완전탐색/백트래킹 ]■■■■■■■■■■■■■
cartesian([1,1,1], xyz, ([i,j,k])=>(i%j==j%k & j%k==k%i)).length; //25494

//! 완전탐색, 백트래킹: 성능이 중요하기 때문에 절차지향적으로 작성함.
//> 성능 문제: 구조분해할당 vs 직접할당,  [...상태, e] vs push(e)/pop
완전탐색 = (정보) => {
	if ('온전한_순서쌍을_이루었는가?') {
		'순서쌍을_가지고_무엇을_할것인가?';
		if ('순서쌍이_해를_만족하는가?') {
			'해를_가지고_무엇을_할것인가?';
			해집합.push('순서쌍을_어떻게_가공할_것인가?');
		}
		return ;
	}

    for (e of '다음_깊이에_해당하는_변수의_변화_구간') {
		if ('곧바로_부정되지는_않는_미래인가?') {
			상태.push(e);
			정보.깊이++;
			완전탐색(정보);
			상태.pop();
			정보.깊이--;
		}
		if ('해가_얼마나_많이_필요한가?' || '조기_종료_시점인가?')
			return 해집합;
	}
	
	return 해집합;
};


발견: ({스택: [i, j]}) => [i, j, i*j].includes( N );
종료: ({해집합}) => 해집합.length == 1;
cartesian([2,1], [9,9], 정보).해집합.length.log() //32710


발견: ({스택: [x, y, z]}) => x%y==y%z && y%z==z%x;
cartesian([1,1,1], xyz, 정보).해집합.length //25494


예선: ({스택}, 가지) => (스택.length <= 0) || (스택.at(-1) * 가지 >= N);
발견: ({스택: [x, y]}) => x*y >= N; // 예선 또는 발견을 사용
가공: ({스택: [x, y]}) => [x+y, x, y];
cartesian([1,1], [N, N], 정보).해집합.toSorted((a,b)=>a[0]-b[0]).thru(x => x[0].slice(1)).log(' '); //3276

// 13580
cartesian([-1,-1,-1], [1,1,1]).해집합
.map(([i,j,k])=> a*i + b*j + c*k).filter(x=>x==0)
.length > 1 ? log('S') : log('N');