#! /bin/sh
# Berlin Brown


if [ -n "$CLASSPATH" ] ; then
	LOCALCLASSPATH="$CLASSPATH"
fi

if [ -z "$LOCALCLASSPATH" ] ; then
	LOCALCLASSPATH="./build/Neural.jar"
else
	LOCALCLASSPATH="./build/Neural":"$LOCALCLASSPATH"
fi

LOG=../../spiritbot/lib/log4j-1.2.8.jar
SPIRIT=../../spiritbot/build/SpiritBot.jar

LOCALCLASSPATH=./build/Neural.jar:$LOG:$SPIRIT

echo $LOCALCLASSPATH

java -classpath $LOCALCLASSPATH org.retro.gis.NeuralWords 10000 0.1 0.9 0

