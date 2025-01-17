//! 네임 스페이스 제거
const { sqrt, ceil, floor, abs, sign, max, min, random } = Math;
const { clear, log } = console;

//! 테스트 케이스 불러오기
input = (s,t=1)=>require("fs").readFileSync("./dev/stdin").toString()[t? 'trim' : 'it']()[s? 'split' : 'it'](s);

//!	기본 함수, 디버깅 도구
Object.prototype.it = function (f) { return this.valueOf() };
Object.prototype.Each = function (f) { this.forEach(f); return this };
Object.prototype.print = function (s) { log(s==undefined ? this.valueOf() : this.join(s)); return this };
Object.prototype.show = function () { log(Object.entries(this).map(([k,v])=>[k, ...v].join('\t')).join('\n')) };
stamp = (()=>{ let count = 0; return (msg='STAMP',tabs=0)=>log("\t".repeat(tabs) + msg + ':', ++count) })();
repl = (msg=log('REPL모드')) => require('repl').start();
randz = (min, max, arr=0) => arr ? range(arr).map(x => randz(min,max)) : floor(random() *(max - min + 1)) + min;

//!	배열 함수 확장, 문자열에도 적용
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a + d * i * sign(l - a) : d * i * sign(a));
arr_str = ['join', 'toReversed'];
itertools = [
	rank = function () {return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[x[0],i]).toSorted((a,b)=>a[0]-b[0]).map(x=>x[0])},
	toSorted = function (cmp) { return this.sort(cmp) },
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


//: ■■■■■■■■■■■■■■[ 메인 ]■■■■■■■■■■■■■■

//! 문자열 양식
// /*  14581 */	log(`:fan::fan::fan:\n:fan::${input(' ')}::fan:\n:fan::fan::fan:`);

//! 문자열을 반복해서 출력
// /*  9316 */	range(input(' ')).forEach(i => log(`Hello World, Judge ${i + 1}!`))
// /* 26766 */	log( 문자열.repeat(input(' ')) );

//! 아스키코드
// input(' ').charAt();

"123".repeat(input()).print();