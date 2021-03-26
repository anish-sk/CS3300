%token IDENTIFIER NUMBER INTEGER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT PRINTF FMTSPEC
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAXSIZE 15
    void yyerror(char*);
    int yylex(void);
    int max(int, int);
    FILE* yyin;
    char mytext[100];
    extern int integerConstantCount;
    int pointerDeclarations = 0;
    int lpath = 0;
    int iflpath = 0;
    int whilelpath = 0;
    int switchlpath = 0;
    int mainlpath = 0;
    int ismain = 0;
    struct node {
        int val;
        char name[100];
        int max;
        int maxending;
        struct node *children[MAXSIZE];
    };
    struct ab{
        int a;
        int b;
    };
    #define YYSTYPE struct node
    void initialize(struct ab children[]);
    int maxsubtree (struct ab children[]);
    int maxending(struct ab children[]);
    char mytext[100];
%}


%%

program         : decl_list
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

decl_list       : decl_list decl 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                //printf("after decl_list %d\n", $$.maxending);
                }
                | decl 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

decl            : var_decl 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                //printf("after var_decl%d\n", lpath);
                }
                | func_decl 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | struct_decl
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

struct_decl     : STRUCT identifier  '{' local_decls '}' ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

var_decl        : type_spec identifier  ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | type_spec identifier  ',' var_decl
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | type_spec identifier  '[' integerLit ']' ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | type_spec identifier  '[' integerLit ']' ',' var_decl
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                children[6].a = $7.max; children[6].b = $7.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

type_spec       : extern_spec VOID 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | extern_spec INT
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | extern_spec FLOAT
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | extern_spec VOID MULT 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | extern_spec INT MULT
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | extern_spec FLOAT MULT
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | STRUCT identifier  
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | STRUCT identifier  MULT
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

extern_spec     : EXTERN
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

func_decl       : type_spec identifier  {if(strcmp(mytext, "main") == 0) ismain = 1;} '(' params ')' compound_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                //children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = $7.max; children[6].b = $7.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                if(ismain){
                    mainlpath = max(mainlpath, $$.max);
                    ismain = 0;
                }
                //printf("after func_decl %d\n", $$.max);
                //printf("after comp_stmt %d\n", $7.max);
                }
                ;

params          : param_list
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                //printf("after params %d\n", $$.max);
                }
                | 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

param_list      : param_list ',' param 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | param
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

param           : type_spec identifier  
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | type_spec identifier  '[' ']'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = 1; children[3].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

stmt_list       : stmt_list stmt 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

stmt            : assign_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | compound_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | if_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | while_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | switch_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | return_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | break_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | continue_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | dowhile_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | print_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | incr_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | decr_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                | expr_stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                ;

/*expr_stmt       : expr ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;
*/

while_stmt      : WHILE '(' expr ')' stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                whilelpath = max(whilelpath, $$.max);
                }
                ;

dowhile_stmt    : DO stmt WHILE '(' expr ')' ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = 1; children[6].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

print_stmt      : PRINTF '(' format_specifier ',' identifier  ')' ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = 1; children[6].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

format_specifier    : FMTSPEC
                    {struct ab children[MAXSIZE]; initialize(children);
                    children[0].a = 1; children[0].b = 1;
                    $$.maxending = maxending(children);
                    $$.max = maxsubtree(children);
                    $$.max = max($$.max, $$.maxending);
                    lpath = max(lpath, $$.max);
                    }
                    ;

compound_stmt   : '{' local_decls stmt_list '}'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                //printf("after comp_stmt %d %d\n", $$.max, $$.maxending);
                }
                ;

local_decls     : local_decls local_decl
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                |
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

local_decl      : type_spec identifier  ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | type_spec identifier  '[' expr ']' ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = 1; children[4].b = 1;
                children[5].a = 1; children[5].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

if_stmt         : IF '(' expr ')' stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                iflpath = max(iflpath, $$.max);
                }
                | IF '(' expr ')' stmt ELSE stmt
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                children[6].a = $7.max; children[6].b = $7.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                iflpath = max(iflpath, $$.max);
                }
                ;

return_stmt     : RETURN ';' 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | RETURN expr ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

break_stmt      : BREAK ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

continue_stmt   : CONTINUE ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

switch_stmt     : SWITCH '(' expr ')' '{' compound_case default_case '}'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                children[4].a = 1; children[4].b = 1;
                children[5].a = $6.max; children[5].b = $6.maxending;
                children[6].a = $7.max; children[6].b = $7.maxending;
                children[7].a = 1; children[7].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                switchlpath = max(switchlpath, $$.max);
                }
                ;

compound_case   : single_case compound_case 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | single_case 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

