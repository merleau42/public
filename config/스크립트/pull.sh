#!/bin/bash

clear;

time_kst=$(TZ='Asia/Seoul' date '+%Y-%m-%d %H:%M:%S');
echo "▼PULL 실행 $time_kst" >> ~/dev/config/스크립트/.log;
cd ~/dev;
git pull;
exit 0;