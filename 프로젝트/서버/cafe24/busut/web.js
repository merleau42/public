// web.js (루트)
const express = require('express');
const path = require('path');
const app = express();

// 카페24가 넣어주는 PORT만 사용 (fallback 제거)
const PORT = process.env.PORT;
const HOST = '0.0.0.0';

app.use(express.json());

// 필요하면 public만 노출: app.use(express.static(path.join(__dirname, 'public')));
app.use(express.static(path.join(__dirname)));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// DB는 라우트 안에서 지연 로드 (부팅 실패 방지)
app.get('/person', (req, res) => {
  const db = require('./db.js');
  db.query('SELECT * FROM person', (err, rows) => {
    if (err) return res.status(500).json({ error: 'DB_ERROR' });
    res.json(rows);
  });
});

// 헬스체크
app.get('/__health', (req, res) => {
  res.json({ up: true, port: PORT });
});

// 호스트까지 명시
app.listen(PORT, HOST, () => {
  console.log(`✅ Listening on http://${HOST}:${PORT}`);
});
