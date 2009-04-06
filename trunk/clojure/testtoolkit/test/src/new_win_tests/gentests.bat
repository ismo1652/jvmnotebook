@echo off

if "%OS%" == "Windows_NT" setlocal

REM -----------------------------------------------------------------
REM 
REM WIN32 STARTUP SCRIPT FOR OCTANE LOG VIEWER
REM 1/20/2009 
REM 
REM -----------------------------------------------------------------

set CURRENT_DIR=%cd%

set INSTALL_DIR=C:\usr\local\projects\testtoolkit

set JAVA_OPTS=-Xms96m -Xmx110m

REM -----------------------------------------------------------------
REM Set java runtime programs
REM -----------------------------------------------------------------
set _RUNJAVA="%JAVA_HOME%\bin\java"
set _RUNJAVAW="%JAVA_HOME%\bin\javaw"
set _RUNJAVAC="%JAVA_HOME%\bin\javac"

set CLASSPATH=%JAVA_HOME%\lib\tools.jar

REM -----------------------------------------------------------------
REM Append to the classpath 
REM -----------------------------------------------------------------
set OCT_LIB1=%INSTALL_DIR%\lib\clojure.jar
set OCT_LIB2=%INSTALL_DIR%\lib\swt\win32\swt.jar
set OCT_LIB4=%INSTALL_DIR%\lib
set OCT_LIB5=%INSTALL_DIR%\conf
set OCT_LIB_SRC=%INSTALL_DIR%\src
set OCT_LIB_SRC2=%INSTALL_DIR%\src\clojure

set OCT_COMMONS=%INSTALL_DIR%\lib\octane_commons.jar

REM -----------------------------------------------------------------
REM -- Set SPRING Libraries --
REM -----------------------------------------------------------------
set SPRING_LIB=%INSTALL_DIR%\lib\spring
set SPLIB1=%SPRING_LIB%\spring-custom.jar
set SPLIB2=%INSTALL_DIR%\log4j.jar
set SPLIB3=%SPRING_LIB%\commons-logging.jar
set SPR_CP=%SPLIB1%;%SPLIB2%;%SPLIB3%

REM -----------------------------------------------------------------

set TEST_SRC=%INSTALL_DIR%\test\src\new_win_tests
set C1=%INSTALL_DIR%\classes

set CLASSPATH=%CLASSPATH%;%C1%;%INSTALL_DIR%\lib\spring\resources;%INSTALL_DIR%\lib\junit-4.4.jar;%TEST_SRC%;%OCT_LIB1%;%OCT_LIB2%;%OCT_LIB4%;%OCT_LIB5%;%OCT_LIB_SRC%;%OCT_LIB_SRC2%;%OCT_COMMONS%;%SPR_CP%;%INSTALL_DIR%

echo (SCRIPT) ------------------------------------
echo %CLASSPATH%
echo %INSTALL_DIR%
echo (SCRIPT) ------------------------------------

mkdir classes

set ARG1=%1
goto %ARG1%
goto end

REM -----------------------------------------------------------------
REM - Test Labels
REM -----------------------------------------------------------------

:compile
REM -- run suite for just a single test --
%_RUNJAVA% %JAVA_OPTS% -classpath "%CLASSPATH%" -Dlight.install.dir="%INSTALL_DIR%" clojure.lang.Script %INSTALL_DIR%\test\src\new_win_tests\test\compile_tests.clj %2 %3 %4 %5 %6
goto end

:runtests
REM -- run suite --
%_RUNJAVA% %JAVA_OPTS% -classpath "%CLASSPATH%" -Dlight.install.dir="%INSTALL_DIR%" test.light_test_suite %2 %3 %4 %5 %6
goto end

:singletest
REM -- run suite --
%_RUNJAVA% %JAVA_OPTS% -classpath "%CLASSPATH%" -Dlight.install.dir="%INSTALL_DIR%" test.light_test_suite_single -- %2 %3 %4 %5 %6
goto end

:singlemem
REM -- run suite --
%_RUNJAVA% %JAVA_OPTS% -verbosegc -verbosegc -verbosegc -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -classpath "%CLASSPATH%" -Dlight.install.dir="%INSTALL_DIR%" test.light_test_suite_single -- %2 %3 %4 %5 %6
goto end

:singlehprof
REM -- run suite --
%_RUNJAVA% %JAVA_OPTS% -verbosegc -Xrunhprof:file=classes/hprof_dump.txt,format=a -classpath "%CLASSPATH%" -Dlight.install.dir="%INSTALL_DIR%" test.light_test_suite_single -- %2 %3 %4 %5 %6
goto end

:end

exit /b

