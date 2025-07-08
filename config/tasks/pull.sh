#!/bin/bash

clear;
echo '▲PULL 실행' >> ~/dev/config/tasks/.log;
cd ~/dev;
git pull;
exit 0;