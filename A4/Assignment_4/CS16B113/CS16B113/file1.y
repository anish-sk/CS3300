%token FLOAT_LITERAL INTEGER_LITERAL INT RETURN BREAK CONT VOID FLOAT WHILE IF
%token IDENTIFIER ELSE OR EQ NEQ LEQ GEQ AND FORMAT_SPECIFIER PRINTF SCANF FORMAT_SCANF
//%type 	program decl_list decl var_decl type_spec func_decl params param_list
//%type 	param stmt_list stmt while_stmt compound_stmt local_decls local_decl
//%type 	if_stmt return_stmt break_stmt continue_stmt assign_stmt expr Pexpr
//%type 	integerLit floatLit identifier arg_list args

%start program

%{
	#include <stdio.h>
	#include <bits/stdc++.h>
	using namespace std;
	typedef struct node
	{
		int h1,h2,max_path,mainflag;
		char name[50];
		int size;
		struct node* child[10];
		
		bool isAvail;
		int value;
		int line;
		int lastDec;
		string netExpr;
	}node;
	int ifmax = 0,whmax =0,mainmax = 0;
	extern char* yytext;
	node* root = NULL;
	node *mknode0(int s);
	node *mknode1(int s,node* c1);
	node *mknode2(int s,node *c1,node *c2);
	node *mknode3(int s,node *c1,node *c2,node *c3);
	node *mknode4(int s,node *c1,node *c2,node *c3,node *c4);
	node *mknode5(int s,node *c1,node *c2,node *c3,node *c4,node *c5);
	node *mknode6(int s,node *c1,node *c2,node *c3,node *c4,node *c5,node *c6);
	node *mknode7(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7);
	node *mknode8(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7,node *c8);
	void yyerror(string);
	int yylex(void);
	
	string final_as = "\t.text\n\t.section\t.rodata\n";
	string main_as = "";

	string function_as = "";
	
	string label = ".LC";
	int labelcount = 0, varcount = 0, numvar = 0;
	unordered_map<string, int> var;	// variable name -> entry number
	unordered_map<string, pair<bool, int> > varValues; // variable name -> (true if constant, value)
	unordered_map<string, bool> varIsUsed;

	// for cse
	unordered_map<string, int> varLastDec;		// line no. of latest declaration of variable
	unordered_map<string, map<int, vector<int> > > expLast2Used; // exp -> (last Modified -> line no.s where it is used)
	void getCSE(node* root);

	map<int, int> strengthreduction;

	int linenum = 1;
	bool ifExpr = false;
	int ifSimple = -1;

	void constProp_Fold(node* root);
	vector<pair<int, pair<string,int> > > constantProp;
	// vector<tuple<int, string, int> > constantProp;
	map<int, int> constantFold;

	// Generate Assembly Code
	void gas(node *root);

#define YYSTYPE struct node *
%}

%%

program:
	decl_list
	{
		$$ = mknode1(1,$1);
		root = $$;
		strcpy($$->name,"program");
	};

decl_list:
	decl_list decl
	{
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"decl_list");
	}
|	decl
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"decl_list");
	};

decl:
	var_decl
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"decl");
	}
|	func_decl
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"decl");
	};

var_decl:
	type_spec identifier ';'
	{
		$3 = mknode0(0);
		strcpy($3->name,";");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"var_decl");
	}
|	type_spec identifier ',' var_decl
	{
		$3 = mknode0(0);
		strcpy($3->name,";");
		$$ = mknode4(4,$1,$2,$3,$4);
		strcpy($$->name,"var_decl");
	}
|	type_spec identifier '[' integerLit ']' ';'
	{
		$3 = mknode0(0);
		strcpy($3->name,"[");
		$5 = mknode0(0);
		strcpy($5->name,"]");
		$6 = mknode0(0);
		strcpy($6->name,";");
		$$ = mknode6(6,$1,$2,$3,$4,$5,$6);
		strcpy($$->name,"var_decl");
	}
|	type_spec identifier '[' integerLit ']' ',' var_decl
	{
		$3 = mknode0(0);
		strcpy($3->name,"[");
		$5 = mknode0(0);
		strcpy($5->name,"]");
		$6 = mknode0(0);
		strcpy($6->name,",");
		$$ = mknode7(7,$1,$2,$3,$4,$5,$6,$7);
		strcpy($$->name,"var_decl");
	};

type_spec:
	VOID
	{
		$1 = mknode0(0);
		strcpy($1->name,"VOID");
		$$ = mknode1(1,$1);
		strcpy($$->name,"type_spec");
	}
|	INT
	{
		$1 = mknode0(0);
		strcpy($1->name,"INT");
		$$ = mknode1(1,$1);
		strcpy($$->name,"type_spec");
	}	
|	FLOAT
	{
		$1 = mknode0(0);
		strcpy($1->name,"FLOAT");
		$$ = mknode1(1,$1);
		strcpy($$->name,"type_spec");
	}
|	VOID '*'
	{
		$1 = mknode0(0);
		strcpy($1->name,"VOID");
		$2 = mknode0(0);
		strcpy($2->name,"*");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"type_spec");
	}
|	INT '*'
	{
		$1 = mknode0(0);
		strcpy($1->name,"INT");
		$2 = mknode0(0);
		strcpy($2->name,"*");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"type_spec");
	}
