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

echo %CP%

REM ### SET ADD1=-Xrunhprof:heap=sites,depth=4,format=a,file=prof/hprof_dump.txt
set ADD1=-Xrunhprof:file=dump.hprof,format=b

%_RUNJAVA% %JAVA_OPTS% c -classpath %CP% clojure.lang.Script %INSTALL_DIR%\src\clj\org\perf\baseline_hello.clj -- %1 %2 %3 %4 %5 %6 

:end
exit /b
