//	테스트 케이스 읽기
file = require("fs").readFileSync("./dev/stdin").toString()

//	입력값 파싱
input = file
// .split(" ")
// .split("\n")
// .map(x=>x.split(" "));
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//	편의성, 배열, 문자열 함수
print = function (x=this) { console.log(x.valueOf()); return x };
rank = function (arr=this) { return [...arr].map((x,i) => [x*1, i]).toSorted((a,b) => a[0] - b[0]).map((x,i) => [i, x[1]]).toSorted((a,b) => a[1] - b[1]).map(x => x[0]) };
range = (start, end) => [...Array(Math.abs(end - start))].map((_,i)=>start + i * (2 * (end > start) - 1));

//	체인 호출까지
Object.prototype.with = function(i,x) { tmp=[...this]; tmp[i]=x; return tmp };
Array.prototype.toSorted = function(cmp) { return [...this].sort(cmp) };
['print'].forEach(f => Object.prototype[f] = globalThis[f]);
['rank'].forEach(f => Array.prototype[f] = globalThis[f]);
['rank'].forEach(f => String.prototype[f] = globalThis[f]);

//	디버깅 도구
show = sheet=>{ console.log(sheet.map(x=>x.join('\t\t\t')).join('\n') + '\n') };

//: 수열, 누적합, 구간합
search = input[0]*1
seq = input[1].split(" ")
sheet1 = seq.reduce((s,c,i,a) => [...s, [
	i,
	c*1,
	c*1 + s[i][2]*1
 ]], [[0,0,0,0,0,0,0]]).with(0, ["IND", "TRM", "SUM"])

// console.log( sheet1.filter(x=>x[1]==search).length )

"77777".print();
print("777");
[654,12,8787,1111,-4654,0,-77].rank().join(' ').print();
['a', 'b', 'c'].with(1,'z').print();
print( sheet1 )

zzz = function() {print(7123)}
global['zzz']();

"testtest".print();

"안녕하세요요".with(3,79).print().join('').print();

k = [1,2,3,4,5];
k.toSpliced(k.indexOf(4), 1, ...['a', 'b', 'c']).print();

[..."4127890235"].rank().print();

//: 미분류
// sheet1 = input.reduce((s,c,i,a) => [...s, [
// 	i,
// 	c[0],
// 	age = c[1]*1,
// 	wei = c[2]*1,
// 	(age > 17 || wei >= 80) ? 'Senior' : 'Junior'
//  ]], [[0,0,0,0,0,0]]).with(0, ["IND", "NAM", "AGE", "WEI", "VAL"])


