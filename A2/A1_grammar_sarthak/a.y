%token IDENTIFIER NUMBER INTEGER PLUS MINUS MULT DIV IF ELSE FOR WHILE DO INT FLOAT CHAR EQ EQEQ GEQ LEQ GT LT
%token NEWOP NEQ BITAND BITOR BITNOT BITXOR AND OR NOT MOD EXTERN LONG SHORT DOUBLE
%token VOID SWITCH CASE STRUCT BREAK CONTINUE RETURN STRLITERAL CHARLITERAL INC DEC ARROW SIZEOF DEFAULT
%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(char*);
    int yylex(void);
    int max(int, int);
    FILE* yyin;
    char mytext[100];
    int globalDeclarations = 0;
    int functionDefinition = 0;
    extern int integerConstantCount;
    int pointerDeclarations = 0;
    int maxIfElseDepth = 0;
    int ifWithoutElse = 0;
%}

%%

CProgram: GlobalDeclaration {globalDeclarations++; $$ = $1; maxIfElseDepth = max(maxIfElseDepth, $$);}
          | CProgram GlobalDeclaration {globalDeclarations++; $$ = max($1, $2); maxIfElseDepth = max(maxIfElseDepth, $$);};

GlobalDeclaration: Declaration {$$ = 0;} | FunctionDefinition {functionDefinition++; $$ = $1;};

FunctionDefinition: DeclarationType Declarator DeclarationList ScopeStatement {$$ = $4;}
                  | DeclarationType Declarator ScopeStatement {$$ = $3;};

DeclarationList: Declaration | DeclarationList Declaration;

Declaration: DeclarationType InitializerDeclaratorList ';' {$$ = 0;}
            | DeclarationType ';' {$$ = 0;};

DeclarationType: EXTERN Type | Type;

InitializerDeclaratorList: InitializerDeclarator | 
                    InitializerDeclaratorList ',' InitializerDeclarator;

InitializerDeclarator: Declarator 
              | Declarator EQ Initializer;

Type: VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | LONG INT | LONG DOUBLE | SHORT INT
                | LONG LONG | LONG LONG INT | Struct;

Struct: STRUCT IDENTIFIER '{' StructDeclarationList '}'
                | STRUCT IDENTIFIER;

StructDeclarationList: StructDeclaration | StructDeclarationList StructDeclaration;

StructDeclaration: Type StructDeclaratorList ';';

StructDeclaratorList: StructDeclarator | StructDeclaratorList ',' StructDeclarator;

StructDeclarator: Declarator | Declarator ':' ConstantExpression | ':' ConstantExpression;

Declarator: Pointer RealDeclarator {pointerDeclarations++;}
            | RealDeclarator;

RealDeclarator: IDENTIFIER 
                | '(' Declarator ')' 
                | RealDeclarator '[' ConstantExpression ']'
                | RealDeclarator '[' ']'
                | RealDeclarator '(' ParameterList ')'
                | RealDeclarator '(' IdentifierList ')'
                | RealDeclarator '(' ')';

Pointer: MULT | MULT Pointer;

ParameterList: ParameterDeclaration 
             | ParameterList ',' ParameterDeclaration;

ParameterDeclaration: DeclarationType Declarator
                    | DeclarationType
                    | DeclarationType UnnamedDeclarator;

UnnamedDeclarator: Pointer BracketDeclarator
                   | BracketDeclarator
                   | Pointer;

IdentifierList: IDENTIFIER 
              | IdentifierList ',' IDENTIFIER;

Initializer: AssignExpression | '{' InitializerList '}' | '{' InitializerList ',' '}';

InitializerList: Initializer | InitializerList ',' Initializer;

TypeName: Type UnnamedDeclarator | Type;

BracketDeclarator: '(' UnnamedDeclarator ')' 
                        | BracketDeclarator '[' ConstantExpression ']'
                        | BracketDeclarator '[' ']'
                        | '[' ConstantExpression ']'
                        | '[' ']'
                        | BracketDeclarator '(' ParameterList ')'
                        | BracketDeclarator '(' ')'
                        | '(' ParameterList ')'
                        | '(' ')';

Statement: LabelStatement {$$ = $1;}
         | ExpressionStatement {$$ = 0;}
         | ScopeStatement {$$ = $1;}
         | DecisionStatement {$$ = $1;}
         | LoopStatement {$$ = $1;}
         | ControlStatement {$$ = $1;}
;

LabelStatement: IDENTIFIER ':' Statement {$$ = $3;}
              | CASE ConstantExpression ':' Statement {$$ = $4;}
              | DEFAULT ':' Statement {$$ = $3;}
