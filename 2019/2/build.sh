#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "Usage: ./build.sh <problem>"
    exit
fi

g++ problems/$1/solution.cpp -o problems/$1/build/$1_launch -std=c++14 -pthread -O3 -DDEBUG
