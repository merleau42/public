const express = require('express');
const app = express();
const path = require('path');
const port = 8001;

const bodyParser = require('body-parser');


//! 데이터
let boardList = [
	{ no: 1, title: '제목1', content: '내용1' },
	{ no: 2, title: '제목2', content: '내용2' },
	{ no: 3, title: '제목3', content: '내용3' }
];


//! USE
// 미들웨어		요청이 라우터에 도달하기 전에, 공통으로 실행되는 함수
app.use((req, res, next) => {
	console.log(`[${req.method}]\t${req.originalUrl}`);
	next();
});
app.use(bodyParser.json());


//!	GET
//	메인	curl -X GET http://localhost:3000/
app.get('/', (req, res) => {
	res.sendFile(path.join(__dirname, 'index.html'));
});

//	검색	curl -X GET "http://localhost:3000/search?keyword=abc&page=2"
app.get('/search', (req, res) => {
	const qs = JSON.stringify(req.query);
	console.log(`[GET] search: ${qs}`);
	res.send("검색 결과\n");
});

//	게시글 조회		curl -X GET http://localhost:3000/board/2
app.get('/board/:no', (req, res) => {
	const no = Number(req.params.no);
	const board = boardList.find(bd => bd.no === no);
	res.json(board);
});

//	movies 목록 조회	curl -X GET http://localhost:3000/movies
app.get('/movies', (req, res) => {
	res.send("영화 목록 데이터");
});


//!	POST
// 게시글 추가
/* curl -X POST http://localhost:3000/board \
		-H "Content-Type: application/json" \
		-d '{"title":"인셉션","content":"꿈속의 꿈"}' */
app.post('/board', (req, res) => {
	const no = boardList.length ? Math.max(...boardList.map(b => b.no)) + 1 : 1;
	const { title, content } = req.body;
	const newBoard = { no, title, content };
	boardList.push(newBoard);
	res.json({ message: '게시글 추가 완료', board: newBoard });
	console.log(boardList);
});

// movies 추가
/* curl -X POST http://localhost:3000/movies \
		-H "Content-Type: application/json" \
		-d '{"title":"인셉션","year":2010}' */
app.post('/movies', (req, res) => {
	console.log(req.body);
	res.send('영화 추가 완료');
});

//!	PUT
// 게시글 수정
/* curl -X PUT http://localhost:3000/board/2 \
		-H "Content-Type: application/json" \
		-d '{"title":"인터스텔라"}' */
app.put('/board/:no', (req, res) => {
	const no = Number(req.params.no);
	const { title } = req.body;
	const board = boardList.find(bd => bd.no === no);
	board.title = title;
	res.json({ message: '게시글 수정 완료', board });
	console.log(boardList);
});

// movies 수정
/* curl -X PUT http://localhost:3000/movies/42 \
		-H "Content-Type: application/json" \
		-d '{"title":"Interstellar"}' */
app.put('/movies/:id', (req, res) => {
	console.log(req.params.id);
	res.send('영화 수정 완료');
});


//! DELETE
// 게시글 삭제		curl -X DELETE http://localhost:3000/board/3
app.delete('/board/:no', (req, res) => {
	const no = Number(req.params.no);
	const beforeLength = boardList.length;
	boardList = boardList.filter(bd => bd.no !== no);
	res.json({ message: '게시글 삭제 완료' });
	console.log(boardList);
});

// movies 삭제		curl -X DELETE http://localhost:3000/movies/42
app.delete('/movies/:id', (req, res) => {
	console.log(req.params.id);
	res.send('영화 삭제 완료');
});


//! LISTEN
app.listen(port, () => console.log(port + '포트에서 대기 중'));


//! 기타
// 서버 프로세스 종료	lsof -ti :3000 | xargs kill -9
