@echo off

if "%OS%" == "Windows_NT" setlocal

REM -----------------------------------------------------------------
REM 
REM WIN32 STARTUP SCRIPT FOR OCTANE LOG VIEWER
REM 1/20/2009 
REM 
REM -----------------------------------------------------------------

cd ..

octscripts.bat scripts\scripts\archive_search.clj %1 %2 %3 %4 %5

:end

exit /b
