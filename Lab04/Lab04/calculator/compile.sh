#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab4/macdougall

cp CI/objects/calculator/* Lab4/calculator/
cd Lab4/calculator/
gcc --std=c18 calculator.c calculatorM1.o -o calc1
gcc --std=c18 calculator.c calculatorM2.o -o calc2
./calc1 input1 > output1_1
./calc1 input2 > output1_2
./calc2 input1 > output2_1
./calc2 input2 > output2_2
../../CI/compare-calc-files.sh

