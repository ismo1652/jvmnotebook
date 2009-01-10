#!/bin/sh

LIB1=./lib/clojure.jar
LIB2=./lib/swt/win32/swt.jar

# Check the clojure library path
if [ -f $LIB1 ]
then
	echo "$LIB1 exists, continue"
else
	echo "$LIB1 does not exist, exiting"
	exit 1;
fi

# Check the SWT library path
if [ -f $LIB2 ]
then
	echo "$LIB2 exists, continue"
else
	echo "$LIB2 does not exist, exiting"
fi


LIB1=`cygpath -w $LIB1`
LIB2=`cygpath -w $LIB2`
CP=".;${LIB1};${LIB2};"

echo $CP
java -cp $CP clojure.lang.Repl src/octane_main.clj



