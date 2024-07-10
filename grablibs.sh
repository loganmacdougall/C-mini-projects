#!/bin/bash

# Folder that stores all the libraries
LIBFOLDER="~/Courses/CSCI2122/Labs/libs"

# Delete the current lib folder
if [ -d lib ]; then
    rm -r lib
fi

# If not given any arguments, copy over all the libraries
if [ $# == 0 ]; then
    cp -r ${LIBFOLDER} $(pwd)/lib
# Otherwise, only copy over the libraries being asked for
else
    mkdir ./lib
    for arg in $@; do
	cp ${LIBFOLDER}/${arg}.h ./lib/${arg}.h
	cp ${LIBFOLDER}/${arg}.c ./lib/${arg}.c
    done
fi

