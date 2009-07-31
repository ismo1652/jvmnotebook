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

set ADD2=-verbosegc -verbosegc -verbosegc -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -Xmx32m

echo %CP%

%_RUNJAVA% %JAVA_OPTS% -classpath %CP% %ADD2% org.node.perf.test.andy.mandelbrot_no_threads %1 %2 %3 %4 %5 %6 

:end
exit /b
