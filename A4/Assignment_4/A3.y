%token INTEGER_LITERAL FLOAT_LITERAL IDENTIFIER SC PRINTF FORMAT_SPECIFIER
%token INT VOID FLOAT WHILE IF ELSE BREAK CONTINUE RETURN
%token COMMA PAREN_OPEN PAREN_CLOSE SQ_OPEN SQ_CLOSE CURLY_OPEN CURLY_CLOSE
%token OR EE NE LE LT GE GT AND PLUS MINUS INTO BY MOD NOT ASSGN UNAND
%{
	#define YYSTYPE struct node*
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    #include "y.tab.h"
    #define max(a,b) (a>b)?a:b
    void yyerror(string);
    int yylex(void);
    extern char* yytext;
    typedef struct node{
        bool asmd = false;
        string type;
        struct node* children[10];
        int noc;
    }node;
    node* root;
    void getasm(node* root);
    node* mk0(string t);
    node* mk1(string t, node* one);
    node* mk2(string t, node* one, node* two);
    node* mk3(string t, node* one, node* two, node* three);
    node* mk4(string t, node* one, node* two, node* three, node* four);
    node* mk5(string t, node* one, node* two, node* three, node* four, node* five);
    node* mk6(string t, node* one, node* two, node* three, node* four, node* five, node* six);
    node* mk7(string t, node* one, node* two, node* three, node* four, node* five, node* six, node* seven);
    void freenodes(node* root);
    void printtree(node* root);
    string getlabel();
    unordered_map<string,unordered_map <string,int>> loc;
    unordered_map<string,int> temp;
    unordered_map<string,string> funlabel;
    string currfun;
    int nn = 0, variables=0;
    int top = 4;
    int ctr = 0;
%}

%%

program:        decl_list 
                {
                    root = mk1("program", $1);
                };

decl_list:      decl_list decl        
                {
                    $$ = mk2("decl_list", $1, $2);
                }
                | decl                  
                {
                    $$ = mk1("decl_list", $1);
                }
                ;

decl:           var_decl                
                {
                    variables++;
                    loc["global"][$1->children[0]->children[0]->type] = top;
                    top += 4;
                    $$ = mk1("decl", $1);
                }
                | func_decl             
                {
                    currfun = $1->children[1]->children[0]->type;
                    loc[currfun] = temp;
                    temp.clear();
                    $$ = mk1("decl", $1);
                }
                ;

var_decl:       type_spec identifier SC 
                {
                    $3 = mk0(";");
                    $$ = mk3("var_decl", $1, $2, $3);
                }                                                    
                | type_spec identifier COMMA var_decl
                {
                    $3 = mk0(",");
                    $$ = mk4("var_decl", $1, $2, $3, $4);
                }
                | type_spec identifier SQ_OPEN integerLit SQ_CLOSE SC
                {
                    $3 = mk0("[");
                    $5 = mk0("]");
                    $6 = mk0(";");
                    $$ = mk6("var_decl", $1, $2, $3, $4, $5, $6);
                }
                | type_spec identifier SQ_OPEN integerLit SQ_CLOSE COMMA var_decl
                {
                    $3 = mk0("[");
                    $5 = mk0("]");
                    $6 = mk0(",");
                    $$ = mk7("var_decl", $1, $2, $3, $4, $5, $6,$7);
                }
                ;

type_spec:      VOID 
                {
                    $1 = mk0("void");
                    $$ = mk1("type_spec", $1);
                }
                | INT 
                {
                    $1 = mk0("int");
                    $$ = mk1("type_spec", $1);
                }
                | FLOAT 
                {
                    $1 = mk0("float");
                    $$ = mk1("type_spec", $1);
                }
                ;

func_decl:      type_spec identifier PAREN_OPEN params PAREN_CLOSE compound_stmt
                {
                    $3 = mk0("(");
                    $5 = mk0(")");
                    $$ = mk6("func_decl", $1, $2, $3, $4, $5, $6);
                }
                ;

params:         param_list 
                {
                    $$ = mk1("params", $1);
                }
                | 
                {
                    $$ = mk1("params", mk0("epsilon"));
                }
                ;

param_list:     param_list COMMA param 
                {
                    $2 = mk0(",");
                    $$ = mk3("param_list", $1, $2, $3);
                }
                | param
                {
                    $$ = mk1("param_list", $1);
                }
                ;

