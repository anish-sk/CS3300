%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];

%}

%%
"//".*	;
"/*"([^*]|\*+[^*/])*"*/" ;
"/*"[.\n]* 		err1();

"for"                   {/*printf("FOR ");*/ return FOR;}
"do"                    {/*printf("DO ");*/ return DO;}
"while"                 {/*printf("WHILE ");*/ return WHILE;}
"if"                    {/*printf("IF ");*/ return IF;}
"else"                  {/*printf("ELSE ");*/ return ELSE;}
"switch"                {/*printf("SWITCH ");*/ return SWITCH;}
"default"               {/*printf("DEFAULT ");*/ return DEFAULT;}
"case"                  {/*printf("CASE ");*/ return CASE;}
"break"                 {/*printf("BREAK ");*/ return BREAK;}
"continue"              {/*printf("CONTINUE ");*/ return CONTINUE;}
"return"                {/*printf("RETURN ");*/ return RETURN;}
"int"                   {/*printf("INT ");*/ return INT;}
"long"                  {/*printf("LONG ");*/ return LONG;}
"short"                 {/*printf("SHORT ");*/ return SHORT;}
"float"                 {/*printf("FLOAT ");*/ return FLOAT;}
"double"                {/*printf("DOUBLE ");*/ return DOUBLE;}
"void"                  {/*printf("VOID ");*/ return VOID;}
"char"                  {/*printf("CHAR ");*/ return CHAR;}
"extern"                {/*printf("EXTERN ");*/ return EXTERN;}
"struct"                {/*printf("STRUCT ");*/ return STRUCT;}
"sizeof"                {/*printf("SIZEOF ");*/ return SIZEOF;}

"<=>"                   {/*printf("NEW ");*/return NEW;}
"=="                    {/*printf("EQ ");*/return EQ;}
">="                    {/*printf("GE ");*/return GE;}
"<="                    {/*printf("LE ");*/return LE;}
"!="                    {/*printf("NE ");*/return NE;}
"&&"                    {/*printf("AND ");*/return AND;}
"||"                    {/*printf("OR ");*/return OR;}
"++"                    {/*printf("INC ");*/return INC;}
"--"                    {/*printf("DEC ");*/return DEC;}
"->"                    {/*printf("NN ");*/return NN;}
">"                     {/*printf("GT ");*/return GT;}
"<"                     {/*printf("LT ");*/return LT;}
"="                     {/*printf("ASS ");*/return ASS;}
"+"                     {/*printf("PLS ");*/return PLS;}
"-"                     {/*printf("MIN ");*/return MIN;}
"!"                     {/*printf("NEG ");*/return NEG;}
"*"                     {/*printf("MUL ");*/return MUL;}
"&"                     {/*printf("AMP ");*/return AMP;}
"/"                     {/*printf("DIV ");*/return DIV;}
"%"                     {/*printf("MOD ");*/return MOD;}
"{"                     {/*printf("OP ");*/return OP;}
"}"                     {/*printf("CP ");*/return CP;}
"["                     {/*printf("OB ");*/return OB;}
"]"                     {/*printf("CB ");*/return CB;}
"("                     {/*printf("OC ");*/return OC;}
")"                     {/*printf("CC ");*/return CC;}
"|"                     {/*printf("SL ");*/return SL;}
"^"                     {/*printf("XR ");*/return XR;}
"."                     {/*printf("DOT ");*/return DOT;}
"~"                     {/*printf("CUR ");*/return CUR;}
":"                     {/*printf("COL ");*/return COL;}

";"						{/*printf("SC ");*/return SC;}
","						{/*printf("CM ");*/return CM;}

\'(\\.|[^\\'])*\'					{/*printf("Character ");*/ return IC; }	
\"(\\.|[^\\"])*\"					{/*printf("Strings ");*/ return STRING_LITERAL; }
[a-zA-Z_][a-zA-Z_0-9]*   			{/*printf("Identifier %s\n", yytext); strcpy(mytext, yytext);*/ return IDEN;}
"0x"[1-9A-Fa-f][0-9A-Fa-f]*|0x0     {/*printf("HEXXXXXXXXXXX\n");*/return IC; }
[0-9]*[.][0-9]+     			{/*printf("floating-point ");*/return FC;}
[0-9]*[.][0-9]+[e|E][+-]?[1-9][0-9]* 		{/*printf("exp ");*/return FC;}
([1-9][0-9]*)[e|E][+-]?[1-9][0-9]* 		{/*printf("exp ");*/return FC;}
[1-9][0-9]*|0                       {/*printf("Number ");*/return IC;}
[ \t\n\b] ;
.	;
%%
int err1(){
	printf("***lexing terminated*** [lexer error]: ill-formed comment\n");
	exit(0);
	return 0;
}
int yywrap(void) {
    return 1;
}
//To handle characters