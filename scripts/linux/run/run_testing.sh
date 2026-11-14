#!/bin/bash
set -e

BUILD_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../build" && pwd)"
"$BUILD_DIR"/main_testing 35 0.85 100 0.1 4