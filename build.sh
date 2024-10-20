#!/bin/bash
#

cd build
pwd
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
