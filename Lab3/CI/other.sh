#!/bin/bash

result=$(ls -a1 Lab2/ | wc -l)

if (( $result > 5 )); then
    echo "Failure. There is an extra file or directory present in Lab2/."
    exit -1
fi

echo "Lab2/ directory count correct."

result=$(ls -a1 Lab2/coins/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab2/coins/."
    exit -1
fi

echo "Lab2/coins/ file count correct."

result=$(ls -a1 Lab2/power/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab2/power/."
    exit -1
fi

echo "Lab2/power/ file count correct."

result=$(ls -a1 Lab2/triangle/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab2/triangle/."
    exit -1
fi

echo "All files correctly counted."

exit 0
