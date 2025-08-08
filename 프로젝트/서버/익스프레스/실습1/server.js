const express = require('express');
const app = express();
const path = require('path');


// 포트 설정
app.set('port', process.env.PORT || 3000);


// GET 요청시 응답 정의
app.get('/', (요청, 응답) => {
	응답.send('Hello Worsssld!');
	// 응답.sendFile(path.join(path.join(__dirname, 'index.html')));
});


app.listen(app.get('port'), () => console.log(app.get('port'), '번 포트에서 대기 중') );
