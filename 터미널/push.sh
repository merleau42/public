#!/bin/bash

clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d %H:%M:%S');
echo "[실행] ▲PUSH\t$time_kst" >> ~/dev/터미널/.log;
cd ~/dev;
git add .; git commit -m "▲PUSH $time_kst"; git push;
exit 0;