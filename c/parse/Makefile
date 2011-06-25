all: parse.y lex.l
	bison -d parse.y
	flex lex.l
	gcc -c -g parse.tab.c lex.yy.c

clean:
	rm parse.tab.c parse.tab.h lex.yy.c *.o 
