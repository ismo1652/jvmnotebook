#!/bin/sh

LIB1=./lib/clojure/clojure.jar
LIB2=./lib/swt/win32_x86/swt.jar

LIB1=`cygpath -w $LIB1`
LIB2=`cygpath -w $LIB2`


java -cp ".;${LIB1};${LIB2}" clojure.lang.Repl src/octane_main.clj



