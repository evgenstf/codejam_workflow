#!/bin/bash

mkdir bin 2> /dev/null
g++ base_solution/solution.cpp -o bin/solution -std=c++17 -pthread
