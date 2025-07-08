#!/bin/bash

clear;
echo '▲DEV 실행';
cd ~/dev;
git add .;
git commit -m 'Auto push';
git push;
echo '완료' > recent;
exit 0;