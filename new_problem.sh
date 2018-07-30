#!/bin/bash -e
if [ "$#" -ne 1 ]; then
    echo "Usage: ./new_problem.sh <problem>"
    exit
fi

cp -r base/problem problems/$1
sed -i -e "s/<<<problem_name>>>/$1/g" problems/$1/*.sh
