const express = require('express');

const app = express();

app.set('port', process.env.PORT || 3000); // 변수명과 값설정. get/set

app.get('/', (req, res) => { // get 요청에 대한 응답 정의.  get함수가 중의적으로 정의됨.
	res.send('Hello World!');
});

app.listen(app.get('port'), () => {
	console.log(app.get('port'), '번 포트에서 대기 중');
})
