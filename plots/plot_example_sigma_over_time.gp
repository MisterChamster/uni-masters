set title "Example sigma change over time"
set xlabel "T turns"
set ylabel "Sigma"
set grid
set key bottom right

files = system("find '" . data_dir . "' -maxdepth 1 -name '*.txt' | sort")
plot for [file in files] file using 1:2 with lines \
    title system("basename '" . file . "' .txt | sed 's/\.txt$//'")

pause -1
