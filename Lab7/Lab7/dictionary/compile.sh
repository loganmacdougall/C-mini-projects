#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab7/macdougall

cp CI/objects/dictionary/dictM.o Lab7/dictionary/
cd Lab7/dictionary/
./getLibs.sh
rm -f dictionary.o dictionary
make
./dictionary
