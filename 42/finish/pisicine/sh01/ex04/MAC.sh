#!/bin/sh
ifconfig | grep "ether " | sed 's/[ \t]\+ether //g' | sed 's/ .\+//g'