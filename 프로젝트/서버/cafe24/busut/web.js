const express = require('express');
const path = require('path');
const app = express();

const PORT = process.env.PORT || 8001; // Cafe24
const HOST = '0.0.0.0';

app.use(express.json());

// const db = require('./db.js');

// 정적 파일 서비스 (index.html 포함)
app.use(express.static(path.join(__dirname)));

// 루트 라우트 → index.html 자동 응답
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

// app.get('/person', (req, res) => {
//   db.query('select * from person', (err, rows) => {
//     if (err) {
//       console.error(err);
//       return res.status(500).json({ error: 'DB_ERROR' });
//     }
//     console.log(rows);
//     res.json(rows);
//   });
// });

app.listen(PORT, () => {
  console.log(`🚀 Server running on http://${HOST}:${PORT}`);
});
