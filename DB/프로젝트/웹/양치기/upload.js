// upload.js
const admin = require('firebase-admin');
const fs = require('fs');

admin.initializeApp({
  credential: admin.credential.applicationDefault(),
});
const db = admin.firestore();

async function uploadData() {
  const problems = JSON.parse(fs.readFileSync('problems.json', 'utf-8'));
  const categories = JSON.parse(fs.readFileSync('categories.json', 'utf-8'));

  for (const p of problems) {
    await db.collection('problems').doc(p.id.toString()).set(p);
  }
  for (const c of categories) {
    await db.collection('categories').doc(c.group).set(c);
  }
  console.log('Upload complete.');
}

uploadData();



// 다음을 실행
// JSON갱신:	GOOGLE_APPLICATION_CREDENTIALS="/home/solved/dev/DB/프로젝트/웹/양치기/serviceAccountKey.json" node upload.js
// HTML갱신:	firebase deploy --only hosting