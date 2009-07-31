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

REM - Only JVM switches used thus far
set ADD1=-Xrunhprof:file=dump.hprof,format=b
set ADD2=-verbosegc -verbosegc -verbosegc -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -Xmx32m
set ADD3=-javaagent:shiftone-jrat.jar
set ADD4=-agentpath:C:\projects\downloads_main\downloads21\netbeans\profiler3\lib\deployed\jdk15\windows\profilerinterface.dll=C:\projects\downloads_main\downloads21\netbeans\profiler3\lib,5140
echo %CP%

%_RUNJAVA% %JAVA_OPTS% -classpath %CP% %ADD3% clojure.lang.Script %INSTALL_DIR%\src\clj\org\perf\andy\mandelbrot.clj -- %1 %2 %3 %4 %5 %6 

:end
exit /b
