console.clear();

function ex1() {
	[a, b] = process.argv.slice(2).map(Number);
	console.log(a + b);
	console.log(a - b);
	console.log(a * b);
	console.log(a / b);
}

function ex2() {
	[a, b] = process.argv.slice(2).map(Number);
	console.log( Math.floor(a / b)); //parseInt
	console.log(a % b);
}

function ex3() {
	[이름, 나이, 키] = process.argv.slice(2);
	console.log(`이름:${이름}`);
	console.log(`나이:${나이}살`);
	console.log(`키:${키}cm`);
}

function ex4() {
	[...seq] = process.argv.slice(2).map(Number);
	console.log(seq.reduce((s,c) => s+c));
	console.log(seq.reduce((s,c) => s+c) / seq.length );
}

function ex5() {
	[gender] = process.argv.slice(2)
	console.log( {'F' : 'Female', 'M' : 'Male'}[gender] );
}

function ex6() {
	[n] = process.argv.slice(2)
	console.log( ['짝수', '홀수'][n % 2] );
}

function ex7() {
	[n] = process.argv.slice(2)

	for (i=1; i<=9; i++)
		console.log(`${n} * ${i} = ${n * i}`);
}

function ex8() {
	[a,b] = process.argv.slice(2).map(Number);

	let sum = 0;
	for (i=a; i<=b; i++)
		sum += i;
	console.log(sum);
}

function ex9() {
	[이름,키,몸무게] = process.argv.slice(2).map(Number);

	const 표준체중 = (키-100)*0.9;

	console.log(
		`${이름}님은 `
		+ `${Math.abs(몸무게-표준체중)}만큼 `
		+ `${['증량', '감량'][(몸무게 > 표준체중)*1]}해야 합니다.`
	)
}

ex9();