|	FLOAT '*'
	{
		$1 = mknode0(0);
		strcpy($1->name,"FLOAT");
		$2 = mknode0(0);
		strcpy($2->name,"*");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"type_spec");
	};

func_decl:
	type_spec identifier '(' params ')' compound_stmt
	{
		$3 = mknode0(0);
		strcpy($3->name,"(");
		$5 = mknode0(0);
		strcpy($5->name,")");
		$$= mknode6(6,$1,$2,$3,$4,$5,$6);
		strcpy($$->name,"func_decl");
	};

params:
	param_list
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"params");
	}
|	{
		$$ = mknode0(1);
		strcpy($$->name,"params");
	};

param_list:
	param_list ',' param
	{
		$2 = mknode0(0);
		strcpy($2->name,",");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"param_list");
	}
|	param
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"param_list");
	};

param:
	type_spec identifier
	{
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"param");
	}
|	type_spec identifier '[' ']' 
	{
		$3 = mknode0(0);
		strcpy($3->name,"[");
		$4 = mknode0(0);
		strcpy($4->name,"]");
		$$ = mknode4(4,$1,$2,$3,$4);
		strcpy($$->name,"param");
	};

stmt_list:
	stmt_list stmt
	{
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"stmt_list");
	}
|	stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt_list");
	};

stmt:
	assign_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	compound_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	if_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	while_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	print_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	scan_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	return_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	break_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	}
|	continue_stmt
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"stmt");
	};

while_stmt:
	WHILE '(' expr ')' stmt
	{
		$1 = mknode0(0);
		strcpy($1->name,"WHILE");
		$2 = mknode0(0);
		strcpy($2->name,"(");
		$4 = mknode0(0);
		strcpy($4->name,")");
		$$ = mknode5(5,$1,$2,$3,$4,$5);
		strcpy($$->name,"while_stmt");
	};

print_stmt:
	PRINTF '(' format_specifier ',' identifier ')' ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"PRINTF");
		$2 = mknode0(0);
		strcpy($2->name,"(");
		$4 = mknode0(0);
		strcpy($4->name,",");
		$6 = mknode0(0);
		strcpy($6->name,")");
		$7 = mknode0(0);
		strcpy($7->name,";");
		$$ = mknode7(7,$1,$2,$3,$4,$5,$6,$7);
		strcpy($$->name,"print_stmt");
	};

scan_stmt:
	SCANF '(' format_specifier ',' '&' identifier ')' ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"SCANF");
		$2 = mknode0(0);
		strcpy($2->name,"(");
		$4 = mknode0(0);
		strcpy($4->name,",");
		$5 = mknode0(0);
		strcpy($5->name, "&");
		$7 = mknode0(0);
		strcpy($6->name,")");
		$8 = mknode0(0);
		strcpy($7->name,";");
		$$ = mknode8(8,$1,$2,$3,$4,$5,$6,$7,$8);
		strcpy($$->name,"scan_stmt");
	};
	
compound_stmt:
	'{' local_decls stmt_list '}'
	{
		$1 = mknode0(0);
		strcpy($1->name,"{");
		$4 = mknode0(0);
		strcpy($4->name,"}");
		$$ = mknode4(4,$1,$2,$3,$4);
		strcpy($$->name,"compound_stmt");
	};

local_decls:
	local_decls local_decl
	{
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"local_decls");
	}
|	{
		$$ = mknode0(1);
		strcpy($$->name,"local_decls");
	};

local_decl:
	type_spec identifier ';'
	{
		$3 = mknode0(0);
		strcpy($3->name,";");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"local_decl");
		
		numvar++;
	}
|	type_spec identifier '[' expr ']' ';'
	{
		$3 = mknode0(0);
		strcpy($3->name,"[");
		$5 = mknode0(0);
		strcpy($5->name,"]");
		$6 = mknode0(0);
		strcpy($6->name,";");
		$$ = mknode6(6,$1,$2,$3,$4,$5,$6);
		strcpy($$->name,"local_decl");
	};

if_stmt:
	IF '(' expr ')' stmt
	{
		$1 = mknode0(0);
		strcpy($1->name,"IF");
		$2 = mknode0(0);
		strcpy($2->name,"(");
		$4 = mknode0(0);
		strcpy($4->name,")");
		$$ = mknode5(5,$1,$2,$3,$4,$5);
		strcpy($$->name,"if_stmt");
	}
|	IF '(' expr ')' stmt ELSE stmt
	{
		$1 = mknode0(0);
		strcpy($1->name,"IF");
		$2 = mknode0(0);
		strcpy($2->name,"(");
		$4 = mknode0(0);
		strcpy($4->name,")");
		$6 = mknode0(0);
		strcpy($6->name,"ELSE");
		$$ = mknode7(7,$1,$2,$3,$4,$5,$6,$7);
		strcpy($$->name,"if_stmt");
	};

return_stmt:
	RETURN ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"RETURN");
		$2 = mknode0(0);
		strcpy($2->name,";");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"return_stmt");
	}
|	RETURN expr ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"RETURN");
		$3 = mknode0(0);
		strcpy($3->name,";");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"return_stmt");
	};

