// web.js — 진단용 (Express 제거, 포트/호스트 고정)
const http = require('http');
const os = require('os');

const PORT = 8001;               // ★ 당신 계정의 고정 포트(메일에 8001)
const HOST = '0.0.0.0';          // ★ 외부에서 붙게끔

const handler = (req, res) => {
  if (req.url === '/__health') {
    const payload = JSON.stringify({
      up: true,
      ts: new Date().toISOString(),
      host: HOST,
      port: PORT,
      node: process.version,
      pid: process.pid
    });
    res.writeHead(200, { 'Content-Type': 'application/json' });
    return res.end(payload);
  }

  // 최소 응답 (index.html 없이도 동작 확인)
  res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
  res.end('OK: raw http server\n');
};

const server = http.createServer(handler);

server.listen(PORT, HOST, () => {
  console.log(`[RAW] listening on http://${HOST}:${PORT}`);
});

// 크래시 방지용 로그
process.on('uncaughtException', (e) => console.error('[uncaughtException]', e));
process.on('unhandledRejection', (e) => console.error('[unhandledRejection]', e));
