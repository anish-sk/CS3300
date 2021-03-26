%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];
%}
%%
if			{return IF;}
else 		{return ELSE;}
switch		{return SWITCH;}
case		{return CASE;}
default		{return DEFAULT;}
for			{return FOR;}
while		{return WHILE;}
do			{return DO;}
break		{return BREAK;}
continue	{return CONTINUE;}
struct		{return STRUCT;}
return		{return RETURN;}
sizeof		{return SIZEOF;}	
void 		{return VOID;}
int 		{return INT;} 
float 		{return FLOAT;}
extern 		{return EXTERN;} 
printf		{return PRINT;}
"\"%d\"" 			{return FORMAT_SPEC;}
[a-zA-Z_][a-zA-Z_0-9]*	{return IDENTIFIER;}
[0-9]+	{return INTEGERLITERAL;}
"-"		{return MINUS;}
"="		{return EQ;}
"+"		{return PLUS;}
(([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) { return FLOATLITERAL;}
"++" 	{return INC;}
"--" 	{return DEC;}
"<"		{return LESS;}
">"		{return GREATER;}
"=="	{return COM_EQ;}
"<="	{return LE;}
">="	{return GE;}
"!=" 	{return NOT_EQ;}
"<=>"	{return NEW_OP;}
"!"		{return NOT;}
"*"		{return STAR;}
[\&]	{return AMPERSAND;}
"&&"	{return AND;}
"->"	{return ACCESS;}
"/"		{return DIV;}
"%"		{return MOD;}
"||"	{return OR;}
"."		{return DOT;}
[;]		{return SC;}
[:]		{return COLON;}
[(]		{return OP;}
[)]		{return CP;}
[{]		{return OFB;}
[}]		{return CFB;}
"["		{return OSB;}
"]"		{return CSB;}
","		{return COMMA;}
"//"(\\.|[^\n])*[\n] ;
[/][*]([^*]|[*]*[^*/])*[*]+[/] ;
[ \n\t] ;

.	{yyerror("unknown character");}
%%
int yywrap(void) {
    return 1;
}
