@echo off
set CLOJURE_DIR=C:\projects\tools\home\projects\projects_ecl\botclient\botnetclient\clojure\lib
set CLOJURE_JAR=%CLOJURE_DIR%\target\clojure-lang-1.0-SNAPSHOT.jar
IF (%1)==() (
  java -cp %CLOJURE_DIR%\jline-0.9.94.jar;%CLOJURE_JAR% jline.ConsoleRunner clojure.lang.Repl
) ELSE (
  java -cp %CLOJURE_JAR% clojure.lang.Script %1
)
