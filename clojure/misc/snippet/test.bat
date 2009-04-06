@echo off

if "%OS%" == "Windows_NT" setlocal

REM -----------------------------------------------------------------
REM 
REM WIN32 STARTUP SCRIPT FOR OCTANE LOG VIEWER
REM 1/20/2009 
REM 
REM -----------------------------------------------------------------

set CURRENT_DIR=%cd%

set INSTALL_DIR=C:\usr\local\pfs\projects\octane

set JAVA_OPTS=-Xms128m -Xmx164m

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
set OCT_LIB2=%INSTALL_DIR%\lib\junit-4.4.jar
set OCT_LIB4=%INSTALL_DIR%\lib
set OCT_LIB5=%INSTALL_DIR%\conf
set OCT_LIB_SRC=%INSTALL_DIR%\src

REM -----------------------------------------------------------------

set CLASSPATH=%CLASSPATH%;.;classes;%OCT_LIB1%;%OCT_LIB2%;%OCT_LIB4%;%OCT_LIB5%;%OCT_LIB_SRC%;%INSTALL_DIR%

echo (SCRIPT) ------------------------------------
echo %CLASSPATH%
echo %INSTALL_DIR%
echo (SCRIPT) ------------------------------------

%_RUNJAVA% %JAVA_OPTS% -classpath "%CLASSPATH%" -Doctane.install.dir="%INSTALL_DIR%" junit.textui.TestRunner api_examples %1 %2 %3 %4 %5 %6

:end

exit /b
