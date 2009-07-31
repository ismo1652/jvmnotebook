set terminal png
set output 'gc_1.png'
set title 'GC results'
set size 1,1
set key left top
set autoscale
# stats 1
#set xlabel 'gc_iter (gc iterations)'
#set ylabel 'gc_end_occ (total available space)'

set xlabel 'gc_iter (gc iterations)'
set ylabel 'gc heap memory (in xxx-xxxxx k)'

plot 'image_gc_analysis.txt' using 0:1 title 'Mandel GC Results Clj (used mem)' with linespoints, 'image_gc_analysis.txt' using 0:2 title 'Mandel GC Results Clj (total)' with linespoints 