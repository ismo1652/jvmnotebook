/**
 * Simple Remote Definition Meta Language
 */

grammar RemoteDef;

options {
    k = 2;
}

OPEN_PAREN : '(';

CLOSE_PAREN : ')';

protected
DIGIT: '0' .. '9';

protected
LETTER: 'a' .. 'z' | 'A' .. 'Z';


WS  :  (' '|'\r'|'\t'|'\u000C'|'\n') {channel=99;}
    ;

COMMENT
    :   '/*' ( options {greedy=false;} : . )* '*/' {channel=99;}
    ;

LINE_COMMENT
    : '//' ~('\n'|'\r')* '\r'? '\n' {channel=99;}
    ;

