#!/bin/bash
set -e

EXECUTABLES_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../build/executables" && pwd)"
"$EXECUTABLES_DIR"/Triangle_n 35 0.85 100 0.1 4