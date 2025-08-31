// Cafe24 expects the entry file to be named web.js and to listen on your assigned port (often 8001)
const express = require('express');
const path = require('path');
const fs = require('fs');
const morgan = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
const rateLimit = require('express-rate-limit');
const multer = require('multer');
const jwt = require('jsonwebtoken');
const bcrypt = require('bcryptjs');
require('dotenv').config();

const { query } = require('./src/db');
const { authRequired } = require('./src/auth');
const { buildFileUrl, sanitizeFilename } = require('./src/utils');

const app = express();
const PORT = parseInt(process.env.PORT || '8001', 10);
const UPLOAD_DIR = process.env.UPLOAD_DIR || 'uploads';

// Ensure upload dir exists
if (!fs.existsSync(UPLOAD_DIR)) fs.mkdirSync(UPLOAD_DIR, { recursive: true });

const upload = multer({
  storage: multer.diskStorage({
    destination: (req, file, cb) => cb(null, UPLOAD_DIR),
    filename: (req, file, cb) => {
      const ext = path.extname(file.originalname);
      const base = path.basename(file.originalname, ext);
      const safe = sanitizeFilename(base);
      const stamp = Date.now() + '-' + Math.round(Math.random()*1e9);
      cb(null, `${safe}-${stamp}${ext}`);
    }
  }),
  limits: { fileSize: 20 * 1024 * 1024 }, // 20MB
});

// Middlewares
app.use(helmet());
app.use(cors());
app.use(morgan('combined'));
app.use(express.json({ limit: '2mb' }));
app.use(express.urlencoded({ extended: true }));
app.use('/uploads', express.static(path.join(__dirname, UPLOAD_DIR)));

// Health check
app.get('/health', (req, res) => res.json({ ok: true }));

// -------- Auth --------
// Register (for first admin account). Consider disabling this after creating your account.
app.post('/api/auth/register', async (req, res) => {
  const { email, password } = req.body;
  if (!email || !password) return res.status(400).json({ error: 'email and password required' });
  const hash = await bcrypt.hash(password, 10);
  try {
    await query('INSERT INTO users (email, password_hash) VALUES (?, ?)', [email, hash]);
    res.json({ ok: true });
  } catch (e) {
    res.status(400).json({ error: 'email already exists?' });
  }
});

app.post('/api/auth/login', async (req, res) => {
  const { email, password } = req.body;
  const users = await query('SELECT * FROM users WHERE email = ?', [email]);
  const user = users[0];
  if (!user) return res.status(401).json({ error: 'invalid credentials' });
  const ok = await bcrypt.compare(password, user.password_hash);
  if (!ok) return res.status(401).json({ error: 'invalid credentials' });
  const token = jwt.sign({ id: user.id, email: user.email }, process.env.JWT_SECRET, { expiresIn: '7d' });
  res.json({ token });
});

// -------- Posts CRUD --------
app.get('/api/posts', async (req, res) => {
  const posts = await query('SELECT p.id, p.title, p.content, p.created_at, p.updated_at, u.email as author FROM posts p JOIN users u ON u.id = p.user_id ORDER BY p.id DESC', []);
  res.json(posts);
});

app.get('/api/posts/:id', async (req, res) => {
  const postId = parseInt(req.params.id, 10);
  const posts = await query('SELECT p.*, u.email as author FROM posts p JOIN users u ON u.id = p.user_id WHERE p.id = ?', [postId]);
  if (!posts[0]) return res.status(404).json({ error: 'not found' });
  const files = await query('SELECT id, original_name, stored_name, mime_type, size, path FROM files WHERE post_id = ? ORDER BY id DESC', [postId]);
  res.json({ ...posts[0], files });
});

app.post('/api/posts', authRequired, async (req, res) => {
  const { title, content } = req.body;
  if (!title) return res.status(400).json({ error: 'title required' });
  const result = await query('INSERT INTO posts (user_id, title, content) VALUES (?, ?, ?)', [req.user.id, title, content || '']);
  res.json({ id: result.insertId });
});

app.put('/api/posts/:id', authRequired, async (req, res) => {
  const postId = parseInt(req.params.id, 10);
  const rows = await query('SELECT * FROM posts WHERE id = ?', [postId]);
  if (!rows[0]) return res.status(404).json({ error: 'not found' });
  if (rows[0].user_id !== req.user.id) return res.status(403).json({ error: 'forbidden' });
  const { title, content } = req.body;
  await query('UPDATE posts SET title = ?, content = ? WHERE id = ?', [title ?? rows[0].title, content ?? rows[0].content, postId]);
  res.json({ ok: true });
});

app.delete('/api/posts/:id', authRequired, async (req, res) => {
  const postId = parseInt(req.params.id, 10);
  const rows = await query('SELECT * FROM posts WHERE id = ?', [postId]);
  if (!rows[0]) return res.status(404).json({ error: 'not found' });
  if (rows[0].user_id !== req.user.id) return res.status(403).json({ error: 'forbidden' });
  await query('DELETE FROM posts WHERE id = ?', [postId]);
  res.json({ ok: true });
});

// -------- File Upload --------
app.post('/api/upload', authRequired, upload.single('file'), async (req, res) => {
  const file = req.file;
  if (!file) return res.status(400).json({ error: 'no file' });
  const postId = req.body.postId ? parseInt(req.body.postId, 10) : null;
  const storedName = path.basename(file.filename);
  const filePath = `/uploads/${storedName}`;
  const result = await query(
    'INSERT INTO files (user_id, post_id, original_name, stored_name, mime_type, size, path) VALUES (?, ?, ?, ?, ?, ?, ?)',
    [req.user.id, postId, file.originalname, storedName, file.mimetype, file.size, filePath]
  );
  res.json({
    id: result.insertId,
    url: buildFileUrl(req, storedName),
    original_name: file.originalname,
    size: file.size,
    mime_type: file.mimetype,
    post_id: postId
  });
});

app.get('/api/files/:id', async (req, res) => {
  const id = parseInt(req.params.id, 10);
  const rows = await query('SELECT * FROM files WHERE id = ?', [id]);
  if (!rows[0]) return res.status(404).json({ error: 'not found' });
  const file = rows[0];
  res.json({
    id: file.id,
    original_name: file.original_name,
    url: buildFileUrl(req, file.stored_name),
    mime_type: file.mime_type,
    size: file.size,
    post_id: file.post_id
  });
});

// Basic limiter to keep your app safe
const limiter = rateLimit({ windowMs: 60 * 1000, max: 120 });
app.use(limiter);

// -------------- Start --------------
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
