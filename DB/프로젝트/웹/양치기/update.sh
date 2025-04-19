echo "JSON 업데이트";
GOOGLE_APPLICATION_CREDENTIALS="/home/solved/dev/DB/프로젝트/웹/양치기/serviceAccountKey.json" node upload.js;

echo "HTML 업데이트";
firebase deploy --only hosting;