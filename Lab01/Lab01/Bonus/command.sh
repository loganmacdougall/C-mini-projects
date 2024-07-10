#!/bin/bash

grep -re dinner ./one ./this ./us | cut -d ":" -f 1 | rev | cut -d "/" -f 1 | rev | sort | cut -c 3-
