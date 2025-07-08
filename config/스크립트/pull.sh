#!/bin/bash

clear;
echo '▲PULL 실행 '"$(date -u -d '+9 hours' '+%Y-%m-%d %H:%M:%S')" >> ~/dev/config/스크립트/.log
cd ~/dev;
git pull;
exit 0;