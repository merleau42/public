#!/bin/bash

clear;

time_kst=$(TZ='Asia/Seoul' date '+%Y-%m-%d %H:%M:%S');
echo "▲PUSH 실행 $time_kst" >> ~/dev/config/스크립트/.log;
cd ~/dev;
git add .; git commit -m "▲PUSH $time_kst"; git push;
exit 0;