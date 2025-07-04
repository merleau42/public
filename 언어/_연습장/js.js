const http = require('https');

const options = {
  method: 'GET',
  hostname: 'solved.ac',
  port: null,
  path: '/api/v3/problem/show?problemId=1234',
  headers: {
    Accept: 'application/json'
  }
};

const req = http.request(options, function (res) {
  const chunks = [];

  res.on('data', function (chunk) {
    chunks.push(chunk);
  });

  res.on('end', function () {
    const body = Buffer.concat(chunks);
    console.log(body.toString());
  });
});

req.end();