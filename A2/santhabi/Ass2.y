%token VOID INT FLOAT EXTERN STRUCT IF ELSE SWITCH FOR WHILE DO BREAK CONTINUE CASE DEFAULT RETURN INTEGERLITERAL FLOATLITERAL SIZEOF IDENTIFIER OP CP OFB CFB OSB CSB SC DOT INC DEC AMPERSAND UN_OR LESS GREATER EQ COM_EQ NOT NOT_EQ LE GE ACCESS PLUS MINUS STAR DIV MOD  NEW_OP COMMA OR PRINT FORMAT_SPEC AND COLON QU

%{
	#include <stdio.h>
	#include<string.h>
	void yyerror(char *);
	int yylex(void);
	extern FILE *yyin;
	extern char *yytext;
	int yydebug=1;
	int lbl_main=0,lbl_pass=1;
	int tr_depth=0,if_depth=0,wh_depth=0,sw_depth=0,main_depth=0;
	struct Node{
		int depth;
		int max_path;
	};
	#define YYSTYPE struct Node
	struct Node s(int n,struct Node states[]){
		int max_depth=0,prev_max_depth=0,max_path=0;
		for(int i=0;i<n;i++){
			if((states[i].depth+1)>=max_depth){
				prev_max_depth=max_depth;
				max_depth=states[i].depth+1;
			}
			else if(prev_max_depth<states[i].depth+1) prev_max_depth=states[i].depth+1;
			max_path=(max_path>states[i].max_path)?max_path:states[i].max_path;
		}
		struct Node ans;
		ans.max_path=(max_path>max_depth+prev_max_depth)?max_path:max_depth+prev_max_depth;
		ans.depth=max_depth;	
		return ans;
	}
	struct Node s1(struct Node x1){
		struct Node temp[]={x1};
		return s(1,temp);
	}
	struct Node s2(struct Node x1,struct Node x2){
		struct Node temp[]={x1,x2};
		return s(2,temp);
	}
	struct Node s3(struct Node x1,struct Node x2,struct Node x3){
		struct Node temp[]={x1,x2,x3};
		return s(3,temp);
	}
	struct Node s4(struct Node x1,struct Node x2,struct Node x3,struct Node x4){
		struct Node temp[]={x1,x2,x3,x4};
		return s(4,temp);
	}
%}


%%
program : decl_list { $$ = s1($1); tr_depth=($$).max_path + 1; }
		;

decl_list : decl_list decl { $$ = s2($1,$2); }
		  | decl  { $$= s1($1); }
		  ;

decl : var_decl { $$ = s1($1); } | func_decl { $$ = s1($1); } | struct_decl { $$ = s1($1); }
	 ;

struct_decl : STRUCT identifier OFB local_decls CFB SC { $$ = s2($2,$4); } ;

var_decl : type_spec identifier SC { $$ = s2($1,$2); }
		 | type_spec identifier COMMA var_decl { $$ = s3($1,$2,$4); }
		 | type_spec identifier OSB integerLit CSB SC  { $$ = s3($1,$2,$4); }
		 | type_spec identifier OSB integerLit CSB COMMA var_decl { $$ = s4($1,$2,$4,$7); }
		 ;

type_spec : extern_spec VOID  { $$ = s2($1,(struct Node){0,0}); }
		 | extern_spec INT   { $$ = s2($1,(struct Node){0,0}); }
		 | extern_spec FLOAT  { $$ = s2($1,(struct Node){0,0}); }
		 | extern_spec VOID STAR   { $$ = s2($1,(struct Node){0,0}); }
		 | extern_spec INT STAR    { $$ = s2($1,(struct Node){0,0}); }
		 | extern_spec FLOAT STAR  { $$ = s2($1,(struct Node){0,0}); }
		 | STRUCT identifier      { $$ = s2($2,(struct Node){0,0}); }
		 | STRUCT identifier STAR  { $$ = s2($2,(struct Node){0,0}); }
		 ;

extern_spec : EXTERN  { $$ = (struct Node){1,1}; }
			|  { $$ = (struct Node){1,1}; }
			;

func_decl : type_spec identifier OP params CP compound_stmt { $$ = s4($1,$2,$4,$6); if(lbl_main) {main_depth=($$).max_path+1;lbl_main=0;} printf("%d",($$).max_path); }
		  ;

params : param_list { $$ = s1($1); }
		|  { $$ = (struct Node){1,1}; }
		;

param_list  : param_list COMMA param { $$=s2($1,$3); }
			| param   { $$=s1($1); }
			;

param : type_spec identifier  { $$=s2($1,$2); }
	  | type_spec identifier OSB CSB  { $$=s2($1,$2); }
	  ;

stmt_list : stmt_list stmt  { $$=s2($1,$2); printf("%d", $$.max_path);}
		  | stmt  { $$=s1($1); printf("stl = %d\n", $$.max_path);}
		  ;

stmt : assign_stmt { $$=s1($1); printf("st = %d\n", $$.max_path);} | compound_stmt { $$=s1($1); } | if_stmt { $$=s1($1); }
	 | while_stmt { $$=s1($1); } | switch_stmt { $$=s1($1); }
	 | return_stmt { $$=s1($1); } | break_stmt { $$=s1($1); }
	 | continue_stmt { $$=s1($1); } | dowhile_stmt { $$=s1($1); }
	 | print_stmt { $$=s1($1); } | incr_stmt { $$=s1($1); } | decr_stmt { $$=s1($1); }
	 ;

while_stmt : WHILE OP expr CP stmt { $$ = s2($3,$5); wh_depth=(wh_depth>($$).max_path+1)?wh_depth:(($$).max_path+1); }
		   ;

dowhile_stmt : DO stmt WHILE OP expr CP SC { $$ = s2($2,$5); }
			 ;

