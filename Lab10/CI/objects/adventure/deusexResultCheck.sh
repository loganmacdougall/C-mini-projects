#!/bin/bash

alive=$(wc -l deusex_alive | cut -d ' ' -f1)
dead=$(wc -l deusex_dead | cut -d ' ' -f1)

if [ $alive == 280 ]; then
    echo You have the correct number of living heroes
else
    echo You should have 280 heroes alive, but you have $alive dead
    exit 101
fi

if [ $dead == 20 ]; then
    echo You have the correct number of dead heroes
else
    echo You should have 20 heroes dead, but you have $dead dead
    exit 101
fi
