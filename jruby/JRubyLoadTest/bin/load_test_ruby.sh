#!/bin/sh

# Depending on if we are running from pwd or not, determine
# proper location to change directory to.
case $0 in 
	/*) 
		ABS_APP_PATH=$0
		ABS_CONF=`dirname $ABS_APP_PATH`
		ABS_CONF=`dirname $ABS_CONF`
		;; 
	*) 
		ABS_APP_PATH=`pwd`
		ABS_CONF=`dirname $ABS_APP_PATH`
		;; 
esac

if [ -z "$JAVA_HOME"  ] ; then
 JAVA_HOME=/usr
fi

JAVA=$JAVA_HOME/bin/java

BOTBERT_HOME=$ABS_CONF
TOPDIR=$BOTBERT_HOME
DIR_PROPERTIES=$BOTBERT_HOME

LIB1=$BOTBERT_HOME/lib/botlistloadtest.jar
LIB2=$BOTBERT_HOME/lib/jruby.jar
LIB3=$BOTBERT_HOME/lib/ibatis-2.3.0.677.jar

if [ $(uname -s | grep -c CYGWIN) -gt 0 ]; then
	echo "WARN: running in CYGWIN environment"
	DIR_PROPERTIES=`cygpath -wp $BOTBERT_HOME`
fi

LIN_CPBOTBERT=".:$LIB1:$LIB2:$LIB3"

cd $BOTBERT_HOME

APP_MAIN=org.jruby.Main
echo "running in directory=${BOTBERT_HOME}"
echo $LIN_CPBOTBERT
echo "-----------------------"

# Append '&' to run in background
# Append -Xmx32M heap settings if needed
"$JAVA" -classpath $LIN_CPBOTBERT $APP_MAIN ruby/bot_remote_sync.rb $@

# Write the process id
#echo $! > $BOTBERT_HOME/bin/currentapp.pid

# End of Script --
