//! 네임 스페이스 제거
const { sqrt, round, ceil, floor, trunc, abs, sign, max, min, random, PI } = Math;
const { log, clear } = console;
const { keys } = Object;
const { isArray } = Array;
const { fromCharCode } = String;

//! 테스트 케이스 불러오기
input = (...s) => `${require("fs").readFileSync("./dev/stdin")}`.trim().deepsplit(s);

//!	기본 함수
Object.prototype.if = function (T, F, cond=self) { return cond(this.valueOf()) ? T : F };
Object.prototype.branch = function (T, F, cond=self) { return cond(this.valueOf()) ? T(this.valueOf()) : F(this.valueOf()) };
Object.prototype.thru = function (fn) { return fn(this.valueOf())}; //0차원 맵
Object.prototype.log = function (...s) { log(s.length ? typeOf(this)=='array' ? this.deepjoin(s) : this.join(s) : this.valueOf()); return this };
Object.defineProperty(Function.prototype, "memo", { get() { return this.cache ??= {}; } });
objtools = [
	self = function (obj=this) { return obj.valueOf() },
	Each = function (f) { this.forEach(f); return this },
	ascii = function (n=0, x=this) { t=typeOf(x)[0]; return t=='s' ? x.map(c => n + c.charCodeAt()) : t=='n' ? fromCharCode(x) : x },
	typeOf = function (x=this) { return isArray(x) ? 'array' : typeof x.valueOf() },
].map(f => f.name).forEach(f => Object.prototype[f] = globalThis[f]);

//! 디버깅 도구
Object.prototype.show = function () { log(Object.entries(this).map(([k,v])=>[k, ...v].join('\t')).join('\n')) };
stamp = (()=>{ count = 0; ago = Date.now(); return (msg='STAMP')=>{log(msg, ++count, Date.now() - ago); ago=Date.now()} })();
repl = (msg=log('REPL모드')) => require('repl').start();
randz = (min, max, arr=0) => arr ? range(arr).map(x => randz(min,max)) : floor(random() *(max - min + 1)) + min;

//! 상수 함수
I = (x) => ( ()=>x );
T = TRUE = 참 = I(true);
F = FALSE = 거짓 = I(false);

//!	배열 함수 확장, 문자열에도 적용
arrayfuncs = ['join', 'reduce', 'map', 'forEach', 'filter'];
itertools = [
	rank = function () {return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[x[1],i]).toSorted((a,b)=>a[0]-b[0]).map(x=>x[1])},
	// rank = function () { S = this.toSorted((a,b)=>a-b); return this.map(e => S.indexOf(e))},
	toSorted = function (cmp) { return [...this].sort(cmp) },
	toReversed = function () { return [...this].reverse() },
	update = function (index, fn) { tmp=[...this]; tmp[index]=fn( tmp[index] ); return tmp },
	inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] },
	deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] },
	removed = function (tar, from=0) { i = this.indexOf(tar,from); return i > -1 ? this.deleted(i) : this },
	deepjoin = function (sep, arr=this, depth=0) { return arr.map(row => isArray(row) ? deepjoin(sep, row, depth+1) : row).join(sep[depth]) },
	mapleaves = function (fn, arr=this) { return (isArray(arr) ? arr.map(x => mapleaves(fn, x)) : fn(arr.valueOf())) },
	chunk = function (...s) { return s.length == 0 ? [this.valueOf()] : [this.slice(0, s[0]), ...this.slice(s[0]).chunk(...s.slice(1))] },
	unique = function () { return [...new Set(this)] },
	leftpad = function (p, v=0) { return p > this.length ? vector(p - this.length, x=>v).concat(this) : this },
	rightpad = function (p, v=0) { return p > this.length ? this.concat(vector(p - this.length, x=>v)) : this },
	subsetOf = function (S) { return this.every(e => S.includes(e)) },
	has = function (e) { return this.indexOf(e) != -1},
	equals = function (arr) { return this.length == arr.length ? this.every((_,i) => this[i] == arr[i]) : false },
	// until = function (WHILE, DO) {while(WHILE) DO(this);},
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f])
.concat(arrayfuncs).forEach(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );

