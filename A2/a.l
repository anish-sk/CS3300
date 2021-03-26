%{
    #include "y.tab.h"
    int integerConstantCount = 0;  // count the number of integers
    extern char mytext[];
%}

digit [0-9]
hexdigit [0-9a-f]
letter [a-zA-Z]
hex "0x"
Ls "l"|"ll"|"L"|"LL"|"u"|"U"
number {digit}+(\.{digit}+)?(e[+-]?{digit}+)?{Ls}?  
integer {digit}+{Ls}?
hexinteger {hex}{hexdigit}+{Ls}?
identifier ({letter}|_)({letter}|_|{digit})*
delim [ \t\n]
all ({delim}|.)
whiteSpace {delim}+
colon :
semicolon ;
dot \.
comma ,

%%

"//".*[\n] {
   
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    
}

"/*" {
    printf("lexer error\n");
    exit(0);
}

\"%d\" {
    strcpy(mytext, yytext);
    return FMTSPEC;
}

\"([^\n"\\]|\\.)*\" {
    strcpy(mytext, yytext);
    return STRLITERAL;
}

'(\\.|[^\n\\'])+' {
    strcpy(mytext, yytext);
    integerConstantCount++;
    return CHARLITERAL;
}

int {
    strcpy(mytext, yytext);
    return INT;
}

float {
    strcpy(mytext, yytext);
    return FLOAT;
}

char {
    strcpy(mytext, yytext);
    return CHAR;
}

long {
    strcpy(mytext, yytext);
    return LONG;
}

double {
    strcpy(mytext, yytext);
    return DOUBLE;
}

short {
    strcpy(mytext, yytext);
    return SHORT;
}

void {
    strcpy(mytext, yytext);
    return VOID;
}

if {
    strcpy(mytext, yytext);
    return IF;
}

else {
    strcpy(mytext, yytext);
    return ELSE;
}

for {
    strcpy(mytext, yytext);
    return FOR;
}

while {
    strcpy(mytext, yytext);
    return WHILE;
}

do {
    strcpy(mytext, yytext);
    return DO;
}

switch {
    strcpy(mytext, yytext);
    return SWITCH;
}

case {
    strcpy(mytext, yytext);
    return CASE;
}

printf {
    strcpy(mytext, yytext);
    return PRINTF;
}

struct {
    strcpy(mytext, yytext);
    return STRUCT;
}

break {
    strcpy(mytext, yytext);
    return BREAK;
}

continue {
    strcpy(mytext, yytext);
    return CONTINUE;
}

return {
    strcpy(mytext, yytext);
    return RETURN;
}

sizeof {
    strcpy(mytext, yytext);
    return SIZEOF;
}

default {
    strcpy(mytext, yytext);
    return DEFAULT;
}

extern {
    strcpy(mytext, yytext);
    return EXTERN;
}

{integer} {
    strcpy(mytext, yytext);
    integerConstantCount++;
    return INTEGER;
}

{hexinteger} {
    strcpy(mytext, yytext);
    integerConstantCount++;
    return INTEGER;
}

{number} {
    strcpy(mytext, yytext);
    return NUMBER;
}

{identifier} {
    strcpy(mytext, yytext);
    return IDENTIFIER;
}

"->"|"++"|"--" {
    if(strcmp(yytext, "++") == 0) {
        return INC;
    }
    else if(strcmp(yytext, "--") == 0) {
        return DEC;
    }
    else if(strcmp(yytext, "->") == 0) {
        return ARROW;
    }
}

[&|^~] {
    char ch = yytext[0];
    switch (ch) {
        case '&' : return BITAND;
            break;
        case '|' : return BITOR;
             break;
        case '^' : return BITXOR;
            break;
        case '~' : return BITNOT;
            break;
    }
}

"&&"|"||"|"!" {
    if(strcmp(yytext, "&&") == 0) {
        return AND;
    }
    else if(strcmp(yytext, "||") == 0) {
        return OR;
    }
    else if(strcmp(yytext, "!") == 0) {
        return NOT;
    }
}

[%*+/-] {
    char ch = yytext[0];
    switch (ch) {
        case '+' : return PLUS;
            break;
        case '-' : return MINUS;
             break;
        case '*' : return MULT;
            break;
        case '/' : return DIV;
            break;
        case '%' : return MOD;
            break;
    }
}

"=="|"<="|">="|">"|"<"|"<=>"|"!=" {
    if(strcmp(yytext, "==") == 0) {
        return EQEQ;
    }
    else if(strcmp(yytext, ">=") == 0) {
        return GEQ;
    }
    else if(strcmp(yytext, "<=") == 0) {
        return LEQ;
    }
    else if(strcmp(yytext, ">") == 0) {
        return GT;
    }
    else if(strcmp(yytext, "<") == 0) {
        return LT;
    }
    else if(strcmp(yytext, "!=") == 0) {
        return NEQ;
    }
    else if(strcmp(yytext, "<=>") == 0){
        return NEWOP;
    }   
}

\= {
    return EQ;
}

"(" {
    return '(';
}

")" {
    return ')';
}

"[" {
    return '[';
}

"]"  {
    return ']';
}

"{" {
    return '{';
}

"}" {
    return '}';
}

{whiteSpace} {
   
}

{dot} {
    return '.'; 
}

{colon} {
    return ':';
}

{comma} {
    return ',';
}

{semicolon} {
    return ';';
}

. {
    
}

%%

int yywrap(void) {
    return 1;
}
