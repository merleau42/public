//!	입력값의 테스트 케이스를 불러와서 파싱
input = require("fs").readFileSync("./dev/stdin").toString()
// .split(" ")
// .split("\n")
// .map(x=>x.split(" "));
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//! 네임 스페이스 제거
const { sqrt, ceil, floor, abs, sign, max, min } = Math;
const { clear, log } = console;

//!	배열, 문자열 함수
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a + d * i * sign(l - a) : d * i * sign(a));
arr_str = ['join', 'toReversed'];
itertools = [
	rank = function () { return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[i,x[1]]).toSorted((a,b)=>a[1]-b[1]).map(x=>x[0]) },
	toSorted = function (cmp) { return this.sort(cmp) },
	inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] },
	deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] },
	removed = function (item, from=0) { i = this.indexOf(item,from); return i > -1 ? this.deleted(i) : this },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f])
.concat(arr_str).Each(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );

//!	프로토타입 함수 등록 (체인 호출 가능)
Object.prototype.print = function (s) { log(s==undefined ? this.valueOf() : this.join(s)); return this };
Object.prototype.Each = function (f) { this.forEach(f); return this };

//!	디버깅 도구
stamp = (()=>{ let count = 0; return (msg='STAMP',tabs=0)=>log("\t".repeat(tabs) + msg + ':', ++count) })();
table = (...info) => log( info.map(x=>x.join('\t')).join('\n') );
repl = () => require('repl').start();
deep = (x) => JSON.parse( JSON.stringify(x) )

//! 수열, 누적합, 구간합
Array.prototype.pre = [];
seqtools = [
	serial = function () { return this.pre.index = this.map((_,x) => i)},
	psum = function (arr=this) { return arr.pre.psum = arr.reduce((s,c,i) => [ ...s, c + (s[i-1]||0) ], []) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f]);
seq = range(33, 40);

//! 정수론
isPrime = (N)=> N==2 || N>1 && !range(2, ceil(sqrt(N)) + 1 ).some(i => N % i == 0);

//! 메인
range(1, 100).psum().print();
