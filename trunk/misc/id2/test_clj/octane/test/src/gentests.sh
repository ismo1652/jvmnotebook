#!/bin/sh

OS=`uname -a`

# Install Directory Path (editable attribute)
INSTALL_DIR=/usr/local/projects/octane
TOP_DIR=`pwd`

# Put the configuration directory in the classpath
CONF_LIB=$INSTALL_DIR/conf
LIB1=$INSTALL_DIR/lib/clojure.jar
LIB2=$INSTALL_DIR/lib/swt/win32/swt.jar
LIB3=$INSTALL_DIR/lib/jline-0.9.94.jar
LIB2_LINUX=$INSTALL_DIR/lib/swt/linux/swt.jar
LIB4=$INSTALL_DIR/lib/org.eclipse.jface.text_3.4.1.r341_v20080827-1100.jar
LIB5=$INSTALL_DIR/lib/junit-4.4.jar

CLOJURE=$TOP_DIR/../../src

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
		CONF_LIB=`cygpath -w $CONF_LIB`
		LIB4=`cygpath -w $LIB4`
		LIB5=`cygpath -w $LIB5`
		INSTALL_DIR=`cygpath -w $INSTALL_DIR`		
		# SET THE CLASSPATH for CYGWIN
		CP=".;test;src;classes;${LIB1};${LIB2};$CONF_LIB;$LIB4;$LIB5" ;;
	*)
		LIB2=$LIB2_LINUX
		CP=".:./test:src:./classes:${LIB1}:${LIB2}:${LIB3}:${LIB5}:${CLOJURE}:$CONF_LIB" ;;
esac 

echo "(SCRIPT): -------------------------"
echo "(SCRIPT): install directory= $INSTALL_DIR"
echo "(SCRIPT): classpath= $CP"
echo "(SCRIPT): -------------------------"

MAIN1=test.OctaneFullTest
FILE1=main_gen_tests.clj

MAIN2=test.OctaneSampleTestGen
FILE2=main_gen_tests.clj

FILE=$FILE1
MAIN=$MAIN1

mkdir -vp classes

java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" clojure.lang.Repl $FILE 
java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" junit.textui.TestRunner $MAIN 

#;;;;;;;;;;;;;;;;
# End of Script
#;;;;;;;;;;;;;;;;
