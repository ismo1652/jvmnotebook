########## Makefile for JNI builds #############
### 11/11/2012
### i686-pc-mingw32-g++ (GCC) 4.5.2

CC=i686-pc-mingw32-g++ 
FLAGS=-mwindows -Wl,--add-stdcall-alias -shared -static
HEADERS=-I/opt/jdk/include -I/opt/jdk/include/win32

# All target:
all: sort.dll Sorter.class QuickSort2.class

sort.dll: Sorter.c
	${CC} -o $@ Sorter.c ${FLAGS} ${INCLUDE_DIRS} ${HEADERS} 

Sorter.class: Sorter.java
	javac Sorter.java

QuickSort2.class: QuickSort2.java
	javac QuickSort2.java

run:
	java Sorter

clean:
	rm -vf *.dll *.class *.dat
# End of Makefile #

