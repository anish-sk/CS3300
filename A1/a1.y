%token VARIABLE BREAK CASE CHAR COL COM CONTINUE DEFAULT DO DOUBLE ELSE ERR EXTERN FLOAT FOR IF INT LONG RETURN SHORT SIZEOF STRUCT SWITCH VOID WHILE LSQ RSQ LPA RPA LCU RCU DOT ARROW PINC PDEC BAND MUL ADD SUB NEG NOT DIV MOD LESS GRTR LEQ GEQ EEQ EQ NEQ XOR OR BOR AND TWAY SCONST SCOLON FCONST ICONST CCONST
%{
        
	#include <stdio.h>
        #include <string.h>
        #include <stdlib.h>
        void yyerror(char *);
        int yylex(void);
        char mytext[100];
        char var[100];
        int num = 0;
        extern char *yytext;
        extern FILE *yyin;
        extern int yylineno;
        int er = 0;
        int yydebug = 1;
        int global_declarations = 0;
        int function_definitions = 0;
        int integer_constants = 0;
        int local_pointer = 0;
        int pointers_declarations = 0;
        int ifs_without_else = 0;
        int max_depth = 0;
        #define max(x, y) (x>=y?x:y) 
%}
%nonassoc IF
%nonassoc ELSE


%left COM
%left OR
%left AND
%left BOR
%left XOR
%left BAND
%left EEQ NEQ
%left LESS GRTR LEQ GEQ TWAY
%left ADD SUB
%left MUL DIV MOD
%right NOT NEG SIZEOF DUMMY
%left ARROW DOT PDEC PINC
%%
/* program: lines;
 
lines: oneline {
		printf("lines: oneline\n");
    	}
	| oneline lines {
		printf("lines: oneline lines\n");
	}
;

oneline: TYPE VARIABLE {strcpy(var, yytext);} EQ NUMBER {num = atoi(yytext);} ';' {
		printf("oneline %s %d\n", var, num);
	}
    | IF VARIABLE THEN oneline{
        printf("if-then\n");
    }
;*/
/*
program: line | line program
;
line:    VARIABLE {printf("%s", yytext);} |
            BREAK {printf("%s", yytext);} |
            CASE {printf("%s", yytext);} |
            CHAR{printf("%s", yytext);} |
            CONTINUE {printf("%s", yytext);} |
            DEFAULT {printf("%s", yytext);} |
            DO {printf("%s", yytext);} |
            DOUBLE {printf("%s", yytext);} |
            ELSE {printf("%s", yytext);} |
            EXTERN {printf("%s", yytext);} |
            FLOAT {printf("%s", yytext);} |
            FOR {printf("%s", yytext);} |
            IF {printf("%s", yytext);} |
            INT{printf("%s", yytext);} |
            LONG{printf("%s", yytext);} |
            RETURN{printf("%s", yytext);} |
            SHORT{printf("%s", yytext);} |
            SIZEOF{printf("%s", yytext);} |
            STRUCT{printf("%s", yytext);} |
            SWITCH{printf("%s", yytext);} |
            VOID {printf("%s", yytext);} |
            WHILE{printf("%s", yytext);} |
            LSQ{printf("%s", yytext);} |
            RSQ{printf("%s", yytext);} |
            LPA{printf("%s", yytext);} |
            RPA{printf("%s", yytext);} |
            LCU{printf("%s", yytext);} |
            RCU{printf("%s", yytext);} |
            DOT{printf("%s", yytext);} |
            ARROW{printf("%s", yytext);} |
            PINC{printf("%s", yytext);} |
            PDEC{printf("%s", yytext);} |
            BAND{printf("%s", yytext);} |
            MUL{printf("%s", yytext);} |
            ADD{printf("%s", yytext);} |
            SUB{printf("%s", yytext);} |
            NEG{printf("%s", yytext);} |
            NOT{printf("%s", yytext);} |
            DIV{printf("%s", yytext);} |
            MOD{printf("%s", yytext);} |
            LESS{printf("%s", yytext);} |
            GRTR{printf("%s", yytext);} |
            LEQ{printf("%s", yytext);} |
            GEQ{printf("%s", yytext);} |
            EEQ{printf("%s", yytext);} |
            EQ{printf("%s", yytext);} |
            NEQ{printf("%s", yytext);} |
            XOR{printf("%s", yytext);} |
            OR{printf("%s", yytext);} |
            BOR{printf("%s", yytext);} |
            AND{printf("%s", yytext);} |
            TWAY{printf("%s", yytext);} |
            SCONST{printf("%s", yytext);} |
            SCOLON{printf("%s", yytext);} |
            FCONST{printf("%s", yytext);} |
            ICONST{printf("%s", yytext);} |
            CCONST {printf("%s ", yytext);}
*/
program : declaration_list 
        {$$ = $1; max_depth = max(max_depth, $$);}
        ;

