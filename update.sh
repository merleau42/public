#터미널 입력:  ./update.sh


cp -r ~/dev/DB/프로젝트/게임/자바스크립트/빼빼로줍기/ ./게임;
cp -r ~/dev/DB/프로젝트/프론트엔드/릴레이/끝말잇기/ ./게임;
cp -r ~/dev/DB/프로젝트/프론트엔드/릴레이/연속변환기/ ./프론트엔드;
cp -r ~/dev/DB/프로젝트/프론트엔드/테이블/스프레드시트/ ./프론트엔드;

git add .;
git commit -m 'update';
git push;

clear;
echo "확인(컨트롤 클릭): https://github.com/merleau42/public";