PREFIX	=	.

include $(PREFIX)/common.mk

SRC_C	=	main.c
OBJS	=	$(SRC_C:.c=.o)

SUBDIRS	=	parse \

.PHONY: all
all: main.o
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i all ;\
	done
	
.PHONY: clean
clean:
	rm $(OBJS)
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i clean ;\
	done