declaration_list    : declaration
                    {global_declarations++;$$ = max($$, $1);}
                    | declaration 
                    {global_declarations++;}
                    declaration_list
                    {$$ = max($1, $2);
                    //printf("%d", $$);
                    max_depth = max(max_depth, $$);}
                    ;

declaration : var_declaration 
            {$$ = 0;}
            | fun_declaration
            {$$ = $1;}
            | fun_prototype
            | struct_definition
            ;

var_declaration : type var_list
                | type SCOLON
                ;

svar_declaration        : type svar_list
                        | type SCOLON
                        ;

//var_declaration_list : var_declaration 
//                     | var_declaration var_declaration_list
//                     ;
svar_declaration_list : svar_declaration 
                     | svar_declaration svar_declaration_list
                     ;

basic_type  : INT {/*printf("found int\n");*/}
            | FLOAT
            | CHAR
            | VOID
            | STRUCT VARIABLE {/*printf("hey struct %s\n", yytext);*/}
            | LONG
            | SHORT
            | EXTERN
            | DOUBLE
            ;

type: basic_type
    | type basic_type
    ;

pointer_type    : type 
                | type stars
                ;

stars   : MUL
        | MUL stars
        ;

var_list        
                : var_dec {/*printf("var %s found\n", yytext);*/} SCOLON
                | var_dec {/*printf("var %s found\n", yytext);*/} COM var_list
                ;

svar_list       
                : svar_dec {/*printf("var %s found\n", yytext);*/} SCOLON
                | svar_dec {/*printf("var %s found\n", yytext);*/} COM svar_list
                ;

var_dec : var_dec_lhs
        | var_dec_lhs EQ expression
        ;

svar_dec : var_dec_lhs
        ;

var_dec_lhs     : var_id 
                //| var_dec_lhs LSQ expression RSQ
                | var_dec_lhs LSQ exp_wrap RSQ
                ;

var_id : VARIABLE {local_pointer = 0;} 
       | MUL {local_pointer++; if(local_pointer == 1) pointers_declarations++;} var_id
       ;

fun_declaration : type var_id LPA proto_param_list RPA compound_statement
                {function_definitions++; $$ = $6;}
                ;

fun_prototype : type var_id LPA proto_param_list RPA SCOLON
              ;

proto_param_list: 
                | proto_params 
                | proto_params COM proto_param_list
                ;

proto_params: pointer_type
            | type var_id
            | type var_id nd_bracket
            ;

nd_bracket  : LSQ RSQ
            | nd_bracket LSQ RSQ

struct_definition : STRUCT VARIABLE LCU svar_declaration_list RCU SCOLON 
                  | STRUCT VARIABLE LCU svar_declaration_list RCU var_list 
                  {/*printf("struct found");*/}
                 ;

decl_statement  : var_declaration
                | struct_definition
                ;

statement_list  : statement
                {$$ = $1;}
                | statement statement_list
                {$$ = max($1, $2);}
                ;

compound_statement  : LCU RCU
                    | LCU statement_list RCU
                    {$$ = $2;}
                    ;

statement   : compound_statement
                    {$$ = $1;}
            | decl_statement
                    {$$ = $1;}
            | if_statement
                    {$$ = $1;}
            | while_statement
                    {$$ = $1;}
            | switch_statement
                    {$$ = $1;}
            | return_statement
                    {$$ = $1;}
            | break_statement
                    {$$ = $1;}
            | case_statement
                    {$$ = $1;}
            | assign_statement
                    {$$ = $1;}
            | for_statement
                    {$$ = $1;}
            | continue_statement
                    {$$ = $1;}
            | default_statement
                    {$$ = $1;}
            | do_statement
                    {$$ = $1;}
            | expression_statement
                    {$$ = $1;}
            | SCOLON
            ;

