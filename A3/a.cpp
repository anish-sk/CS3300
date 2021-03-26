%token IDENTIFIER INTEGER_NUMBER FLOAT_NUMBER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE PRINTF PERCENTD
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
    #include <bits/stdc++.h>
    using namespace std;
    #define nc (node->children)
    void yyerror(char*);
    int yylex(void);
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
    string code="";
    int labelc = 0;
    unordered_map<string, int> symbol_table;
    unordered_map<string, vector<int>> array_symbol_table;
    stack<int> rvalues;
    class treeNode {
        public:
            vector<treeNode*> children;   // children
            int maxRootedLength;          // maximum path length passing through this node
            int maxSubtreeLength;         // maximum path length in the subtree rooted at this node  
            int maxDirectLength;          // maximum path length ending at this node
            string nodeName;              // name of the node
            string lexValue;              // lexical value, name of identifier etc.
            int val;                      // value of the subexpression rooted at this node if exists
            int level;                    // for printing
            //int isarray;
            treeNode(string nodeName, vector<treeNode*> children) {  // for non-terminals, assume valid pointers are passed
                this->nodeName = nodeName;
                this->children = children;
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
                //isarray = 0;
                //compute();
            }
            treeNode(string nodeName) {     // for epsilon and terminals, no need to call compute
                this->nodeName = nodeName;
                children.assign(0, NULL);
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
            }
            int max_path_in_children() {
                vector<int> x;
                for(auto& child : children) {
                    x.push_back(child->maxSubtreeLength);
                }
                sort(x.rbegin(), x.rend());
                return x[0];
            }
            pair<int, int> max_and_smax_from_children() {
                vector<int> x;
                for(auto& child : children) {
                    if(child) {
                        x.push_back(child->maxDirectLength);
                    }
                }
                sort(x.rbegin(), x.rend());
                return {x[0], x[1]};
            }
            void compute() {
                if(children.size() == 0) {
        
                }
                if(children.size() == 1) {
                    maxDirectLength = 1 + children[0]->maxDirectLength;
                    maxRootedLength = maxDirectLength;
                    maxSubtreeLength = max(maxRootedLength, children[0]->maxSubtreeLength);
                }
                else {
                    pair<int, int> max_and_smax = max_and_smax_from_children();
                    maxDirectLength = 1 + max_and_smax.first;
                    maxRootedLength = 1 + max_and_smax.first + max_and_smax.second;
                    vector<int> x;
                    x.push_back(maxRootedLength);
                    for(auto& child : children) {
                        x.push_back(child->maxSubtreeLength);
                    }            
                    sort(x.rbegin(), x.rend());
                    maxSubtreeLength = x[0];
                }
            }
            void debug() {
                cout << nodeName << endl;
                for(auto& child : children) {
                    if(child) {
                        cout << child->nodeName << ' ';
                    }
                }
                cout << endl;
                cout << maxDirectLength << ' ' << maxRootedLength << ' ' << maxSubtreeLength << endl;
                cout.flush();
            }
    };
    class funcdetails{
        public:
        treeNode* comp_stmt;
        unordered_map<string, int> symbol_table;
        unordered_map<string, vector<int>> array_symbol_table;
        string name;
        deque<string> parameters; 
        funcdetails(){
            name = "$";
            comp_stmt = nullptr;
            symbol_table = unordered_map<string, int>();
            array_symbol_table = unordered_map<string, vector<int>> ();
            parameters = deque<string>();
        }
        funcdetails(funcdetails &f){
            this.name = f.name;
            this.comp_stmt = f.comp_stmt;
            this.symbol_table = f.symbol_table;
            this.array_symbol_table = f.array_symbol_table;
            this.parameters = f.parameters;
        }
    };
    stack<funcdetails *> fstack;
    unordered_map<string, funcdetails> functions;
    extern char* yytext;
    funcdetails current_function;
    treeNode* ast;   // pointer to the root of the final abstract syntax tree   
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
%type <node> format_specifier
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
                            }

         | extern_spec FLOAT    {
                                    $2 = new treeNode("FLOAT");
                                    vector<treeNode*> v = {$1, $2}; 
                                    $$ = new treeNode("type_spec", v);
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

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';'  {
                                                                    $1 = new treeNode("PRINTF"); $2 = new treeNode("("); $4 = new treeNode(",");
                                                                    $6 = new treeNode(")"); $7 = new treeNode(";");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("print_stmt", v); 
                                                                };

format_specifier: PERCENTD  {
                                $1 = new treeNode("PERCENTD");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("format_specifier", v);
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
                                $$->val = atoi((mytext));
                                //cout<<$$->val<<"\n";
                            };

floatLit: FLOAT_NUMBER  {
                            $1 = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("floatLit", v);
                            $$->lexValue = mytext;
                        };

identifier: IDENTIFIER  {
                            $1 = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("identifier", v);
                            $$->lexValue = mytext;
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

void printAST() {   // not a pretty printer
    queue<treeNode*> q;
    ast->level = 0;
    q.push(ast);
    int previous_level = 0;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        if(curr->level > previous_level) {
            cout << endl;
            previous_level = curr->level;
        }
        cout << curr->nodeName;
        for(int i = 0; i < 5; i++) {
            cout << ' ';
        }
        for(auto& child : curr->children) {
            child->level = 1 + curr->level;
            q.push(child);
        }
    }
    cout << endl;
}

void printAST(treeNode* root, string prefix = "", bool isLast = true) {
    if(root == NULL) {
        return;
    }
    cout << prefix;
    if(isLast) {
        cout << "└───────";
    }
    else {
        cout << "├───────";
    }
    cout << root->nodeName << endl;
    for(int i = 0; i < root->children.size(); i++) {
        if(i == root->children.size() - 1) {
            printAST(root->children[i], prefix + "|        ", true);
        }
        else {
            printAST(root->children[i], prefix + "|        ", false);
        }
    }
}
void compbexp(treeNode* node){
    int result = 0;
    int op1 = (nc[0])->val;
    int op2 = (nc[1])->val;
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
    node->val = result;
}
void compuexp(treeNode *node ){
    int result = 0;
    int op1 = nc[1]->val;
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
    node->val = result;
}
void populate_with_params(string name, treeNode *node){
   treeNode *param = nullptr; 
   if(nc.size() == 3){
       populate_with_params(name, nc[0]);
       param = nc[2];
   }
   else{
       param = nc[0];
   }
   functions[name].symbol_table[(param->children)[1]] = 0;
   parameters.push_back((param->children)[1].lexValue);
}
void populate_with_args(string name, treeNode *node, funcdetails *fcall, int &index ){
    treeNode *arg = nullptr;
    if(nc.size() == 3){
        populate_with_args(name, nc[0], fcall, index);
        arg = nc[2];
    }
    else{
        arg = nc[0];
    }
    fcall->symbol_table[fcall->parameters[index]] = arg->val;    
    index++;
}
void dfs(treeNode*);
void dfs(treeNode* node,unordered_map<string, int> &symbol_table, unordered_map<string, vector<int>> &array_symbol_table){
    if(node == nullptr){
        return;
    }
    else{
        string name = node->nodeName;
        if(name == "if_stmt"){                
            if(nc.size() == 5){                    
                dfs(nc[2]);
                if(nc[2]->val){                        
                    dfs(nc[4]);
                }
            }         
            else if(nc.size() == 7){
                dfs(nc[2]);
                if(nc[2]->val){                        
                    dfs(nc[4]);
                }
                else{
                    dfs(nc[6]);
                }
            }
            return;
        }
        else if(name == "while_stmt"){
            dfs(nc[2]);
            while(nc[2]->val){                    
                dfs(nc[4]);
                dfs(nc[2]);
            }                        
            return;
        }
        else if(name == "func_decl"){                
            symbol_table.clear();
            string fname = nc[1]->lexValue;
            if(fname != "main")
            {
                functions[fname] = funcdetails();
                functions[fname].comp_stmt = nc[5];
                if((nc[3]->children).size())
                populate_with_params(fname, (nc[3]->children)[0]);
            }
            string function_start = 
            "	.section	.rodata \n .LC0: \n .string	\"%d\\n\" \n .globl "	+ fname + "\n .type " + fname + ", @function \n";
            function_start += fname + ": \n pushq %rbp \n ";
            function_start += "movq	%rsp, %rbp \n";
            code += function_start;
            dfs(nc[5]);                    
            string function_end = " popq %rbp \n ret \n";
            function_end+= "  .size	" + fname + ", .-" + fname + "\n";
            code += function_end;
            return;
        }
        //cout<<name<<"\n"<<flush;
        if(nc.size())
        for(auto child : nc){
            dfs(child);
        }
        if(name == "identifier"){
            if(symbol_table.count(node->lexValue) == 0)
            symbol_table[node->lexValue] = 0;
            else node->val = symbol_table[node->lexValue];
        }
        else if(name == "local_decl"){
            if(nc.size() == 6){
               array_symbol_table[nc[1]->lexValue] = vector<int>(nc[3]->val, 0); 
            }
        }
        else if(name == "expr"){
            if(nc.size() == 1){
                treeNode* op = nc[0];
                if((op->children).size() == 2){
                    compbexp(op);
                    node->val = op->val;
                }
                else if(op->nodeName == "Pexpr"){
                    node->val = op->val;
                }
            }
            else if(nc.size() == 2){
                compuexp(node);
            }
            else if(nc.size() == 4){
                if(nc[0]->nodeName == "SIZEOF")
                node->val = 4;
                else if(nc[1]->nodeName == "["){
                    node->val = array_symbol_table[nc[0]->lexValue][nc[2]->val];
                }
                else if(nc[1]->nodeName == "("){
                    string fname = nc[0]->lexValue;
                    funcdetails *newfcall = new treeNode(functions[fname]);
                    if((nc[2]->children).size())
                        populate_with_args(fname, (nc[2]->children)[0], newfcall, 0); 
                    fstack.push(current_function);
                    rvalues.push(0);
                    current_function = *fcall;
                    dfs(fcall->comp_stmt);
                    node->val = rvalues.top();
                    rvalues.pop();
                    current_function = fstack.top();
                    fstack.pop();
                }

            }
        }
        else if(name == "Pexpr"){
            if(nc.size() == 3){                    
                node->val = nc[1]->val;
            }
            else{
                node->val = nc[0]->val;
            }
            //cout<<node->val<<"\n"<<flush;
        }
        else if(name == "assign_stmt"){                
            //cout<<"hi";
            treeNode *eqnode = nc[0];
            if((eqnode->children).size() == 2)
            symbol_table[(nc[0]->children[0])->lexValue] = (nc[0]->children[1])->val;
            else{
                array_symbol_table[(eqnode->children[0])->lexValue][(eqnode->children[2])->val] = (eqnode->children[4])->val;
            }
            //cout<<(nc[0]->children[0])->lexValue<<" "<<(nc[0]->children[1])->val<<"\n";
        }
        else if(name == "print_stmt"){
            //cout<<"hi";
            string printfcode = "   movl	$" + to_string(symbol_table[nc[4]->lexValue]) + ", %esi \n leaq	.LC0(%rip), %rdi \n ";
	        printfcode+= " movl	$0, %eax \n call printf@PLT  \n ";
            code+=printfcode;
        }
        else if(name == "return_stmt"){                
            // string returncode = "";
            if(nc.size() == 3){
            //     returncode += "movl $" + to_string(nc[2]->val) + ", %rax \n";
                rvalues.pop();
                rvalues.push(nc[1]->val);
            }

        }
        //else if(name == "integerLit"){
            //cout<<node->val<<"\n";
        //}
        //cout<<name<<"\n"<<flush;
    }
}
void dfs(treeNode* node){
    string name = current_function.name;
    dfs(node, functions[name].symbol_table, functions[name].array_symbol_table);
}
void codegen(){
    string bootstrap = ".file   \" input.c \" \n.text \n";
    code+=bootstrap;
    functions["main"] = funcdetails();
    functions["main"].name = "main";
    current_function = functions["main"];
    fstack.push(functions["main"]);
    rvalues.push(0);
    dfs(ast);
}
int main() {
    yyparse();
    // printf("***parsing successful***\n");
    //printAST(ast, "", true);
    codegen();
    cout<<code;
    return 0;
}
