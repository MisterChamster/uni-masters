#!/bin/bash
cd ..
cmake -S . -B build
cmake --build build
cd debug