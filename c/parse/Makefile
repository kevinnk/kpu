PREFIX	=	..

include $(PREFIX)/common.mk

SRC_Y	=	parse.y
SRC_L	=	lex.l

OBJS	=	$(SRC_C:.c=.o) $(SRC_Y:.y=.o) $(SRC_L:.l=.o)


.PHONY: all
all: $(OBJS)

parse.o: parse.y
	$(YACC) $(YFLAGS) parse.y
	$(CC) $(CFLAGS) parse.tab.c -c -o parse.o
	rm parse.tab.c

clean:
	rm parse.tab.h
	rm $(OBJS)
