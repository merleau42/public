//!	테스트 케이스 읽기
file = require("fs").readFileSync("./dev/stdin").toString()

//!	입력값 파싱
input = file
// .split(" ")
// .split("\n")
// .map(x=>x.split(" "));
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//! 네임 스페이스 제거
const { sqrt, ceil, floor, abs, sign } = Math;
const { clear, log } = console;

//!	배열, 문자열 함수
range = (a, l=0, d=1) => [...Array(abs(l - a)/d)].map((_,i)=>l ? a + d * i * sign(l - a) : d * i * sign(a));
rank = function () { return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[i,x[1]]).toSorted((a,b)=>a[1]-b[1]).map(x=>x[0]) };
toSorted = function (cmp) { return this.sort(cmp) };
inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] };
deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] };
removed = function (item, from=0) { i = this.indexOf(item,from); return i > -1 ? this.deleted(i) : this };

//!	체인 호출 등록
Object.prototype.print = function (s) { log(s==undefined ? this.valueOf() : this.join(s)); return this };
Object.prototype.Each = function (f) { this.forEach(f); return this };
['rank', 'toSorted', 'inserted', 'deleted', 'removed'].Each(f => Array.prototype[f] = globalThis[f])
.concat(['join']).Each(f => String.prototype[f] = function(...args) { return [...this][f](...args) } );
  

//!	디버깅 도구
stamp = msg=>`<${Date().match(/\d+:\d+:\d+/)[0]} // ${Date.now() % 1000000}> ${msg??''}`.print();
show = sheet=>{ console.log(sheet.map(x=>x.join('\t\t\t')).join('\n') + '\n') };
repl = () => require('repl').start();

//! 메인
stamp();
"12345".print();
range(10).print('');
"abcd".removed('d').print();

range(10).print();
range(-10).print();


//! 수열, 누적합, 구간합
// search = input[0]*1
// seq = input[1].split(" ")
// sheet1 = seq.reduce((s,c,i,a) => [...s, [
// 	i,
// 	c*1,
// 	c*1 + s[i][2]*1
//  ]], [[0,0,0,0,0,0,0]]).with(0, ["IND", "TRM", "SUM"])
// console.log( sheet1.filter(x=>x[1]==search).length )


//! 미분류
// sheet1 = input.reduce((s,c,i,a) => [...s, [
// 	i,
// 	c[0],
// 	age = c[1]*1,
// 	wei = c[2]*1,
// 	(age > 17 || wei >= 80) ? 'Senior' : 'Junior'
//  ]], [[0,0,0,0,0,0]]).with(0, ["IND", "NAM", "AGE", "WEI", "VAL"])


//! 정수론
isPrime = (N)=> N<2 ? false : !range(2, floor(sqrt(N) + 1) ).some(i => N % i == 0);




repl();