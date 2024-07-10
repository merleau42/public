input = require("fs").readFileSync("./dev/stdin").toString()
// .split(" ");
.split("\n");
// .split("\n").map(x=>x.split(" "));

Array.prototype.toSorted = function(cmp) { return [...this].sort(cmp) };
Array.prototype.with = function(i,x) { tmp=[...this]; tmp[i]=x; return tmp };
show = sheet=>{ console.log(sheet.map(x=>x.join('\t\t\t')).join('\n') + '\n') };

// console.log(input)
// if (input.pop() == "") input.pop(); // 마지막 줄 제거(EOF 등)

//: 수열, 누적합, 구간합
search = input[0]*1
seq = input[1].split(" ")
sheet1 = seq.reduce((s,c,i,a) => [...s, [
	i,
	c*1,
	c*1 + s[i][2]*1
 ]], [[0,0,0,0,0,0,0]]).with(0, ["IND", "TRM", "SUM"])

console.log( sheet1.filter(x=>x[1]==search).length )

//: 미분류
// sheet1 = input.reduce((s,c,i,a) => [...s, [
// 	i,
// 	c[0],
// 	age = c[1]*1,
// 	wei = c[2]*1,
// 	(age > 17 || wei >= 80) ? 'Senior' : 'Junior'
//  ]], [[0,0,0,0,0,0]]).with(0, ["IND", "NAM", "AGE", "WEI", "VAL"])


