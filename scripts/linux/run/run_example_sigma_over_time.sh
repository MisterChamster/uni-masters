#!/bin/bash
set -e

BUILD_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../build" && pwd)"
"$BUILD_DIR"/example_sigma_over_time