######## 서브 저장소에 업로드할 내용을, 커밋 역할을 하는 폴더에 복사하기
./copy.sh


####### 전체 내용을 메인 저장소에 먼저 add/commit/push 함.
clear; cd ~/dev; git add .; git commit -m "update"; git push;


####### 메인 commit 정보와, subtree 기능을 사용하여, 로컬의 일부 디렉토리만 서브 저장소에 push 함.
git subtree push --prefix=subtree/github.io https://github.com/merleau42/public main

