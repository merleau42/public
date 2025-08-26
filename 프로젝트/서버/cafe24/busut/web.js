// web.js (루트)
const express = require('express');
const path = require('path');
const app = express();

const PORT = process.env.PORT;
const HOST = '0.0.0.0';

const db = require('./db.js');

app.use(express.json());
app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// DB는 라우트 안에서 지연 로드 (부팅 실패 방지)
app.get('/person', (req, res) => {
  db.query('SELECT * FROM person', (err, rows) => {
    if (err) return res.status(500).json({ error: 'DB_ERROR' });
    res.json(rows);
  });
});

// 호스트까지 명시
app.listen(PORT, HOST, () => {
  console.log(`✅ Listening on http://${HOST}:${PORT}`);
});
