#!/bin/bash
set -e

PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)"
BUILD_DIR="$PROJECT_DIR/build"
CMAKE_DIR="$PROJECT_DIR/cpp"

cmake -S "$CMAKE_DIR" -B "$BUILD_DIR"
cmake --build "$BUILD_DIR" --clean-first -j
