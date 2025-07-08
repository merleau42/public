#!/bin/bash

clear;
echo '▲DEV 실행' >> log;
cd ~/dev;
git add .;
git commit -m 'Auto push';
git push;
exit 0;