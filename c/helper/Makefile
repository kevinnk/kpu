PREFIX	=	..

include $(PREFIX)/common.mk

SRC_C	=	log.c

OBJS	=	$(SRC_C:.c=.o) $(SRC_Y:.y=.o) $(SRC_L:.l=.o)


.PHONY: all
all: $(OBJS)
	mv *.o $(PREFIX)/obj/.
clean:
	rm -f $(OBJS)
