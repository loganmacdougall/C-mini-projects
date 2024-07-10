#!/bin/bash

result=$(ls -a1 Lab3/ | wc -l)

if (( $result > 7 )); then
    echo "Failure. There is an extra file or directory present in Lab3/."
    exit -1
fi

echo "Lab3/ directory count correct."

result=$(ls -a1 Lab3/adjmult/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab3/adjmult/."
    exit -1
fi

echo "Lab3/adjmult/ file count correct."

result=$(ls -a1 Lab3/codes/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab3/codes/."
    exit -1
fi

echo "Lab3/codes/ file count correct."

result=$(ls -a1 Lab3/lib/ | wc -l)
if (( $result > 6 )); then
    echo "Failure. There is an extra file or directory present in Lab3/lib/."
    exit -1
fi

echo "Lab3/lib/ file count correct."

result=$(ls -a1 Lab3/pascal/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab3/pascal/."
    exit -1
fi

echo "Lab3/pascal/ file count correct."

result=$(ls -a1 Lab3/primes/ | wc -l)
if (( $result > 4 )); then
    echo "Failure. There is an extra file or directory present in Lab3/primes/."
    exit -1
fi

echo "Lab3/primes/ file count correct."

echo "All files correctly counted."

exit 0

