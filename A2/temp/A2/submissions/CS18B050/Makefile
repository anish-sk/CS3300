a.out: y.tab.c lex.yy.c
	gcc -O3 lex.yy.c y.tab.c
	@echo "Run the program as ./a.out [input_file]"

y.tab.c: a.y 
	yacc -d a.y 

lex.yy.c: a.l y.tab.h
	lex a.l

clean:
	@rm lex.yy.c y.tab.h y.tab.c a.out
