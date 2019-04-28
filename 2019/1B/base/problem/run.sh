#!/bin/bash
echo "build solution"
cd ../../
./build.sh <<<problem_name>>>
cd -

echo "start solution"
build/<<<problem_name>>>_launch
