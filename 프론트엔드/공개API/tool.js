const fs = require('fs');

function load_as_JSON(파일) {
	const data = fs.readFileSync(파일, 'utf8');
	return JSON.parse(data);
}

function load_as_Array(파일) {
	const data = fs.readFileSync(파일, 'utf8');
	return data.split('\n');
}

function save_as_JSON(target, 파일) {
	const result = [];

	target.forEach(line => {
		const record = {
			original: line,
			alter: [line]
		};
		result.push(record);
	});

	fs.writeFileSync(파일, JSON.stringify(result, null, 2), 'utf8');
}


raw = load_as_JSON('kr.json');
// save_as_JSON(raw, 'kr2.json')