;

ExpressionStatement: Expression ';' {$$ = 0;}
                    | ';' {$$ = 0;} ;

ScopeStatement: '{' FunctionBody '}' {$$ = $2;};

FunctionBody: FunctionBody Declaration {$$ = max($1, $2);}
            | FunctionBody Statement   {$$ = max($1,$2);}
            |                          {$$ = 0;} 
;

DecisionStatement: IF '(' Expression ')' Statement  {$$ = $5; ifWithoutElse++;}
                 | IF '(' Expression ')' Statement ELSE Statement {$$ = max($5, 1 + $7);}
                 | SWITCH '(' Expression ')' Statement {$$ = $5;}
;


LoopStatement: WHILE '(' Expression ')' Statement {$$ = $5;}
             | FOR '(' ForRobustExpression RobustExpression ';' RobustExpression ')' Statement {$$ = $8;}
             | DO Statement WHILE '(' Expression ')' {$$ = $2;}
;

ControlStatement: CONTINUE ';' {$$ = 0;}
                | BREAK ';' {$$ = 0;}
                | RETURN RobustExpression ';' {$$ = 0;}
;

Expression: AssignExpression 
            | Expression ',' AssignExpression;

RobustExpression: Expression
                | 
;

ForRobustExpression: Expression ';'
                   | Declaration
                   | ';'
;

AssignExpression: ConditionalExpression
                 | UnaryExpression AssignOp AssignExpression;
  
AssignOp: EQ;

ConstantExpression: ConditionalExpression;

ConditionalExpression: OrExpression;

OrExpression: AndExpression 
             |  OrExpression OR AndExpression;

AndExpression: BitOrExpression 
              | AndExpression AND BitOrExpression;

BitOrExpression: BitXorExpression 
                | BitOrExpression BITOR BitXorExpression;

BitXorExpression: BitAndExpression 
                 | BitXorExpression BITXOR BitAndExpression;

BitAndExpression: EqExpression 
                 | BitAndExpression BITAND EqExpression;

EqExpression: RelExpression
             | EqExpression EqOp RelExpression;

EqOp: EQEQ | NEQ;

RelExpression: AddExpression
              | RelExpression RelOp AddExpression;

RelOp: GT | LT | GEQ | LEQ | NEWOP;

AddExpression: MultExpression 
              | AddExpression AddOp MultExpression;

AddOp: PLUS | MINUS;

MultExpression: TypeCastExpression 
               | MultExpression MultOp TypeCastExpression;

MultOp: MULT | DIV | MOD;

TypeCastExpression: UnaryExpression 
                | '(' TypeName ')' TypeCastExpression;

UnaryExpression: PostfixExpression
                | INC UnaryExpression
                | DEC UnaryExpression
                | SIZEOF '(' UnaryExpression ')'
                | SIZEOF '(' TypeName ')'
                | UnaryOp TypeCastExpression;

UnaryOp: BITAND | MULT | PLUS | MINUS | BITNOT | NOT;

PostfixExpression: PrimExpression 
                  | PostfixExpression '[' Expression ']'
                  | PostfixExpression '(' ArgExpressionList ')'
                  | PostfixExpression '.' IDENTIFIER
                  | PostfixExpression ARROW IDENTIFIER
                  | PostfixExpression PostfixOp;

PostfixOp: INC | DEC;

PrimExpression: IDENTIFIER | NUMBER | CHARLITERAL | String | '(' Expression ')';

String: STRLITERAL | String STRLITERAL;

ArgExpressionList: AssignExpression
                  | ArgExpressionList ',' AssignExpression
                  | 
;


%%

void yyerror(char* s) {
    printf("***parsing terminated*** [syntax error]\n");
    exit(0);
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
    if(argc == 1) {
        printf("***process terminated*** [input error]: invalid number of command-line arguments\n");
    }
    else {
        FILE* fp = fopen(argv[1], "r");
        if(fp) {
            yyin = fp;
            yyparse();
            printf("***parsing successful***\n");
            printf("#global_declarations = %d\n", globalDeclarations);
            printf("#function_definitions = %d\n", functionDefinition);
            printf("#integer_constants = %d\n", integerConstantCount);
            printf("#pointers_declarations = %d\n", pointerDeclarations);
            printf("#ifs_without_else = %d\n", ifWithoutElse);
            printf("if-else max-depth = %d\n", maxIfElseDepth);
        }
        else {
            printf("***process terminated*** [input error]: no such file \"%s\" exists \n", argv[1]);
        }
    }
    return 0;
}
