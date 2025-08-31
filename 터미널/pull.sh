#!/bin/bash

clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d %H:%M:%S');
echo "[실행] ▼PULL\t$time_kst;" # pull은 로그 남기지 않기;
cd ~/dev;
git pull;
exit 0;