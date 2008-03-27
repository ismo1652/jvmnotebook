@echo off

REM ####
REM ####

SET D1=runtime-lib/xercesImpl.jar
SET D2=WEB-INF/lib/commons-dbcp.jar
SET D3=WEB-INF/lib/commons-pool.jar
SET D4=WEB-INF/lib/ehcache-1.1.jar
SET D5=WEB-INF/lib/cglib-2.1.3.jar
SET D6=WEB-INF/lib/mysql-connector-java-5.0.3-bin.jar
SET D7=WEB-INF/lib/asm.jar
SET D8=WEB-INF/lib/asm-attrs.jar
SET D9=WEB-INF/lib/jta.jar
SET D10=WEB-INF/lib/c3p0-0.9.0.jar
SET D11=WEB-INF/lib/hibernate3.jar
SET D12=WEB-INF/lib/junit-3.8.1.jar
SET D13=WEB-INF/lib/log4j-1.2.14.jar
SET D14=WEB-INF/lib/dom4j-1.6.1.jar
SET D15=WEB-INF/lib/commons-logging-1.0.4.jar
SET D16=WEB-INF/lib/commons-collections-2.1.1.jar
SET D17=WEB-INF/lib/mysql-connector-java-5.0.3-bin.jar
SET D18=WEB-INF/lib/cglib-2.1.3.jar
SET D19=WEB-INF/lib/jta.jar
SET D20=WEB-INF/lib/antlr-2.7.6rc1.jar
SET D21=WEB-INF/lib/spring.jar
SET D22=servlet-lib/servlet-api.jar
SET D23=WEB-INF/lib/jruby.jar
SET D24=WEB-INF/lib/bsf.jar
SET D25=WEB-INF/classes
SET D26=WEB-INF

SET DLIB1=%D1%;%D2%;%D3%;%D4%;%D5%;%D6%;%D7%;%D8%;%D9%;%D10%;%D11%;%D12%;%D13%;%D14%
SET DLIB2=%D15%;%D16%;%D17%;%D28%;%D19%;%D20%;%D21%;%D22%;%D23%;%D24%;%D25%;%D26%

java -classpath %DLIB1%;%DLIB2% org.spirit.client.RubyFileLoader -f ./WEB-INF/scripts/load_scan_files.rb

REM ### End of Script ###
