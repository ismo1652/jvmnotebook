@echo off

REM # Depending on if we are running from pwd or not, determine
REM # proper location to change directory to.

set JAVA=java

set LIB1=lib/botlistloadtest.jar
set LIB2=lib/jruby.jar
set LIB3=lib/ibatis-2.3.0.677.jar

set LIN_CPBOTBERT=".;%LIB1%;%LIB2%;%LIB3%"
set APP_MAIN=org.jruby.Main

echo %LIN_CPBOTBERT%
echo "-----------------------"

"%JAVA%" -classpath %LIN_CPBOTBERT% %APP_MAIN% "ruby/bot_remote_sync.rb" %1 %2

