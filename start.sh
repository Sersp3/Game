#!/bin/bash
cmake --build build
if [[ "$?" == 0 ]]; then
  ./build/bin/main
fi
