#!/bin/sh

OS=`uname -a`

# Install Directory Path (editable attribute)
INSTALL_DIR=/projects/tools/home/projects/aaageneralprojects/jvmnotebook/misc/id2/test_clj/octane

# Put the configuration directory in the classpath
CONF_LIB=./conf
LIB1=./lib/clojure.jar
LIB2=./lib/swt/win32/swt.jar
LIB3=./lib/jline-0.9.94.jar
LIB2_LINUX=./lib/swt/linux/swt.jar
LIB4=./lib/org.eclipse.jface.text_3.4.1.r341_v20080827-1100.jar

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
		INSTALL_DIR=`cygpath -w $INSTALL_DIR`		
		# SET THE CLASSPATH for CYGWIN
		CP=".;src;${LIB1};${LIB2};$CONF_LIB;$LIB4" ;;
	*)
		LIB2=$LIB2_LINUX
		CP=".:src:${LIB1}:${LIB2}:${LIB3}:$CONF_LIB" ;;
esac 

echo "(SCRIPT): install directory= $INSTALL_DIR"
echo "(SCRIPT): classpath= $CP"
java -Xms200m -Xmx324m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" clojure.lang.Repl src/octane_main.clj

# End of Script