lstatement   : compound_statement
                    {$$ = $1;}
            | if_statement
                    {$$ = $1;}
            | while_statement
                    {$$ = $1;}
            | switch_statement
                    {$$ = $1;}
            | return_statement
                    {$$ = $1;}
            | break_statement
                    {$$ = $1;}
            | case_statement
                    {$$ = $1;}
            | assign_statement
                    {$$ = $1;}
            | for_statement
                    {$$ = $1;}
            | continue_statement
                    {$$ = $1;}
            | default_statement
                    {$$ = $1;}
            | do_statement
                    {$$ = $1;}
            | expression_statement
                    {$$ = $1;}
            | SCOLON
            ;

if_statement    : IF LPA expression RPA lstatement 
                {ifs_without_else++;
                $$ = $5;}
                | IF LPA expression RPA lstatement ELSE lstatement
                {$$ = max($5, 1 + $7);
                max_depth = max(max_depth, $$);
                //printf("%d", $$);
                }
                ;

while_statement : WHILE LPA expression RPA lstatement
                {$$ = $5;}
                ;

switch_statement : SWITCH LPA expression RPA lstatement 
                 {$$ = $5;}
                 ;

return_statement    : RETURN SCOLON
                    | RETURN expression SCOLON
                    ;

case_statement : CASE expression COL statement_list
               ;

continue_statement : CONTINUE SCOLON
                   ;

break_statement : BREAK SCOLON
                ;

default_statement   : DEFAULT COL statement_list 
                    {$$ = $3;}
                    ;

assign_statement    : term EQ expression SCOLON
                    ;

//assign_statement01  : 
//                    | assign_statement
//                    ;

exp_wrap        : 
                | expression
                ;

for_statement   : FOR LPA exp_wrap SCOLON exp_wrap SCOLON exp_wrap RPA lstatement
                {$$ = $9;}
                | FOR LPA var_declaration exp_wrap SCOLON exp_wrap RPA lstatement
                {$$ = $8;}
                ;

do_statement    : DO lstatement WHILE LPA expression RPA SCOLON
                {$$ = $2;}
                ;

expression  : term EQ expression
            | expression binary_operator expression
            | expression relational_operator expression 
            | expression logical_operator expression 
            | cast_expression term
            | term
            ;

cast_expression : LPA pointer_type RPA  

term    : SUB term %prec DUMMY
        | ADD term %prec DUMMY
        | unary_operator term
        | MUL term %prec DUMMY
        | BAND term %prec DUMMY
        | term PINC
        | term PDEC
        | PINC term %prec DUMMY
        | PDEC term %prec DUMMY
        | SIZEOF LPA term RPA
        | SIZEOF LPA pointer_type RPA
        | lhs
        | constants
        | function_call
        | LPA expression RPA
        | LCU expression RCU
        ;

lhs : VARIABLE 
    | lhs LSQ expression RSQ
    ;

function_call   : VARIABLE LPA arguments RPA
                ;

arguments   : argument_list
            | 
            ;

argument_list   : expression
                | argument_list COM expression

expression_statement    : expression SCOLON
                        ;

constants   : ICONST {integer_constants++;}
            | CCONST {integer_constants++;}
            | FCONST
            | multisconsts
            ;

multisconsts    : SCONST
                | SCONST multisconsts
                ;

binary_operator : ADD
                | SUB
                | MUL
                | DIV
                | MOD
                | BAND
                | BOR
                | XOR
                | TWAY
                | ARROW
                | DOT
                | COM
                ;

relational_operator : EEQ
                    | LEQ
                    | LESS
                    | GRTR
                    | GEQ
                    | NEQ
                    ;

logical_operator    : AND
                    | OR
                    ;

unary_operator : NEG
               | NOT
               ;

%%

void yyerror(char *s) {
    er++;
    if(er == 1){
        fprintf(stdout, "***parsing terminated*** [syntax error]\n");
        //fprintf(stdout, "lineno = %d", yylineno);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2){
        printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
    }
    else{
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
        }
        else{
            yyparse();
            if(er == 0){
                printf("***parsing successful***\n");
                printf("#global_declarations = %d\n", global_declarations);
                printf("#function_definitions = %d\n", function_definitions);
                printf("#integer_constants = %d\n", integer_constants);
                printf("#pointers_declarations = %d\n", pointers_declarations);
                printf("#ifs_without_else = %d\n", ifs_without_else);
                printf("if-else max-depth = %d\n", max_depth);
            }
        }
    }
    return 0;
}

