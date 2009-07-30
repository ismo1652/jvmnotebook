set terminal png transparent nocrop enhanced font arial 8 size 640,480 
set output 'line_scala_freq.1.png'
set size 1,1
set key left top
set autoscale
set label 1 "Execution time including Scala, over increasing N number of iterations" at graph 0.02, 0.85, 0 left norotate back textcolor lt 3 nopoint offset character 0, 0, 0
set xlabel 'Iterations'
set ylabel 'Execution Time (ms)'
#plot 'line_clj_freq.dat' using 1:2 title 'GC Results' with linespoints, 'line_java_freq.dat' using 1:0 title 'GC Results' with linespoints 		

plot 'line_clj_sort.dat' using 1:2 title 'CLJ iterations/perf time' with linespoints, 'line_java_sort.dat' using 1:2 title 'Java iterations/perf time' with linespoints, 'line_scala_sort.dat' using 1:2 title 'Scala iterations/perf time' with linespoints 
		 