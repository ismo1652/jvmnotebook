#!/bin/sh

L=`cygpath -w ../../../lib/swt/win32/swt.jar`

echo $L


javac -classpath ".;$L" *.java
java -classpath ".;$L"  JavaViewer
