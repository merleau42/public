// web.js
const express = require('express');
const path = require('path');
const app = express();

const PORT = process.env.PORT;
const HOST = '0.0.0.0';

app.use(express.json());

app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// ★ DB는 라우트 안에서 지연 로드 (부팅 실패 방지)
app.get('/person', (req, res) => {
  const db = require('./db.js');
  db.query('SELECT * FROM person', (err, rows) => {
    if (err) return res.status(500).json({ error: 'DB_ERROR' });
    res.json(rows);
  });
});

// (선택) 헬스체크
app.get('/__health', (req, res) => {
  res.json({ up: true, port: PORT });
});

app.listen(PORT, HOST, () => {
  console.log(`🚀 Server running on http://${HOST}:${PORT}`);
});
