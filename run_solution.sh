#!/bin/bash
if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit
fi

problems/$1/build/launch < problems/$1/tests/large.txt
