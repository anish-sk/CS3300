%token IDENTIFIER INTEGER_NUMBER FLOAT_NUMBER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE PRINTF SCANF PERCENTD PERCENTDD
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
    #include <bits/stdc++.h>
    #include <fstream>
    using namespace std;
    void yyerror(char*);
    int yylex(void);     extern FILE* yyin;
    char mytext[10000];
    //Useless begins

    void set_programLongestPath(int); // Set Longest Path in the program
    void set_ifLongestPath(int);      // Set Longest Path among all subtrees of if statement
    void set_whileLongestPath(int);   // Set Longest Path among all subtrees of while statement
    void set_mainLongestPath(int);    // Set Longest Path of main subtee
    void set_switchLongestPath(int);  // Set Longest Path among all subtrees of switch statement
    int programLongestPath = 0;
    int ifLongestPath = 0;
    int whileLongestPath = 0;
    int mainLongestPath = 0;
    int switchLongestPath = 0;
    int isMain = 0;

    //Useless ends

    int linecount = 1;
    ofstream outas("assembly.s");

    int getOffset();
    map <string, int>  ST;
    map <string , int> ArrayST;
    map <string,int>::iterator it;

    map <string, int> used;
    vector <string> unused;
    vector <string> varList;
    unordered_map <int,int> MaxVals; // lineNum , max integerLit at that point
    map <string,int> values; // Variable , CurrentValue
    map <string,int> VarLastDec; //Variables and their most recent declaration linenumbers are stored
    map <string, map <int , vector <int> > > ExprList; // Expression , LastDecl Point , LineNumber Vectors
    map <int, map <string, int> > CP;
    map<int, int> CF;
    map<int,int>  SR;


    //void constProp_Fold(treeNode* root);

    int offset = 0;
    int labelcount = 0;
    int IfSimple = -1;
    class treeNode {
        public:
            vector<treeNode*> children;   // children
            int maxRootedLength;          // maximum path length passing through this node
            int maxSubtreeLength;         // maximum path length in the subtree rooted at this node  
            int maxDirectLength;          // maximum path length ending at this node
            string nodeName;              // name of the node
            string lexValue;              // lexical value, name of identifier etc.
            int level;                    // for printing
	    int linenum;
	    bool known;
	    int CFVal;
	    int value;
	    int lastDec;
	    bool valueCalc;
	    string FinalExpr;
	    treeNode(){
		;
	    }

	    treeNode(string nodeName, vector <treeNode*> children , int linenumb){
		this->nodeName = nodeName;
                this->children = children;
		this->linenum = linenumb;
	    }

	    treeNode(string nodeName, vector <treeNode*> children , int linenumb, int known){
		this->nodeName = nodeName;
                this->children = children;
		this->linenum = linenumb;
		this->known = known;
	    }

            treeNode(string nodeName, vector<treeNode*> children) {  // for non-terminals, assume valid pointers are passed
                this->nodeName = nodeName;
                this->children = children;
                maxRootedLength = 1;
                maxSubtreeLength = 1;
                maxDirectLength = 1;
                compute();
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
                outas << nodeName << endl;
                for(auto& child : children) {
                    if(child) {
                        outas << child->nodeName << ' ';
                    }
                }
                outas << endl;
                outas << maxDirectLength << ' ' << maxRootedLength << ' ' << maxSubtreeLength << endl;
                outas.flush();
            }
    };
    extern char* yytext;
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
%type <node> scan_stmt
%type <node> print_stmt
%type <node> format_specifier
%type <node> format_specifier1
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
%type <node> SCANF
%type <node> PERCENTD
%type <node> PERCENTDD
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
    | scan_stmt     {
			vector <treeNode*> v = {$1};
			$$ = new treeNode("stmt",v);
		
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


scan_stmt : SCANF '(' format_specifier1 ',' BITAND identifier ')' ';' {
						
						$1 = new treeNode("SCANF");
						$2 = new treeNode("(");
						$4 = new treeNode(",");
						$5 = new treeNode("&");
						$7 = new treeNode(")");
						vector <treeNode*> v  = {$1,$2,$3,$4 ,$5,$6,$7};
						$$ = new treeNode("scan_stmt",v, linecount);  	

};

print_stmt: PRINTF '(' format_specifier ',' identifier ')' ';'  {
                                                                    $1 = new treeNode("PRINTF"); $2 = new treeNode("("); $4 = new treeNode(",");
                                                                    $6 = new treeNode(")"); $7 = new treeNode(";");
                                                                    vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                                                    $$ = new treeNode("print_stmt", v, linecount); 
                                                                };
format_specifier1 : PERCENTDD{

				$1 = new treeNode("PERCENTDD");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("format_specifier1", v);
		  

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
                                            $$ = new treeNode("local_decl", v, linecount);
					    //string idname = $2->lexValue;
			    	            //int curroffset = getOffset();
			    		    //ST.insert( make_pair( idname , curroffset));
		
					    
                                        }
          | type_spec identifier '[' expr ']' ';'   {
                                                        $3 = new treeNode("["); $5 = new treeNode("]"); $6 = new treeNode(";");
                                                        vector<treeNode*> v = {$1, $2, $3, $4, $5, $6};
                                                        $$ = new treeNode("local_decl", v); 

							//int arraylength = stoi($4->children[0]->children[0]->lexValue);
							//string idname = $2->lexValue;
			    				//int curroffset = getOffset();
			    				//ST.insert( make_pair( idname , curroffset));
							//ArrayST.insert(make_pair( idname , arraylength));			
							//offset++; //Pointer to int has size 8 bytes
						
                                                    };

if_stmt: IF '(' expr ')' stmt   {   
                                    $1 = new treeNode("IF");
                                    $2 = new treeNode("("); $4 = new treeNode(")");
                                    vector<treeNode*> v = {$1, $2, $3, $4, $5};
                                    $$ = new treeNode("if_stmt", v, linecount);
                                    set_ifLongestPath($$->maxSubtreeLength); 
                                }
       | IF '(' expr ')' stmt ELSE stmt { 
                                            $1 = new treeNode("IF");
                                            $2 = new treeNode("("); $4 = new treeNode(")"); $6 = new treeNode("ELSE");
                                            vector<treeNode*> v = {$1, $2, $3, $4, $5, $6, $7};
                                            $$ = new treeNode("if_stmt", v, linecount);
                                            set_ifLongestPath($$->maxSubtreeLength); 
                                        };

return_stmt: RETURN ';' { 
                            $1 = new treeNode("RETURN"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("return_stmt", v, linecount);
                        }
           | RETURN expr ';'    {
                                    $1 = new treeNode("RETURN"); $3 = new treeNode(";");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("return_stmt", v, linecount);
                                };

break_stmt: BREAK ';'   {
                            $1 = new treeNode("BREAK"); $2 = new treeNode(";");
                            vector<treeNode*> v = {$1, $2};
                            $$ = new treeNode("break_stmt", v, linecount);
                        };

continue_stmt: CONTINUE ';' {
                                $1 = new treeNode("CONTINUE"); $2 = new treeNode(";");
                                vector<treeNode*> v = {$1, $2};
                                $$ = new treeNode("continue_stmt", v, linecount);
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
                                        $$ = new treeNode("assign_stmt", v, linecount);
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
                                    $$ = new treeNode("incr_stmt", v, linecount);
                                };

decr_stmt: identifier DEC ';'   {
                                    $3 = new treeNode(";");
                                    $2 = new treeNode("DEC");
                                    vector<treeNode*> v = {$1, $2, $3};
                                    $$ = new treeNode("decr_stmt", v, linecount);
                                };

expr: Pexpr LT Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr GT Pexpr    {   
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr LEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("LEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr GEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("GEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr OR Pexpr    {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("OR", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | SIZEOF '(' Pexpr ')'  {
                                $1 = new treeNode("SIZEOF"); $2 = new treeNode("("); $4 = new treeNode(")");
                                vector<treeNode*> v = {$1, $2, $3, $4};
                                $$ = new treeNode("expr", v, linecount);
                            }
    | Pexpr EQEQ Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("EQEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr NEQ Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEQ", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr NEWOP Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("NEWOP", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr AND Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("AND", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr ARROW Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("ARROW", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr PLUS Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("PLUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr MINUS Pexpr {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MINUS", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr MULT Pexpr  {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("MULT", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
                        }
    | Pexpr DIV Pexpr   {
                            vector<treeNode*> u = {$1, $3};
                            $2 = new treeNode("DIV", u);
                            vector<treeNode*> v = {$2};
                            $$ = new treeNode("expr", v, linecount);
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
                    $$ = new treeNode("expr", v, linecount);
                }
    | MINUS Pexpr   {
                        $1 = new treeNode("MINUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v, linecount);
                    }
    | PLUS Pexpr    {
                        $1 = new treeNode("PLUS");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v, linecount);
                    }
    | MULT Pexpr    {
                        $1 = new treeNode("MULT");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v, linecount);
                    }
    | BITAND Pexpr  {   
                        $1 = new treeNode("BITAND");
                        vector<treeNode*> v = {$1, $2};
                        $$ = new treeNode("expr", v, linecount);
                    }
    | Pexpr {
                vector<treeNode*> v = {$1};
                $$ = new treeNode("expr", v , linecount);
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
                        $$ = new treeNode("Pexpr", v , $1->linenum);
                    }
     | floatLit {
                    vector<treeNode*> v = {$1};
                    $$ = new treeNode("Pexpr", v, $1->linenum);
                }
     | identifier   {
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("Pexpr", v, $1->linenum);
                    }
     | '(' expr ')' {
                        $1 = new treeNode("("); $3 = new treeNode(")");
                        vector<treeNode*> v = {$1, $2, $3};
                        $$ = new treeNode("Pexpr", v , $2->linenum);
                    };

integerLit: INTEGER_NUMBER  {
                                $1 = new treeNode("INTEGER_NUMBER");
                                vector<treeNode*> v = {$1};
                                $$ = new treeNode("integerLit", v , linecount);
				$$->lexValue = mytext;
                            };

floatLit: FLOAT_NUMBER  {
                            $1 = new treeNode("FLOAT_NUMBER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("floatLit", v , linecount);
			    $$->lexValue = mytext;
                        };

identifier: IDENTIFIER  {
                            $1 = new treeNode("IDENTIFIER");
                            vector<treeNode*> v = {$1};
                            $$ = new treeNode("identifier", v , linecount );
                            $$->lexValue = mytext;
                        } 
          | PRINTF  {
                        $1 = new treeNode("IDENTIFIER");
                        vector<treeNode*> v = {$1};
                        $$ = new treeNode("identifier", v , linecount);
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

bool customSort(vector <int> &a, vector <int> &b){
	if(a.size() > 0 && b.size() >0)
	 	return a[0] < b[0];
}

void PrintReturn(){

		outas<<"	movl $0, %eax" << endl;
		outas<<"	leave" <<endl;
		outas<<"	ret" << endl;


}

void PrintInit(){

	
	outas<<"	 .file \"source.c\" " << endl;
	outas<<"	 .text" << endl;
	outas<<"	 .section .rodata" << endl;
	outas<<".LC1: "<< endl;
	outas<<" 	.string \"%d\"" << endl;
	outas<<".LC0: " << endl;
	outas<<"	.string \"%d\\n\"" << endl;
	outas<<"	.text" << endl;
	outas<<"	.globl main"<< endl;
	outas<<"	.type main, @function"<< endl;
	outas<<"main:"<< endl;
	outas<<"	pushq %rbp"<< endl;
	outas<<"	movq %rsp, %rbp"<< endl;
	//cout << offset << "offset ehre is " << endl;
	int stackval = (((offset+1)*4)/16 + 1)*16;
	outas<<"	subq $"<< stackval <<", %rsp"<< endl;

}
int pow2(int op){
	int rem;
	int counter = 0;
	while(op > 1){
		rem = op%2;
		if(rem == 0){
			counter++;
			op=op/2;
		}
		else return -1;
	}
    return counter;
}
void PrintCode(treeNode* root){

	
       if(root == NULL) return;

       string nodetype = root->nodeName;

	if(nodetype == "local_decl"){
		
		switch(root->children.size()){

		
		case 3 : { 
			

			    break;
		}

		case 6 : {

			    string idname = root->children[1]->lexValue;
			    PrintCode(root->children[3]);
			    it = ST.find(idname);
			    outas <<"		movl $4, %ebx" << endl;
			    outas <<"		imull %ebx , %eax" << endl;
   			    outas <<"		movl %eax, %edi" << endl;
			    outas <<"		call malloc@PLT" << endl;
			    outas <<"		movq %rax," << it->second <<"(%rbp)" << endl; 	
			    break;

		}
			

		}
	


	}


	if(nodetype == "Pexpr"){ 

		string Ptype = root->children[0]->nodeName;	

		if(Ptype == "integerLit") { 
		
				    string intvalue = root->children[0]->lexValue;
				    //outas << intvalue << endl;
				    outas << "\tmovl $" << intvalue << ", %eax" << endl;

				    }

		else if(Ptype == "identifier") { 

				    string idname = root->children[0]->lexValue;
				    it = ST.find(idname);
				    outas << "\tmovl " << it->second << "(%rbp), %eax" << endl;

				    }

		 else if(Ptype ==  "floatLit")    ;

		 else PrintCode(root->children[1]) ; //Parenthesis Case

	}


	else if( nodetype == "expr" ){

		cout << root->known << " : " << root->linenum << endl;
		if(root->known){
		cout << root->value  << "  : " << root->linenum << endl;
		outas << "	movl $" << root->value << ", %eax" << endl;
		return;
		}

			
		treeNode* C1 = root->children[0];
		int childsize = root->children.size();
	
		treeNode* LHS = new treeNode;
		treeNode* RHS = new treeNode;
		string Name = C1 -> nodeName;

		if(childsize == 1){
			LHS = C1->children[0];
			RHS = C1->children[1];
		}	

		
		
			if(Name ==  "LT") { 

				PrintCode(RHS);
				outas<<"		pushq %rax" << endl;
				PrintCode(LHS);
				outas<<"		popq %rbx" << endl;

				outas<<"		cmpl %ebx, %eax"<< endl;
				outas<<"		setl %al"<< endl;
				outas<<"		movzbl %al, %eax"<< endl;
				
			}

	                 else if(Name ==  "GT") {

                                PrintCode(RHS);
                                outas<<"		pushq %rax" << endl;
                                PrintCode(LHS);
                                outas<<"		popq %rbx" << endl;

                                outas<<"		cmpl %ebx, %eax"<< endl;
                                outas<<"		setg %al"<< endl;
                                outas<<"		movzbl %al, %eax"<< endl;
                        
                        }

                         else if(Name ==  "LEQ") {

                                PrintCode(RHS);
                                outas<<"		pushq %rax" << endl;
                                PrintCode(LHS);
                                outas<<"		popq %rbx" << endl;

                                outas<<"		cmpl %ebx, %eax"<< endl;
                                outas<<"		setle %al"<< endl;
                                outas<<"		movzbl %al, %eax"<< endl;
                        
                        }

                        else if(Name ==  "GEQ") {

                                PrintCode(RHS);
                                outas<<"		pushq %rax" << endl;
                                PrintCode(LHS);
                                outas<<"		popq %rbx" << endl;

                                outas<<"		cmpl %ebx, %eax"<< endl;
                                outas<<"		setge %al"<< endl;
                                outas<<"		movzbl %al, %eax"<< endl;
                        
                        }
                        else if(Name ==  "EQEQ") {

                                PrintCode(RHS);
                                outas<<"		pushq %rax" << endl;
                                PrintCode(LHS);
                                outas<<"		popq %rbx" << endl;

                                outas<<"		cmpl %ebx, %eax"<< endl;
                                outas<<"		sete %al"<< endl;
                                outas<<"		movzbl %al, %eax"<< endl;
                        
                        }
                        else if(Name ==  "NEQ") {

                                PrintCode(RHS);
                                outas<<"		pushq %rax" << endl;
                                PrintCode(LHS);
                                outas<<"		popq %rbx" << endl;

                                outas<<"		cmpl %ebx, %eax"<< endl;
                                outas<<"		setne %al"<< endl;
                                outas<<"		movzbl %al, %eax"<< endl;
                        
                        }
				
			else if(Name == "SIZEOF"){	

				//outas << root->children[2]->children[0]->children[0]->nodeName << endl;
				if(root->children[2]->children[0]->nodeName == "integerLit")		
				outas <<"	 movl $4, %eax" << endl;

				else if(root->children[2]->children[0]->nodeName == "identifier"){

					string idname  = root->children[2]->children[0]->lexValue;
					//outas << idname << endl;
					it = ArrayST.find(idname);
					if(ArrayST.end() == it)
						outas <<"	 movl $4, %eax" << endl;

					else 	outas <<"	 movl $ " << 4*it->second <<" , %eax" << endl;

				}
			
			}

			else if(Name == "AND") {

				PrintCode(LHS);
				outas<<"		cmpl $0, %eax"<<endl;
				int falselabel = ++labelcount;
				outas<<"		je .L"<< falselabel<<endl;
				PrintCode(RHS);
				outas<<"		cmpl $0, %eax"<< endl;
				outas<<"		je .L"<<falselabel<<endl;
				outas<<"		movl $1, %eax" << endl;
				int truelabel = ++labelcount;
				outas<<"		jmp .L"<<truelabel<<endl;
				outas<<".L"<<falselabel<<":"<<endl;
				outas<<"         movl $0, %eax" << endl;
				outas<<".L"<<truelabel <<":"<<endl;

			}

			else if(Name == "OR" ){ 
			
			int truelabel = ++labelcount;
			int falselabel = ++labelcount;

                        PrintCode(LHS);
                        outas<<"		cmpl $0, %eax"<<endl;
                        outas<<"		jne .L"<< truelabel <<endl;

                        PrintCode(RHS);
                        outas<<"		cmpl $0, %eax"<< endl;
                        outas<<"		jne .L"<<truelabel<<endl;

                        outas<<"		movl $0, %eax" << endl;
                        outas<<"		jmp .L"<< falselabel <<endl;
                        outas<<".L"<< truelabel<<":"<<endl;
                        outas<< "	movl $1, %eax" << endl;
                        outas<<".L"<< falselabel <<":"<<endl;
	
			}
			
			else if(Name == "PLUS"){ 

				if(childsize != 2){
					
					PrintCode(RHS);
					outas <<"	pushq %rax" << endl;
					PrintCode(LHS);
					outas <<"	popq %rbx" << endl;
					outas <<"	addl %ebx, %eax" << endl;
				
				}

			}
			
			else if(Name == "MINUS"){
			
				if(childsize != 2){
				        PrintCode(RHS);
				        outas <<"	pushq %rax" << endl;
				        PrintCode(LHS);
				        outas <<"	popq %rbx" << endl;
				        outas <<"	subl %ebx, %eax" << endl;

		                }

		                else{
				        PrintCode(root->children[1]);
				        outas<<"		negl %eax"<<endl;

		                }

		 	}

			else if(Name == "MULT"){
				if(RHS->known && (pow2(RHS->value) >= 0)){
					PrintCode(LHS);
					outas << "	sall $" << pow2(RHS->value) << ", %eax " << endl;
	
				}	

				else if(LHS->known && (pow2(LHS->value) >= 0) ){
					PrintCode(RHS);
					outas << "	sall $" << pow2(LHS->value) << ", %eax " << endl;
				}

				else{
		                PrintCode(RHS);
		                outas <<"	pushq %rax" << endl;
		                PrintCode(LHS);
		                outas <<"	popq %rbx" << endl;
		                outas <<"	imull %ebx, %eax" << endl;
				}
			}

			else if(Name == "DIV"){

		                PrintCode(RHS);
		                outas <<"	pushq %rax" << endl;
		                PrintCode(LHS);
		                outas <<"	popq %rcx" << endl;
				outas <<"	cltd"<<endl;
		                outas <<"	idiv %ecx" << endl;

                        }

			else if(Name == "MOD"){
			
		                PrintCode(RHS);
		                outas <<"	pushq %rax" << endl;
		                PrintCode(LHS);
		                outas <<"	popq %rcx" << endl;
				outas<<"		cltd\n";
		                outas <<"	idiv %ecx" << endl;
				outas <<"	movl %edx , %eax" << endl;
                        }
	
			else if(Name == "NOT"){
				
				PrintCode(root->children[1]);
				outas << "	cmpl $0, %eax" << endl;
				outas<<"		sete %al" << endl;
				outas<<"		movzbl %al, %eax" << endl;
		
			}

			else if(Name == "identifier" && root->children[1]->nodeName == "["){

			PrintCode(root->children[2]);
			outas << "	movl %eax, %ebx" << endl;

			it = ST.find(root->children[0]->lexValue);	
			outas << "	movq " << it->second << "(%rbp), %rax" << endl;
			outas << "	movq (%rax, %rbx, 4 ) , %rax" << endl; 

			}

			else {	int ii;
			
				for(ii = 0; ii < (int)root->children.size();ii++){
				PrintCode(root->children[ii]);
			}

	
	}		
	 
	
	}

	else if(nodetype == "print_stmt" ){
        
                string idname  = root->children[4]->lexValue;
                it = ST.find(idname);

                outas<<"	movl "<< it->second <<"(%rbp), %esi\n";
                outas<<"	leaq .LC0(%rip), %rdi\n";
                outas<<"	movl $0, %eax\n";
                outas<<"	call printf@PLT\n";

		}

	else if(nodetype == "scan_stmt"){
		
		string idname = root->children[5]->lexValue;
		it = ST.find(idname);
		outas << "	xorq %rax , %rax" << endl;
	        outas << "	leaq " << it->second << "(%rbp), %rax " << endl;
		outas << "	movq  %rax, %rsi" << endl;
	        outas << "  	leaq  .LC1(%rip), %rdi" << endl; 
	        outas << "	movl  $0, %eax" << endl; 
	        outas << "	call  scanf@PLT" << endl;

	}

 
        else if(nodetype == "assign_stmt"){ 

		switch(root->children[0]->children.size()){
			
		case 2 :{
		 
				 treeNode* LHS;
				 LHS = root->children[0]->children[0]; 
				
				 treeNode* RHS;
				 RHS= root->children[0]->children[1];

				 //Print Code for RHS Expression
				 PrintCode(RHS);

				 //Find offset of current identifier
				 string idname = LHS->lexValue;
				 it  = ST.find(idname);
				 
				 outas<<"	movl %eax, "<<(it->second)<<"(%rbp)\n";
		
				break;

			}

		case 5 : {

			treeNode* index = root->children[0]->children[2];
			PrintCode(index);

			outas <<"	pushq %rax" << endl;

			treeNode* value = root->children[0]->children[4];
			PrintCode(value);
			outas <<"	movq %rax , %rbx" << endl;
	
			outas <<"	popq %rcx" << endl;

			string idname = root->children[0]->children[0]->lexValue;
			it  = ST.find(idname);
			outas<<"	movq " << (it->second)<<"(%rbp) , %rax\n" << endl;
			outas << "	movl %ebx , (%rax, %rcx ,4)" << endl; 

			break;
	

		}

		}
	
	}

   
	else if(nodetype == "while_stmt"){
	
		treeNode* Condition = root->children[2];
		treeNode* Statement = root->children[4];

		int EndLabel = ++(labelcount);
		int CondLabel = ++(labelcount);

		//Jump to Condition
                outas<<"	.L"<< CondLabel << ":" <<endl;
                PrintCode(Condition);
                outas<<"		cmpl $0, %eax" << endl;
                outas<<"		je .L"<< EndLabel <<endl;
                PrintCode(Statement);
		outas << "	jmp .L" << CondLabel << endl;
		outas << ".L" << EndLabel <<  " :" << endl;
        
	}

	else if(nodetype == "if_stmt" ){ 

			treeNode* Condition;

			switch (root->children.size()){

				case 5 : //If only case
				
					{
						Condition = root->children[2];
						treeNode* Statement = root->children[4];

					        PrintCode(Condition); 
					        outas<<"		cmpl $0, %eax\n";				
					        outas<<"		je .L"<< (++labelcount) <<endl;

				        	PrintCode(Statement);

				        	outas<<"	.L"<< labelcount <<":"<<endl;
						
						break;	
					}

				case 7 : //If-else Case

					{
						 Condition = root->children[2];
						 treeNode* TrueStatement = root->children[4];
						 treeNode* FalseStatement = root->children[6];

						PrintCode(Condition);

						int TrueLabel = ++labelcount;
						int FalseLabel = ++labelcount;
						int ExitLabel = ++labelcount;

						outas<<"		cmpl $0, %eax\n";
				                outas<<"		jne .L"<< TrueLabel <<endl;

						PrintCode(FalseStatement);
					        outas <<"	jmp .L" <<ExitLabel << endl;
						
		  				outas << ".L" << TrueLabel << ": " << endl;				
						PrintCode(TrueStatement);
				
						outas <<".L" << ExitLabel << ": " <<  endl;

						 break;

					}		
			}


	}

	else if(nodetype == "return_stmt"){
		
		
		switch (root->children.size()){

			case 2 : {		//returning without expr;

						outas<<"		movl $0, %eax" << endl;
						outas<<"		leave" <<endl;
						outas<<"		ret" << endl;
						break;
			
			}

			case 3 :{		//returning expr
						PrintCode(root->children[1]);
						outas<<"		movl $0, %eax" << endl;
						outas<<"		leave" <<endl;
						outas<<"		ret" << endl;
						break;					

			}
		
		}
		
	
	}


	else {	int ii;

		for(ii = 0; ii < (int)root->children.size();ii++){
			PrintCode(root->children[ii]);
		}

	}	



}

void ClearVals(treeNode* root){
	root->valueCalc = false;
 	for(int ii = 0; ii < root->children.size();ii++){
		ClearVals(root->children[ii]);
		root->value =INT_MAX;
	}
}

void FindValues(treeNode* root){
	if(root->valueCalc == true)
	return;
        root->valueCalc = true;
	string type = root->nodeName;
	if(type == "Pexpr"){
		string ptype = root->children[0]->nodeName;
		if(ptype == "integerLit"){
			root->known = true;
			root->value = stoi(root->children[0]->lexValue);
			root->CFVal = INT_MIN;
			if(MaxVals.count(root->linenum) == 0)
			MaxVals[root->linenum] = root->value;
			else MaxVals[root->linenum] = max(MaxVals[root->linenum],root->value);
		}
		if(ptype == "identifier"){
			string idname = root->children[0]->lexValue;
			root->CFVal = INT_MIN;
			if(values.find(idname) == values.end()){
				cout << "id not found " << idname << " : " << root->linenum << endl;
				root->children[0]->known = false;
				root->known = false;
			}
			else{
				cout << "id found " << idname << endl;
				root->known = true;
				root->children[0]->known = true;
				root->value = values.find(idname)->second;
			}

		}

		if(ptype  == "("){
			FindValues(root->children[1]);
			if(root->children[1]->known){
				root->known = true;
				root->value = root->children[1]->value;
			}
			else root->known = false;
		}

	}

	if(type == "assign_stmt"){
		
		treeNode* LHS = root->children[0]->children[0];
		treeNode* RHS = root->children[0]->children[1];
		FindValues(RHS);
		if(RHS->known == true){
			string idname = LHS->lexValue;
			int val = RHS->value;
			if(values.find(idname) == values.end()){
				values.insert(make_pair(idname,val));
			}
			else values.find(idname)->second = val;

		}
		else {
			string idname = LHS->lexValue;
			if(values.find(idname) == values.end()){
				;
			}
			else values.erase(values.find(idname));

		}
		
	}
	if(type == "expr"){
		treeNode* C1 = root->children[0];
		if(root->children.size() == 2){
			string type1 = C1->nodeName;
			FindValues(C1);
			root->known = C1->known;
			if(root->known){
				if(type1 == "!"){
					root->value = !(C1->value);
				}
				else if(type1  == "-"){
					root->value = -(C1->value);
				}
				else if(type1  == "+"){
					root->value = (C1->value);
				}
		
			}
		}
		else if(root->children.size() == 1 && C1->nodeName != "Pexpr"){	
			C1 = root->children[0]->children[0];
			treeNode* C2 = root->children[0]->children[1];
			FindValues(C1);
			FindValues(C2);
			string op = root->children[0]->nodeName;
			if(op == "LT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value < C2->value);
				}
			}
			if(op == "GT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value > C2->value);
				}
			}
			if(op == "LEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value <= C2->value);
				}
			}
			if(op == "GEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value >= C2->value);
				}
			}
			if(op == "OR"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value || C2->value);
				}
			}
			if(op == "EQEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value == C2->value);
				}
			}
			if(op == "NEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value != C2->value);
				}
			}
			if(op == "AND"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value && C2->value);
				}
			}
			if(op == "PLUS"){
				root->known = C1->known && C2->known;
				if(root->known){
					//cout << root->linenum << endl;
					root->value = (C1->value + C2->value);
				}
			}
			if(op == "MINUS"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value - C2->value);
				}
			}
			if(op == "MULT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value * C2->value);
				}
			}
			if(op == "DIV"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value / C2->value);
				}
			}
			if(op == "MOD"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value % C2->value);
				}
			}

		}

		else if(C1->nodeName == "Pexpr"){
			FindValues(C1);
			root->known = C1->known;
			root->value = C1->value;
		}


	}

	if(type == "print_stmt"){
		string idname = root->children[4]->lexValue;
		if(values.find(idname) == values.end())
		     root->known = false;		
		else {
			root->known = true;
			root->value = values.find(idname)->second;
		}
	}

	if(type == "scan_stmt"){
		string idname = root->children[5]->lexValue;
		if(values.find(idname) == values.end())
				;
		else values.erase(values.find(idname));
	}

	if(type == "if_stmt"){
		treeNode* cond = root->children[2];
		FindValues(cond);
		if(root->children.size() == 7){
			if(cond->known){
				if(cond->value)
					FindValues(root->children[4]);
				else 	FindValues(root->children[6]);

			}
			else{
				map <string,int> map1;
				//Saving map before if stmnts
				map1 = values;
				FindValues(root->children[4]);
				map <string,int> m1;
				m1 = values;
				values = map1;
				FindValues(root->children[6]);
				map <string,int> m2;
				m2 = values;
				values.clear();
				for(auto x : m1){    //Updating final values
					if(m2.find(x.first) != m2.end() && x.second == m2.find(x.first)->second){
						//cout << "values inserted are " << x.first << " " << x.second << endl;
						values.insert(make_pair(x.first,x.second));
					}
				}

			}
	      }
	      else{
			if(cond->known){
				if(cond->value)
					FindValues(root->children[4]);
				else 	;


			}
			else{
				map <string,int> map1= values;
				FindValues(root->children[4]);
				map <string,int> final;
				for(auto x: values){
					if(map1.find(x.first) != map1.end() && map1.find(x.first)->second == x.second)
						final[x.first] = x.second;
				}
				values = final;

			}

	      }
	}

	else{	//All other types, just recursively call
		for(int ii = 0; ii < root->children.size();ii++)
			FindValues(root->children[ii]);
	}


}

