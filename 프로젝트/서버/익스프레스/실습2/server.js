const express = require('express');
const app = express();
const port = 3000;

const db = require('./config/db.js');


app.get('/', (req, res) => {
	res.send('Hello World!');
});

app.get('/person', (req, res) => {
	db.query('select * from person', (err, rows) => {
		if (err)
			console.log(err);
		else {
			console.log(rows);
			res.send(rows);
		}
	})
});

app.listen(port, () => {
	console.log(port, '번 포트에서 대기 중');
})