break_stmt:
	BREAK ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"BREAK");
		$2 = mknode0(0);
		strcpy($2->name,";");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"break_stmt");
	};

continue_stmt:
	CONT ';'
	{
		$1 = mknode0(0);
		strcpy($1->name,"CONT");
		$2 = mknode0(0);
		strcpy($2->name,";");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"continue_stmt");
	};

assign_stmt:
	identifier '=' expr ';'
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"=");
		$4 = mknode0(0);
		strcpy($4->name,";");
		$$ = mknode2(2,$2,$4);
		strcpy($$->name,"assign_stmt");
	}
|	identifier '[' expr ']' '=' expr ';'
	{
		$2 = mknode0(0);
		strcpy($2->name,"[");
		$4 = mknode0(0);
		strcpy($4->name,"]");
		$7 = mknode0(0);
		strcpy($7->name,";");
		$5 = mknode5(5,$1,$2,$3,$4,$6);
		strcpy($5->name,"=");
		$$ = mknode2(2,$5,$7);
		strcpy($$->name,"assign_stmt");
	};

expr:
	Pexpr OR Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"OR");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr EQ Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"EQ");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr NEQ Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"NEQ");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr LEQ Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"LEQ");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '<' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"<");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr GEQ Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"GEQ");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '>' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,">");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr AND Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"AND");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '+' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"+");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '-' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"-");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '*' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"*");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '/' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"/");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr '%' Pexpr
	{
		$2 = mknode2(2,$1,$3);
		strcpy($2->name,"%");
		$$ = mknode1(1,$2);
		strcpy($$->name,"expr");
	}
|	'!' Pexpr
	{
		$1 = mknode0(0);
		strcpy($1->name,"!");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"expr");
	}
|	'-' Pexpr
	{
		$1 = mknode0(0);
		strcpy($1->name,"-");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"expr");
	}
|	'+' Pexpr
	{
		$1 = mknode0(0);
		strcpy($1->name,"+");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"expr");
	}
|	'*' Pexpr
	{
		$1 = mknode0(0);
		strcpy($1->name,"*");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"expr");
	}
|	'&' Pexpr
	{
		$1 = mknode0(0);
		strcpy($1->name,"&");
		$$ = mknode2(2,$1,$2);
		strcpy($$->name,"expr");
	}
|	Pexpr
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"expr");
	}
|	identifier '(' args ')'
	{
		$2 = mknode0(0);
		$4 = mknode0(0);
		strcpy($2->name,"(");
		strcpy($4->name,")");			
		$$ = mknode4(4,$1,$2,$3,$4);
		strcpy($$->name,"expr");
	}
|	identifier '[' expr ']'
	{
		$2 = mknode0(0);
		$4 = mknode0(0);
		strcpy($2->name,"[");
		strcpy($4->name,"]");
		$$ = mknode4(4,$1,$2,$3,$4);
		strcpy($$->name,"expr");
	};

Pexpr:
	integerLit
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"Pexpr");
	}
|	floatLit
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"Pexpr");
	}
|	identifier
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"Pexpr");
	}
|	'(' expr ')'
	{
		$1 = mknode0(0);
		$3 = mknode0(0);
		strcpy($1->name,"(");
		strcpy($3->name,")");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"Pexpr");
	};

integerLit:
	INTEGER_LITERAL
	{
		$1 = mknode0(0);
		strcpy($1->name,yytext);
		$$ = mknode1(1,$1);
		strcpy($$->name,"integerLit");	
	};

floatLit:
	FLOAT_LITERAL
	{
		$1 = mknode0(0);
		strcpy($1->name,yytext);
		$$ = mknode1(1,$1);
		strcpy($$->name,"floatLit");
	};

identifier:
	IDENTIFIER
	{
		$1 = mknode0(0);
		strcpy($1->name,yytext);
		$$ = mknode1(1,$1);
		strcpy($$->name,"identifier");
	};
	
format_specifier:
	FORMAT_SPECIFIER
	{
		$1 = mknode0(0);
		strcpy($1->name,yytext);
		$$ = mknode1(1,$1);
		strcpy($$->name,"format_specifier_print");
	}
|	FORMAT_SCANF
	{
		$1 = mknode0(0);
		strcpy($1->name,yytext);
		$$ = mknode1(1,$1);
		strcpy($$->name,"format_specifier_scan");
	}
	;

arg_list:
	arg_list ',' expr
	{
		$2 = mknode0(0);
		strcpy($2->name,",");
		$$ = mknode3(3,$1,$2,$3);
		strcpy($$->name,"arg_list");
	}
|	expr
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"arg_list");
	};

args:
	arg_list
	{
		$$ = mknode1(1,$1);
		strcpy($$->name,"args");
	}
|	{
		$$ = mknode0(1);
		strcpy($$->name,"args");
	};



%%

void yyerror(string s) {
    printf("Invalid Input\n");
	exit(0);
}

bool custSort1(const pair<int, int>& a, const pair<int, int>& b) 
{
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first; 
}

bool custSort2(const pair<int, pair<string, int> >& a, const pair<int, pair<string, int> >& b) 
{
	if(a.first == b.first)
		return var[a.second.first] < var[b.second.first];
	else
		return (a.first < b.first);
}

bool custSort3(const string& a, const string& b)
{
	return var[a] < var[b];
}

