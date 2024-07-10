#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab9/macdougall

cp CI/objects/pool/* Lab9/pool/
cd Lab9/pool/
./getLibs.sh
rm -f pool
make
./pool > pool_out
../../CI/compare-pool-outputs.sh

