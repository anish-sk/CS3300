%{
    #include <stdio.h>
    #include "y.tab.h"
    void yyerror(char *);
%}

%%

"//".* 					{}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {}

"printf"				{ return PRINTF;}

"\"\%d\\n\""			{ return FORMAT_SPECIFIER;}

"scanf"					{ return SCANF;}

"\"\%d\""				{ return FORMAT_SCANF;}

"int" 					{ return INT;}

"void" 					{ return VOID;}

"float" 				{ return FLOAT;}

"while" 				{ return WHILE;}

"if" 					{ return IF;}

"else" 					{ return ELSE;}

"break" 				{ return BREAK;}

"continue" 				{ return CONTINUE;}

"return" 				{ return RETURN;}

\;						{return SC;}

\,						{return COMMA;}

\( 						{return PAREN_OPEN;}

\)						{return PAREN_CLOSE;}

\[						{return SQ_OPEN;}

\]						{return SQ_CLOSE;}

\{ 						{return CURLY_OPEN;}

\}						{return CURLY_CLOSE;}

"="						{return ASSGN;}

"&"						{return UNAND;}

"||"					{return OR;}

"=="					{return EE;}

"!="					{return NE;}

"<="					{return LE;}

"<"						{return LT;}

">="					{return GE;}

">"						{return GT;}

"&&"					{return AND;}

"+"						{return PLUS;}

"-"						{return MINUS;}

"*"						{return INTO;}

"/"						{return BY;}

"%"						{return MOD;}

"!"						{return NOT;}

[0-9]+					{return INTEGER_LITERAL;}

[0-9]+\.[0-9]*			{return FLOAT_LITERAL;}

[_a-zA-Z][_a-zA-Z0-9]*	{return IDENTIFIER;}

[ \t\n]	 				;

. 						{}

%%

int yywrap(void) {
    return 1;
}
