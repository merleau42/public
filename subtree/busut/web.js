const express = require('express');
const app = express();
const port = 8001;

const db = require('./db.js');


app.get('/', (req, res) => {
  res.send('cafe24에 호스팅 성공');
});

app.get('/person', (req, res) => {
  db.query('select * from person', (err, rows) => {
    if (err)
      console.log(err);
    else {
      console.log(rows);
      res.send(rows);
    }
  });
});

app.listen(port, () => {
  console.log(`서버 실행 중:`);  
});
