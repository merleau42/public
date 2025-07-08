#!/bin/bash

clear;
echo '▲PULL 실행 '"$(TZ='Asia/Seoul' date '+%Y-%m-%d %H:%M:%S')" >> ~/dev/config/스크립트/.log
cd ~/dev;
git pull;
exit 0;