@echo off

REM #############################################
REM Batch script for performance and memory test
REM 7/15/2009
REM Tested with Windows XP
REM #############################################

set CURRENT_DIR=%cd%
set INSTALL_DIR=%CURRENT_DIR%

echo %INSTALL_DIR%

"%INSTALL_DIR%\lib\jruby\bin\jruby.bat" src/jruby/test11_sort.rb %1 %2 %3 %4 
