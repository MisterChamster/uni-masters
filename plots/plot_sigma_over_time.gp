set title "Sigma change over time"
set xlabel "T turns"
set ylabel "Sigma"
set grid
set key bottom right

plot "output/sigma_over_time/sigma_over_time.txt" index 0 using 1:2 with linespoints title "p = 0.25", \
     "output/sigma_over_time/sigma_over_time.txt" index 1 using 1:2 with linespoints title "p = 0.50", \
     "output/sigma_over_time/sigma_over_time.txt" index 2 using 1:2 with linespoints title "p = 0.75", \
     "output/sigma_over_time/sigma_over_time.txt" index 3 using 1:2 with linespoints title "p = 1"

pause -1
