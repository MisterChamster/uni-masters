#!/bin/bash
set -e

PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../.." && pwd)"
EXECUTABLES_DIR="$PROJECT_DIR/build/executables"
CMAKE_DIR="$PROJECT_DIR/cpp"

cmake -S "$CMAKE_DIR" -B "$EXECUTABLES_DIR"
cmake --build "$EXECUTABLES_DIR" --clean-first -j
