%token IDENTIFIER INTEGER_NUMBER FLOAT_NUMBER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE PRINTF PERCENTD PERCENTDSLASHN SCANF
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
    #include <bits/stdc++.h>
    #include "IRGenerator.hpp"
    using namespace std;
    void yyerror(char*);
    int yylex(void);
    #define nc (node->children)
    void set_programLongestPath(int); // Set Longest Path in the program
    void set_ifLongestPath(int);      // Set Longest Path among all subtrees of if statement
    void set_whileLongestPath(int);   // Set Longest Path among all subtrees of while statement
    void set_mainLongestPath(int);    // Set Longest Path of main subtee
    void set_switchLongestPath(int);  // Set Longest Path among all subtrees of switch statement
    extern FILE* yyin;
    char mytext[10000];
    int programLongestPath = 0;
    int ifLongestPath = 0;
    int whileLongestPath = 0;
    int mainLongestPath = 0;
    int switchLongestPath = 0;
    int isMain = 0;
    int prop_need = 1;  
    extern char* yytext;
    treeNode* ast;   // pointer to the root of the final abstract syntax tree   
    int line_no = 0;
    unordered_map<string, int> curr_isconst;
    unordered_map<string, int> curr_symbol_table;
    unordered_map<string, int> used;
    unordered_map<string, int> isconst;
    unordered_map<string, int> if_isconst;
    unordered_map<string, int> else_isconst;
    unordered_map<string, int> symbol_table;
    unordered_map<string, int> if_symbol_table;
    unordered_map<string, int> else_symbol_table;
    vector<string> varlist;
    vector<vector<string>> summary(6, vector<string>());
    unordered_map<int, string> opti_list{
                                {0, "unused-vars"},
                                {1, "if-simpl"},
                                {2, "strength-reduction"},
                                {3, "constant-folding"},
                                {4, "constant-propagation"},
                                {5, "cse"},
                                };
    int if_else = -1;
    map<int, int> constant_folding;
    map<int, vector<pair<string, int>>> constant_prop;
    map<int, int> strength_reduction;
    map<string, int> curr_var_counter;
    map<string, int> var_counter;
    map<string, int> if_var_counter;
    map<string, int> else_var_counter;
    int global_counter = 0; 
    int curr_global_counter = 0;
    struct vnnode{
        string name;
        int l;
        int r;
    };
    #define vnentry pair<string, pair<int, int> >
    map<vnentry, int> curr_value_number;
    map<int, vnentry> curr_rev_value_number;
    map<vnentry, int> value_number;
    map<int, vnentry> rev_value_number;
    map<vnentry, int> if_value_number;
    map<int, vnentry> if_rev_value_number;
    map<vnentry, int> else_value_number;
    map<int, vnentry> else_rev_value_number;
    map<int, multiset<int>> csubexprs;
    set<string> constlist;
%}

%union {
    class treeNode* node;
}

%type <node> program
%type <node> decl_list
%type <node> decl
%type <node> struct_decl
%type <node> var_decl
%type <node> type_spec
%type <node> extern_spec
%type <node> func_decl
%type <node> params
%type <node> param_list
%type <node> param
%type <node> stmt_list
%type <node> stmt
// %type <node> expr_stmt
%type <node> while_stmt
%type <node> dowhile_stmt
%type <node> print_stmt
%type <node> scanf_stmt
%type <node> format_specifier1
%type <node> format_specifier2
%type <node> compound_stmt
%type <node> local_decls
%type <node> local_decl
%type <node> if_stmt
%type <node> return_stmt
%type <node> break_stmt
%type <node> continue_stmt
%type <node> switch_stmt
%type <node> compound_case
%type <node> single_case
%type <node> default_case
%type <node> assign_stmt
%type <node> incr_stmt
%type <node> decr_stmt
%type <node> expr
%type <node> Pexpr
%type <node> integerLit
%type <node> floatLit
%type <node> identifier
%type <node> arg_list
%type <node> args

%type <node> IDENTIFIER
%type <node> INTEGER_NUMBER
%type <node> FLOAT_NUMBER
%type <node> PRINTF
%type <node> PERCENTD
%type <node> PERCENTDSLASHN
%type <node> SCANF
%type <node> PLUS
%type <node> MINUS
%type <node> MULT
%type <node> DIV
%type <node> IF
%type <node> ELSE
%type <node> FOR
%type <node> WHILE
%type <node> DO
%type <node> INT
%type <node> FLOAT
%type <node> CHAR
%type <node> EQ
%type <node> EQEQ
%type <node> GEQ
%type <node> LEQ
%type <node> GT
%type <node> LT
%type <node> NEWOP
%type <node> NEQ
%type <node> BITAND
%type <node> BITOR
%type <node> BITNOT
%type <node> BITXOR
%type <node> AND
%type <node> OR
%type <node> NOT
%type <node> MOD
%type <node> EXTERN
%type <node> LONG
%type <node> SHORT
%type <node> DOUBLE
%type <node> VOID
%type <node> SWITCH
%type <node> CASE
%type <node> STRUCT
%type <node> BREAK
%type <node> CONTINUE
%type <node> RETURN
%type <node> STRLITERAL
%type <node> CHARLITERAL
%type <node> INC
%type <node> DEC
%type <node> ARROW
%type <node> SIZEOF
%type <node> DEFAULT
%type <node> '['
%type <node> ']'
%type <node> '('
%type <node> ')'
%type <node> ';'
%type <node> ','
%type <node> ':'
%type <node> '{'
%type <node> '}'
%type <node> '.'
%%

