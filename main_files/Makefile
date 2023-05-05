CC=gcc
SRCS=libll.c
OBJS=$(SRCS:.c=.o)
CFLAGS=-fPIC
SONAME=libll.so
VERSION=1.0

object     :
	$(CC) -c $(SRCS)
lib        :
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(SONAME).$(VERSION) -o $(SONAME).$(VERSION) $(OBJS)
clean      :
	rm -f $(SONAME).$(VERSION) $(OBJS)
clean_obj  :
	rm -f *.o