bool custSort4(const vector<int> &a, const vector<int> &b)
{
	return a[0] <= b[0];
}

int main()
{
	yyparse();

	constProp_Fold(root->child[0]->child[0]->child[0]->child[5]);

	// get unused variables and sort in order of declaration
	vector<string> unused;
	auto it = varIsUsed.begin();
	for(; it!=varIsUsed.end(); ++it)
		if(!it->second)
			unused.push_back(it->first);

	sort(unused.begin(), unused.end(), custSort3);
	//sort(constantFold.begin(), constantFold.end(), custSort1);
	sort(constantProp.begin(), constantProp.end(), custSort2);

	// remove space allocated for unused variables
	for(int i=0; i<unused.size(); ++i)
	{
		int entrynum = var[unused[i]];
		
		var.erase(unused[i]);
		varcount--;

		for(auto it = var.begin(); it!=var.end(); ++it)
			if(it->second > entrynum)
				it->second--;
	}

	getCSE(root->child[0]->child[0]->child[0]->child[5]);
	// for(auto itr = expLast2Used.begin(); itr != expLast2Used.end(); ++itr)
	// {
	// 	cout << "yo ";
	// 	cout << itr->first << "\n";
	// 	for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
	// 	{
	// 		cout << itr2->first << " ";
	// 		for(auto itr3 = itr2->second.begin(); itr3 != itr2->second.end(); ++itr3)
	// 			cout << *itr3 << " ";
	// 		cout << "\n";
	// 	}
	// }
	vector< vector<int> > ans_cse;
	for(auto itr = expLast2Used.begin(); itr != expLast2Used.end();)
	{
		for(auto itr2 = itr->second.begin(); itr2 != itr->second.end();)
		{
			if(itr2->second.size() > 1)
			{	
				ans_cse.push_back(itr2->second);
				++itr2;
			}
			else
			{
				(itr->second).erase(itr2++);
			}
		}

		if(itr->second.empty())
			expLast2Used.erase(itr++);
		else
			++itr;
	}

	// cout << "wait\n";

	// for(auto itr = expLast2Used.begin(); itr != expLast2Used.end(); ++itr)
	// {
	// 	cout << "yo ";
	// 	cout << itr->first << "\n";
	// 	for(auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
	// 	{
	// 		cout << itr2->first << " ";
	// 		for(auto itr3 = itr2->second.begin(); itr3 != itr2->second.end(); ++itr3)
	// 			cout << *itr3 << " ";
	// 		cout << "\n";
	// 	}
	// }
	sort(ans_cse.begin(), ans_cse.end(), custSort4);
	// varcount += ans_cse.size();
	
	// generate assembly code
	ofstream outasm("assembly.s");
	main_as = "\t.text\n\t.globl\tmain\n\t.type\tmain, @function\nmain:\n";
	main_as +="\tpushq\t%rbp\n\tmovq\t%rsp, %rbp\n\tsubq\t$";
	main_as += "64, %rsp\n";//to_string(4*varcount+20)+", %rsp\n";
	gas(root->child[0]->child[0]->child[0]->child[5]->child[2]);
	
	main_as += "\tnop\n\tleave\n\tret";
	final_as += function_as + main_as;
	outasm << final_as << endl;

	// print optimisation summary
	ofstream outsum("summary.txt");

	outsum << "unused-vars\n";
	for(int i=0; i<unused.size(); ++i)
		outsum << unused[i] << "\n";
	outsum << "\n";

	if(ifSimple >= 0)
		outsum << "if-simpl\n" << ifSimple << "\n\n";
	else
		outsum << "if-simpl\n\n";

	outsum << "strength-reduction\n";
	for(auto i=strengthreduction.begin(); i!= strengthreduction.end(); ++i)
	{
		outsum << i->first << " " << i->second << "\n";
	}
	outsum << "\n";

	outsum << "constant-folding\n";
	// for(int i=0; i<constantFold.size(); ++i)
	// {
	// 	if( (i < constantFold.size()-1) && constantFold[i].first == constantFold[i+1].first)
	// 		continue;
	// 	outsum << constantFold[i].first << " " << constantFold[i].second << "\n";
	// }
	for(auto i=constantFold.begin(); i!= constantFold.end(); ++i)
	{
		outsum << i->first << " " << i->second << "\n";
	}
	outsum << "\n";

	outsum << "constant-propagation";
	for(int i=0; i<constantProp.size(); ++i)
	{
		if((i>0) && (constantProp[i].first) == (constantProp[i-1].first))
		{
			if((constantProp[i].second.first) != (constantProp[i-1].second.first))
				outsum << " " << (constantProp[i].second.first) << " " << (constantProp[i].second.second) << "";
		}
		else
			outsum << "\n" << (constantProp[i].first) << " " << (constantProp[i].second.first) << " " << (constantProp[i].second.second);
	}
	outsum << "\n\n";

	outsum << "cse\n";
	for(int i=0; i<ans_cse.size(); ++i)
	{
		for(int j=0; j<ans_cse[i].size(); ++j)
			outsum << ans_cse[i][j] << " ";
		outsum << "\n";
	}

	return 0;
}

