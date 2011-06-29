OUT	=	kcc
OBJDIR	=	obj

CC	=	gcc
LINK	=	gcc
YACC	=	bison
LEX	=	flex

DBG	=	-g3
OLV	=	-O0

TOP 	=	$(PREFIX)
INC	=	-I$(TOP)/include
WARN	=	-Wall -Wextra -Werror

CFLAGS	=	$(INC) $(DBG) $(OLV) $(WARN)
YFLAGS	=	-t -d
LFLAGS	=