param:          type_spec identifier 
                {
                    variables++;
                    temp[$2->children[0]->type] = top;
                    top+=4;
                    $$ = mk2("param", $1, $2);
                }
                | type_spec identifier SQ_OPEN SQ_CLOSE
                {
                    $3 = mk0("[");
                    $4 = mk0("]");
                    $$ = mk4("param", $1, $2, $3 , $4);
                }
                | type_spec SQ_OPEN SQ_CLOSE identifier
                {
                    $2 = mk0("[");
                    $3 = mk0("]");
                    $$ = mk4("param", $1, $2, $3 , $4);
                }
                ;

stmt_list:      stmt_list stmt 
                {
                    $$ = mk2("stmt_list", $1, $2);
                }
                | stmt
                {
                    $$ = mk1("stmt_list", $1);
                }
                ;

stmt:           assign_stmt 
                {
                    $$ = mk1("stmt", $1);
                }
                | compound_stmt 
                {
                    $$ = mk1("stmt", $1);
                }
                | if_stmt 
                {
                    $$ = mk1("stmt", $1);
                }
                | while_stmt
                {
                    $$ = mk1("stmt", $1);
                }
                | return_stmt 
                {
                    $$ = mk1("stmt", $1);
                }
                | break_stmt 
                {
                    $$ = mk1("stmt", $1);
                }
                | continue_stmt
                {
                    $$ = mk1("stmt", $1);
                }
                | print_stmt
                {
                    $$ = mk1("stmt", $1);
                }
                ;

while_stmt:     WHILE PAREN_OPEN expr PAREN_CLOSE stmt
                {
                    $1 = mk0("while");
                    $2 = mk0("(");
                    $4 = mk0(")");
                    $$ = mk5("while_stmt", $1, $2, $3, $4, $5);
                }
                ;

print_stmt:     PRINTF PAREN_OPEN FORMAT_SPECIFIER COMMA identifier PAREN_CLOSE SC
                {
                    $$ = mk1("print_stmt",$5);
                }
                ;

scan_stmt:		SCANF PAREN_OPEN FORMAT_SCANF COMMA UNAND identifier PAREN_CLOSE SC
				{
					$$ = mk1;
				}
				;

compound_stmt:  CURLY_OPEN local_decls stmt_list CURLY_CLOSE
                {
                    $1 = mk0("{");
                    $4 = mk0("}");
                    $$ = mk4("compound_stmt", $1, $2, $3, $4);
                }
                ;

local_decls:    local_decls local_decl 
                {
                    $$ = mk2("local_decls", $1, $2);
                }
                |
                {
                    $$ = mk1("local_decls", mk0("epsilon"));
                }
                ;

local_decl:     type_spec identifier SC 
                {
                    variables++;
                    temp[$2->children[0]->type] = top;
                    top+=4;
                    $3 = mk0(";");
                    $$ = mk3("local_decl", $1, $2, $3);
                }
                | type_spec identifier SQ_OPEN expr SQ_CLOSE SC
                {
                    $3 = mk0("[");
                    $5 = mk0("]");
                    $6 = mk0(";");
                    $$ = mk6("local_decl", $1, $2, $3, $4, $5, $6);
                }
                ;

if_stmt:        IF PAREN_OPEN expr PAREN_CLOSE stmt
                {
                    $1 = mk0("if");
                    $2 = mk0("(");
                    $4 = mk0(")");
                    $$ = mk5("if_stmt", $1, $2, $3, $4, $5);
                }
                | IF PAREN_OPEN expr PAREN_CLOSE stmt ELSE stmt
                {
                    $1 = mk0("if");
                    $2 = mk0("(");
                    $4 = mk0(")");
                    $6 = mk0("else");
                    $$ = mk7("if_stmt", $1, $2, $3, $4, $5, $6, $7);
                }
                ;

return_stmt:    RETURN SC 
                {
                    $1 = mk0("return");
                    $2 = mk0(";");
                    $$ = mk2("return_stmt", $1, $2);
                }
                | RETURN expr SC
                {
                    $1 = mk0("return");
                    $3 = mk0(";");
                    $$ = mk3("return_stmt", $1, $2, $3);
                }
                ;

break_stmt:     BREAK SC
                {
                    $1 = mk0("break");
                    $2 = mk0(";");
                    $$ = mk2("break_stmt", $1, $2);
                }
                ;

continue_stmt:  CONTINUE SC
                {
                    $1 = mk0("continue");
                    $2 = mk0(";");
                    $$ = mk2("continue_stmt", $1, $2);
                }
                ;

assign_stmt:    identifier ASSGN expr SC 
                {
                    $4 = mk0(";");
                    $$ = mk2("assign_stmt", mk2("=", $1, $3), $4);
                }
                | identifier SQ_OPEN expr SQ_CLOSE ASSGN expr SC
                {
                    $5 = mk5("=", $1, mk0("["), $3, mk0("]"), $6);
                    $$ = mk1("assign_stmt", $5);
                }
                ;

