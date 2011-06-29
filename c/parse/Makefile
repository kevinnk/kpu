PREFIX	=	..

include $(PREFIX)/common.mk

SRC_Y	=	parse.y
SRC_L	=	lex.l

OBJS	=	$(SRC_C:.c=.o) $(SRC_Y:.y=.o) $(SRC_L:.l=.o)


.PHONY: all
all: $(OBJS)
	cp -u *.o $(PREFIX)/$(OBJDIR)/.

parse.o: parse.y
	$(YACC) $(YFLAGS) parse.y
	$(CC) $(CFLAGS) parse.tab.c -c -o parse.o

lex.o: lex.l
	$(LEX) $(LFLAGS) -t lex.l > lex.c
	$(CC) $(CFLAGS) lex.c -c -o lex.o

clean:
	rm -f parse.tab.h parse.tab.c lex.c $(OBJS)
