#!/bin/bash
set -e

# Get project dir
PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../.." && pwd)"
cd "$PROJECT_DIR"

# Get last made dir in sot simulations
SOT_PARENT_DIR="$PROJECT_DIR"/output/sigma_over_time
LATEST_DIR=$(
    find "$SOT_PARENT_DIR" -mindepth 1 -maxdepth 1 -type d |
    sed 's|.*/||' |
    sort |
    tail -n 1
)
# Validate if a dir was found
if [ -z "$LATEST_DIR" ]; then
    echo "No directories found in $SOT_PARENT_DIR" >&2
    exit 1
fi
echo "$LATEST_DIR"

# Plot files from latest dir
FILENAME="plot_sigma_over_time.gp"
gnuplot -e "data_dir='output/sigma_over_time/$LATEST_DIR'" plots/"$FILENAME"