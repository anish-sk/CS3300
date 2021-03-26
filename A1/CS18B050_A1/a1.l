%{
	#include <stdlib.h>
	#include "y.tab.h"
	void yyerror(char *);
	extern char mytext[];
%}

IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
INTEGER [0-9]+
%option yylineno

%%
break { return BREAK; }
case { return CASE; }
char { return CHAR; }
continue { return CONTINUE; }
default { return DEFAULT; }
do { return DO; }
double { return DOUBLE; }
else { return ELSE; }
extern { return EXTERN; }
float { return FLOAT; }
for { return FOR; }
if { return IF; }
int { return INT; }
long { return LONG; }
return { return RETURN; }
short { return SHORT; }
sizeof { return SIZEOF; }
struct { return STRUCT; }
switch { return SWITCH; }
void { return VOID; }
while { return WHILE; }

"[" { return LSQ; }
"]" { return RSQ; }
"(" { return LPA; }
")" { return RPA; }
"{" { return LCU; }
"}" { return RCU; }
"." { return DOT; }
"->" { return ARROW; }
"++" { return PINC; }
"--" { return PDEC; }
"&" { return BAND; }
"*" { return MUL; }
"+" { return ADD; }
"-" { return SUB; }
"~" { return NEG; }
"!" { return NOT; }
"/" { return DIV; }
"%" { return MOD; }
"<" { return LESS; }
">" { return GRTR; }
"<=" { return LEQ; }
"==" { return EEQ; }
"=" { return EQ; }
"!=" { return NEQ; }
">=" { return GEQ; }
"^" { return XOR; }
"||" { return OR; }
"|" { return BOR; }
"&&" { return AND; }
"<=>" { return TWAY; }
"," {return COM;}
":" {return COL;}

"//".* {/*single line comment*/;}

"/*"([^*]|("*"[^/]))*"*/" {/*multi line comment*/;}
"/*"([^*]|("*"[^/]))* {printf("***lexing terminated*** [lexer error]: ill-formed comment\n"); exit(0);}

\"([^"\\]|(\\.))*\" {return SCONST; }

({INTEGER}|(0x{INTEGER})) { return ICONST; }
({INTEGER})?"."({INTEGER}) { return FCONST; }
({INTEGER})"."({INTEGER})? { return FCONST; }
'([^'\\]|(\\.))*' {return CCONST; }

{IDENTIFIER} { return VARIABLE; }

";"     { return SCOLON;}

[ \n\t\r]	{;}

.	    {printf("%d\n", yytext[0]); return ERR;}
%%

int yywrap(void) {
    //'(.|(\\[abfnvrt\\'0]))' {return CCONST; }
    return 1;
}


