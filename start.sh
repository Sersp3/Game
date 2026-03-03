#!/bin/bash

if [[ ! -f "build/CMakeCache.txt" ]]; then
  cmake -B build
  if [[ "$?" != 0 ]]; then
    echo "Program didn't pass setting the enviroment\n"
    exit 1 

fi

cmake --build build
if [[ "$?" == 0 ]]; then
  ./build/bin/main
else; then
  echo "Programm didn't pass the build\n"
  exit 1
fi
