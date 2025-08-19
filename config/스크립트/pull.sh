#!/bin/bash

clear;

time_kst=$(date -u -d '+9 hours' '+%Y-%m-%d %H:%M:%S');
echo "[실행] ▼PULL\t$time_kst" >> ~/dev/config/스크립트/.log;
cd ~/dev;
git pull;
exit 0;