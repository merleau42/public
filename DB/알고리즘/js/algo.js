//!	테스트 케이스 읽기
file = require("fs").readFileSync("./dev/stdin").toString()

//!	입력값 파싱
input = file
// .split(" ")
// .split("\n")
// .map(x=>x.split(" "));
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//!	편의성, 배열, 문자열 함수
print = function (x=this, sep=null) { console.log(!!sep ? x.valueOf().join(sep) : x.valueOf()); return x };
rank = function (arr=this) { return arr.map((x,i) => [x*1, i]).toSorted((a,b) => a[0] - b[0]).map((x,i) => [i, x[1]]).toSorted((a,b) => a[1] - b[1]).map(x => x[0]) };
range = (start, end) => [...Array(Math.abs(end - start))].map((_,i)=>start + i * (2 * (end > start) - 1));
toSorted = function (cmp, arr=this) { return [...arr].sort(cmp) };
inserted = function (index, src, dest=this) { return [...dest.slice(0, index), ...src, ...dest.slice(index)] };
deleted = function (index, size=1, dest=this) { return [...dest.slice(0, index), ...dest.slice(index + size)] };
// inserted, removed, 

//!	체인 호출 등록
Object.prototype.with = function(i,x) { tmp=[...this]; tmp[i]=x; return tmp };
['print'].forEach(f => Object.prototype[f] = globalThis[f]);
['rank', 'toSorted', 'inserted', 'deleted'].forEach(f => Array.prototype[f] = globalThis[f]);
['toSorted'].forEach(f => String.prototype[f] = globalThis[f]);
// Array.prototype.toSpliced = function (start, deleteCount, ...items) { return [...this.slice(0, start), ...items, ...this.slice(start + deleteCount)] };
  

//!	디버깅 도구
stamp = (msg='')=>print(`<${Date.now() % 1000000}> ${msg}`)
show = sheet=>{ console.log(sheet.map(x=>x.join('\t\t\t')).join('\n') + '\n') };


//! 메인
stamp();
[0,1,2,3,4,5].deleted(2).print();
[0,1,2,3,4,5].inserted(2,[...'abc']).print();
[0,1,2,3,4,5].deleted(2).inserted(2,[...'abc']).print();

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


