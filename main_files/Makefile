CC=gcc
SRCS=libll.c
INCL=libll.h
OBJS=$(SRCS:.c=.o)
CFLAGS=-fPIC -Wall 
SONAME=libll.so
VERSION=1.0
LIBPATH=/home/kali/lib


$(SONAME).$(VERSION)    :  $(OBJS)
	$(CC) $(CFLAGS) -shared -Wl,-soname,$(SONAME) -o $(SONAME).$(VERSION) $(OBJS)

$(OBJS)                 :  $(SRCS) $(INCL)
	$(CC) $(CFLAGS) -c $(SRCS)

install    :      $(SONAME).$(VERSION)
	mkdir -p $(LIBPATH)
	mkdir -p /home/kali/include
	cp ./$(SONAME).$(VERSION) $(LIBPATH)
	cp ./libll.h /home/kali/include
	ldconfig -n $(LIBPATH)

clean      :
	rm -f $(SONAME).$(VERSION) libll.o libll.h.gch
