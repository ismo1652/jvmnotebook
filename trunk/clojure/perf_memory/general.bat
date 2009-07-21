@echo off

REM ### set JAVA_OPTS=-Xms200m -Xmx280m

set CURRENT_DIR=%cd%
set INSTALL_DIR=%CURRENT_DIR%

set CP="%INSTALL_DIR%\src\clj;%INSTALL_DIR%\lib\clojure-1.0.0.jar"

set _RUNJAVA="java"