single_case     : CASE integerLit ':' stmt_list
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                children[3].a = $4.max; children[3].b = $4.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

default_case    : DEFAULT ':' stmt_list
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

assign_stmt     : identifier  EQ expr ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = $4.max; children[3].b = $4.maxending;
                //printf("after expr %d %d\n", $3.max, $3.maxending);
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                //printf("after assign %d\n", $$.max);
                }
                | identifier  '[' expr ']' EQ expr ';'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                //children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = $6.max; children[5].b = $6.maxending;
                children[6].a = 1; children[6].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | identifier ARROW identifier  EQ expr ';'
                /*{struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending+1;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending+1;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | identifier  '.' identifier  EQ expr ';'
                /*{struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending+1;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending+1;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                //children[3].a = $4.max; children[3].b = $4.maxending;
                children[4].a = $5.max; children[4].b = $5.maxending;
                children[5].a = 1; children[5].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.maxending = maxending(children);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

incr_stmt       : identifier INC ';'
                /*{struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

decr_stmt       : identifier DEC ';'
                /*{struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                */
                
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

expr            : Pexpr LT Pexpr 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr GT Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr LEQ Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr GEQ Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr OR Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | SIZEOF '(' Pexpr ')'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | Pexpr EQEQ Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr NEQ Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr NEWOP Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr AND Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr ARROW Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr PLUS Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr MINUS Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr MULT Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr DIV Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | Pexpr MOD Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                //children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                int x = maxending(children);
                int y = maxsubtree(children);
                $$.maxending = max(x+1, 2);
                $$.max = max(x+2, y);
                //$$.max = maxsubtree(children);
                //$$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                /*
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }*/
                | NOT Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | MINUS Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | PLUS Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | MULT Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | BITAND Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | Pexpr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | identifier  '(' args ')'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | identifier  '[' expr ']'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[3].a = 1; children[3].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

Pexpr           : integerLit 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | floatLit 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | identifier  
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | '(' expr ')'
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                children[1].a = $2.max; children[1].b = $2.maxending;
                children[2].a = 1; children[2].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

integerLit      : INTEGER
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                //children[0].a = 0; children[0].b = -1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

floatLit        : NUMBER
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

identifier      : IDENTIFIER
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

arg_list        : arg_list ',' expr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                children[1].a = 1; children[1].b = 1;
                children[2].a = $3.max; children[2].b = $3.maxending;
                children[2].a = $3.max; children[2].b = $3.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | expr
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;

args            : arg_list 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = $1.max; children[0].b = $1.maxending;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                | 
                {struct ab children[MAXSIZE]; initialize(children);
                children[0].a = 1; children[0].b = 1;
                $$.maxending = maxending(children);
                $$.max = maxsubtree(children);
                $$.max = max($$.max, $$.maxending);
                lpath = max(lpath, $$.max);
                }
                ;


%%

void yyerror(char* s) {
    printf("syntax error\n");
    exit(0);
}

void initialize(struct ab children[]){
    for(int i=0; i<MAXSIZE; i++){
        children[i].a =  0;
        children[i].b =  0;

    }
}

int maxending(struct ab children[]){
    int mx = 0;
    for(int i=0; i<MAXSIZE; i++){
        mx = max(mx, children[i].b);
    }
    return (mx+1);
}

int maxsubtree(struct ab children[]){
    int m1=0, m2 =0;
    for(int i=0; i<MAXSIZE; i++){
        if(children[i].b >=m1){
            m2 = m1;
            m1 = children[i].b;
        }
        else if(children[i].b >=m2){
            m2 = children[i].b;
        }
    }
    int m3 = 0;
    for(int i=0; i<MAXSIZE; i++){
        m3 = max(m3, children[i].a);
    }
    return max(m3,m1 + m2 + 1);
}

int max(int a, int b) {
    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main(int argc, char** argv) {
    //yyin = fopen(argv[1], "r");
    //if(argc == 1) {
    //    printf("***process terminated*** [error]\n");
    //}
    //else {
    //    FILE* fp = fopen(argv[1], "r");
    //    if(fp) {
    //        yyin = fp;
    //        yyparse();
    //        printf("%d\n", lpath);
    //        printf("%d\n", iflpath);
    //        printf("%d\n", whilelpath);
    //        printf("%d\n", switchlpath);
    //        printf("%d\n", mainlpath);
    //    }
    //    else {
    //        printf("***process terminated*** [error]\n");
    //    }
    //}
    yyparse();
    printf("%d\n", lpath);
    printf("%d\n", iflpath);
    printf("%d\n", whilelpath);
    printf("%d\n", switchlpath);
    printf("%d\n", mainlpath);
    return 0;
}
