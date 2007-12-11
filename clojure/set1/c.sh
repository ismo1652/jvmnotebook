#!/bin/sh
#
# Script for launching clojure source

TOPDIR=`pwd`
CDIR=`dirname $TOPDIR`
BOOK_DIR=`dirname $CDIR`
CLJ_PATH=$BOOK_DIR/syslib/clojure.jar
CP_PATH=.:$CLJ_PATH

if [ $(uname -s | grep -c CYGWIN) -gt 0 ]; then
	echo "WARN: running in CYGWIN environment"
	CLJ_PATH=`cygpath -wp $CLJ_PATH`
	CP_PATH=".;$CLJ_PATH"
fi

echo $CP_PATH
java -cp "$CP_PATH" clojure.lang.Script lib/boot.clj hello.lisp 


