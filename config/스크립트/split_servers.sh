### 상태 표시줄 버튼 [ ▲Servs ] 스크립트
clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d_%H:%M:%S');
echo "[실행] ▲Servs\t$time_kst" >> ~/dev/config/스크립트/.log;

WEB=~/dev/프로젝트/웹;
DIR=~/dev/subtree/servers;

## [ servers ]에 업로드할 내용을, 서브 폴더에 복사하기
rsync -av --exclude='node_modules' "$WEB/확장프로그램/metaberse/server/" "$DIR/metaberse/server/";
#  cp -r "$WEB/확장프로그램/metaberse/server/"		"$DIR/metaberse";

## 로컬 디렉토리의 전부를, 메인 저장소에 먼저 add/commit/push 시킴.
## 로컬 디렉토리의 일부만 add/commit 해도 되지만, 하나하나 지정하기 번거로움.
clear; cd ~/dev; git add .; git commit -m "▲Servs_$time_kst"; git push;

## 서브 폴더를 [ Servers ]에 push 함.
## 로컬 파일의 삭제 여부가 저장소에는 반영되지 않는 경우 --force 플래그를 사용.
REV=$(git subtree split --prefix=subtree/servers)
git push https://github.com/merleau42/servers.git $REV:refs/heads/main --force

exit 0;