program: decl_list  {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("program", v); 
                        set_programLongestPath($$->maxSubtreeLength);
                        ast = $$;
                    };

decl_list: decl_list decl   { 
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("decl_list", v); 
                            }

         | decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl_list", v); 
                };
         
decl: var_decl  {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 
                }

    | func_decl {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("decl", v); 
                }

    | struct_decl   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("decl", v); 
                    };

struct_decl: STRUCT identifier '{' local_decls '}' ';'  {
                                                            $1 = new treeNode("STRUCT"); $3 = new treeNode("{"); 
                                                            $5 = new treeNode("}"); $6 = new treeNode(";");
                                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                            $$ = new treeNode("struct_decl", v); 
                                                        };

var_decl: type_spec identifier ';'  {
                                        $3 = new treeNode(";");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("var_decl", v); 
                                    }

        | type_spec identifier ',' var_decl {
                                                $3 = new treeNode(",");
                                                vector<treeNode*> v = {$1, $2, $3, $4};
                                                $$ = new treeNode("var_decl", v); 
                                            }   

        | type_spec identifier '[' integerLit ']' ';'   {
                                                            $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                            $$ = new treeNode("var_decl", v); 
                                                        }
    
        | type_spec identifier '[' integerLit ']' ',' var_decl  {
                                                                    $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(",");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("var_decl", v); 
                                                                };

type_spec: extern_spec VOID {
                                $2 = new treeNode("VOID");
                                vector<treeNode*> v = {$1, $2}; 
                                $$ = new treeNode("type_spec", v); 
                            }
         | extern_spec INT  {
                                $2 = new treeNode("INT");
                                vector<treeNode*> v = {$1, $2}; 
                                $$ = new treeNode("type_spec", v);
                                $$->width = 4;
                            }

         | extern_spec FLOAT    {
                                    $2 = new treeNode("FLOAT");
                                    vector<treeNode*> v = {$1, $2}; 
                                    $$ = new treeNode("type_spec", v);
                                    $$->width = 8;
                                }

         | extern_spec VOID MULT {
                                    $2 = new treeNode("VOID"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                }

         | extern_spec INT MULT {
                                    $2 = new treeNode("INT"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                }

         | extern_spec FLOAT MULT {
                                    $2 = new treeNode("FLOAT"); $3 = new treeNode("MULT");
                                    vector<treeNode*> v = {$1, $2, $3}; 
                                    $$ = new treeNode("type_spec", v);
                                  }

         | STRUCT identifier    {
                                    $1 = new treeNode("STRUCT");
                                    vector<treeNode*> v = {$1, $2};
                                    $$ = new treeNode("type_spec", v); 
                                }
         | STRUCT identifier MULT   {
                                        $1 = new treeNode("STRUCT"); $3 = new treeNode("MULT");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("type_spec", v);
                                    };

extern_spec: EXTERN {
                        $1 = new treeNode("EXTERN");
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("extern_spec", v);
                    }
           |    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    $$ = new treeNode("extern_spec", v);
                };

func_decl: type_spec identifier '(' params ')' compound_stmt    {
                                                                    $3 = new treeNode("("); $5 = new treeNode(")");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                                    $$ = new treeNode("func_decl", v);      
                                                                    if($2->lexValue == "main") {
                                                                        set_mainLongestPath($$->maxSubtreeLength);
                                                                    }
                                                                };

params: param_list  {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("params", v);
                    } 
      | {
          auto x = new treeNode("epsilon");
          vector<treeNode*> v = {x};
          $$ = new treeNode("params", v);
        };

param_list: param_list ',' param    {
                                        $2 = new treeNode(",");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("param_list", v);
                                    }
          | param   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("param_list", v);
                    };

param: type_spec identifier {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("param", v);
                            }
     | type_spec identifier '[' ']' {
                                        $3 = new treeNode("["); $4 = new treeNode("]");
                                        vector<treeNode*> v = {$1, $2, $3, $4};
                                        $$ = new treeNode("param", v);
                                    };

stmt_list: stmt_list stmt   {
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("stmt_list", v);
                            }
         | stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt_list", v);
                };

