$ uname -a
CYGWIN_NT-6.1-WOW64 xx 1.7.17(0.262/5/3) 2012-10-19 14:39 i686 Cygwin


Output:

$ make run
java Sorter
Running sorter, launch native
Average : 880000 Brute : 2105032704
Writing random number data file ./numbers.dat
Done
+ Launching Sort : ./numbers.dat
Quick Sorting, count=80000 len=1

++ Printing Sort ++
i:0 0
i:1 1
i:2 3
i:3 5
i:4 7
i:5 9
i:6 10
i:7 11
i:8 12
i:9 12
i:10 12
i:11 13
i:12 13
i:13 14
...
! Number of swaps : 811121 , sort/calls : 53899 , parti/calls : 1,579,984 , brute=2,105,032,704 ops=0


------------------

Output from TestSort:
Based on gnupath:

->j:2 2
->j:3 4
->j:4 10
->j:5 12
->j:6 13
->j:7 16
->j:8 16
->j:9 19
->j:10 21
->j:11 23
->j:12 23
Compares : 1178981