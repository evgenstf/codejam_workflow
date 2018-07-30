#!/bin/bash
if [ "$#" -ne 2 ]; then
    echo "Usage: ./run_solution.sh <problem> <test>"
    exit
fi

time problems/$1/build/launch < problems/$1/tests/$2.txt > problems/$1/answers/$2.ans

echo "----------------------------"
head problems/$1/answers/$2.ans