void getCSE(node* root)
{
	if(root == NULL)
		return;

	if(strcmp(root->name,"compound_stmt") == 0)
	{
		getCSE(root->child[1]);
		getCSE(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			getCSE(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;	// variable's name

			varLastDec[temp] = root->child[1]->child[1]->child[0]->line;
			if(varValues.count(temp) <= 0)
			{
				varValues[temp].first = false;
				varValues[temp].second = -1;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		getCSE(root->child[0]);
		getCSE(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
	{
		getCSE(root->child[0]);
	}
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		getCSE(root->child[0]->child[1]);

		string temp_varname = root->child[0]->child[0]->child[0]->name;
		varValues[temp_varname].first = false;

		varLastDec[temp_varname] = root->line;
		// cout << "check " << temp_varname << " " << root->line << "\n";

		if(root->child[0]->child[1]->isAvail)
		// statically computable
		{
			varValues[temp_varname].second = root->child[0]->child[1]->value;
			varValues[temp_varname].first = true;
		}
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		string temp = root->child[4]->child[0]->name;
		if(varValues[temp].first)
		{
			root->child[4]->child[0]->isAvail = true;
			root->child[4]->child[0]->value = varValues[temp].second;
			root->child[4]->isAvail = true;
			root->child[4]->value = root->child[4]->child[0]->value;
		}
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		string temp = root->child[5]->child[0]->name;
		varValues[temp].first = false;
		varLastDec[temp] = root->line;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		getCSE(root->child[2]);

		if(root->child[2]->isAvail)
		// statically computable
		{
			if(root->child[2]->value > 0)
			// else block is dead
			{
				getCSE(root->child[4]->child[0]);
			}
			else
			// "if" block is dead
			{
				if(root->size > 5)
					getCSE(root->child[6]->child[0]);
				// else
				// 	root = NULL;
			}
		}
		else
		{
			getCSE(root->child[4]);
			if(root->size > 5)
				getCSE(root->child[6]);
		}
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->size == 1)
		{
			if(strcmp(root->child[0]->name, "-") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value - root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "-" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}

			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value + root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "+" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value * root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
					root->netExpr = to_string(root->value);
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
					root->netExpr = root->child[0]->child[0]->netExpr + "*" + root->child[0]->child[1]->netExpr;
					
					int temp_lastdec = max(root->child[0]->child[0]->lastDec, root->child[0]->child[1]->lastDec);
					root->lastDec = temp_lastdec;
					expLast2Used[root->netExpr][temp_lastdec].push_back(root->line);
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					if(root->child[0]->child[0]->value > root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;

					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value < root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				getCSE(root->child[0]->child[0]);				
				getCSE(root->child[0]->child[1]);
			}
			else
			// Pexpr
			{
				getCSE(root->child[0]);

				root->isAvail = root->child[0]->isAvail;

				if(root->child[0]->isAvail)
				{
					root->value = root->child[0]->value;
				}
			}
		}
		else if(root->size == 2)
		{	
			if(strcmp(root->child[0]->name, "!") == 0)
				getCSE(root->child[1]);
			else if(strcmp(root->child[0]->name, "-") == 0)
				getCSE(root->child[1]);
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(strcmp(root->child[0]->name, "identifier") == 0)
		{
			if(varValues[root->child[0]->child[0]->name].first)
			// statically computable
			{
				root->child[0]->child[0]->value = varValues[root->child[0]->child[0]->name].second;
				root->child[0]->child[0]->isAvail = true;

				root->child[0]->value = root->child[0]->child[0]->value;
				root->child[0]->isAvail = true;

				root->value = root->child[0]->value;
				root->isAvail = true;
				root->netExpr = to_string(root->value);
				root->lastDec = varLastDec[root->child[0]->child[0]->name];
			}
			else
			{
				root->isAvail = false;
				root->netExpr = root->child[0]->child[0]->name;
				root->lastDec = varLastDec[root->child[0]->child[0]->name];				
			}
		}
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
		{
			char* gen;
			root->child[0]->value = strtol(root->child[0]->child[0]->name, &gen, 10);
			root->child[0]->isAvail = true;

			root->value = root->child[0]->value;
			root->isAvail = true;
			root->netExpr = root->child[0]->child[0]->name;
		}
		else
		// Case 3: ( expr )
		{
			getCSE(root->child[1]);
			root->isAvail = root->child[1]->isAvail;
			root->value = root->child[1]->value;
			root->netExpr = "(" + root->child[1]->netExpr + ")";
			root->lastDec = root->child[1]->lastDec;

			// if(!root->child[1]->isAvail)
			// 	expLast2Used[root->netExpr][root->lastDec].push_back(root->line);
		}
	}
	
	return;	
}

void constProp_Fold(node* root)
{
	if(root == NULL)
		return;

	if(strcmp(root->name,"compound_stmt") == 0)
	{
		// cout << "here";
		constProp_Fold(root->child[1]);
		constProp_Fold(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			constProp_Fold(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;

			if(var.count(temp) <= 0)
			// to get order of declaration of variables
			{
				var[temp] = varcount;
				++varcount;
			}
			if(varValues.count(temp) <= 0)
			{
				varValues[temp].first = false;
				varValues[temp].second = -1;
			}
			if(varIsUsed.count(temp) <= 0)
			// for "used variable" optimisation
			{
				varIsUsed[temp] = false;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		constProp_Fold(root->child[0]);
		constProp_Fold(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
	{
		constProp_Fold(root->child[0]);

		if(strcmp(root->child[0]->name, "if_stmt") == 0)
		{
			if(root->child[0]->child[2]->isAvail)
			// statically computable
			{
				if(root->child[0]->child[2]->value > 0)
				// else block is dead
				{
					ifSimple = 1;
					constProp_Fold(root->child[0]->child[4]->child[0]);
				}
				else
				// "if" block is dead
				{
					ifSimple = 0;
					if(root->child[0]->size > 5)
						constProp_Fold(root->child[0]->child[6]->child[0]);
					else
						root->child[0] = NULL;
				}
			}
			else
			{
				constProp_Fold(root->child[0]->child[4]);
				if(root->size > 5)
					constProp_Fold(root->child[0]->child[6]);
			}
		}
	}
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		constProp_Fold(root->child[0]->child[1]);

		varValues[root->child[0]->child[0]->child[0]->name].first = false;

		if(root->child[0]->child[1]->isAvail)
		{
			varValues[root->child[0]->child[0]->child[0]->name].second = root->child[0]->child[1]->value;
			varValues[root->child[0]->child[0]->child[0]->name].first = true;
		}

		// isUsed
		varIsUsed[root->child[0]->child[0]->child[0]->name] = true;
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		string temp = root->child[4]->child[0]->name;
		varIsUsed[temp] = true;

		if(varValues[temp].first)
		{
			root->child[4]->child[0]->isAvail = true;
			root->child[4]->child[0]->value = varValues[temp].second;
			root->child[4]->isAvail = true;
			root->child[4]->value = root->child[4]->child[0]->value;

			constantProp.push_back(make_pair(root->child[4]->line, make_pair(temp, root->child[4]->value)));
		}
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		string temp = root->child[5]->child[0]->name;
		varIsUsed[temp] = true;

		varValues[temp].first = false;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		ifExpr = true;
		constProp_Fold(root->child[2]);
		ifExpr = false;
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->size == 1)
		{
			if(strcmp(root->child[0]->name, "-") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value - root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line]=root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}

			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value + root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line] = root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					root->child[0]->value = root->child[0]->child[0]->value * root->child[0]->child[1]->value;
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;

					if(!ifExpr)	constantFold[root->line] = root->value;
				}
				else
				{
					root->child[0]->isAvail = false;
					root->isAvail = false;
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					if(root->child[0]->child[0]->value > root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;

					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value < root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value >= root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value <= root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value == root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value != root->child[0]->child[1]->value)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value > 0 || root->child[0]->child[1]->value > 0)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				constProp_Fold(root->child[0]->child[0]);				
				constProp_Fold(root->child[0]->child[1]);

				if(root->child[0]->child[0]->isAvail && root->child[0]->child[1]->isAvail)
				// constant folding
				{
					// cout << root->child[0]->child[1]->value << endl;
					if(root->child[0]->child[0]->value > 0 && root->child[0]->child[1]->value > 0)
						root->child[0]->value =  1;
					else
						root->child[0]->value = -1;
					
					root->child[0]->isAvail = true;

					root->value = root->child[0]->value;
					root->isAvail = true;
				}
			}
			else
			// Pexpr
			{
				constProp_Fold(root->child[0]);

				root->isAvail = root->child[0]->isAvail;

				if(root->child[0]->isAvail)
				{
					root->value = root->child[0]->value;
				}
			}
		}
		else if(root->size == 2)
		{	
			if(strcmp(root->child[0]->name, "!") == 0)
				constProp_Fold(root->child[1]);
			else if(strcmp(root->child[0]->name, "-") == 0)
				constProp_Fold(root->child[1]);
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(strcmp(root->child[0]->name, "identifier") == 0)
		{
			varIsUsed[root->child[0]->child[0]->name] = true;

			if(varValues[root->child[0]->child[0]->name].first)
			// statically computable
			{
				if(!ifExpr)
					constantProp.push_back(make_pair(root->child[0]->child[0]->line, make_pair(root->child[0]->child[0]->name, varValues[root->child[0]->child[0]->name].second)));
				root->child[0]->child[0]->value = varValues[root->child[0]->child[0]->name].second;
				root->child[0]->child[0]->isAvail = true;

				root->child[0]->value = root->child[0]->child[0]->value;
				root->child[0]->isAvail = true;

				root->value = root->child[0]->value;
				root->isAvail = true;
			}
		}
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
		{
			char* gen;
			root->child[0]->value = strtol(root->child[0]->child[0]->name, &gen, 10);
			root->child[0]->isAvail = true;

			root->value = root->child[0]->value;
			root->isAvail = true;
		}
		else
		// Case 3: ( expr )
		{
			constProp_Fold(root->child[1]);
			root->isAvail = root->child[1]->isAvail;
			root->value = root->child[1]->value;
		}
	}
	
	return;	
}

void gas(node *root)
{
	if(root == NULL)
		return;
	
	if(strcmp(root->name, "program") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "decl_list") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "decl") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "func_decl") == 0)
		gas(root->child[5]);
	else if(strcmp(root->name,"compound_stmt") == 0)
	{
		gas(root->child[1]);
		gas(root->child[2]);
	}
	else if(strcmp(root->name, "local_decls") == 0)
	{
		if(strcmp(root->child[0]->name, "#EPS") == 0)
		{
			return;
		}
		else
		{
			gas(root->child[0]);
			string temp = root->child[1]->child[1]->child[0]->name;
			if(var.count(temp) <= 0)
			{
				var[temp] = varcount;
				++varcount;
			}
		}
	}
	else if(strcmp(root->name, "stmt_list") == 0)
	{
		gas(root->child[0]);
		gas(root->child[1]);
	}
	else if(strcmp(root->name, "stmt") == 0)
		gas(root->child[0]);
	else if(strcmp(root->name, "assign_stmt") == 0)
	{
		gas(root->child[0]->child[1]);
		
		main_as += "\tmovl\t%eax, " + to_string(-4*(var[root->child[0]->child[0]->child[0]->name]+3)) + "(%rbp)\n";
	}
	else if(strcmp(root->name, "print_stmt") == 0)
	{
		function_as += label + to_string(labelcount) + ":\n\t.string\t\"%d\\n\"\n";
		
		if(root->child[4]->isAvail)
		// constant prop
			main_as += "\tmovl\t$" + to_string(root->child[4]->value) + ", %esi\n";
		else
			main_as += "\tmovl\t" + to_string(-4*(var[root->child[4]->child[0]->name]+3)) + "(%rbp), %esi\n";

		main_as += "\tleaq\t" + label + to_string(labelcount) + "(%rip), %rdi\n";
		main_as += "\tmovl\t$0, %eax\n";
		main_as += "\tcall\tprintf@PLT\n";
		
		labelcount++;
	}
	else if(strcmp(root->name, "scan_stmt") == 0)
	{
		function_as += label + to_string(labelcount) + ":\n\t.string\t\"%d\"\n";
		//printf("hellllllo");
		main_as += "\tleaq\t" + to_string(-4*(var[root->child[5]->child[0]->name]+3)) + "(%rbp), %rax\n";
		main_as += "\tmovq\t%rax, %rsi\n";
		main_as += "\tleaq\t" + label + to_string(labelcount) + "(%rip), %rdi\n";
		main_as += "\tmovl\t$0, %eax\n";
		main_as += "\tcall\tscanf@PLT\n";
		
		labelcount++;
	}
	else if(strcmp(root->name, "if_stmt") == 0)
	{
		if(root->child[2]->isAvail)
		// statically computable
		{
			if(root->child[2]->value > 0)
			// else block is dead
			{
				gas(root->child[4]->child[0]);
			}
			else
			// "if" block is dead
			{
				if(root->size > 5)
				{
					// cout << "hellllllo\n";
					gas(root->child[6]->child[0]);
				}
				else
					return;
			}
		}
		else
		{
			gas(root->child[2]);
			main_as += "\tcmpl\t$0, %eax\n";
			string temp_label = ".ELSE" + to_string(labelcount);
			labelcount++;
			
			main_as += "\tje\t" + temp_label + "\n";
			
			gas(root->child[4]);
			string temp_label1 = "";	
			if(root->size > 5)
			{
				temp_label1 = ".OUT" + to_string(labelcount++);
				main_as += "\tjmp\t" + temp_label1 + "\n";
			}
				
			main_as += temp_label + ":\n";
			
			if(root->size > 5)
			{
				gas(root->child[6]);
				main_as += temp_label1 + ":\n";
			}
		}
	}
	else if(strcmp(root->name, "while_stmt") == 0)
	{
		string temp_label = ".WHILE" + to_string(labelcount);
		string temp_label1 = ".EXITWHILE" + to_string(labelcount);
		labelcount++;
		
		main_as += temp_label + ":\n";
		
		gas(root->child[2]);
		main_as += "\tcmpl\t$0, %eax\n";
		main_as += "\tje\t" + temp_label1 + "\n";
		
		gas(root->child[4]);
		main_as += "\tjmp\t" + temp_label + "\n";
		main_as += temp_label1 + ":\n";
	}
	else if(strcmp(root->name, "expr") == 0)
	{
		if(root->isAvail)
		{
			main_as += "\tmovl\t$" + to_string(root->value) + ", %eax\n";
		}
		else if(root->size == 1)
		{
			if(root->child[0]->isAvail)
			{
				main_as += "\tmovl\t$" + to_string(root->child[0]->value) + ", %eax\n";
			}
			else if(strcmp(root->child[0]->name, "-") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tsubl\t%esi, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "+") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\taddl\t%esi, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "*") == 0)
			{
				if(root->child[0]->child[0]->isAvail && __builtin_popcount(root->child[0]->child[0]->value) == 1)
				{
					int temp_power = __builtin_ctz(root->child[0]->child[0]->value);
					gas(root->child[0]->child[1]);
					main_as += "\tsall\t$" + to_string(temp_power) + ", %eax\n";

					if(strengthreduction.count(root->child[0]->line) <= 0)
						strengthreduction[root->child[0]->line] = temp_power;
					else
						strengthreduction[root->child[0]->line] = max(strengthreduction[root->child[0]->line], temp_power);
				}
				else if(root->child[0]->child[1]->isAvail && __builtin_popcount(root->child[0]->child[1]->value) == 1)
				{
					int temp_power = __builtin_ctz(root->child[0]->child[1]->value);
					gas(root->child[0]->child[0]);
					main_as += "\tsall\t$" + to_string(temp_power) + ", %eax\n";

					if(strengthreduction.count(root->child[0]->line) <= 0)
						strengthreduction[root->child[0]->line] = temp_power;
					else
						strengthreduction[root->child[0]->line] = max(strengthreduction[root->child[0]->line], temp_power);
				}
				else
				{
					gas(root->child[0]->child[0]);
					main_as += "\tpushq\t%rax\n";
					
					gas(root->child[0]->child[1]);
					main_as += "\tmovl\t%eax, %esi\n";
					main_as += "\tpopq\t%rax\n";
					main_as += "\timull\t%esi, %eax\n";
				}
			}
			else if(strcmp(root->child[0]->name, "/") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcltd\n\tidivl\t%esi\n";
			}
			else if(strcmp(root->child[0]->name, "%") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcltd\n\tidivl\t%esi\n";
				main_as += "\tmovl\t%edx, %eax\n";
			}
			else if(strcmp(root->child[0]->name, ">") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetg\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "<") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetl\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "GEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetge\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "LEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetle\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "EQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsete\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "NEQ") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tpushq\t%rax\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tmovl\t%eax, %esi\n";
				main_as += "\tpopq\t%rax\n";
				main_as += "\tcmpl\t%esi, %eax\n";
				main_as += "\tsetne\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "OR") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tjne\t.L" + to_string(labelcount) + "\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount+1) + "\n";
				
				main_as += ".L" + to_string(labelcount) + ":\n";
				main_as += "\tmovl\t$1, %eax\n";
				main_as += "\tjmp\t.L" + to_string(labelcount+2) + "\n";
				main_as += ".L" + to_string(labelcount+1) + ":\n";
				main_as += "\tmovl\t$0, %eax\n";
				main_as += ".L" + to_string(labelcount+2) + ":\n";
				
				labelcount += 3;
			}
			else if(strcmp(root->child[0]->name, "AND") == 0)
			{
				gas(root->child[0]->child[0]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount) + "\n";
				
				gas(root->child[0]->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tje\t.L" + to_string(labelcount) + "\n";
				main_as += "\tmovl\t$1, %eax\n";
				main_as += "\tjmp\t.L" + to_string(labelcount+1) + "\n";
				
				
				main_as += ".L" + to_string(labelcount) + ":\n";
				main_as += "\tmovl\t$0, %eax\n";
				main_as += ".L" + to_string(labelcount+1) + ":\n";
				
				labelcount += 2;
			}
			else
			// Pexpr
			{
				gas(root->child[0]);
			}
		}
		else if(root->size == 2)
		{
			if(strcmp(root->child[0]->name, "!") == 0)
			{
				gas(root->child[1]);
				main_as += "\tcmpl\t$0, %eax\n";
				main_as += "\tsete\t%al\n";
				main_as += "\tmovzbl\t%al, %eax\n";
			}
			else if(strcmp(root->child[0]->name, "-") == 0)
			{
				gas(root->child[1]);
				main_as += "\tnegl\t%eax\n";
			}
		}
	}
	else if(strcmp(root->name, "Pexpr") == 0)
	{
		if(root->isAvail)
		{
			main_as += "\tmovl\t$" + to_string(root->value) + ", %eax\n";
		}
		else if(strcmp(root->child[0]->name, "identifier") == 0)
			main_as += "\tmovl\t" + to_string(-4*(var[root->child[0]->child[0]->name]+3)) + "(%rbp), %eax\n";
		
		else if(strcmp(root->child[0]->name, "integerLit") == 0)
			main_as += "\tmovl\t$" + (string)root->child[0]->child[0]->name + ", %eax\n";
		else
			gas(root->child[1]);
	}
	
	return;
}

