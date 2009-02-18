#!/bin/sh

OS=`uname -a`

# Install Directory Path (editable attribute)
INSTALL_DIR=/usr/local/projects/octane
TOP_DIR=`pwd`

# Put the configuration directory in the classpath
CONF_LIB=$TOP_DIR/../../conf
LIB1=$INSTALL_DIR/lib/clojure.jar
LIB2=$INSTALL_DIR/lib/swt/win32/swt.jar
LIB3=$INSTALL_DIR/lib/jline-0.9.94.jar
LIB2_LINUX=$INSTALL_DIR/lib/swt/linux/swt.jar
LIB4=$INSTALL_DIR/lib/org.eclipse.jface.text_3.4.1.r341_v20080827-1100.jar
LIB5=$INSTALL_DIR/lib/junit-4.4.jar

LIB6=$TOP_DIR/lib/jmock/jmock-2.5.1.jar 
LIB7=$TOP_DIR/lib/jmock/hamcrest-library-1.1.jar
LIB8=$TOP_DIR/lib/jmock/hamcrest-core-1.1.jar
LIB9=$TOP_DIR/lib/jmock/cglib-nodep-2.1_3.jar
LIB10=$TOP_DIR/lib/jmock/objenesis-1.0.jar
LIB11=$TOP_DIR/lib/jmock/jmock-legacy-2.5.1.jar

CLOJURE=$TOP_DIR/../../src

JFREE_LIB=$TOP_DIR/../../lib/jfreechart
LIB6j=$JFREE_LIB/gnujaxp.jar
LIB7j=$JFREE_LIB/jcommon-1.0.15.jar
LIB8j=$JFREE_LIB/jfreechart-1.0.12-experimental.jar
LIB9j=$JFREE_LIB/jfreechart-1.0.12.jar
LIB10j=$JFREE_LIB/jfreechart-1.0.12-swt.jar
LIB11j=$JFREE_LIB/swtgraphics2d.jar

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
	*)
        #####################################
        ## Convert the Path to Cygwin Path ##
        #####################################
		LIB1=`cygpath -w $LIB1` 
		LIB2=`cygpath -w $LIB2`
		CONF_LIB=`cygpath -w $CONF_LIB`
		LIB4=`cygpath -w $LIB4`
		LIB5=`cygpath -w $LIB5`
		INSTALL_DIR=`cygpath -w $INSTALL_DIR`		
        
        #######################################
        # Continue with cygpath (for jfreelib)
        #######################################
        LIB6j=`cygpath -w ${LIB6j}`
        LIB7j=`cygpath -w ${LIB7j}`
        LIB8j=`cygpath -w ${LIB8j}`
        LIB9j=`cygpath -w ${LIB9j}`
        LIB10j=`cygpath -w ${LIB10j}`
        LIB11j=`cygpath -w ${LIB11j}`
        
        ############################
        # Convert the jmock classes
        ############################
        LIB6=`cygpath -w $LIB6`
        LIB9=`cygpath -w $LIB9`
        LIB10=`cygpath -w $LIB10`
        LIB11=`cygpath -w $LIB11`
        
        CLOJURE=`cygpath -w $CLOJURE`

		# SET THE CLASSPATH for CYGWIN
        LIB_CP_JFREE="${LIB6j};${LIB7j};${LIB8j};${LIB9j};${LIB10j};${LIB11j}"
		CP=".;test;src;classes;${LIB1};${LIB2};$CONF_LIB;$LIB4;$LIB5;${LIB6};${LIB7};${LIB8};${LIB9};${LIB10};${LIB11};${LIB_CP_JFREE};${CLOJURE};$CONF_LIB" 
        ;;

esac 

echo "(SCRIPT): -------------------------"
echo "(SCRIPT): install directory= $INSTALL_DIR"
echo "(SCRIPT): classpath= $CP"
echo "(SCRIPT): jfree classpath= $LIB_CP_JFREE"
echo "(SCRIPT): -------------------------"

MAIN1=test.OctaneFullTest
FILE1=main_gen_tests.clj

MAIN2=test.OctaneSampleTestGen
FILE2=main_gen_tests.clj
MAIN3=test.OctaneSampleMockTest
MAIN4=test.OctaneGraphsAnalyticsTest
MAIN5=test.OctaneUtilsTest

FILE=$FILE1
MAIN=$MAIN5

mkdir -vp classes

java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" clojure.lang.Repl $FILE 
java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" junit.textui.TestRunner $MAIN

#;;;;;;;;;;;;;;;;
# End of Script
#;;;;;;;;;;;;;;;;
