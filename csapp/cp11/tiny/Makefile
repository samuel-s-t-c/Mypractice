CC = gcc
CFLAGS = -O2 -Wall -I .

# This flag includes the Pthreads library on a Linux box.
# Others systems will probably require something different.
LIB = -lpthread

all: tiny tiny1 cgi

tiny1: tiny1.c csapp.o
	$(CC) $(CFLAGS) -o tiny1 tiny1.c csapp.o $(LIB)


tiny: tiny.c csapp.o
	$(CC) $(CFLAGS) -o tiny tiny.c csapp.o $(LIB)

csapp.o: csapp.c
	$(CC) $(CFLAGS) -c csapp.c

cgi:
	(cd cgi-bin; make)

clean:
	rm -f *.o tiny tiny1 *~
	(cd cgi-bin; make clean)

