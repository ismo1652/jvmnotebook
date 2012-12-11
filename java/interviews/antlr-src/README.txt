######################################
12/11/2012

Download antlr source:

https://github.com/antlr/antlr3/tarball/master

Run these commands:

mvn -N install
mvn -Dgpg.skip=true -N install
mvn -Dgpg.skip=true -Dmaven.test.skip=true package

Run the command below to generate java source against the 1.5 grammar

java  -classpath "antlr-3.5-snapshot.jar;antlr-3.4-complete.jar" org.antlr.Tool -o org/berlin Java.g

javac -classpath '.;../../antlr-3.5-snapshot.jar;../../antlr-3.4-complete.jar' *.java
java -classpath '.;../../antlr-3.5-snapshot.jar;../../antlr-3.4-complete.jar' org.berlin.Main Test.java
