const { fchown } = require("fs");

//! 네임 스페이스 제거
const { sqrt, ceil, floor, trunc, abs, sign, max, min, random } = Math;
const { clear, log } = console;

//! 테스트 케이스 불러오기
input = (s,t=1)=>`${require("fs").readFileSync("./dev/stdin")}`[t? 'trim' : 'it']()[s? 'split' : 'it'](s);
input2 = (s1,s2)=>`${require("fs").readFileSync("./dev/stdin")}`.trim().split(s1).map(x=>x.trim().split(s2));

//!	기본 함수
Object.prototype.it = function (f) { return this.valueOf() };
Object.prototype.Each = function (f) { this.forEach(f); return this };
Object.prototype.if = function (T,F) { return this.valueOf() ? T : F };
Object.prototype.log = function (s) { log(s==undefined ? this.valueOf() : this.join(s)); return this };

//! 디버깅 도구
Object.prototype.show = function () { log(Object.entries(this).map(([k,v])=>[k, ...v].join('\t')).join('\n')) };
stamp = (()=>{ let count = 0; return (msg='STAMP',tabs=0)=>log("\t".repeat(tabs) + msg + ':', ++count) })();
repl = (msg=log('REPL모드')) => require('repl').start();
randz = (min, max, arr=0) => arr ? range(arr).map(x => randz(min,max)) : floor(random() *(max - min + 1)) + min;

//!	배열 함수 확장, 문자열에도 적용
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a + d * i * sign(l - a) : d * i * sign(a));
arr_str = ['join'];
itertools = [
	rank = function () {return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[x[1],i]).toSorted((a,b)=>a[0]-b[0]).map(x=>x[1])},
	toSorted = function (cmp) { return this.sort(cmp) },
	toReversed = function () { return this.reverse()},
	toSeq = function() { return  },
	inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] },
	deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] },
	removed = function (item, from=0) { i = this.indexOf(item,from); return i > -1 ? this.deleted(i) : this },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f])
.concat(arr_str).Each(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );

//! 수열, 누적합, 구간합
Array.prototype.sheet = {};
Array.prototype.prep = function () { seqtools.forEach(f => this[f]()); return this};
seqtools = [
	serial = function () { return this.sheet.index = this.map((_,i) => i) },
	value = function () { return this.sheet.value = [...this] },
	psum = function (arr=this) { return arr.sheet.psum = arr.reduce((s,c,i) => [ ...s, c + (s[i-1]||0) ], []) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f]);

//! 정수론
isPrime = (N)=> N>1 && N==2 || !range(2, ceil(sqrt(N)) + 1 ).some(i => N % i == 0);
fibo = (arr=range(100)) => arr.reduce((s,_,i) => i<2 ? s : [...s, s[i-2] + s[i-1]], [0, 1]);

//: ■■■■■■■■■■■■■■■■[ 유형 ]■■■■■■■■■■■■■■■■
//! 문자열 양식
// /*  14581 */	log(`:fan::fan::fan:\n:fan::${input()}::fan:\n:fan::fan::fan:`);

//! 문자열을 반복해서 출력
// /*  9316 */	range(input()).forEach(i => log(`Hello World, Judge ${i + 1}!`))
// /* 26766 */	log( 문자열.repeat(input()) );		// 문자열을 통째로 출력하는게 forEach(log) 보다 빠름

//! 아스키코드
// input().charCodeAt().log()

//! 비교
// /*  4101 */	input('\n').slice(0,-1).map(x=>x.split(' ')).forEach(([a,b])=>(+a>+b ? 'Yes' : 'No').log());
// /* 10871 */	[_, x, ...seq]=input(/\W/); seq.filter(e => +e < +x).log(' ');
// /* 10807 */	[_, seq, [v]] = input2('\n', ' '); seq.filter(e => +e==+v).length.log();
// /* 26209 */	input(' ').some(x => +x > 1).if('F', 'S').log();

//! 사칙연산
// /* 10869 */	[a,b]=input(' ').map(x=>x*1); [a+b, a-b, a*b, (a/b)|0, a%b].log('\n');

//! 조건에 따라서 알맞은 메시지 출력
// log(x<425?"Violet":x<450?"Indigo":x<495?"Blue":x<570?"Green":x<590?"Yellow":x<620?"Orange":x<=780?"Red":"")
// [[], [12,1600], [11,894], [11,1327], '...', [6,556], [6,773]][input()*1].log('');


//: ■■■■■■■■■■■■■■■■[ 풀이 ]■■■■■■■■■■■■■■■■
