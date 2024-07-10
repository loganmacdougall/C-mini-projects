#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab4/macdougall

cp CI/objects/book/* Lab4/book/
cd Lab4/book/
gcc --std=c18 book.c bookM.o -o book
./book i_must_scream
./book shadow_over_innsmouth
../../CI/compare-book-files.sh