//! 문자열 관련 함수
strtools = [ 
	stoi = function () { return this.match(/\-?\d+/)?.[0]*1||0 },
	_match = function (regex, fail=[]) { return this.match(regex)??fail },
	asciiShift = function (s) { return this.ascii().map(x => (x+s).ascii()).join('') },
	deepsplit = function (s, str=this, d=0) { return s[d] == undefined ? str : str.split(s[d]).map(e=>deepsplit(s, e, d+1)); },
	len = function () { return this.length },
].map(f => f.name).forEach(f => String.prototype[f] = globalThis[f]);

//! 수열, 누적합/구간합, 누적곱/구간곱, 슬라이딩 윈도우
seqtools = [
	serial = function () { return this.map((_,i) => i) },
	value = function () { return [...this] },
	sum = function (arr=this) { return arr.reduce((s,c) => s + c*1, 0) },
	sumif = function (cond, arr=this) { return arr.reduce((s,c) => !cond || cond && cond(c) ? s + c*1 : s, 0) },
	average = function () { return this.sum()/this.length },
	psum = function () { return this.reduce((s,c,i) => [ ...s, c + (s[i-1]||0) ], []) },
	product = function () { return this.reduce((s,c)=>s*1 * c*1) },
	pproduct = function () { return this.reduce((s,c,i) => [ ...s, c * (s[i-1]||BigInt(1)) ], []) },
	_min = function (lim = -Infinity, err = -1) { return this.length == 0 ? err : max(lim, this.reduce((s,c) => s > +c ? c : s, +Infinity)) },
	_max = function (lim = +Infinity, err = -1) { return this.length == 0 ? err : min(lim, this.reduce((s,c) => s < +c ? c : s, -Infinity)) },
	mini = function (err = -1) { return this.length == 0 ? err : this.reduce((s,c,i) => +this[s] > +c ? i : s, 0) },
	maxi = function (err = -1) { return this.length == 0 ? err : this.reduce((s,c,i) => +this[s] < +c ? i : s, 0) },
	slide = function (gap, fn=a=>a, arr=this) { return arr.reduce((s,_,i,a) => i>gap-2 ? (s.push( fn(a.slice(i-gap+1, i+1)) ), s) : s, []) },
].map(f => f.name).forEach(f => Array.prototype[f] = globalThis[f]);

//! 컬렉션
map = (n, kf=i=>i, vf=()=>0) => [...Array(n)].reduce((s,_,i) => s.set(kf(i), vf(i)), new Map());
Map.prototype.update = function (key, fn) { return this.set(key, fn(this.get(key) || 0)) };
Map.prototype._values = function () { return [...this.values()] };

//! 행렬
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a*1 + d * i * sign(l - a) : d * i * sign(a));
natural = (n, m=undefined) => m ? range(+n, (+m)+1) : range(1, (+n)+1);
vector = (n, f=()=>0) => [...Array(n)].map((_,i)=>f(i,n));
matrix = (rows, cols, f=()=>0) => vector(rows).map((_,i) => vector(cols).map((_,j) => f(i,j,rows,cols)));
dimtools = [
	blend = function (arr, f, depth=1) { return this.map((_,i) => f(this[i], arr[i])) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f]);
Array.prototype.draw = function(f) { return this.map((row,i) => row.map((col,j) => f(col,i,j,this))) };

//! 정수론
isPrime = (N)=> N>1 && N==2 || !range(2, ceil(sqrt(N)) + 1 ).some(i => N % i == 0);
facto = (N) => N == undefined ? [1].concat(range(1, 101)).map(BigInt).pproduct() : facto()[+N];
clamp = (x, min, max) => x < min ? min : x > max ? max : x;
divisor = (N) => range(1, N+1).filter(x => !(N%x));
numtools = [
	length = function (base=10, N=this) { return N==0 ? 1 : floor(Math.log(N) / Math.log(base)) + 1 },
].map(f => f.name).forEach(f => Number.prototype[f] = globalThis[f]);

