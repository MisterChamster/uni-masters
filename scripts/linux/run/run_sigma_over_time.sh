#!/bin/bash
set -e

BUILD_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../build" && pwd)"
"$BUILD_DIR"/sigma_over_time "KITTY_FILEEEEE1"