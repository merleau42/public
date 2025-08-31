const path = require('path');

function buildFileUrl(req, storedName) {
  const base = process.env.BASE_URL || `${req.protocol}://${req.get('host')}`;
  return `${base}/uploads/${encodeURIComponent(storedName)}`;
}

function sanitizeFilename(name) {
  return name.replace(/[^a-zA-Z0-9._-]+/g, '_').slice(0, 200);
}

module.exports = { buildFileUrl, sanitizeFilename };
