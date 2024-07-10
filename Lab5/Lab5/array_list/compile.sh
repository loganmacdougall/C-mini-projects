#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab5/macdougall

cp CI/objects/array_list/arrayM.o Lab5/array_list/
cd Lab5/array_list/
make
test -f array_list.o
test -f array_list
./array_list
