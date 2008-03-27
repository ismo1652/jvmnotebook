#! /bin/sh
# Berlin Brown
#
# $Id: scheme.sh,v 1.1 2004/05/01 02:35:41 bigbinc Exp $
#

SPIRITHOME=../../spiritbot

##
#
# @@@@@ --> Use this script to launch the full Scheme application
#
##

# -- Change the java_home from the Config file ---
. Config

MYSQLPATH="/home/bigbinc/java/jmysql/mysql-connector-java-3.0.11-stable-bin.jar"

LOG4J="$SPIRITHOME/lib/log4j-1.2.8.jar"
LOCALCLASSPATH="$SPIRITHOME/build/SpiritBot.jar:$MYSQLPATH:$LOG4J"

echo "Classpath [ $LOCALCLASSPATH ] "

java -classpath "$LOCALCLASSPATH" org.retro.scheme.Scheme


