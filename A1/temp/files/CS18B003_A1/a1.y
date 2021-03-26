%token FOR DO WHILE IF SL XR IDEN CUR COL OC DOT STRING_LITERAL SIZEOF CM CC SC IC FC ELSE SWITCH DEFAULT CASE BREAK CONTINUE RETURN INT LONG SHORT FLOAT DOUBLE VOID CHAR EXTERN STRUCT NEW EQ GE LE NE AND OR INC DEC NN GT LT ASS PLS MIN NEG MUL AMP DIV MOD OP CP OB CB
%{
	#include <stdio.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern FILE *yyin;
	int ic=0, ifc=0, fc=0, ptr=0, glb=0, mxie=0, ieb=0;
	int flcs=1;
%}

%%
program: mlines;

mlines: moneline{glb++;} | moneline{glb++;} mlines ;
moneline: dec | function{fc++;} | function_dec | struct_init;
lines: oneline | oneline lines ;
oneline: dec | ifs | while |fors | dowh | switch | init_list| struct_init  | ret_stat | flow  | exp11 SC | OP lines CP; 

init_list: left ASS init SC | left ASS init CM init_list; 

function_dec: type IDEN OC param_list_dec SC | type IDEN OC CC SC;
param_list_dec: type CC | type IDEN CC| type IDEN mul_brack CC | type CM param_list_dec | type IDEN CM param_list_dec |  type IDEN mul_brack CM param_list_dec;


function: type IDEN OC param_list inner_fun | type IDEN OC VOID CC inner_fun;
inner_fun: OP CP | OP lines CP;
param_list: CC | type IDEN CC | type IDEN CM param_list | type IDEN mul_brack CC | type IDEN mul_brack CM param_list;
mul_brack: OB CB | OB expression CB | OB CB mul_brack | OB expression CB mul_brack;

left: left1 | left1 CM left;
left1: exp2 | unary_ops left;

fcall: mul_idens OC param_list_call ;
mul_idens: IDEN | IDEN DOT mul_idens;
param_list_call: CC | mul_exp12 CC;
mul_exp12: exp12 | exp12 CM mul_exp12;
flow: BREAK SC | CONTINUE SC;

arr: exp12 | OP arr CP | exp12 CM arr |  OP arr CP CM arr;
init: expression | OP arr CP;


//Expressions Start
expression: exp12 | expression CM exp12;
exp0: mul_idens | IC{ic++;} | FC | STRING_LITERAL| OC expression CC;// | OP arr CP;
exp1: exp0 | exp1 INC | exp1 DEC | exp1 NN IDEN | exp1 DOT IDEN | fcall | exp1 OB expression CB;
exp2: exp1 | unary_ops exp2 | SIZEOF OC exp2 CC | SIZEOF OC{flcs=0;} type CC{flcs=1;} | OC{flcs=0;} type CC{flcs=1;} exp2 ; 
exp3: exp2 | exp3 muls exp2;
exp4: exp3 | exp4 sums exp3;
exp5: exp4 | exp5 rels exp4;
exp6: exp5 | exp6 eqas exp5;
exp7: exp6 | exp7 AMP exp6;
exp8: exp7 | exp8 SL exp7;
exp9: exp8 | exp9 XR exp8;
exp10: exp9 | exp10 AND exp9;
exp11: exp10 | exp11 OR exp10;
exp12: exp11 | exp12 ASS exp11;
unary_ops: PLS | MIN | NEG | AMP | INC | DEC | CUR | MUL ;
muls: DIV | MOD | MUL;
sums: PLS | MIN;
rels: LE | GE | LT | GT | NEW;
eqas: NE | EQ;
//Expressions End

//Declarations Start
decs: dec_struct | dec_struct decs;
dec: type dec_gen SC;
dec_gen: dec_base | dec_gen CM dec_base_1 | dec_gen CM dec_base;
dec_base: IDEN mul_brack ASS init | IDEN mul_brack | IDEN ASS init| IDEN;
dec_base_1: MULt_MUL IDEN mul_brack ASS init | MULt_MUL IDEN mul_brack |MULt_MUL IDEN ASS init| MULt_MUL IDEN ;

dec_struct: type dec_gen_struct SC;
dec_gen_struct: dec_base_struct | dec_base_struct  CM dec_gen_struct | dec_base_struct_1  CM dec_gen_struct;
dec_base_struct: IDEN OB expression CB | IDEN;
dec_base_struct_1: MULt_MUL IDEN OB expression CB | MULt_MUL IDEN;


type: sin_type | sin_type type;
sin_type: INT | LONG| SHORT| FLOAT| DOUBLE| VOID |CHAR | sin_type MULt_MUL  | EXTERN | STRUCT IDEN ;
MULt_MUL: MUL{ptr+=flcs;} | MUL MULt_MUL;

struct_init: type sin_struct_init | sin_struct_init;	
sin_struct_init: STRUCT IDEN OP decs CP SC | STRUCT IDEN OP decs CP mul_iden_cm;
mul_iden_cm: IDEN SC | IDEN CM mul_iden_cm;

//Declarations End

ret_stat: RETURN SC | RETURN expression SC;
ifs: IF OC expression CC inner{ifc++;} | IF OC expression CC inner ELSE{ieb++; if(mxie<ieb) mxie=ieb; } inner{ieb--;};
while: WHILE OC expression CC inner;
fors: FOR OC op1 op2 op3 inner ;
op1: SC | init_list | dec | expression SC;
op2: SC | exp11 SC;
op3: CC | expression CC;
dowh: DO inner while;
switch: SWITCH OC expression CC OP cases;
cases: CP| CASE expression COL lines cases | DEFAULT COL lines cases |  CASE expression COL cases | DEFAULT COL cases;
inner:ifs | while |fors | dowh | switch | init_list| struct_init  | ret_stat | flow  | exp11 SC | OP lines CP | OP CP | SC;

%%

void yyerror(char *s) 
{
    printf("***parsing terminated*** [syntax error]\n");
	exit(0);
}

int main(int argc, char* argv[]) {
	
	if(argc!=2)
	{
		printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
		return 0;
	}
	
	else if(!(yyin=fopen(argv[1], "r")))
	{
		printf("***process terminated*** [input error]: no such file %s exists\n", argv[1]);
		return 0;
	}
		
	
    if(!yyparse()){
		printf("***parsing successful***\n");
		printf("#global_declarations = %d\n", glb);
		printf("#function_definitions = %d\n", fc);
		printf("#integer_constants = %d\n", ic);
		printf("#pointers_declarations = %d\n", ptr);
		printf("#ifs_without_else = %d\n", ifc);
		printf("if-else max-depth = %d\n", mxie);
		return 0;
	}
	else{
		printf("***parsing terminated*** [syntax error]\n");
		return 0;
	}
}
