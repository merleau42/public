// upload.js
const admin = require('firebase-admin');
const fs = require('fs');

admin.initializeApp({
  credential: admin.credential.applicationDefault(),
});
const db = admin.firestore();

async function uploadData() {
  const problems = JSON.parse(fs.readFileSync('problems.json', 'utf-8'));
  const categories = JSON.parse(fs.readFileSync('category.json', 'utf-8'));

  for (const p of problems) {
    await db.collection('problems').doc(p.id.toString()).set(p);
  }
  for (const c of categories) {
    await db.collection('categories').add(c);
  }
  console.log('Upload complete.');
}

uploadData();