expr:           Pexpr OR Pexpr 
                {
                    $2 = mk2("||", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr EE Pexpr
                {
                   $2 = mk2("==", $1, $3);
                    $$ = mk1("expr", $2);
                } 
                | Pexpr NE Pexpr
                {
                    $2 = mk2("!=", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr LE Pexpr 
                {
                    $2 = mk2("<=", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr LT Pexpr 
                {
                    $2 = mk2("<", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr GE Pexpr 
                {
                    $2 = mk2(">=", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr GT Pexpr
                {
                    $2 = mk2(">", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr AND Pexpr
                {
                    $2 = mk2("&&", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr PLUS Pexpr 
                {
                    $2 = mk2("+", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr MINUS Pexpr
                {
                    $2 = mk2("-", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr INTO Pexpr 
                {
                    $2 = mk2("*", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr BY Pexpr 
                {
                   $2 = mk2("/", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | Pexpr MOD Pexpr
                {
                    $2 = mk2("%%", $1, $3);
                    $$ = mk1("expr", $2);
                }
                | NOT Pexpr 
                {
                    $1 = mk0("!");
                    $$ = mk2("expr", $1, $2);
                }
                | MINUS Pexpr
                {
                    $1 = mk0("-");
                    $$ = mk2("expr", $1, $2);
                } 
                | PLUS Pexpr 
                {
                    $1 = mk0("+");
                    $$ = mk2("expr", $1, $2);
                }
                | INTO Pexpr 
                {
                    $1 = mk0("*");
                    $$ = mk2("expr", $1, $2);
                }
                | UNAND Pexpr
                {
                    $1 = mk0("&");
                    $$ = mk2("expr", $1, $2);
                }
                | Pexpr
                {
                    $$ = mk1("expr", $1);
                }
                | identifier PAREN_OPEN args PAREN_CLOSE
                {
                    if(loc.find($1->children[0]->type)==loc.end())
                        yyerror("");
                    $2 = mk0("(");
                    $4 = mk0(")");
                    $$ = mk4("expr", $1, $2, $3, $4);
                }
                | identifier SQ_OPEN expr SQ_CLOSE
                {
                    $2 = mk0("[");
                    $4 = mk0("]");
                    $$ = mk4("expr", $1, $2, $3, $4);
                }
                ;

Pexpr:          integerLit
                {
                    $$ = mk1("Pexpr", $1);
                }
                | floatLit 
                {
                    $$ = mk1("Pexpr", $1);
                }
                | identifier 
                {
                    if(temp.find($1->children[0]->type)==temp.end() && loc["global"].find($1->children[0]->type)==loc["global"].end())
                        yyerror("");
                    $$ = mk1("Pexpr", $1);
                }
                | PAREN_OPEN expr PAREN_CLOSE 
                {
                    $1 = mk0("(");
                    $3 = mk0(")");
                    $$ = mk3("Pexpr", $1, $2, $3);
                }
                ;

integerLit:     INTEGER_LITERAL 
                {
                    $1 = mk0(string(yytext));
                    $$ = mk1("integerLit", $1);
                }
                ;

floatLit:       FLOAT_LITERAL 
                {
                    $1 = mk0(string(yytext));
                    $$ = mk1("floatLit", $1);
                }
                ;

identifier:     IDENTIFIER 
                {
                    $1 = mk0(string(yytext));
                    $$ = mk1("IDENTIFIER", $1);
                }
                ;

args:           args_list 
                {
                    $$ = mk1("args", $1);
                }
                | 
                {
                    $$ = mk1("args", mk0("epsilon"));
                }
                ;

args_list:      args_list COMMA expr 
                {
                    $2 = mk0(",");
                    $$ = mk3("args_list", $1, $2, $3);
                }
                | expr
                {
                    $$ = mk1("args_list", $1);
                }
                ;
%%

void yyerror(string s) {
    printf("Invalid\n");
    exit(0);
}

int main(void) {
    loc["global"];
    yyparse();
    top = (int)(16 * (ceil(variables/4.0)));
    // cout << top << endl;
    // for(auto &it:loc) {
    //     cout << it.first << endl;
    //     for(auto &j:it.second)
    //     {
    //         cout <<"\t"<< j.first <<"->" << j.second << endl;
    //     }
    //     cout <<"===" << endl;
    // }
    printf(".LC0:\n\t.string \"%%d\\n\"\n\t.text\n\t.globl main\n\t.type main, @function\n");
    printf("main:\n.LFB0:\n\t.cfi_startproc\n\tpushq %%rbp\n\t.cfi_def_cfa_offset 16\n\t.cfi_offset 6, -16\n\tmovq %%rsp, %%rbp\n\t.cfi_def_cfa_register 6\n\t");
    printf("subq $%d,%%rsp\n", top);
    getasm(root);
    printf("\tmovl $0, %%eax\n\tleave\n\t.cfi_def_cfa 7, 8\n\tret\n\t.cfi_endproc\n");
    //printtree(root);
    freenodes(root);
    return 0;
}

void getexp(node* root) {
    if(root == NULL)
        return;

    for(int i=0;i<root->noc;i++)
        getexp(root->children[i]);

    if(root->type == "IDENTIFIER" && !root->asmd) {
        printf("\tmovl -%d(%%rbp),%%ecx\n\tpushq %%rcx\n",loc[currfun][root->children[0]->type]);
        root->asmd = true;
    }
    //add for function call
    else if(root->type == "integerLit") {
        printf("\tmovl $%d,%%ecx\n\tpushq %%rcx\n",stoi(root->children[0]->type));
    }
    else if(root->type == "floatLit") {
        printf("\tmovl $%d,%%ecx\n\tpushq %%rcx\n",stoi(root->children[0]->type));
    }
    else if(root->type == "+" && root->noc == 2) {
        printf("\tpopq %%rbx\n\tpopq %%rcx\n\taddl %%ebx, %%ecx\n\tpushq %%rcx\n");
    }
    else if(root->type == "-" && root->noc == 2) {
        printf("\tpopq %%rbx\n\tpopq %%rcx\n\tsubl %%ebx, %%ecx\n\tpushq %%rcx\n");
    }
    else if(root->type == "*" && root->noc == 2) {
        printf("\tpopq %%rbx\n\tpopq %%rcx\n\timull %%ebx, %%ecx\n\tpushq %%rcx\n");
    }
    else if(root->type == "/") {
        printf("\tpopq %%rcx\n\tpopq %%rax\n\tcltd\n\tidivl %%ecx\n\tpushq %%rax\n");
    }
    else if(root->type == "%%") {
        printf("\tpopq %%rcx\n\tpopq %%rax\n\tcltd\n\tidivl %%ecx\n\tpushq %%rdx\n");
    }
    else if(root->type == "||") {
        string l1 = getlabel();
        string l2 = getlabel();
        string l3 = getlabel();
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl $0,%eax\n\tjne "<<l1<<"\n\tcmpl $0,%ebx\n\tje "<<l2<<"\n"<<l1<<":\n\tmovl $1,%eax\n\tjmp "<<l3<<"\n"<<l2<<":\n\tmovl $0,%eax\n"<<l3<<":\n\tpushq %rax\n";
    }
    else if(root->type == "&&") {
        string l1 = getlabel();
        string l2 = getlabel();
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl $0,%ebx\n\tje "<<l1<<"\n\tcmpl $0,%eax\n\tje "<<l1<<"\n\tmovl $1,%eax\n\tjmp "<<l2<<"\n"<<l1<<":\n\tmovl $0,%eax\n"<<l2<<":\n\tpushq %rax\n";
    }
    else if(root->type == "==") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsete %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == "!=") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsetne %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == "<=") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsetle %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == "<") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsetl %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == ">=") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsetge %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == ">") {
        cout <<"\tpopq %rax\n\tpopq %rbx\n\tcmpl %eax,%ebx\n\tsetg %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == "expr" && root->children[0]->type == "!") {
        getasm(root->children[1]);
        cout <<"\tpopq %rbx\n\tcmpl $0,%ebx\n\tsete %al\n\tmovzbl %al,%eax\n\tpushq %rax\n";
    }
    else if(root->type == "expr" && root->children[0]->type == "-" && root->children[0]->noc == 0) {
        getasm(root->children[1]);
        cout <<"\tpopq %rax\n\tnegl %eax\n\tpushq %rax\n";
    }
}

void getasm(node* root) {
    if(root == NULL)
        return;

    if(root->type == "if_stmt" && !root->asmd) {
        root->asmd = true;
        if(root->noc == 5) {
            getexp(root->children[2]);
            string l1 = getlabel();
            cout << "\tpopq %rax\n\tcmpl $0, %eax\n\tje " << l1 << "\n";
            getasm(root->children[4]);
            cout << l1 << ":\n";
        }
        else if(root->noc == 7) {
            getexp(root->children[2]);
            string l1 = getlabel();
            string l2 = getlabel();
            cout << "\tpopq %rax\n\tcmpl $0, %eax\n\tje " << l1 << "\n";
            getasm(root->children[4]);
            cout << "\tjmp " << l2 << "\n";
            cout << l1 << ":\n";
            getasm(root->children[6]);
            cout << l2 << ":\n";
        }
    }
    else if(root->type == "while_stmt" && !root->asmd) {
        root->asmd = true;
        string l1 = getlabel();
        string l2 = getlabel();
        cout << l1 << ":\n"; 
        getexp(root->children[2]);
        cout << "\tpopq %rax\n\tcmpl $0, %eax\n\tje " << l2 << "\n";
        getasm(root->children[4]);
        cout << "jmp " << l1 <<"\n";
        cout << l2 <<":\n";
    }
    // else if(root->type == "func_decl" && !root->asmd) {
    //     root->asmd = true;
    //     currfun = root->children[1]->children[0]->type;

    //     cout << currfun << ":\n";
    //     printf("\t.cfi_startproc\n\tpushq %%rbp\n\t.cfi_def_cfa_offset 16\n\t.cfi_offset 6, -16\n\tmovq %%rsp, %%rbp\n\t.cfi_def_cfa_register 6\n\t");
    //     getasm(root->children[3]);
    //     getasm(root->children[5]);
    //     printf("\t.cfi_def_cfa 7, 8\n\tret\n\t.cfi_endproc\n");
    // }

    for(int i=0;i<root->noc;i++)
        getasm(root->children[i]);

    if(root->type == "print_stmt" && !root->asmd) {
        root->asmd = true;
        int addr = loc[currfun][root->children[0]->children[0]->type];
        printf("\tmovl -%d(%%rbp), %%eax\n\tmovl %%eax, %%esi\n\tleaq    .LC0(%%rip), %%rdi\n\tmovl $0, %%eax\n\tcall printf@PLT\n",addr);      
    }
    else if(root->type == "=" && !root->asmd) {
        root->asmd = true;
        getexp(root->children[1]);
        //cout << exp;
        printf("\tpopq %%rbx\n\tmovl %%ebx, -%d(%%rbp)\n",loc[currfun][root->children[0]->children[0]->type]);
    }
    // else if(root->type == "return_stmt" && !root->asmd) {
    //     root->asmd = true;
    //     if(root->noc != 2) {
    //         getexp(root->children[1]);
    //     }
    // }
    // else if(root->type == "param" && !root->asmd) {
    //     root->asmd = true;
    //     printf("\tpopq %%rax\n\tmovl %%eax,-%d(rbp)\n",loc[currfun][root->children[1]->children[0]->type]);
    // }

}

node* mk0(string t) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->noc = 0;
    return newnode;
}

node* mk1(string t, node* one) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->noc = 1;
    return newnode;
}

node* mk2(string t, node* one, node* two) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->noc = 2;
    return newnode;
}

node* mk3(string t, node* one, node* two, node* three) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->children[2] = three;
    newnode->noc = 3;
    return newnode;
}

node* mk4(string t, node* one, node* two, node* three, node* four) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->children[2] = three;
    newnode->children[3] = four;
    newnode->noc = 4;
    return newnode;
}

node* mk5(string t, node* one, node* two, node* three, node* four, node* five) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->children[2] = three;
    newnode->children[3] = four;
    newnode->children[4] = five;
    newnode->noc = 5;
    return newnode;
}

node* mk6(string t, node* one, node* two, node* three, node* four, node* five, node* six) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->children[2] = three;
    newnode->children[3] = four;
    newnode->children[4] = five;
    newnode->children[5] = six;
    newnode->noc = 6;
    return newnode;
}

node* mk7(string t, node* one, node* two, node* three, node* four, node* five, node* six, node* seven) {
    node* newnode = new node;
    
    newnode->type = t;
    
    newnode->children[0] = one;
    newnode->children[1] = two;
    newnode->children[2] = three;
    newnode->children[3] = four;
    newnode->children[4] = five;
    newnode->children[5] = six;
    newnode->children[6] = seven;
    newnode->noc = 7;
    return newnode;
}


void freenodes(node* root) {
    if(root->noc == 0) {
        free(root); 
        return;
    }
    int i;
    for(int i = 0; i < root->noc; i++)
        free(root->children[i]);
    free(root);
}

string getlabel() {
    return (".L" + to_string(ctr++)); 
}

// void printtree(node* root) {
//     nn++;
//     printf("%s--->",root->type);
//     for(int i=0;i<root->noc;i++)
//         printf("(%i~~%s)    ",i,root->children[i]->type);
//     printf("\n\n\n");
//     for(int i=0;i<root->noc;i++)
//         printtree(root->children[i]);
// }
