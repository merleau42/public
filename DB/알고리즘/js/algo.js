//! 네임 스페이스 제거
const { sqrt, round, ceil, floor, trunc, abs, sign, max, min, random } = Math;
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
	unbase = function (b) { [B,r]=b[0]?[[...b],b.len()]:[vector(b,String),b]; N=this.map(String); return N.subsetOf(B)?N.reduce((s,c)=>s*r + B.indexOf(c+''), 0):0},
	has = function (e) { return this.indexOf(e) != -1},
	equals = function (arr) { return this.length == arr.length ? this.every((_,i) => this[i] == arr[i]) : false },
	// until = function (WHILE, DO) {while(WHILE) DO(this);},
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f])
.concat(arrayfuncs).forEach(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );

//! 문자열 관련 함수
strtools = [ 
	stoi = function () { return this.match(/\-?\d+/)?.[0]*1||0 },
	_match = function (regex, fail=[]) { return this.match(regex)??fail },
	asciiShift = function (s) { return this.ascii().map(x => ascii(x+s)).join('') },
	deepsplit = function (s, str=this, d=0) { return s[d] == undefined ? str : str.split(s[d]).map(e=>deepsplit(s, e, d+1)); },
	len = function () { return this.length },
].map(f => f.name).forEach(f => String.prototype[f] = globalThis[f]);

//! 수열, 누적합/구간합, 누적곱/구간곱
seqtools = [
	serial = function () { return this.map((_,i) => i) },
	value = function () { return [...this] },
	sum = function (cond) { return this.reduce((s,c) => !cond || cond && cond(c) ? s + c*1 : s, 0) },
	average = function () { return this.sum()/this.length },
	psum = function () { return this.reduce((s,c,i) => [ ...s, c + (s[i-1]||0) ], []) },
	product = function () { return this.reduce((s,c)=>s*1 * c*1) },
	pproduct = function () { return this.reduce((s,c,i) => [ ...s, c * (s[i-1]||BigInt(1)) ], []) },
	_min = function (lim = -Infinity, err = -1) { return this.length == 0 ? err : max(lim, this.reduce((s,c) => s > +c ? c : s, +Infinity)) },
	_max = function (lim = +Infinity, err = -1) { return this.length == 0 ? err : min(lim, this.reduce((s,c) => s < +c ? c : s, -Infinity)) },
	mini = function (err = -1) { return this.length == 0 ? err : this.reduce((s,c,i) => +this[s] > +c ? i : s, 0) },
	maxi = function (err = -1) { return this.length == 0 ? err : this.reduce((s,c,i) => +this[s] < +c ? i : s, 0) },
].map(f => f.name).forEach(f => Array.prototype[f] = globalThis[f]);

//! 컬렉션
map = (n, kf=i=>i, vf=()=>0) => [...Array(n)].reduce((s,_,i) => s.set(kf(i), vf(i)), new Map());
Map.prototype.update = function (key, fn) { return this.set(key, fn(this.get(key) || 0)) };
Map.prototype.vals = function () { return [...this.values()] };

//! 행렬
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a*1 + d * i * sign(l - a) : d * i * sign(a));
natural = (n) => range(1, n+1);
vector = (n, f=()=>0) => [...Array(n)].map((_,i)=>f(i,n));
matrix = (rows, cols, f=()=>0) => vector(rows).map((_,i) => vector(cols).map((_,j) => f(i,j,rows,cols)));
dimtools = [
	blend = function (arr, f, depth=1) { return this.map((_,i) => f(this[i], arr[i])) },
].map(f => f.name).Each(f => Array.prototype[f] = globalThis[f]);
Array.prototype.draw = function(f) { return this.map((row,i) => row.map((col,j) => f(col,i,j,this))) };

//! 정수론
isPrime = (N)=> N>1 && N==2 || !range(2, ceil(sqrt(N)) + 1 ).some(i => N % i == 0);
facto = (N) => N == undefined ? [1].concat(range(1, 101)).map(BigInt).pproduct() : facto()[N];
clamp = (x, min, max) => x < min ? min : x > max ? max : x;
divisor = (N) => range(1, N+1).filter(x => !(N%x));
numtools = [
	len = function (base=10, N=this) { return N==0 ? 1 : floor(Math.log(N) / Math.log(base)) + 1 },
	notate = function (b) { [B,r]=b[0]?[b,b.len()]:[vector(b, String),b]; return (this<r)?[B[this]]:[...floor(this/r).notate(b),B[this%r]] },
].map(f => f.name).forEach(f => Number.prototype[f] = globalThis[f]);

