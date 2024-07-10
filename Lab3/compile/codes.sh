#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab3/macdougall

cp CI/objects/codes/* Lab3/codes/
cp -R Lab3/lib Lab3/codes
cd Lab3/codes/
gcc --std=c18 -lm -Ilib lib/mmath.c lib/mstring.c codes.c codesM.o -o codes
test -f codes
./codes