void CSE(treeNode* root){
	string type = root->nodeName;
	if(type == "Pexpr"){
		string ptype = root->children[0]->nodeName;
		if(ptype == "integerLit"){
			string v = root->children[0]->lexValue;
			root->known = true;
			root->FinalExpr = v;
			root->lastDec = 0;
		}
		if(ptype == "identifier"){
			string idname = root->children[0]->lexValue;
			if(values.find(idname) == values.end()){
				root->known = false;
				root->FinalExpr = idname;
				root->lastDec = VarLastDec[idname];
			}
			else{
				root->known = true;
				root->FinalExpr = to_string(values.find(idname)->second);
				root->lastDec = 0;
			}
		}
		if(ptype == "("){
			treeNode* expr = root->children[1];
			CSE(expr);
			root->FinalExpr = "(" + expr->FinalExpr + ")";
			root->lastDec = expr->lastDec;

			//if(!root->known)
		 	//ExprList[root->FinalExpr][root->lastDec].push_back(root->linenum);
		}
	}
	else if(type == "expr"){
	
		treeNode* C1 = root->children[0];
		if(root->children.size() == 2){
			string type1 = C1->nodeName;
			//FindValues(C1);
			CSE(C1);
			root->known = C1->known;
				if(type1 == "!"){
					if(root->known)
					root->value = !(C1->value);
					else{
					root->FinalExpr = "!" + C1->FinalExpr;
					root->lastDec = C1->lastDec;
					}
				}
				else if(type1  == "-"){
					if(root->known)
					root->value = -(C1->value);
					else{
					root->FinalExpr = "!" + C1->FinalExpr;
					root->lastDec = C1->lastDec;
					}
				}

		 if(!root->known)
		  ExprList[root->FinalExpr][root->lastDec].push_back(root->linenum);
	
		}
		else if(root->children.size() == 1 && C1->nodeName != "Pexpr"){	
			C1 = root->children[0]->children[0];
			treeNode* C2 = root->children[0]->children[1];
			//FindValues(C1);
			//FindValues(C2);
			CSE(C1);
			CSE(C2);
			string op = root->children[0]->nodeName;
			if(op == "LT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value < C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "<" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "GT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value > C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + ">" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "LEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value <= C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "<=" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "GEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value >= C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + ">=" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "OR"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value || C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "||" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "EQEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value == C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "==" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "NEQ"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value != C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "!=" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "AND"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value && C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "&&" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "PLUS"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value + C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "+" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "MINUS"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value - C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "-" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "MULT"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value * C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "*" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "DIV"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value / C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "/" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
			if(op == "MOD"){
				root->known = C1->known && C2->known;
				if(root->known){
					root->value = (C1->value % C2->value);
				}
				else{
				root->FinalExpr = C1->FinalExpr + "%" + C2->FinalExpr ;
				root->lastDec = max(C1->lastDec, C2->lastDec);
				}
			}
		 	if(!root->known)
		 	ExprList[root->FinalExpr][root->lastDec].push_back(root->linenum);

		}

		else if(C1->nodeName == "Pexpr"){
			FindValues(C1);
			CSE(C1);
			root->known = C1->known;
			root->value = C1->value;
			if(!root->known){
			root->FinalExpr = C1->FinalExpr;
			root->lastDec = C1->lastDec;
			}
		}
		
	}

	else if(type == "assign_stmt"){

		treeNode* LHS = root->children[0]->children[0];		
		treeNode* RHS = root->children[0]->children[1];
		CSE(RHS);
		FindValues(RHS);
		string idname = LHS->lexValue;
		VarLastDec[idname] = root->linenum;
		if(RHS->known){
			if(values.find(idname) == values.end())
				values.insert(make_pair(idname,RHS->value));
			else values.find(idname)->second = RHS->value;
		}
		else {
			if(values.find(idname) == values.end())
				;
			else values.erase(values.find(idname));

		}
	}

	else if(type == "if_stmt" && root->children.size() == 7){
			CSE(root->children[2]);
			map <string,int> map1= values;
			CSE(root->children[4]);
			values = map1;
			CSE(root->children[6]);
			values = map1;
	}

	else if(type == "scan_stmt"){
	
		string idname = root->children[5]->lexValue;
		VarLastDec[idname] = root->linenum;
			if(values.find(idname) == values.end())
				;
			else values.erase(values.find(idname));
	}

	else{
		for(int ii = 0; ii < root->children.size(); ii++)
			CSE(root->children[ii]);
	}



}



void ReduceStrength(treeNode* root){

	string type = root->nodeName;
	if(type == "expr"){
		treeNode* C1 = root->children[0];
		if(C1->nodeName == "MULT" & C1->children.size() == 2){		
			treeNode* op1 = C1->children[0];
			treeNode* op2 = C1->children[1];
			ReduceStrength(op1);
			ReduceStrength(op2);
			if(!op1->known && op2->known && (pow2(op2->value) >= 0)){
				int l = root->linenum;
				SR[l] = max(SR[l], pow2(op2->value));
			}
			if(!op2->known && op1->known && (pow2(op1->value) >= 0)){
				int l = root->linenum;
				SR[l] = max(SR[l], pow2(op1->value));
			}
		}

		else{

			for(int ii = 0; ii < root->children.size(); ii++){
				ReduceStrength(root->children[ii]);
			}
		}

	}
	else{
		for(int ii = 0; ii < root->children.size(); ii++)
			ReduceStrength(root->children[ii]);
	}
}

void ConstProp(treeNode* root){
	string type = root->nodeName;
	//outas << type << endl;
	if(type  == "Pexpr"){
		string ptype = root->children[0]->nodeName;
		if(ptype == "identifier"){
				string idname = root->children[0]->lexValue;
				if(root->children[0]->known){	
				int l = root->linenum;
				CP[l][idname] = root->value;
				}
			
		}
		else{
			for(int ii = 0; ii < root->children.size();ii++)
				ConstProp(root->children[ii]);
		}
	}
	if(type  == "print_stmt"){
		if(root->known){
				string idname = root->children[4]->lexValue;
				int l = root->linenum;
				CP[l][idname] = root->value;
		}

	}
	else{

		for(int ii = 0; ii < root->children.size(); ii++){
			ConstProp(root->children[ii]);
		}
	}


}

void ConstFold(treeNode* root){
	string type = root->nodeName;
	if(type  == "Pexpr" ){
		root->CFVal = INT_MIN;
		if(root->children[0]->nodeName == "integerLit"){
			root->known = true;
			root->CFVal = root->value;
		}
		if(root->children[0]->nodeName == "identifier"){
			string idname = root->children[0]->lexValue;
			if(root->known){
				root->CFVal = INT_MIN;
			}	
		}
		if(root->children[0]->nodeName == "("){
		ConstFold(root->children[1]);
			if(root->known){
				root->CFVal = root->children[1]->CFVal;			
			}
		}
	}
	else if(type  == "expr"){
		if(root->children.size() == 1 && root->children[0]->nodeName != "Pexpr"){
				string op = root->children[0]->nodeName;
				treeNode* C1 = root->children[0]->children[0];
				treeNode* C2 = root->children[0]->children[1];	
				if(op == "PLUS"){
					root->known = C1->known && C2->known;
					if(root->known){
					    root->CFVal = root->value;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = root->value;
					   else CF[root->linenum] = max(CF[root->linenum],root->value);
					    return;
					}
					else if(C1->known){
					   ConstFold(C2); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C1->CFVal != INT_MIN)
					   	cfval = C1->value;
					   else if(C2->CFVal != INT_MIN)
					  	 cfval = max(cfval,C2->CFVal);
					   else return;  
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else if(C2->known){
					   ConstFold(C1); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C2->CFVal != INT_MIN)
					   cfval = C2->value;
					   else if(C1->CFVal != INT_MIN)
					   cfval = max(cfval,C1->CFVal);
					   else return;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else{
					   ConstFold(C1);
					   ConstFold(C2);
					   int cfval = INT_MIN;
					   if(C1->CFVal != INT_MIN)
						cfval = C1->CFVal;
					   if(C2->CFVal != INT_MIN)
						cfval = max(cfval, C2->CFVal);
					   if(cfval != INT_MIN){
						   if(CF.count(root->linenum) == 0)
							CF[root->linenum] = cfval;
						   else CF[root->linenum] = max(CF[root->linenum],cfval);
					   }
					}
				}
				else if(op == "MINUS"){
					root->known = C1->known && C2->known;
					if(root->known){
					    root->CFVal = root->value;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = root->value;
					   else CF[root->linenum] = max(CF[root->linenum],root->value);
					    return;
					}
					else if(C1->known){
					   ConstFold(C2); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C1->CFVal != INT_MIN)
					   cfval = C1->value;
					   else if(C2->CFVal != INT_MIN)
					   cfval = max(cfval,C2->CFVal);
					   else return;
					   
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else if(C2->known){
					   ConstFold(C1); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C2->CFVal != INT_MIN)
					   cfval = C2->value;
					   else if(C1->CFVal != INT_MIN)
					   cfval = max(cfval,C1->CFVal);
					   else return;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else{
					   ConstFold(C1);
					   ConstFold(C2);
					   int cfval = INT_MIN;
					   if(C1->CFVal != INT_MIN)
						cfval = C1->CFVal;
					   if(C2->CFVal != INT_MIN)
						cfval = max(cfval, C2->CFVal);
					   if(cfval != INT_MIN){
						   if(CF.count(root->linenum) == 0)
							CF[root->linenum] = cfval;
						   else CF[root->linenum] = max(CF[root->linenum],cfval);
					   }
					}

				}
				else if(op == "MULT"){
					root->known = C1->known && C2->known;
					if(root->known){
					    root->CFVal = root->value;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = root->value;
					   else CF[root->linenum] = max(CF[root->linenum],root->value);
					    return;
					}
					else if(C1->known){
					   ConstFold(C2); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C1->CFVal != INT_MIN)
					   cfval = C1->value;
					   else if(C2->CFVal != INT_MIN)
					   cfval = max(cfval,C2->CFVal);
					   else return;
					   
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else if(C2->known){
					   ConstFold(C1); //Find Maximum in unknown side	
					   int cfval = 0;	
					   if(C2->CFVal != INT_MIN)
					   cfval = C2->value;
					   else if(C1->CFVal != INT_MIN)
					   cfval = max(cfval,C1->CFVal);
					   else return;
					   if(CF.count(root->linenum) == 0)
						CF[root->linenum] = cfval;
					   else CF[root->linenum] = max(CF[root->linenum],cfval);
					}
					else{
					   ConstFold(C1);
					   ConstFold(C2);
					   int cfval = INT_MIN;
					   if(C1->CFVal != INT_MIN)
						cfval = C1->CFVal;
					   if(C2->CFVal != INT_MIN)
						cfval = max(cfval, C2->CFVal);
					   if(cfval != INT_MIN){
						   if(CF.count(root->linenum) == 0)
							CF[root->linenum] = cfval;
						   else CF[root->linenum] = max(CF[root->linenum],cfval);
					   }
					
					}
				}
				else{
					//Other Operators
					for(int ii = 0; ii < root->children.size(); ii++){
						ConstFold(root->children[ii]);
					}
				}
		}
		else if(root->children[0]->nodeName == "Pexpr"){
			ConstFold(root->children[0]);
			root->known = root->children[0]->known;
			root->CFVal = root->children[0]->CFVal;
		}
		//Other Expression types
		else{

			for(int ii = 0; ii < root->children.size(); ii++){
				ConstFold(root->children[ii]);
			}
		}

	}


	else if(type == "if_stmt"){
		cout << "ifstmt here" << endl;
		for(int ii = 0; ii < root->children.size(); ii++){
			ConstFold(root->children[ii]);
		}
		
	}

	else{

		for(int ii = 0; ii < root->children.size(); ii++){
			ConstFold(root->children[ii]);
		}
	}
	

}

void FindUsed(treeNode* root){
	//Identify every place where a variable can be used
	string type = root->nodeName;
	if(type == "Pexpr"){
		string ptype = root->children[0]->nodeName;
		if(ptype == "identifier"){ //expr -> Pexpr -> identifier
			string idname = root->children[0]->lexValue;
			used.insert(make_pair(idname,used.size()));
		}
		else{
			for(int ii = 0; ii < root->children.size(); ii++){
			FindUsed(root->children[ii]);
			}
		}

	}
	else if(type == "assign_stmt"){ //LHS of assignment statements
		FindUsed(root->children[0]->children[1]);
		string idname = root->children[0]->children[0]->lexValue;
		used.insert(make_pair(idname,used.size()));
	}
	else if(type == "print_stmt"){	//Usage in printing
		string idname = root->children[4]->lexValue;
		used.insert(make_pair(idname,used.size()));
	}
	else if(type == "scan_stmt"){
		string idname = root->children[5]->lexValue;
		used.insert(make_pair(idname,used.size()));
	}
	else {
		//All other statements , recursively call
		for(int ii = 0; ii < root->children.size(); ii++){
			FindUsed(root->children[ii]);
		}

	}
}

void FindUnused(treeNode* root){
	
	if(root->nodeName == "local_decl"){
		string idname = root->children[1]->lexValue;
		if(used.find(idname) != used.end()){
		  varList.push_back(idname);
                  int curroffset = getOffset();
                  ST.insert( make_pair( idname , curroffset));
		}
		else unused.push_back(idname);
	}
	
	else{
		for(int ii = 0; ii < root->children.size(); ii++){
			FindUnused(root->children[ii]);
		}
	}

}



void IfSimplify(treeNode* root){
	
	string type = root->nodeName;
	if(type == "assign_stmt"){
		//Finding values assigned to a variable
		treeNode* LHS = root->children[0]->children[0];
		treeNode* RHS = root->children[0]->children[1];
		string idname = LHS->lexValue;
		if(RHS->known == true){ //RHS value available statically
			int val = RHS->value;
			if(values.find(idname) == values.end()){ 
				values.insert(make_pair(idname,val)); //Inserting variable into values list
			}
			else values.find(idname)->second = val;	      //Changing variable value to current value

		}
		else{

			if(values.find(idname) == values.end()){ 
				; 
			}
			else values.erase(values.find(idname));	 
			

		}
		
	}

	else if(type == "scan_stmt"){
		string idname = root->children[5]->lexValue; //Finding id which is being scanned
		//Removing from values list
		if(values.find(idname) == values.end())
				;
		else values.erase(values.find(idname));
	}

	else if(type == "stmt"){
		//Checking if-stmnt conditions
		if(root->children[0]->nodeName == "if_stmt"){
		treeNode* cond = root->children[0]->children[2];
		ReduceStrength(cond);
		//ConstProp(cond);
			if(root->children[0]->children.size() == 7){ //IF WITH ELSE;

				if(cond->known){ //Condition Value is statically available
					if(cond->value){	//Else is removed
						root->children = root->children[0]->children[4]->children;
						IfSimple = 1;
					}
						
					else{			//If is removed
						root->children = root->children[0]->children[6]->children;
						IfSimple = 0;
					}


				}
			}
			else{
				cout << "if without else" << endl;
				if(cond->known){ //Condition Value is statically available
					if(cond->value){	//Else is removed
						root->children = root->children[0]->children[4]->children;
						IfSimple = 1;
					}
						
					else{			//If is removed
						vector <treeNode*> none;
						root->children = none;
						IfSimple = 0;
					}


				}

			}

		}
	
		else{
		//Other types of statements, recursive calls
		for(int ii = 0; ii < root->children.size();ii++)
			IfSimplify(root->children[ii]);

		}

	}

	else{	//All other types, just recursively call
		for(int ii = 0; ii < root->children.size();ii++)
			IfSimplify(root->children[ii]);
	}


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
            outas << endl;
            previous_level = curr->level;
        }
        outas << curr->nodeName;
        for(int i = 0; i < 5; i++) {
            outas << ' ';
        }
        for(auto& child : curr->children) {
            child->level = 1 + curr->level;
            q.push(child);
        }
    }
    outas << endl;
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

