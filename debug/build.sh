#!/bin/bash
cd ..
cmake -S . -B build
cmake --build build --clean-first
cd debug