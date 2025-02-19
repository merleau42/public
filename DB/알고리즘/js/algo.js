//! 네임 스페이스 제거
const { sqrt, round, ceil, floor, trunc, abs, sign, max, min, random } = Math;
const { log } = console;
const { isArray } = Array;
const { fromCharCode } = String;

//! 테스트 케이스 불러오기
input = (...s) => `${require("fs").readFileSync("./dev/stdin")}`.trim().deepsplit(s);

//!	기본 함수
Object.prototype.if = function (T, F=false, cond=it) { return cond(this.valueOf()) ? T : F };
Object.prototype.log = function (...s) { log(s.length ? typeOf(this)=='array' ? this.deepjoin(s) : this.join(s) : this.valueOf()); return this },

objtools = [
	it = function (obj=this) { return obj.valueOf() },
	Each = function (f) { this.forEach(f); return this },
	ascii = function (x=this) { t=typeOf(x)[0]; return t=='s' ? x.map(c => c.charCodeAt()) : t=='n' ? fromCharCode(x) : x },
].map(f => f.name).forEach(f => Object.prototype[f] = globalThis[f]);
typeOf = (x) => isArray(x) ? 'array' : typeof x.valueOf();

//! 디버깅 도구
Object.prototype.show = function () { log(Object.entries(this).map(([k,v])=>[k, ...v].join('\t')).join('\n')) };
stamp = (()=>{ count = 0; ago = Date.now(); return (msg='STAMP')=>{log(msg, ++count, Date.now() - ago); ago=Date.now()} })();
repl = (msg=log('REPL모드')) => require('repl').start();
randz = (min, max, arr=0) => arr ? range(arr).map(x => randz(min,max)) : floor(random() *(max - min + 1)) + min;

//!	배열 함수 확장, 문자열에도 적용
arrayfuncs = ['join', 'reduce', 'map', 'forEach', 'filter'];
itertools = [
	rank = function () {return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[x[1],i]).toSorted((a,b)=>a[0]-b[0]).map(x=>x[1])},
	toSorted = function (cmp) { return this.sort(cmp) },
	toReversed = function () { return this.reverse()},
	inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] },
	deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] },
	removed = function (tar, from=0) { i = this.indexOf(tar,from); return i > -1 ? this.deleted(i) : this },
	deepjoin = function (sep, arr=this, depth=0) { return arr.map(row => isArray(row) ? deepjoin(sep, row, depth+1) : row).join(sep[depth]) },
	unique = function () { return [...new Set(this)] },
	mapleaves = function (fn, arr=this) { return (isArray(arr) ? arr.map(x => mapleaves(fn, x)) : fn(arr.valueOf())) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f])
.concat(arrayfuncs).Each(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );

//! 함수 객체 편의 기능
// Function.prototype.memoized = function (fn=this) { return (...args) => memo[args] ?? (memo[args] = fn(...args))  }

//! 문자열 관련 함수
strtools = [ 
	stoi = function () { return this.match(/\-?\d+/)?.[0]*1||0 },
	Match = function (regex, fail=[]) { return this.match(regex)??fail },
	asciiShift = function (s) { return this.ascii().map(x => ascii(x+s)).join('') },
	deepsplit = function (s, str=this, d=0) { return s[d] == undefined ? str : str.split(s[d]).map(e=>deepsplit(s, e, d+1)); },
].map(f => f.name).Each(f => String.prototype[f] = globalThis[f]);

//! 수열, 누적합/구간합, 누적곱/구간곱
seqtools = [
	serial = function () { return this.map((_,i) => i) },
	value = function () { return [...this] },
	sum = function () { return this.reduce((s,c)=>s*1 + c*1) },
	psum = function () { return this.reduce((s,c,i) => [ ...s, c + (s[i-1]||0) ], []) },
	product = function () { return this.reduce((s,c)=>s*1 * c*1) },
	pproduct = function () { return this.reduce((s,c,i) => [ ...s, c * (s[i-1]||BigInt(1)) ], []) },
	mini = function () { return this.reduce((s,c,i) => +this[s] > +c ? i : s, 0) },
	maxi = function () { return this.reduce((s,c,i) => +this[s] < +c ? i : s, 0) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f]);


//! 정수론
isPrime = (N)=> N>1 && N==2 || !range(2, ceil(sqrt(N)) + 1 ).some(i => N % i == 0);
fibo = (N, start=[0, 1]) => cache[N] = cache[N] ?? (N<2 ? start[N] : fibo(N-2) + fibo(N-1));
facto = (N) => N == undefined ? [1].concat(range(1, 101)).map(BigInt).pproduct() : facto()[N];
clamp = (x, min, max) => x < min ? min : x > max ? max : x;

//! 행렬
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a*1 + d * i * sign(l - a) : d * i * sign(a));
vector = (n, f=()=>null) => [...Array(n)].map((x,i)=>f(i));
matrix = (rows, cols, f=()=>0) => vector(rows).map((_,i) => vector(cols).map((_,j) => f(i,j)));
matrixR = (rowR, colR, f) => rowR.map(i => colR.map(j => f(i,j)));
Array.prototype.draw = function(f) { return this.map((row,i) => row.map((col,j) => f(col,i,j,this))) };

//: ■■■■■■■■■■■■■■■■[ 풀이 ]■■■■■■■■■■■■■■■■
//! 전역 변수
// cache = new Map();

//! 메인
[x, l] = input('\n',' ').map(([t,e,f])=>t*3 + e*20 + f*120); log(x, l); log(x > l ? 'Max' : x == l ? 'Draw' : 'Mel');

//! 분류중
// [a,b, c,d] = input(' '); log(a*b + c*d); //B5 8370
// [a, c] = input('\n', ' '); [c[0] - a[2],  c[1] / a[1],  c[2] - a[0]].log(' '); //B4 17256 인덱싱