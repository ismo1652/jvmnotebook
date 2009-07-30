set terminal png transparent nocrop enhanced font arial 8 size 640,480 
set output 'andy_mandel.1.png'
set size 1,1
set key left top
set autoscale
set label 1 "Mandel execution time, over increasing mandel size" at graph 0.02, 0.85, 0 left norotate back textcolor lt 3 nopoint offset character 0, 0, 0
set xlabel 'Mandel Size'
set ylabel 'Execution Time (ms)/time func'

plot 'line_clj_sort.dat' using 1:2 title 'Java mandel size/perf time' with linespoints, '' using 1:3 title 'Clj mandel size/perf time' with linespoints 
		 