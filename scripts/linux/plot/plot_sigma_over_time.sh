#!/bin/bash
set -e

FILENAME="plot_sigma_over_time.gp"
PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../.." && pwd)"

gnuplot "$PROJECT_DIR"/plots/"$FILENAME"