node *mknode8(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7, node *c8)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->child[6] = c7;
	nn->child[7] = c8;
	nn->size = 8;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode7(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6,node *c7)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->child[6] = c7;
	nn->size = 7;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode6(int s,node *c1,node *c2,node *c3,node* c4,node *c5,node *c6)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->child[5] = c6;
	nn->size = 6;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode5(int s,node *c1,node *c2,node *c3,node* c4,node *c5)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->child[4] = c5;
	nn->size = 5;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode4(int s,node *c1,node *c2,node *c3,node* c4)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->child[3] = c4;
	nn->size = 4;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode3(int s,node *c1,node *c2,node *c3)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->child[2] = c3;
	nn->size = 3;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode2(int s,node *c1,node *c2)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->child[1] = c2;
	nn->size = 2;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode1(int s,node *c1)
{
	node* nn = (node *)malloc(sizeof(node));
	nn->child[0] = c1;
	nn->size = 1;
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}

node *mknode0(int s)
{
	node* nn = (node *)malloc(sizeof(node));
	if(s == 0)
	{
		nn->size = 0;
	}
	if(s == 1)
	{
		node* nnc = (node *)malloc(sizeof(node));
		nnc->size = 0;
		strcpy(nnc->name,"#EPS");
		nn->child[0] = nnc;
		nn->size = 1;
	}
	nn->isAvail = false;
	nn->line = linenum;
	nn->lastDec = -1;
	return nn;
}