const functions = require('firebase-functions');
const fetch = require('node-fetch');
const { JSDOM } = require('jsdom');

exports.getPage = functions.https.onRequest(async (req, res) => {
  const { url, code } = req.body;

  try {
    const html = await fetch(url).then(r => r.text());
    const dom = new JSDOM(html);
    const document = dom.window.document;

    const fn = new Function('document', code);
    const result = fn(document);

    res.send({ result });
  } catch (err) {
    res.status(500).send({ error: err.message });
  }
});