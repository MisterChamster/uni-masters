#!/bin/bash
cd ..
cmake -S . -B build
cmake --build build --clean-first
./build/Triangle_n
cd debug