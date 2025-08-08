const express = require('express');
const app = express();
const path = require('path'); // 경로를 직접 입력해도 되지만, OS마다 표기 방식이 달라서 호환성을 위해 사용
const port = 3000;

const bodyParser = require('body-parser');

// 모든 HTTP 메소드 요청시 응답 정의
app.use( (요청, 응답, next) => {
	console.log('HTTP 통신 발생');
	next();
}); // next가 있어야 get/post 등이 실행됨

app.use(bodyParser.json());


//	GET 메소드 요청시 응답 정의
app.get('/', (요청, 응답) => {
	응답.sendFile(  path.join(__dirname, 'index.html') );
});
app.get('/movies', (요청, 응답) => {
	응답.send(  "영화 목록 데이터" );
});


//	POST 메소드 요청시 응답 정의
app.post('/movies', (요청, 응답) => {
	console.log('POST 요청 발생');  console.log(요청.body);
});


// 포트 번호로 서버 개방. 하나의 app은 하나의 포트를 가짐.
app.listen(port, () => console.log(port + '포트에서 대기 중') );

