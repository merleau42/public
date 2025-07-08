#!/bin/bash

cd ~/dev || exit 1
git add .
git commit -m "▲DEV"
git push

# 종료를 유도하는 명령
echo "작업 완료. 터미널은 자동으로 닫힙니다"
sleep 1
exit
