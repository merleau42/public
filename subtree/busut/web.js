const express = require('express');
const cors = require('cors');
const os = require('os');
const app = express();
const port = 8001;

const db = require('./db.js');

app.use(cors()); // 모든 요청 허용 (개발용)

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

// 로컬 IP 얻기 함수
function getLocalIP() {
  const nets = os.networkInterfaces();
  for (const name of Object.keys(nets)) {
    for (const net of nets[name]) {
      if (net.family === 'IPv4' && !net.internal) {
        return net.address;
      }
    }
  }
  return '127.0.0.1';
}

app.listen(port, () => {
  const localIP = getLocalIP();
  console.log(`서버 실행 중:`);  
  console.log(`- Local:   http://localhost:${port}`);
  console.log(`- Network: http://${localIP}:${port}`);
});
