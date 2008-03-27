#! /bin/sh
# Berlin Brown


LOG=../../spiritbot/lib/log4j-1.2.8.jar
SPIRIT=../../spiritbot/build/SpiritBot.jar

LOCALCLASSPATH=./build/Neural.jar:$LOG:$SPIRIT

echo $LOCALCLASSPATH

#nice -19 java -classpath $LOCALCLASSPATH org.retro.gis.TestTestServer &
java -classpath $LOCALCLASSPATH org.retro.gis.MainDrawCircle

