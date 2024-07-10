#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab3/macdougall

cp CI/objects/pascal/* Lab3/pascal/
cp -R Lab3/lib Lab3/pascal/
cd Lab3/pascal/
gcc --std=c18 -lm -Ilib lib/mmath.c lib/mstring.c pascal.c pascalM.o -o pascal
./pascal > output
