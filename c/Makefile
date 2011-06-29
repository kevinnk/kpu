PREFIX	=	.

include $(PREFIX)/common.mk

SRC_C	=	main.c
OBJS	=	$(SRC_C:.c=.o)

SUBDIRS	=	parse \

.PHONY: all
all: $(OBJDIR) main.o all-recurse
	cp -u *.o $(PREFIX)/$(OBJDIR)/.
	
.PHONY:
$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: all-recurse
all-recurse:
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i all ;\
	done
	
.PHONY: clean
clean:
	rm -f $(OBJS)
	@for i in $(SUBDIRS); do \
		$(MAKE) -C $$i clean ;\
	done
	rm -r $(OBJDIR)
