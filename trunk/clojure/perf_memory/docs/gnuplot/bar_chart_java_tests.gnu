set terminal png transparent nocrop enhanced font arial 8 size 640,480 
set output 'chart1_java.5.png'
set boxwidth 0.6 absolute
set style fill   solid 1.00 border -1
set grid nopolar
set grid noxtics nomxtics ytics nomytics noztics nomztics \
 nox2tics nomx2tics noy2tics nomy2tics nocbtics nomcbtics
set grid layerdefault   linetype 0 linewidth 1.000,  linetype 0 linewidth 1.000
set key inside right top vertical Right noreverse enhanced autotitles columnhead nobox
set pointsize 2
set xtics border in scale 0,0 mirror norotate  offset character 0, 0, 0
set xtics  ( "hello1" 0.00000, "build2" 1.00000, "string3" 2.00000, "euler4" 3.00000, "euler5" 4.0, "str6" 5.0, "math7" 6.0, "coll8" 7.0, "frac9" 8.0, "sort11" 9.0, "wide13" 10.0 ) 
set ytics border in scale 0,0 mirror norotate  offset character 0, 0, 0 autofreq 
set ztics border in scale 0,0 nomirror norotate  offset character 0, 0, 0 autofreq 
set cbtics border in scale 0,0 mirror norotate  offset character 0, 0, 0 autofreq 
set title "Plot java performance tests" 
set xrange [ -0.500000 : 11.5000 ] noreverse nowriteback
set ylabel "Exection time in ms" 
#set yrange [ 0.00000 : 180.000 ] noreverse nowriteback
set bmargin  3
plot 'bar_chart_java_tests.dat' using 0:2 title 2 with boxes,      ''          using 0:2:2 with labels center offset 0,1 notitle
