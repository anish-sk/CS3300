%{ 
 	#include <stdlib.h>
    #include "y.tab.h"
	void yyerror(char *);
	extern int linenum;
%}


%% 

\/\/.*		;
\/\*([^\*]|\n|\*[^\/])*\*\/  ;
int			{return INT;}
return		{return RETURN;}
break		{return BREAK;}
continue	{return CONT;}
void		{return VOID;}
float		{return FLOAT;}
while		{return WHILE;}
if			{return IF;}
else		{return ELSE;}
"||"		{return OR;}
"=="		{return EQ;}
"!="		{return NEQ;}
"<="		{return LEQ;}
">="		{return GEQ;}
"&&"		{return AND;}
"scanf"		{return SCANF;}
"\"\%d\""	{return FORMAT_SCANF;}
\"\%"d"\\"n"\"	{return FORMAT_SPECIFIER;}
printf		{return PRINTF;}

;|,|\[|\]|\*|\(|\)|\=|\{|\}	{return *yytext;}
\<|\>|\+|\-|\/|\%|\!|\&		{return *yytext;}
[_a-zA-Z][_a-zA-Z0-9]* 	{return IDENTIFIER;}
[0-9]+ 			{return INTEGER_LITERAL;}
([0-9]+\.[0-9]*|[0-9]*\.[0-9]+) return FLOAT_LITERAL;
[\n]		{linenum++;}
[' '|\n|\t|\r]	;
.	;		

%% 

int yywrap(void) {
    return 1;
}
