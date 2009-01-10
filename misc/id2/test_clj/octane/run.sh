#!/bin/sh

OS=`uname -a`
LIB1=./lib/clojure.jar
LIB2=./lib/swt/win32/swt.jar
LIB2_LINUX=./lib/swt/linux/swt.jar

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

case "$OS" in 
	"Linux" )
		LIB1=`cygpath -w $LIB1` 
		LIB2=`cygpath -w $LIB2`
		CP=".;${LIB1};${LIB2};" ;;
	*)
		LIB2=$LIB2_LINUX
		CP=".:${LIB1}:${LIB2}:" ;;
esac 

echo $CP
java -cp $CP clojure.lang.Repl src/octane_main.clj


# End of Script
