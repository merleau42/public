//!	테스트 케이스 읽기
file = require("fs").readFileSync("./dev/stdin").toString()

//!	입력값 파싱
input = file
// .split(" ")
// .split("\n")
// .map(x=>x.split(" "));
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//!	편의성, 배열, 문자열 함수
print = function (sep) { console.log(sep ?? 0 ? this.valueOf().join(sep) : this.valueOf()); return this };
rank = function () { return this.map((x,i)=>[x*1,i]).toSorted((a,b)=>a[0]-b[0]).map((x,i)=>[i,x[1]]).toSorted((a,b)=>a[1]-b[1]).map(x=>x[0]) };
range = (start, end) => [...Array(Math.abs(end - start))].map((_,i)=>start + i * (2 * (end > start) - 1));
toSorted = function (cmp) { return this.sort(cmp) };
inserted = function (index, ...src) { return [...this.slice(0, index), ...src, ...this.slice(index)] };
deleted = function (index, size=1) { return [...this.slice(0, index), ...this.slice(index + size)] };

//!	체인 호출 등록
Object.prototype.with = function(i,x) { tmp=[...this]; tmp[i]=x; return tmp };
String.prototype.join = function(sep) { return [...this.valueOf()].join(sep) };
['print'].forEach(f => Object.prototype[f] = globalThis[f]);
['rank', 'toSorted', 'inserted', 'deleted'].forEach(f => Array.prototype[f] = globalThis[f]);
['rank', 'toSorted', 'inserted', 'deleted'].forEach(f => String.prototype[f] = function() { return [...this][f]() } );
  

//!	디버깅 도구
stamp = msg=>`<${Date.now() % 1000000}> ${msg??''}`.print();
show = sheet=>{ console.log(sheet.map(x=>x.join('\t\t\t')).join('\n') + '\n') };


//! 메인
stamp();
range(10,0).print().toSorted((a,b)=>a-b).print();

[..."707468"].rank().print('---');
[..."707468"].toSorted().print('---');
[..."707468"].toSorted().inserted(2, 5, 5, 5).print('---');
[..."707468"].toSorted().deleted(2,3).print('---');

"707468".rank().print('___');
"707468".toSorted().print('___');
"707468".toSorted().inserted(2, 5, 5, 5).print('___');
"707468".toSorted().deleted(2,3).print('___');

range(20,10).print().toSorted().print();
range(20,10).print(', ').toSorted().print();
range(0,6).deleted(2).print();
range(0,6).inserted(2,[...'abc']).print();
range(0,6).deleted(2).inserted(2,[...'abc']).print();
range(0,6).deleted(2,3).inserted(2,[...'abc']).print();

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


