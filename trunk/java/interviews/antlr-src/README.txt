######################################
12/11/2012

Download antlr source:

https://github.com/antlr/antlr3/tarball/master

Run these commands:

mvn -N install
mvn -Dgpg.skip=true -N install
mvn -Dgpg.skip=true -Dmaven.test.skip=true package

Run the command below to generate java source against the 1.5 grammar

java  -classpath "antlr-3.5-snapshot.jar;antlr-3.4-complete.jar" org.antlr.Tool -o org/berlin Java.g

javac -classpath '.;../../antlr-3.5-snapshot.jar;../../antlr-3.4-complete.jar' *.java
java -classpath '.;../../antlr-3.5-snapshot.jar;../../antlr-3.4-complete.jar' org.berlin.Main Test.java
#########


Output, printing tokens in file:

Parsing tree : ANNOTATION_LIST  // class org.antlr.runtime.tree.CommonTree // 0
Parsing tree : class  // class org.antlr.runtime.tree.CommonTree // 1
Parsing tree : MODIFIER_LIST  // class org.antlr.runtime.tree.CommonTree // 1
Parsing tree : public  // class org.antlr.runtime.tree.CommonTree // 1
Parsing tree : Test  // class org.antlr.runtime.tree.CommonTree // 1
Parsing tree : CLASS_TOP_LEVEL_SCOPE  // class org.antlr.runtime.tree.CommonTree // 1
Parsing tree : VOID_METHOD_DECL  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : MODIFIER_LIST  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : public  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : static  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : main  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : FORMAL_PARAM_LIST  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : FORMAL_PARAM_STD_DECL  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : LOCAL_MODIFIER_LIST  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : final  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : TYPE  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : QUALIFIED_TYPE_IDENT  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : String  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : ARRAY_DECLARATOR_LIST  // class org.antlr.runtime.tree.CommonTree // 0
Parsing tree : ARRAY_DECLARATOR  // class org.antlr.runtime.tree.CommonTree // 0
Parsing tree : args  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : BLOCK_SCOPE  // class org.antlr.runtime.tree.CommonTree // 8
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : METHOD_CALL  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : System  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : out  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : println  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : ARGUMENT_LIST  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : "Running"  // class org.antlr.runtime.tree.CommonTree // 11
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : METHOD_CALL  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : System  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : out  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : println  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : ARGUMENT_LIST  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : "Done"  // class org.antlr.runtime.tree.CommonTree // 12
Parsing tree : VOID_METHOD_DECL  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : MODIFIER_LIST  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : public  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : static  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : test2  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : FORMAL_PARAM_LIST  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : BLOCK_SCOPE  // class org.antlr.runtime.tree.CommonTree // 15
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : METHOD_CALL  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : .  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : System  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : out  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : println  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : ARGUMENT_LIST  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : EXPR  // class org.antlr.runtime.tree.CommonTree // 16
Parsing tree : "Running2"  // class org.antlr.runtime.tree.CommonTree // 16