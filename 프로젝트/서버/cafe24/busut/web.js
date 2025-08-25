const express = require('express');
const path = require('path');
const app = express();

const PORT = process.env.PORT || 8001; // Cafe24
const HOST = '0.0.0.0';

app.use(express.json());

const db = require('./db.js');

// --- API 라우트는 /api 아래로 ---
app.get('/', (req, res) => {
  res.send("cafe24 호스팅 성공");
});

app.get('/person', (req, res) => {
  db.query('select * from person', (err, rows) => {
    if (err) {
      console.error(err);
      return res.status(500).json({ error: 'DB_ERROR' });
    }
    res.json(rows);
  });
});

app.listen(PORT, () => {
  console.log(`🚀 Server running on http://${HOST}:${PORT}`);
});