print_stmt : PRINT OP  format_specifier  COMMA identifier CP SC { $$ = s2($3,$5); }
		   ;

format_specifier : FORMAT_SPEC { $$=(struct Node){1,1}; }
				 ;

compound_stmt : OFB local_decls stmt_list CFB { $$=s2($2,$3); printf("cst = %d\n", $$.max_path);}
			  ;

local_decls : local_decls local_decl  { $$=s2($1,$2); }
			| 	{ $$=(struct Node){1,1}; }
			;

local_decl : type_spec identifier SC { $$=s2($1,$2); }
		   | type_spec identifier OSB expr CSB SC  { $$=s3($1,$2,$4); }
		   ;

if_stmt : IF OP expr CP stmt  { $$=s2($3,$5); if_depth=(if_depth>($$).max_path+1)?if_depth:(($$).max_path+1); }
		| IF OP expr CP stmt ELSE stmt   { $$=s3($3,$5,$7); if_depth=(if_depth>($$).max_path+1)?if_depth:(($$).max_path+1); }
		;

return_stmt : RETURN SC  { $$=(struct Node){1,2}; }
			| RETURN expr SC  { $$=s2($2,(struct Node){0,0}); }
			;

break_stmt : BREAK SC { $$=(struct Node){1,2}; } ;

continue_stmt : CONTINUE SC { $$=(struct Node){1,2}; } ;

switch_stmt  : SWITCH OP expr CP OFB compound_case default_case CFB {$$=s3($3,$6,$7); printf("ccase %d dcase %d\n", $6.depth, $7.depth); sw_depth=(sw_depth>($$).max_path+1)?sw_depth:($$).max_path+1;};

compound_case : compound_case single_case  { $$ =s2($1,$2); }
			  | single_case { $$=s1($1); }
			  ;

single_case : CASE integerLit COLON stmt_list { $$=s2($2,$4); } ;

default_case : DEFAULT COLON stmt_list { $$=s2($3,(struct Node){0,0}); } ;

assign_stmt : identifier EQ expr SC { $$=s2(s2($1,$3),(struct Node){0,0});  printf("ass = %d\n", $$.max_path);}
			| identifier OSB expr CSB EQ expr SC  { $$=s2(s3($1,$3,$6),(struct Node){0,0}); }
			| identifier ACCESS identifier EQ expr SC  { $$=s2(s3($1,$3,$5),(struct Node){0,0}); }
			| identifier DOT identifier EQ expr SC { $$=s2(s3($1,$3,$5),(struct Node){0,0}); }
			;

incr_stmt : identifier INC SC { $$ = s2($1,(struct Node){0,0}); } ;

decr_stmt : identifier DEC SC { $$ = s2($1,(struct Node){0,0}); } ;

expr : Pexpr LESS Pexpr { $$=s1(s2($1,$3)); } | Pexpr GREATER Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr LE Pexpr { $$=s1(s2($1,$3)); } | Pexpr GE Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr OR Pexpr { $$=s1(s2($1,$3)); }
	 | SIZEOF OP Pexpr CP  { $$=s2($3,(struct Node){0,0}); }
	 | Pexpr COM_EQ Pexpr { $$=s1(s2($1,$3)); } | Pexpr NOT_EQ Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr NEW_OP Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr AND Pexpr { $$=s1(s2($1,$3)); } | Pexpr ACCESS Pexpr { $$=s2($1,$3); }
	 | Pexpr PLUS Pexpr { $$=s1(s2($1,$3)); } | Pexpr MINUS Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr STAR Pexpr { $$=s1(s2($1,$3)); } | Pexpr DIV Pexpr { $$=s1(s2($1,$3)); }
	 | Pexpr MOD Pexpr { $$=s1(s2($1,$3)); }
	 | NOT Pexpr { $$=s2($2,(struct Node){0,0}); } | MINUS Pexpr  { $$=s2($2,(struct Node){0,0}); }
	 | PLUS Pexpr { $$=s2($2,(struct Node){0,0}); } | STAR Pexpr  { $$=s2($2,(struct Node){0,0}); }
	 | AMPERSAND Pexpr { $$=s2($2,(struct Node){0,0}); }
	 | Pexpr { $$=s1($1); }
	 | identifier OP args CP  { $$=s2($1,$3); }
	 | identifier OSB expr CSB  { $$=s2($1,$3); }
	 ;

Pexpr : integerLit { $$=s1($1); } | floatLit { $$=s1($1); } | identifier { $$=s1($1); }
	  | OP expr CP  { $$=s2($2,(struct Node){0,0}); }
	  ;

integerLit : INTEGERLITERAL { $$=(struct Node){1,1}; } ;
floatLit : FLOATLITERAL { $$=(struct Node){1,1}; } ;
identifier : IDENTIFIER { $$=(struct Node){1,1}; if(strcmp(yytext,"main")==0) lbl_main=1; } ;

arg_list : arg_list COMMA expr { $$=s2($1,$3); }
		 | expr { $$=s1($1); }
		 ;

args : arg_list { $$=s1($1); }
	 | /* epsilon */  { $$=(struct Node){1,1}; }
	 ;

%%

void yyerror(char *s) {
	lbl_pass=0;
	return;
}

int main(int argc,char* argv[]) {
	yyin=fopen(argv[1],"r");
	yyparse();
	if(lbl_pass){
		printf("tree_depth = %d \n",tr_depth);
		printf("if_depth = %d \n",if_depth);
		printf("while_depth = %d \n",wh_depth);
		printf("switch_depth = %d \n",sw_depth);
		printf("main_depth = %d \n",main_depth);
	}
	else printf("%s \n","***parsing terminated*** [syntax error]");
	return 0;
}


