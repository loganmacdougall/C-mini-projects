#!/bin/bash

cd ~/Courses/CSCI2122/Labs/Lab6/macdougall

cp CI/objects/bintree/* Lab6/bintree/
cd Lab6/bintree/
rm -f bintree.o bintree
rm -f intree pretree posttree revtree
make
./bintree
./intree > in_out
./pretree > pre_out
./posttree > post_out
./revtree > rev_out
../../CI/compare-expected-files.sh
