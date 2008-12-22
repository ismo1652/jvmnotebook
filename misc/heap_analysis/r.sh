#!/bin/sh

javac CrashJVM.java

FORMAT=,format=b

# Add profiling and verbose garbage collection
java -verbosegc -Xrunhprof:file=dump.txt${FORMAT} CrashJVM -Xms24MB -Xmx32MB

# To run the server:
jhat dump.txt

#jhat dump.txt
