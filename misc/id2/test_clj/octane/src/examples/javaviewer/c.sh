#!/bin/sh

OS=`uname -a`
LIB1=../../../lib/clojure.jar
LIB2=../../../lib/swt/win32/swt.jar
LIB2_LINUX=../../../lib/swt/linux/swt.jar

LIB3=../../../lib/jfreechart/jcommon-1.0.15.jar
LIB4=../../../lib/jfreechart/jfreechart-1.0.12-experimental.jar
LIB5=../../../lib/jfreechart/jfreechart-1.0.12-swt.jar
LIB6=../../../lib/jfreechart/jfreechart-1.0.12.jar
LIB7=../../../lib/jfreechart/swtgraphics2d.jar

LIB_JFREE=$LIB3:$LIB4:$LIB5:$LIB6:$LIB7

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

echo $OS
case "$OS" in 
	CYGWIN* )
		LIB1=`cygpath -w $LIB1` 
		LIB2=`cygpath -w $LIB2`
		CP=".;${LIB1};${LIB2};" ;;
	*)
		LIB2=$LIB2_LINUX
		CP=".:${LIB1}:${LIB2}:${LIB_JFREE}" ;;
esac 

echo $CP
javac -cp $CP *.java
#java -cp $CP Tabs 
#java -cp $CP SWTTimeSeriesDemo 
java -cp $CP SWTTimeSeriesDemo2 
#java -cp $CP SWTPieChartDemo1 
#java -cp $CP SWTBarChartDemo1
#java -cp $CP SWTMultipleAxisDemo1

#End of Script
