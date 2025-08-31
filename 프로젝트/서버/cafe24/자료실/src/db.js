// src/db.js
const mysql = require('mysql2');
require('dotenv').config();

const pool = mysql.createPool({
  host: process.env.DB_HOST || 'busut.cafe24app.com',
  user: process.env.DB_USER || 'busut777',
  password: 'qkrdowlstlf2@',
  database: process.env.DB_NAME || 'busut777',
  port: parseInt(process.env.DB_PORT || '3306', 10),
  waitForConnections: true,
  connectionLimit: 10,
  queueLimit: 0,
  charset: 'utf8mb4'
});

// promise()를 붙여서 async/await 사용
const promisePool = pool.promise();

async function query(sql, params) {
  const [rows] = await promisePool.query(sql, params);
  return rows;
}

module.exports = { pool, query };
