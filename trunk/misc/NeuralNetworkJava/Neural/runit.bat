@echo off

REM   Copy-Left (c) 2004-2004 Berlin Brown.  Here is the code, have fun.

echo Running...Batch Script(Windows)


set LOCALCLASSPATH=.\build\Neural.jar


java -classpath "%LOCALCLASSPATH%" org.retro.gis.Neural
goto end


:end
set LOCALCLASSPATH=
