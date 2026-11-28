#!/bin/bash
set -e

# Get project dir
PROJECT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/../../.." && pwd)"
cd "$PROJECT_DIR"

# Get last made dir in esot simulations
SOT_PARENT_DIR="$PROJECT_DIR"/output/sigma_over_time
START_AT_NTH_CHAR=49
LATEST_DIR=$(
    find "$SOT_PARENT_DIR" -mindepth 1 -maxdepth 1 -type d |
    sed 's|.*/||' |
    awk -v n="$START_AT_NTH_CHAR" '{ print substr($0, n + 1) "\t" $0 }' |
    sort -t "$(printf '\t')" -k1,1 |
    tail -n 1 |
    cut -f2-
)
# Validate if a dir was found
if [ -z "$LATEST_DIR" ]; then
    echo "No directories found in $SOT_PARENT_DIR" >&2
    exit 1
fi
echo "$LATEST_DIR"

# Plot files from latest dir
FILENAME="plot_sigma_over_time.gp"
gnuplot -e "data_dir='$SOT_PARENT_DIR/$LATEST_DIR'" plots/"$FILENAME"