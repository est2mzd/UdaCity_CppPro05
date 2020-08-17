#!/bin/bash

if [ -e ./a.out ]; then
   rm ./a.out
   echo "------ delete a.out ------"
fi

echo "------ compiling -------  "
g++ -std=c++11 test.cpp ../src/block_single.cpp ../src/block_multi.cpp

echo "----- run a.out ------- "
./a.out
