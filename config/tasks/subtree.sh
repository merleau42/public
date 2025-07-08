## 서브 저장소에 업로드할 내용을, 커밋 역할 폴더에 복사하기
./copy.sh

## 로컬 저장소의 전체 파일을 메인 저장소에 먼저 add/commit/push 함.
## 일부 디렉토리만 add/commit 해도 되지만, 하나하나 지정하기 번거로움.
clear; cd ~/dev; git add .; git commit -m "$(date '+%Y-%m-%d %H:%M:%S')"; git push;

## 디렉토리 commit 내용과, subtree 기능을 통해, 로컬 저장소의 일부 디렉토리만 서브 저장소에 push 함.
git subtree push --prefix=subtree/github.io https://github.com/merleau42/public main
