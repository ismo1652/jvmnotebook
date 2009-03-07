#!/bin/sh

######################################################################
# Note: the cygwin launch is deprecated use ./octane.bat
#
######################################################################
OS=`uname -a`

###############################################
# Install Directory Path (editable attribute)
###############################################
INSTALL_DIR=/home/bbrown/workspace_lang/light_clojurebot

# Put the configuration directory in the classpath
LIB1=$INSTALL_DIR/lib/clojure.jar
LIB2=$INSTALL_DIR/lib/swt/win32/swt.jar
LIB3=$INSTALL_DIR/lib/jline-0.9.94.jar
LIB6=$INSTALL_DIR/pircbotjar
LIB2_LINUX=$INSTALL_DIR/lib/swt/linux/swt.jar

CONF_LIB=$INSTALL_DIR/conf

###########################################################

NLP=$INSTALL_DIR/lib/opennlp
NLP1=$NLP/opennlp-tools-1.4.3.jar
NLP2=$NLP/trove.jar
NLP3=$NLP/maxent-2.5.2.jar
NLP_LIB=$NLP1:$NLP2:$NLP3

MODELS=$INSTALL_DIR/models
TESTS=$INSTALL_DIR/test/example_docs
DATA=$INSTALL_DIR/data

###########################################################

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
###############################
# SET THE CLASSPATH for CYGWIN
###############################
		LIB1=`cygpath -w $LIB1` 
		LIB2=`cygpath -w $LIB2`
		CONF_LIB=`cygpath -w $CONF_LIB`
		LIB4=`cygpath -w $LIB4`
		INSTALL_DIR=`cygpath -w $INSTALL_DIR`		
		CP=".;src;${LIB1};${LIB2};$CONF_LIB;$LIB4" ;;
	*)
		LIB2=$LIB2_LINUX
		CP=".:src:conf:${LIB1}:${LIB2}:${LIB3}:${LIB6}:${NLP_LIB}:$CONF_LIB" ;;
esac 

echo "(SCRIPT): --------------------------------"
echo "(SCRIPT): install directory= $INSTALL_DIR"
echo "(SCRIPT): classpath= $CP"
echo "(SCRIPT): --------------------------------"

java -Xms128m -Xmx200m -classpath $CP -Dlight.install.dir="$INSTALL_DIR" \
  clojure.lang.Script src/light/toolkit/nlp/light_pos_tagger.clj

##############################
# End of Script
##############################
