const fs = require('fs/promises');
const { log } = console;

파일 = {};

async function 불러오기() {
	파일.올보카 = await fs.readFile('RAW.tsv', 'utf-8');
	파일.렘마 = await fs.readFile('../BNC_COCA/빈도50+.txt', 'utf-8');
}

(async function main() {
	await 불러오기();
	const {렘마, 올보카} = 파일;
	
	words = 올보카.split('\n').map(ln => ln.split('\t')[1]);
	
	log( words
			.reduce( (s,wd,index) => 렘마.includes(wd) ? s : [...s, `${index}${wd}`],  [])
			.join('\n')	);

})();

//>		clear; node tool.js | tee result.txt
