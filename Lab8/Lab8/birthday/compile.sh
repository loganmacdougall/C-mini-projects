#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab8/macdougall

cp CI/objects/birthday/* Lab8/birthday/
cd Lab8/birthday/
gdb -batch -x birthday_debug
../../CI/compare-memory-outputs.sh
