@echo off

REM #############################################
REM Batch script for performance and memory test
REM 7/15/2009
REM Tested with Windows XP
REM #############################################

if "%OS%" == "Windows_NT" setlocal

REM #### Execute the Include Script #####
CALL general.bat

REM #### Note, only clojure, the 'clj src' path and swt will be used during these tests

set ADD1=-Xrunhprof:file=dump.hprof,format=b
set ADD2=-verbosegc -verbosegc -verbosegc -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -Xmx32m

echo %CP%

echo %ADD2%

%_RUNJAVA% %JAVA_OPTS% %ADD2% -classpath %CP% %ADD2% org.node.perf.test.Test9Fractal %1 %2 %3 %4 %5 %6 

:end
exit /b