int getOffset(){
 	
    offset++;
    return (-4)*(offset);

}

int main() {

    ofstream outsum("summary.txt");
    yyparse();
    cout << "amm" << endl;
    ClearVals(ast);
    FindValues(ast);
    cout << "hh" << endl;
    IfSimplify(ast); //Assigns all known values and also removes the unnecessary branching if applicable
    ClearVals(ast);
    FindValues(ast);

    //Finding unused variables
    FindUsed(ast);
    FindUnused(ast);
    //Printing unused variables
    outsum << "unused-vars" << endl;
    for(int ii = 0; ii < unused.size();ii++)
	outsum << unused[ii] << endl;
    outsum << endl;

    //Printing If-Simplification
    outsum << "if-simpl" << endl;
    if(IfSimple != -1){
    outsum << IfSimple << endl;
    outsum << endl;
    }
    else
    outsum << endl;

    //Printing Strength Reduction
    outsum << "strength-reduction" << endl;
    ReduceStrength(ast);
    for(auto x : SR)
	outsum << x.first << " " << x.second << endl;
    outsum << endl;
    
    //Printing Constant Folding
    outsum << "constant-folding" << endl;
    ConstFold(ast);
    for(auto x : CF)
	outsum << x.first << " " << max(x.second, MaxVals[x.first]) << endl;

    outsum << endl;

    ConstProp(ast);
    printAST(ast);
    outsum << "constant-propagation" << endl;
    for(auto x : CP){
	outsum << x.first << " "; 
	   for(int jj = 0; jj < varList.size();jj++){
		   for(auto y : x.second)
			if(varList[jj] == y.first)
				outsum << y.first << " " << y.second << " ";
		}

	outsum << endl;
    }
    outsum << endl;
   values.clear();
   CSE(ast);
    outsum << "cse" << endl;
   vector< vector<int> > ans_cse;
	for(auto itr = ExprList.begin(); itr != ExprList.end();)
	{
		for(auto itr2 = itr->second.begin(); itr2 != itr->second.end();)
		{
			if(itr2->second.size() > 1)
			{	//outas << itr2->first << endl;
				ans_cse.push_back(itr2->second);
				++itr2;
			}
			else
			{
				(itr->second).erase(itr2++);
			}
		}

		if(itr->second.empty())
			ExprList.erase(itr++);
		else
			++itr;
	}
		
	sort(ans_cse.begin(),ans_cse.end(),customSort);

	for(int i=0; i<ans_cse.size(); ++i)
	{
		for(int j=0; j<ans_cse[i].size(); ++j)
			outsum << ans_cse[i][j] << " ";
		outsum << "\n";
	}

    PrintInit();
    PrintCode(ast);
    PrintReturn();

    return 0;
}
