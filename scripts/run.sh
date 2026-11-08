#!/bin/bash
set -e

BUILD_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../build" && pwd)"
"$BUILD_DIR"/Triangle_n 35 0.75 1 0.1 4
