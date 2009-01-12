#!/bin/sh

L1=../../../lib/swt/win32/swt.jar
L2=../../../lib/swt/linux/swt.jar
#L=`cygpath -w ../../../lib/swt/win32/swt.jar`

L1=$L2


echo $L1

javac -classpath ".:$L1" *.java
java -classpath ".:$L1"  Tmp 
