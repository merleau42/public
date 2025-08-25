### 상태 표시줄 버튼 [ ▲github.io ] 스크립트
clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d_%H:%M:%S');
echo "[실행] ▲busut.cafe24app.com\t$time_kst" >> ~/dev/config/스크립트/.log;

## [ busut.cafe24app.com ]에 업로드할 내용을, 서브 폴더에 복사하기
## node_modules만 제외
# rsync -av --exclude='node_modules' ~/dev/프로젝트/서버/cafe24/busut/ ~/dev/subtree/busut/;
cp -r ~/dev/프로젝트/서버/cafe24/busut/ ~/dev/subtree;

## 로컬 디렉토리의 전부를, 메인 저장소에 먼저 add/commit/push 시킴.
## 로컬 디렉토리의 일부만 add/commit 해도 되지만, 하나하나 지정하기 번거로움.
clear; cd ~/dev; git add .; git commit -m "▲busut.cafe24app.com_$time_kst"; git push;

## 서브 폴더를 [ busut.cafe24app.com ]에 push 함.
## 로컬 파일의 삭제 여부가 저장소에는 반영되지 않는 경우 --force 플래그를 사용.
REV=$(git subtree split --prefix=subtree/busut)
git push busut777@busut.cafe24app.com:busut777_busut $REV:refs/heads/main --force

exit 0;