//! 고정 기수법, 진법
radixtools = [
	notate = function (b, d=99, arr=this) {return (+arr[0] < b) || d < 2 ? [+arr[0]] : [ ...notate(b, d-1, [floor(arr[0]/b)]), (arr[0]%b) ]},
	encode = function (table={..."0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"}, arr=this) {return arr.map(x => table[x])},
	decode = function (table="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", arr=this) {return arr.map(x => table.indexOf(x))},
	unbase = function (b, bound=b, arr=this) {return (bound==false || max(...arr) < bound) ? arr.reduce((s,c)=> s*b + c*1, 0) : 0},
].map(f => f.name).forEach(f => Array.prototype[f] = globalThis[f]);

//! 점화식
fibo = (N, start=[0, 1]) => fibo.memo[N] ??= (N<2 ? start[N] : fibo(N-2) + fibo(N-1));

//! 반복 함수, 궤도, 고정점, 주기점
picard = (f,S,m=100) => {o=[S]; while(m--){c=f(p=o.at(-1)); t=(p==c) ? 'fixed' : o.has(c) ? 'periodic' : 0; o.push(c); if (t) return [o,t];} return [o,'chaos']; };

//! 완전탐색
완전탐색 = (정보 = {}, 초기화 = false) => {
	정보 = 초기화 ? 정보 : {
		하한: [], 상한: [], 스택: [], 깊이: 0, 해집합: [], 최댓값: -Infinity, 최솟값: +Infinity,
		충족: 참, 활동1: ()=>{}, 발견: 참, 활동2: ()=>{}, 가공: ()=>[...스택],
		범위: ()=>[], 예선: 참, 종료: 거짓,  ...정보
	};

	const { 하한, 상한, 스택, 해집합, 충족, 활동1, 발견, 활동2, 가공, 범위, 예선, 종료 } = 정보;

	if (충족(정보)) {
		활동1(정보);
		if (발견(정보)) {
			활동2(정보);
			해집합.push(가공(정보));
		}
		return;
	}

	for (const 가지 of 범위(정보)) {
		if (예선(정보, 가지)) {
			스택.push(가지);
			정보.깊이++;
			완전탐색(정보, true);
			정보.깊이--;
			스택.pop();
		}
		if (종료(정보))
			return 정보;
	}
	
	return 정보;
};


//! 조합론
cartesian = (하한, 상한, 정보={}) => 완전탐색({하한, 상한, 충족: ({하한, 깊이}) => 하한[깊이] == undefined, 범위: ({하한, 상한, 깊이}) => range(하한[깊이], 상한[깊이] + 1), ...정보});

//! 통계학
median3 = (x, y, z) => x ^ y ^ z ^ min(x,y,z) ^ max(x,y,z);

//! 해석학
analytoos = [
	piecewise = function (Else, ...confs) { return this.map(e => confs.concat(x=>[1, Else(e)]).find(conf => conf(e)[0])(e)[1] ) },
].map(f => f.name).forEach(f => Array.prototype[f] = globalThis[f]);


//: ■■■■■■■■■■■■■■■■[ 풀이 ]■■■■■■■■■■■■■■■■
//! 메인
log( {'fdsajkl;':'in-out', 'jkl;fdsa':'in-out',
	'asdf;lkj':'out-in', ';lkjasdf':'out-in',
	'asdfjkl;':'stairs', ';lkjfdsa':'reverse'}[input()]??'molu' );


//! 메모
//> 형변환을 지양하다가 5분 동안 맞왜틀
//> 입출력, 인덱싱, 문자열, 고정기수, 람다, 배열, 집합, 조건문, 정렬, 케이스, 행렬, 상태전이...
//> 수학: 정수론, 대수, 기하, 조합론, 수열, 통계학, 산술...

//! 약수와 배수
//> divisor 도입할 것인지?
// [n, nth] = input(' ').map(Number); log(  divisor(n)[nth - 1]??0  ); //2501, K번째 약수
