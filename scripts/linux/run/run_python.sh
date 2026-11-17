#!/bin/bash
set -e

PY_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../../python" && pwd)"
python3 "$PY_DIR"/main.py
