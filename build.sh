#!/bin/bash
#

cd ~/ws/proj/src/cpp/game_engine/build
pwd
# rm -rf *
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
