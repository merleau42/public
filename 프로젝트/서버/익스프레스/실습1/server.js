const express = require('express');

const app = express();
const path = require('path'); // 경로를 직접 입력해도 되지만, OS마다 표기 방식이 달라서 호환성을 위해 사용
const port = 3000;


// 모든 HTTP 메소드 요청시 응답 정의
app.use( (요청, 응답) => {
	console.log(요청);
});



//	GET 메소드 요청시 응답 정의
app.get('/', (요청, 응답) => {
	응답.sendFile(  path.join(__dirname, 'index.html') )
});

app.get('/movies/:id', (요청, 응답) => {
	const id = 요청.params.id;
	console.log(id);
});


//	POST 메소드 요청시 응답 정의
app.post('/movies', (요청, 응답) => {
	const body = 요청.body;
	console.log(body);
});


// 포트 번호로 서버 개방. 하나의 app은 하나의 포트를 가짐.
app.listen(port, () => console.log(port + '포트에서 대기 중') );

