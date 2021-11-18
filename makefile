CC=gcc
CFLAG= -Wall -I.. -I. -std=c99

EXECUTABLE=Oe

all: $(EXECUTABLE)

new: realclean all

Oe: odd_even_seq.c
	$(CC) $(CFLAG) -o Oe odd_even_seq.c

clean:
	rm -f *.o *~ core

realclean:
	rm -f *.o *~ core Oe