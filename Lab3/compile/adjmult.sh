#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab3/macdougall

cp CI/objects/adjmult/* Lab3/adjmult/
cp -R Lab3/lib Lab3/adjmult
cd Lab3/adjmult/
gcc --std=c18 -lm -Ilib lib/mmath.c lib/mstring.c adjmult.c adjmultM.o -o adjmult
cat grid1 | ./adjmult 72297280
cat grid2 | ./adjmult 77280885
