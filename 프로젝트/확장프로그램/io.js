const fs = require('fs');

data = fs.readFileSync('a.html', 'utf8'); // 파일 읽기
console.log(data)

fs.writeFileSync('a.html', 'abcdefg12345678', 'utf8'); // 파일 쓰기