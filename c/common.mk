OUT	=	kcc
OBJ	=	obj

CC	=	gcc
LINK	=	gcc
YACC	=	bison
LEX	=	flex

DBG	=	-g3
OLV	=	-O3

TOP 	=	$(PREFIX)
INC	=	-I$(TOP)/include
WARN	=	-Wall -Wextra -Werror

CFLAGS	=	$(INC) $(DBG) $(OLV)
YFLAGS	=	-t -d
LFLAGS	=	
