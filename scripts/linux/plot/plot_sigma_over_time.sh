#!/bin/bash
set -e

FILENAME="plot_sigma_over_time.gp"
PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../.." && pwd)"

cd "$PROJECT_DIR"
gnuplot plots/"$FILENAME"