clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d %H:%M:%S');
echo "▲github.io 실행 $time_kst" >> ~/dev/config/스크립트/.log

## 서브 저장소에 업로드할 내용을, 커밋 역할 폴더에 복사하기
# 게임
    cp -r ~/dev/프로젝트/게임/바닐라JS/라이어단어/		~/dev/subtree/github.io/게임;
    cp -r ~/dev/프로젝트/게임/바닐라JS/라이어발언/		~/dev/subtree/github.io/게임;
    cp -r ~/dev/프로젝트/게임/바닐라JS/빼빼로줍기/		~/dev/subtree/github.io/게임;
    cp -r ~/dev/프로젝트/게임/바닐라JS/카츄/			~/dev/subtree/github.io/게임;
    cp -r ~/dev/프로젝트/웹/릴레이/끝말잇기/			~/dev/subtree/github.io/게임;
# 알고리즘
    cp -r ~/dev/프로젝트/웹/양치기/						~/dev/subtree/github.io/알고리즘;
# 프론트엔드
    cp -r ~/dev/프로젝트/웹/릴레이/연속변환기/			~/dev/subtree/github.io/프론트엔드;
    cp -r ~/dev/프로젝트/웹/테이블/스프레드시트/		~/dev/subtree/github.io/프론트엔드;
    cp -r ~/dev/프로젝트/웹/계산기/						~/dev/subtree/github.io/프론트엔드;
# index.html에 관련 항목을 반영할 것 (subtree/github.io/index.html)

## 로컬 저장소의 전체 파일을 메인 저장소에 먼저 add/commit/push 함.
## 일부 디렉토리만 add/commit 해도 되지만, 하나하나 지정하기 번거로움.
clear; cd ~/dev; git add .; git commit -m "▲GIO $time_kst"; git push;

## 로컬 저장소의 일부 디렉토리만 서브 저장소에 push 함.
REV=$(git subtree split --prefix=subtree/github.io)
git push https://github.com/merleau42/public $REV:main



exit 0;