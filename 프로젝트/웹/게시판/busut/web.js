const express = require('express');
const path = require('path');
const app = express();

const PORT = process.env.PORT || 8001; // Cafe24가 주는 PORT 사용
const HOST = '0.0.0.0';

app.use(express.json());

const db = require('./db.js');

// --- API 라우트는 /api 아래로 ---
app.get('/api/health', (req, res) => {
  res.json({ ok: true, env: process.env.NODE_ENV || 'dev' });
});

app.get('/api/person', (req, res) => {
  db.query('select * from person', (err, rows) => {
    if (err) {
      console.error(err);
      return res.status(500).json({ error: 'DB_ERROR' });
    }
    res.json(rows);
  });
});

// --- CRA 빌드 정적 서빙 ---
const buildPath = path.join(__dirname, 'build');
app.use(express.static(buildPath));

// --- SPA 라우팅: 마지막에, API 뒤에 위치 ---
app.get('*', (req, res) => {
  res.sendFile(path.join(buildPath, 'index.html'));
});

app.listen(PORT, HOST, () => {
  console.log(`🚀 Server running on http://${HOST}:${PORT}`);
});
