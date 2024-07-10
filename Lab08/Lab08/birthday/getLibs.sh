#!/bin/bash

# The Lab folder
LABFOLDER="/users/cs/macdougall/Courses/CSCI2122/Labs"
# Folder that stores all the libraries
LIBFOLDER="${LABFOLDER}/libs"
# Script which will grabs the libraries for you
GRABSCRIPT="${LABFOLDER}/grablibs.sh"

# These are the libraries you want to grab
# *** USER INPUT ***
LIBRARIES=""

# If no libraries are specified, nothing needs to be done
if [ "${LIBRARIES}" == "" ]; then
    exit 0

# if a star is used (*), grab all the libraries
elif [ "${LIBRARIES}" == "*" ]; then
    ${GRABSCRIPT}

# Otherwise, grab the libraries specified
else
    ${GRABSCRIPT} ${LIBRARIES}
fi
