@echo off

if "%OS%" == "Windows_NT" setlocal

REM -----------------------------------------------------------------
REM WIN32 STARTUP SCRIPT FOR OCTANE LOG VIEWER
REM 1/20/2009 
REM -----------------------------------------------------------------

set CURRENT_DIR=%cd%

set INSTALL_DIR=C:\projects\tools\home\projects\aaageneralprojects\jvmnotebook\misc\id2\test_clj\octane

set JAVA_OPTS=-Xms200m -Xmx324m


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
set OCT_LIB3=%INSTALL_DIR%\lib\jline-0.9.94.jar
set OCT_LIB4=%INSTALL_DIR%\lib
set OCT_LIB5=%INSTALL_DIR%\conf
set OCT_LIB_SRC=%INSTALL_DIR%\src

set CLASSPATH=%CLASSPATH%;%OCT_LIB1%;%OCT_LIB2%;%OCT_LIB3%;%OCT_LIB4%;%OCT_LIB5%;%OCT_LIB_SRC%;%INSTALL_DIR%

echo %CLASSPATH%
echo %INSTALL_DIR%

%_RUNJAVA% %JAVA_OPTS% -classpath "%CLASSPATH%" -Doctane.install.dir="%INSTALL_DIR%" clojure.lang.Repl "%INSTALL_DIR%\src\octane_main.clj" -- %1 %2 %3 %4 %5 %6

:end

exit /b
