#!/bin/bash

totalLines=0

totalLines=$(expr ${totalLines} + $(wc -l level_dead | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l startegy_dead | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l power_dead | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l charm_dead | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l subtlety_dead | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l level_alive | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l startegy_alive | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l power_alive | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l charm_alive | cut -d ' ' -f1))
totalLines=$(expr ${totalLines} + $(wc -l subtlety_alive | cut -d ' ' -f1))

echo The total number of heroes counted were $totalLines

if [ $totalLines == 1500 ]; then
    echo You printed the correct number of heroes
else
    echo You should have printed 1500 heroes
    exit 101
fi

