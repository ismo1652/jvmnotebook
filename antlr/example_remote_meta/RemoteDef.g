/**
 * Simple Remote Definition Meta Language
 * Grammar Definition for Antlr
 * Date: 12/27/2007
 * Author: Berlin Brown
 *
 * Also see, http://javadude.com/articles/antlrtut/
 */

//***********************************************
// Begin Grammar Definitions
//***********************************************
 
grammar RemoteDef;

options {
    k = 2;
}

root_meta_declarations : 
	meta_declaration+
	;

meta_declaration :
	root_namespace
	;

/** 
 * Only one root namespace, allowed.
 */
root_namespace :
	OPEN_PAREN ( operation_declaration_list|statement_expression_list )+ CLOSE_PAREN
	{ 
		System.out.println("INFO: ROOT NAMESPACE FOUND: ");
	}
	;

statement_expression_list :
	( attribute_expression )+
	;

operation_declaration_list :
	( IDENTIFIER_ATOM? OPEN_BRACE ( statement_expression_list | DATA_PAYLOAD_VALUE )+
	CLOSE_BRACE )+		
	;

/**
 * Process a attribute statement expression, which has the following syntax:
 * <code>@some_attribute: some_value;</code>
 */
attribute_expression :
	attribute_key IDENTIFIER_ATOM END_EXPRESSION
	{ 
		System.out.println("INFO: define attribute expr: [" + $IDENTIFIER_ATOM.text + "]");
	}
	;
	
attribute_key :
	AT_SIGN_IDENTIFIER IDENTIFIER_ATOM COLON
	{ 
		System.out.println("INFO: define attribute key: [" + $IDENTIFIER_ATOM.text + "]");
	}
	;

//***********************************************
// Misc Utility Definitions and Tokens
//***********************************************

IDENTIFIER_ATOM :	
	( LETTER | '0'..'9' )*
	;
	
fragment LETTER :	
		'$'
	|	'A'..'Z'
	|	'.'
	|	'a'..'z'
	|	'_'
	|	'-'
	;	

DATA_PAYLOAD_VALUE : 
	'<<<' ( options {greedy=false;} : . )* '>>>'
	{
		// JAVA COMMENT: set channel = 99
		channel=99;
	}
	;

//***********************************************
// Operators
//***********************************************

COLON : ':' ;

END_EXPRESSION : ';' ;

AT_SIGN_IDENTIFIER : '@' ;

OPEN_PAREN : '(' ;

CLOSE_PAREN : ')' ;

OPEN_BRACE : '{' ;

CLOSE_BRACE : '}' ;

//***********************************************
// Ignore
//***********************************************

WS :
	(' '|'\r'|'\t'|'\u000C'|'\n') 
	{channel=99;}
    ;

COMMENT :
	'/*' ( options {greedy=false;} : . )* '*/' {channel=99;}
    ;

LINE_COMMENT : 
	'//' ~('\n'|'\r')* '\r'? '\n' 
	{
		// JAVA COMMENT: set channel = 99
		channel=99;		
	}
    ;

// End of Grammar File //