stmt: assign_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | compound_stmt {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | if_stmt   {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }
    | while_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | switch_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | return_stmt   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | break_stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                 }
    | continue_stmt {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | dowhile_stmt  {    
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | print_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | scanf_stmt    {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("stmt", v);
                    }
    | incr_stmt {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }  
    | decr_stmt {   
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("stmt", v);
                }; 

while_stmt: WHILE '(' expr ')' stmt { 
                                        $1 = new treeNode("WHILE");
                                        $2 = new treeNode("("); $4 = new treeNode(")");
                                        vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                        $$ = new treeNode("while_stmt", v); 
                                        set_whileLongestPath($$->maxSubtreeLength); 
                                    };

dowhile_stmt: DO stmt WHILE '(' expr ')' ';' { 
                                                $1 = new treeNode("DO"); $3 = new treeNode("WHILE");
                                                $4 = new treeNode("("); $6 = new treeNode(")"); $7 = new treeNode(";");
                                                vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                $$ = new treeNode("dowhile_stmt", v);  
                                            };

print_stmt: PRINTF '(' format_specifier1 ',' identifier ')' ';'  {
                                                                    $1 = new treeNode("PRINTF"); $2 = new treeNode("("); $4 = new treeNode(",");
                                                                    $6 = new treeNode(")"); $7 = new treeNode(";");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("print_stmt", v); 
                                                                };

format_specifier1: PERCENTDSLASHN  {
                                $1 = new treeNode("PERCENTDSLASHN");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("format_specifier1", v);
                            };
scanf_stmt: SCANF '(' format_specifier2 ',' BITAND identifier ')' ';'  {
                                                                    $1 = new treeNode("SCANF"); $2 = new treeNode("("); $4 = new treeNode(",");
                                                                    $5 = new treeNode("&");
                                                                    $7 = new treeNode(")"); $8 = new treeNode(";");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7, $8};
                                                                    $$ = new treeNode("scanf_stmt", v); 
                                                                    //cout<<"asbd"<<flush;
                                                                };

format_specifier2: PERCENTD  {
                                $1 = new treeNode("PERCENTD");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("format_specifier2", v);
                                //cout<<"abd"<<flush;
                            };

compound_stmt: '{' local_decls stmt_list '}'    {
                                                    $1 = new treeNode("{"); $4 = new treeNode("}");
                                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                                    $$ = new treeNode("compound_stmt", v);
                                                };

local_decls: local_decls local_decl {
                                        vector<treeNode*> v = {$1, $2};
                                        $$ = new treeNode("local_decls", v);
                                    } 
           |    {
                    auto x = new treeNode("epsilon");
                    vector<treeNode*> v = {x};
                    $$ = new treeNode("local_decls", v);
                };

local_decl: type_spec identifier ';'    {
                                            $3 = new treeNode(";");
                                            vector<treeNode*> v = {$1, $2, $3};
                                            $$ = new treeNode("local_decl", v);
                                        }
          | type_spec identifier '[' expr ']' ';'   {
                                                        $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                        $$ = new treeNode("local_decl", v); 
                                                    };

if_stmt: IF '(' expr ')' stmt   {   
                                    $1 = new treeNode("IF");
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                    $$ = new treeNode("if_stmt", v);
                                    set_ifLongestPath($$->maxSubtreeLength); 
                                }
       | IF '(' expr ')' stmt ELSE stmt { 
                                            $1 = new treeNode("IF");
                                            $2 = new treeNode("("); $4 = new treeNode(")"); $6 = new treeNode("ELSE");
                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                            $$ = new treeNode("if_stmt", v);
                                            set_ifLongestPath($$->maxSubtreeLength); 
                                        };

return_stmt: RETURN ';' { 
                            $1 = new treeNode("RETURN"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("return_stmt", v);
                        }
           | RETURN expr ';'    {
                                    $1 = new treeNode("RETURN"); $3 = new treeNode(";");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("return_stmt", v);
                                };

break_stmt: BREAK ';'   {
                            $1 = new treeNode("BREAK"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("break_stmt", v);
                        };

continue_stmt: CONTINUE ';' {
                                $1 = new treeNode("CONTINUE"); $2 = new treeNode(";");
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("continue_stmt", v);
                            };

switch_stmt: SWITCH '(' expr ')' '{' compound_case default_case '}' {
                                                                        $1 = new treeNode("SWITCH");
                                                                        $2 = new treeNode("("); $4 = new treeNode(")");
                                                                        $5 = new treeNode("{"); $8 = new treeNode("}");
                                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7, $8};
                                                                        $$ = new treeNode("switch_stmt", v);
                                                                        set_switchLongestPath($$->maxSubtreeLength);    
                                                                    };

compound_case: single_case compound_case    {
                                                vector<treeNode*> v = {$1, $2};
                                                $$ = new treeNode("compound_case", v); 
                                            }
             | single_case  {
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("compound_case", v);
                            };

single_case: CASE integerLit ':' stmt_list  {
                                                $1 = new treeNode("CASE"); $3 = new treeNode(":");
                                                vector<treeNode*> v = {$1, $2, $3, $4};
                                                $$ = new treeNode("single_case", v);
                                            };

default_case: DEFAULT ':' stmt_list {
                                        $1 = new treeNode("DEFAULT"); $2 = new treeNode(":");
                                        vector<treeNode*> v = {$1, $2, $3};
                                        $$ = new treeNode("default_case", v);
                                    };

assign_stmt: identifier EQ expr ';' {
                                        vector<treeNode*> u = {$1, $3};
                                        $2 = new treeNode("EQ", u);
                                        $4 = new treeNode(";");
                                        vector<treeNode*> v = {$2, $4};
                                        $$ = new treeNode("assign_stmt", v);
                                        
                                    }
           | identifier '[' expr ']' EQ expr ';'    {   // check this one
                                                        $2 = new treeNode("["); $4 = new treeNode("]"); $7 = new treeNode(";");
                                                        vector<treeNode*> u = {$1, $2, $3, $4, $6};
                                                        $5 = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {$5, $7};
                                                        $$ = new treeNode("assign_stmt", v);    
                                                    }
           | identifier ARROW identifier EQ expr ';'    {
                                                            $6 = new treeNode(";");
                                                            $2 = new treeNode("ARROW");
                                                            vector<treeNode*> u = {$1, $2, $3, $5};
                                                            $4 = new treeNode("EQ", u);
                                                            vector<treeNode*> v = {$4, $6};
                                                            $$ = new treeNode("assign_stmt", v);
                                                        }
           | identifier '.' identifier EQ expr ';'  {
                                                        $6 = new treeNode(";");
                                                        $2 = new treeNode(".");
                                                        vector<treeNode*> u = {$1, $2, $3, $5};
                                                        $4 = new treeNode("EQ", u);
                                                        vector<treeNode*> v = {$4, $6};
                                                        $$ = new treeNode("assign_stmt", v);
                                                    };

incr_stmt: identifier INC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("INC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("incr_stmt", v);
                                };

decr_stmt: identifier DEC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("DEC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("decr_stmt", v);
                                };

expr: Pexpr LT Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr GT Pexpr    {   
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr LEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr GEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr OR Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("OR", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | SIZEOF '(' Pexpr ')'  {
                                $1 = new treeNode("SIZEOF"); $2 = new treeNode("("); $4 = new treeNode(")");
                                vector<treeNode*> v = {$1, $2, $3, $4};
                                $$ = new treeNode("expr", v);
                            }
    | Pexpr EQEQ Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr NEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr NEWOP Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr AND Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("AND", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr ARROW Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("ARROW", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr PLUS Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("PLUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MINUS Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MINUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MULT Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MULT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr DIV Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("DIV", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | Pexpr MOD Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MOD", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v);
                        }
    | NOT Pexpr {
                    $1 = new treeNode("NOT");
                    vector<treeNode*> v = {$1, $2};
                    $$ = new treeNode("expr", v);
                }
    | MINUS Pexpr   {
                        $1 = new treeNode("MINUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | PLUS Pexpr    {
                        $1 = new treeNode("PLUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | MULT Pexpr    {
                        $1 = new treeNode("MULT");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | BITAND Pexpr  {   
                        $1 = new treeNode("BITAND");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v);
                    }
    | Pexpr {
                vector<treeNode*> v = {$1};
                $$ = new treeNode("expr", v);
            }
    | identifier '(' args ')'   {
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 
                                }
    | identifier '[' expr ']'   {
                                    $2 = new treeNode("["); $4 = new treeNode("]");
                                    vector<treeNode*> v = {$1, $2, $3, $4};
                                    $$ = new treeNode("expr", v); 
                                };

Pexpr: integerLit   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);
                    }
     | floatLit {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("Pexpr", v);
                }
     | identifier   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v);
                    }
     | '(' expr ')' {
                        $1 = new treeNode("("); $3 = new treeNode(")");
                        vector<treeNode*> v = {$1, $2, $3};
                        $$ = new treeNode("Pexpr", v);
                    };

integerLit: INTEGER_NUMBER  {
                                $1 = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("integerLit", v);
                                $$->lexValue = mytext;
                                $$->width = 4;
                                $$->line_no = line_no;
                                $$->isconst = 1;
                                $$->value = strtol(mytext, NULL, 0);
                            };

floatLit: FLOAT_NUMBER  {
                            $1 = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("floatLit", v);
                            $$->lexValue = mytext;
                            $$->width = 8;
                            $$->line_no = line_no;
                            $$->isconst = 1;
                            $$->value = strtol(mytext, NULL, 0);
                        };

identifier: IDENTIFIER  {
                            $1 = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("identifier", v);
                            $$->lexValue = mytext;
                            $$->line_no = line_no;
                        } 
          | PRINTF  {
                        $1 = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("identifier", v);
                        $$->lexValue = "printf";
                    };

arg_list: arg_list ',' expr {
                                $2 = new treeNode(",");
                                vector<treeNode*> v = {$1, $2, $3};
                                $$ = new treeNode("arg_list", v);
                            }
        | expr  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("arg_list", v);
                };

args: arg_list  {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("args", v);
                }
    |   {
            auto x = new treeNode("epsilon");
            vector<treeNode*> v = {x};
            $$ = new treeNode("args", v);
        };

%%

void yyerror(char* s) {
    printf("***parsing terminated*** [syntax error]\n");
    exit(0);
}

void set_programLongestPath(int x) {
    programLongestPath = max(programLongestPath, x);
}

void set_ifLongestPath(int x) {
    ifLongestPath = max(ifLongestPath, x);
}

void set_whileLongestPath(int x) {
    whileLongestPath = max(whileLongestPath, x);
}

void set_switchLongestPath(int x) {
    switchLongestPath = max(switchLongestPath, x);
}

void set_mainLongestPath(int x) {
     mainLongestPath = max(mainLongestPath, x);
}


int compbexp(treeNode* node){
    int result = 0;
    int op1 = (nc[0])->value;
    int op2 = (nc[1])->value;
    //cerr<<"op1= "<<op1<<" op2 = "<<op2<<"\n";
    if(!(nc[0]->isconst && nc[1]->isconst)){
        return -1;
    }
    string name = node->nodeName;
    if(name == "LT"){
        result = op1 < op2;
    }
    else if(name == "GT"){
        result = op1 > op2;
    }
    else if(name == "LEQ"){
        result = op1 <= op2;
    }
    else if(name == "GEQ"){
        result = op1 >= op2;
    }
    else if(name == "OR"){
        result = op1 || op2;
    }
    else if(name == "EQEQ"){
        result = op1 == op2;
    }
    else if(name == "NEQ"){
        result = op1 != op2;
    }
    else if(name == "NEWOP"){
        result = (op1 < op2)?-1:((op1 == op2)?0:1);
    }
    else if(name == "AND"){
        result = op1 && op2;
    }
    else if(name == "PLUS"){
        //cerr<<(nc[0])->nodeName<<" op1 = "<<op1<<" op2 = "<<op2<<"\n";
        result = op1 + op2;
    }
    else if(name == "MINUS"){
        result = op1 - op2;
    }
    else if(name == "MULT"){
        result = op1 * op2;
    }
    else if(name == "DIV"){
        result = op1 / op2;
    }
    else if(name == "MOD"){
        result = op1 % op2;
    }
    node->value = result;
    if(name == "PLUS" or name == "MINUS" or name == "MULT" or name == "DIV"){
        if(constant_folding.count(node->line_no)){
            constant_folding[node->line_no] = max(constant_folding[node->line_no], result);
        }
        else{
            constant_folding[node->line_no] = result;
        }
    }
    return 0;
}
int compuexp(treeNode *node ){
    int result = 0;
    int op1 = nc[1]->value;
    if(!(nc[1]->isconst)){
        return -1;
    }
    string name = nc[0]->nodeName;
    if(name == "NOT"){
        result = !(op1);
    }
    else if(name == "MINUS"){
        result = -op1;
    }
    else if(name == "PLUS"){
        result = op1;
    }
    node->value = result;
    constant_folding[node->line_no] = max(constant_folding[node->line_no], result);
    return 0;
}
void fold(treeNode* node, int val){
    treeNode *nnode = new treeNode("integerLit");
    nnode->isconst = 1;
    nnode->value = val;
    nnode->lexValue = to_string(val);
    nnode->width = 4;
    nnode->line_no = node->line_no;
    vector<treeNode*> u = {nnode};
    treeNode *mnode = new treeNode("Pexpr", u);
    mnode->isconst = 1;
    mnode->value = val;
    //cerr<<val<<"\n";
    *node = *mnode;
}
void dfs(treeNode*);
void dfs(treeNode* node,unordered_map<string, int> &symbol_table, unordered_map<string, int> & isconst){
    if(node == nullptr){
        return;
    }
    else{
        string name = node->nodeName;
        if(name == "if_stmt"){                
            if(nc.size() == 5){ 
                prop_need = 0;                   
                dfs(nc[2]);
                prop_need = 1;                   
                if(nc[2]->isconst){                        
                    if(nc[2]->value){
                        if_else = 1;
                        dfs(nc[4]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[4];
                        *node = *nnode;       
                    }
                    else{
                        if_else = 0;
                        node->nodeName = "if_gone";
                    }
                }
                else{                        
                    curr_symbol_table = symbol_table;
                    curr_isconst = isconst;
                    dfs(nc[4]);
                    if_symbol_table = symbol_table;
                    if_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    for(auto ip: if_symbol_table){
                        if(ip.second != symbol_table[ip.first]){
                            isconst[ip.first] = 0;
                        }
                    }
                    for(auto ip: if_isconst){
                        if(ip.second == 0 or isconst[ip.first] == 0){
                            isconst[ip.first] = 0;
                        }
                    }
                }
            }         
            else if(nc.size() == 7){
                prop_need = 0;                   
                dfs(nc[2]);
                prop_need = 1;                   
                if(nc[2]->isconst){                        
                    if(nc[2]->value){
                        if_else = 1;
                        dfs(nc[4]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[4];
                        *node = *nnode;       
                    }
                    else{
                        if_else = 0;
                        dfs(nc[6]);
                        treeNode *nnode = new treeNode("stmt");
                        *nnode = *nc[6];
                        *node = *nnode;       
                    }
                }
                else{                        
                    //if_symbol_table = symbol_table;
                    //if_isconst = isconst;
                    curr_symbol_table = symbol_table;
                    curr_isconst = isconst;
                    dfs(nc[4]);
                    if_symbol_table = symbol_table;
                    if_isconst = isconst;
                    //else_symbol_table = symbol_table;
                    //else_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    dfs(nc[6]);
                    else_symbol_table = symbol_table;
                    else_isconst = isconst;
                    symbol_table = curr_symbol_table;
                    isconst = curr_isconst;
                    for(auto ip: if_symbol_table){
                        if(ip.second != else_symbol_table[ip.first]){
                            isconst[ip.first] = 0;
                        }
                    }
                    for(auto ip: if_isconst){
                        if(ip.second == 0 or else_isconst[ip.first] == 0){
                            isconst[ip.first] = 0;
                        }
                        else if(ip.second == 1 and else_isconst[ip.first] == 1){
                            if(if_symbol_table[ip.first] == else_symbol_table[ip.first]){
                                isconst[ip.first] = 1;
                            }
                        }
                    }
                    for(auto ip: if_symbol_table){
                        if(isconst.count(ip.first) and isconst[ip.first]){
                            if(ip.second == else_symbol_table[ip.first]){
                                symbol_table[ip.first] = ip.second;
                            }
                        }
                    }
                }
            }
            //(fstack.top()).print_stable();
            return;
        }
        else if(name == "while_stmt"){
            /* dfs(nc[2]);
            wcount = 0;
            while(nc[2]->val and ((wcount)++ < maxloop) and (!finish)){                    
                dfs(nc[4]);
                dfs(nc[2]);
            }                        
            return; */
        }
        else if(name == "func_decl"){                
            //hello
        }
        //cout<<name<<"\n"<<flush;
        if(nc.size())
        for(auto child : nc){
            dfs(child);
            if(child->isconst){
            if(name == "AND" and !(child->value))
            break;
            if(name == "OR" and child->value)
            break;
            } 
        }
        if(name == "identifier"){
            if(symbol_table.count(node->lexValue) == 0)
            symbol_table[node->lexValue] = 0;
            else node->value = symbol_table[node->lexValue];
            if(isconst[node->lexValue]){
                node->isconst = 1;
            }
        }
        else if(name == "local_decl"){
            if(nc.size() == 3){                    
                varlist.push_back(nc[1]->lexValue);       
            }
        }
        else if(name == "expr"){
            if(nc.size() == 1){
                treeNode* op = nc[0];
                if((op->children).size() == 2){
                    if( compbexp(op) == 0){
                        fold(node, op->value);
                    }
                }
                else if(op->nodeName == "Pexpr"){
                    if(nc[0]->isconst){
                        node->value = op->value;
                        node->isconst = 1;
                    }
                }
            }
            else if(nc.size() == 2){
                if(compuexp(node) == 0){
                    fold(node, node->value);
                }
            }
            else if(nc.size() == 4){
                if(nc[0]->nodeName == "SIZEOF")
                    {
                        if(nc[2]->isconst){
                            fold(node, nc[2]->width);
                        }
                    }
                else if(nc[1]->nodeName == "["){
                    
                }
                else if(nc[1]->nodeName == "("){
                   
                }
            }
        }
        else if(name == "Pexpr"){
            if(nc.size() == 3){ 
                if(nc[1]->isconst){
                    fold(node, nc[1]->value);
                    node->width = nc[1]->width;
                }                   
            }
            else{
                if(nc[0]->isconst){
                    //cerr<<nc[0]->lexValue<<" "<<nc[0]->value<<" "<<node->value<<"\n";
                    if(nc[0]->nodeName == "identifier" and prop_need){
                        constant_prop[node->line_no].push_back({nc[0]->lexValue, nc[0]->value});
                    }
                    fold(node, nc[0]->value);
                    node->width = nc[0]->width;
                }
                if(nc[0]->nodeName == "identifier"){
                    used[nc[0]->lexValue] = 1;
                }
            }
        }
        else if(name == "assign_stmt"){                
            //cout<<"hi";
            treeNode *eqnode = nc[0];
            if((eqnode->children).size() == 2){
            used[(nc[0]->children[0])->lexValue] = 1;
            if((nc[0]->children[1])->isconst){
                symbol_table[(nc[0]->children[0])->lexValue] = (nc[0]->children[1])->value;
                isconst[(nc[0]->children[0])->lexValue] = 1;
            }
            else{
                isconst[(nc[0]->children[0])->lexValue] = 0;
            }
            }
        }
        else if(name == "print_stmt"){
            //cout<<"hi";
            used[nc[4]->lexValue] = 1;
            if(nc[4]->isconst)
            constant_prop[node->line_no].push_back({nc[4]->lexValue, nc[4]->value});
        }
        else if(name == "scanf_stmt"){                
            nc[5]->isconst = 0;
            isconst[nc[5]->lexValue] = 0;
            used[nc[5]->lexValue] = 1;
        }
        else if(name == "return_stmt"){                
            if(nc.size() == 3){                    

            }
        }
    }
}
void dfs(treeNode* node){
    dfs(node, symbol_table, isconst);
}

void sr(treeNode* node){
    if(node == nullptr){
        return;
    }
    /*if(node->line_no == 27){
        cerr<<node->value<<" "<<node->nodeName<<"\n";
    }*/
    if(constant_folding.count(node->line_no) and node->nodeName == "integerLit"){
        constant_folding[node->line_no] = max(constant_folding[node->line_no], node->value);
    }
    for(auto child: nc){
        sr(child);
    }
    string name = node->nodeName;
    if(name == "MULT"){
        int va = nc[1]->value;
        //cerr<<va<<"\n";
        if(((va & (va - 1)) == 0) and va){
            int res = -1;
            while(va){
                res++;
                va = va >> 1;
            }
            fold(nc[1], res);
            node->nodeName = "SLEFTR";
            strength_reduction[node->line_no] = max(strength_reduction[node->line_no], res);
            constlist.insert(to_string(res));
        }
        va = nc[0]->value;
        if(((va & (va - 1)) == 0) and va){
            int res = -1;
            while(va){
                res++;
                va = va >> 1;
            }
            fold(nc[0], res);
            node->nodeName = "SLEFTL";
            strength_reduction[node->line_no] = max(strength_reduction[node->line_no], res);
            constlist.insert(to_string(res));
        }

        
    }
    if(name == "integerLit"){
        constlist.insert(node->lexValue);
    }
}
void sav(int x){
    if(x == 0){
        curr_value_number = value_number;
        curr_rev_value_number = rev_value_number;
        curr_global_counter = global_counter;
        curr_var_counter = var_counter;
    }
    else if(x == 1){
        if_value_number = value_number;
        if_rev_value_number = rev_value_number;
        if_var_counter = var_counter;
        value_number = curr_value_number;
        rev_value_number = curr_rev_value_number;
        var_counter = curr_var_counter;
        global_counter = curr_global_counter;
    }
    else{
        else_value_number = value_number;
        else_rev_value_number = rev_value_number;
        else_var_counter = var_counter;
        value_number = curr_value_number;
        rev_value_number = curr_rev_value_number;
        var_counter = curr_var_counter;
        global_counter = curr_global_counter;
    }
}
void cse(treeNode * node){
    if(node == nullptr) return;
    string name = node->nodeName;
    /*if(name == "if_stmt"){
        if(nc.size() == 5){
            cse(nc[2]);
            sav(0);
            cse(nc[4]);
            sav(1);
            //cerr<<"hi";
        }
        else if(nc.size() == 7){
            cse(nc[2]);
            sav(0);
            cse(nc[4]);
            sav(1);
            cse(nc[6]);
            sav(2);
            for(auto ip: if_var_counter){
                if(ip.second > var_counter[ip.first]){
                    global_counter++;
                    var_counter[ip.first]++;
                }
            }
            for(auto ip: else_var_counter){
                if(ip.second > var_counter[ip.first]){
                    global_counter++;
                    var_counter[ip.first]++;
                }
            }
        }
        return;
    }*/
    if(nc.size())
    for(auto child: nc){
        cse(child);
    }
    if(name == "Pexpr"){
        if(nc.size() == 3){
            node->numbering = nc[1]->numbering;
        }
        else{
            if(nc[0]->nodeName == "identifier"){
                vnentry entr = {nc[0]->lexValue + "$" + to_string(var_counter[nc[0]->lexValue]),{-1,-1}};
                if(value_number.count(entr))
                node->numbering = value_number[entr];
                else{
                    global_counter++;
                    value_number[entr] = global_counter;
                    rev_value_number[global_counter] = entr;
                    node->numbering = value_number[entr];
                }
            }
            else{
                vnentry entr = {nc[0]->lexValue,{-1,-1}};
                node->numbering = value_number[entr];
            }
        }
    }
    else if(name == "expr"){
            if(nc.size() == 1){
                treeNode* op = nc[0];
                if((op->children).size() == 2){
                    //cerr<<"hi\n";
                    int l = (op->children[0])->numbering;
                    int r = (op->children[1])->numbering;
                    vnentry entr =  {op->nodeName,{l,r}};
        //cerr<<entr.first<<" "<<entr.second.first<<" "<<entr.second.second<<"\n";
                    if(value_number.count(entr)){                            
                        csubexprs[value_number[entr]].insert(node->line_no);
                    } 
                    else{
                        global_counter++;
                        value_number[entr]=global_counter;
                        rev_value_number[global_counter]=entr;
                        csubexprs[value_number[entr]].insert(node->line_no);
                    }
                    //cerr<<value_number[entr]<<"\n";
                    node->numbering = value_number[entr];
                }
                else if(op->nodeName == "Pexpr"){
                    node->numbering = op->numbering;
                }
            }
    }
    else if(name == "assign_stmt"){
        treeNode *eqnode = nc[0];
        if((eqnode->children).size() == 2){
            var_counter[(eqnode->children[0])->lexValue]++;
            //global_counter++;
            //value_number[{node->lexValue + to_string(var_counter[node->lexValue]),{-1,-1}}] = global_counter;
            //rev_value_number[global_counter] = {node->lexValue + to_string(var_counter[node->lexValue]),{-1,-1}};
        }
    }
    else if(name == "scanf_stmt"){ 
        var_counter[nc[5]->lexValue]++;
    }               
}

int main() {
    yyparse();
    // printf("***parsing successful***\n");
    // printf("%d\n", programLongestPath);
    // printf("%d\n", ifLongestPath);
    // printf("%d\n", whileLongestPath);
    // printf("%d\n", switchLongestPath);
    // printf("%d\n", mainLongestPath);
    dfs(ast);
    for(auto ip: constant_folding){
        constant_folding[ip.first] = -1e9;
    }
    sr(ast);
    for (auto x: varlist){
        global_counter ++;
        value_number[{x+"$0",{-1,-1}}] = global_counter;
        rev_value_number[global_counter] = {x+"$0",{-1,-1}};
    }
    for (auto x: constlist){
        global_counter ++;
        value_number[{x,{-1,-1}}] = global_counter;
        rev_value_number[global_counter] = {x,{-1,-1}};
    }
    cse(ast);
    //printAST(ast);
    for(auto var: varlist){
        if(!(used.count(var))){
            if(var == "main") continue;
            summary[0].push_back(var);
        }
    }
    if(if_else != -1){
        summary[1].push_back(to_string(if_else));
    }
    for(auto ip : strength_reduction){
        summary[2].push_back(to_string(ip.first + 1) + " " + to_string(ip.second));
    }
    for(auto ip: constant_folding){
        if(ip.second != -1e9)
        summary[3].push_back(to_string(ip.first + 1) + " " + to_string(ip.second));
    }
    map<string, int> index;
    for(int i=0; i<varlist.size(); i++){
        index[varlist[i]] = i; 
    }
    map<int, set< pair<int, pair< string, int > > > > constant_prop_ord;
    for(auto ip: constant_prop){
        for(auto pa: ip.second){
            constant_prop_ord[ip.first].insert({index[pa.first],pa});
        }
    }
    for(auto ip: constant_prop_ord){
        string su = to_string(ip.first+1);
        string st = "";
        for(auto pa: ip.second){
            //if(isconst[pa.first])
            st += (" " + pa.second.first + " " + to_string(pa.second.second));
        }
        if(st.size())
        summary[4].push_back(su+st);
    }
    for(auto ip: csubexprs){
        //cerr<<ip.first<<"\n";
        if(ip.second.size() == 1){
            continue;
        }
        vnentry x = rev_value_number[ip.first];
        //cerr<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
        if(x.second.first == -1 or x.second.first == 0){
            continue;
        }
        //cerr<<x.first<<" "<<x.second.first<<" "<<x.second.second<<"\n";
        string su =  "";
        for(auto line: ip.second){
            su += (" " + to_string(line+1));
        }
        summary[5].push_back(su.substr(1));
    }
    int a = generateIR();   // generate 3AC intermediate representation
    ofstream summ;
    summ.open("summary.txt");
    for(int i=0; i<6; i++){
        summ<<opti_list[i]<<"\n";
        for(auto line: summary[i]){
            summ<<line<<"\n";
        }
        if(i<5)
        summ<<"\n";
    }
    summ.close();
    return 0;
}
