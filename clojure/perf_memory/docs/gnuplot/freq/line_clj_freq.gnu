set terminal png transparent nocrop enhanced font arial 8 size 640,480 
set output 'line_clj_freq.1.png'
set size 1,1
set key left top
set autoscale
set label 1 "Generate plot labels from first row in each column" at graph 0.02, 0.85, 0 left norotate back textcolor lt 3 nopoint offset character 0, 0, 0
set xlabel 'gc_iter'
set ylabel 'gc_main_paus_time'
#plot 'line_clj_freq.dat' using 1:2 title 'GC Results' with linespoints, 'line_java_freq.dat' using 1:0 title 'GC Results' with linespoints 		

plot 'line_clj_freq.dat' using 1:2 title 'GC Results' with linespoints, 'line_java_freq.dat' using 1:2 title 'GC Results' with linespoints, 'line_jruby_freq.dat' using 1:2 title 'GC Results' with linespoints 
		 