//! 점화식
fibo = (N, start=[0, 1]) => fibo.memo[N] ??= (N<2 ? start[N] : fibo(N-2) + fibo(N-1));

//! 반복 함수, 궤도, 고정점, 주기점
picard = (f,S,m=100) => {o=[S]; while(m--){c=f(p=o.at(-1)); t=(p==c) ? 'fixed' : o.has(c) ? 'periodic' : 0; o.push(c); if (t) return [o,t];} return [o,'chaos']; };

//! 조합론
cartesian = (하한, 상한, 설정={}, 상태=[], 깊이=0, 해집합=[]) => {
	설정 = { 필터:()=>true, 액션:e=>e, 가지치기:()=>true, 조기리턴:()=>false, ...설정 };

	if (하한[깊이] == undefined) {
		if (설정.필터(...상태))
			해집합.push( 설정.액션(...상태) );
		return ;
	}
	for (e of range(하한[깊이], 상한[깊이] + 1)) {
		if (설정.가지치기(...상태)) {
			상태.push(e);
			cartesian(하한, 상한, 설정, 상태, 깊이+1, 해집합);
			상태.pop();
		}
		if (설정.조기리턴(해집합))
			return 해집합;
	}
	return 해집합;
}

완전탐색 = (자료={}, 전략={}, 상태={}, 초기화=false) => {
	if (!초기화) {
		자료 = { 상한: [], 하한: [], ...자료 };
		상태 = { 스택: [], 깊이: 0, 해집합: [], ...상태 };
		전략 = { 필터: ()=>true, 액션: e=>e, 가지치기: ()=>true, 종료: ()=>false, ...전략 };
	}

    if (자료.하한[상태.깊이] == undefined) {
        if (전략.필터(...상태.스택))
            상태.해집합.push(전략.액션(...상태.스택));
        return;
    }

    for (e of range(자료.하한[상태.깊이], 상태.상한[상태.깊이] + 1)) {
        if (전략.가지치기(...상태.스택)) {
            상태.스택.push(e);
            완전탐색(자료, 전략, 상태, true);
            상태.스택.pop();
        }
        if (전략.조기리턴(상태.해집합))
            return 상태.해집합;
    }
    return 상태.해집합;
}


//! 통계학
median3 = (x, y, z) => x ^ y ^ z ^ min(x,y,z) ^ max(x,y,z);

//: ■■■■■■■■■■■■■■■■[ 풀이 ]■■■■■■■■■■■■■■■■
//! 메인
// [L, R] = input(' ').map(Number); ((L || R) ? L == R ? `Even ${L+R}` : `Odd ${max(L,R) * 2}` : 'Not a moose').log()

cartesian([2,1], [9,9], {필터: (i, j)=>[i, j, i*j].includes( +input() ) }).log()


//! 진법
// [now, [elt]] = input('\n', ' ').mapleaves(Number); (now.unbase(60)+elt).thru(x=>x%86400).notate(60).leftpad(3).log(' ') //2530
// input('\n', ' ').slice(1).map(([i, x])=>[i, x.unbase(8), x.unbase(10), x.unbase("0123456789abcdef")]).log('\n', ' '); //13877
// [n, r] = input(' '); (+n).notate("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".slice(0,r)).log('') //11005
// [n, r] = input(' '); n.unbase("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".slice(0,r)).log() //2745
// [[a, b] ,_ , n] = input('\n', ' ').mapleaves(Number); n.unbase(a).notate(b).log(' ') //11576

//! 완탐
//_ 브4
// deepfor([2,1], [9,9]).filter(([a,b])=>[a,b,a*b].includes(+input())).length ? log(1) : log(0) //32710, 구구구구단
// 테케.map(상한 => deepfor([1,1,1], 상한).filter(([x,y,z]) => (x%y == y%z) && (y%z == z%x)).length.log() );

//! 정수론
//_ 브3
// [n, nth] = input(' ').map(Number); log(  divisor(n)[nth - 1]??0  ); //2501, K번째 약수

//! 기하학
//_ 브3
// n = +input(); deepfor([1,1], [ceil(sqrt(n)), ceil(sqrt(n))]).find(([w,h])=>w*h >= n).log(' ') //3276, 최소둘레 최대넓이

