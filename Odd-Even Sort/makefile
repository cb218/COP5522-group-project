CC=gcc
FLAG= -Wall -I.. -I. -std=c99 -O3

all: OE_omp

new: realclean all

OE_omp: OE_omp.c
	$(CC) $(FLAG) -o OE_omp OE_omp.c -lm

clean:
	rm -f *.o *~ core

realclean:
	rm -f *.o *~ core OE_omp