#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab3/macdougall

cp CI/objects/primes/* Lab3/primes/
cp -R Lab3/lib Lab3/primes
cd Lab3/primes/
gcc --std=c18 -lm -Ilib lib/mmath.c lib/mstring.c primes.c primesM.o -o primes
./primes > output

