#!/bin/bash

if [[ ! -f "build/CMakeCache.txt" ]]; then
  cmake -B build
fi

cmake --build build
if [[ "$?" == 0 ]]; then
  ./build/bin/main
fi
