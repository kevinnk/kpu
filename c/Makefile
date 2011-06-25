OUT	=	kcc
ODIR	=	obj

CC	=	gcc
CDEBUG	=	-g
OLEVEL	= 	-O2
INCLUDE = 	-I./include
CFLAGS 	=	-Wall -pedantic $(CDEBUG) $(OLEVEL) $(INCLUDE)

SUBDIRS = 	parse

.PHONY: all
all: all-recurse main.c
	$(CC) -c $(CFLAGS) main.c ;
	mv *.o ./obj/. ;
	cd obj/ ;
#add gcc here to link

all-recurse:
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i all ;\
		mv $$i/*.o ./obj/. ;\
	done

.PHONY: clean
clean:
	for i in $(SUBDIRS); do \
		$(MAKE) -C $$i clean ; \
	done
	rm -r obj/*.o ;
	rm $(OUT) ;
