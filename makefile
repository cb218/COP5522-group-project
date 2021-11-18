CC=gcc
CFLAG= -Wall -I.. -I. -std=c99

all: Odd_Even_Sort_Seq Sample_Sort_Seq

new: realclean all

Odd_Even_Sort_Seq: odd_even_seq.c
	$(CC) $(CFLAG) -o Odd_Even_Sort_Seq odd_even_seq.c -lm

Sample_Sort_Seq: sample_seq.c
	$(CC) $(CFLAG) -o Sample_Sort_Seq sample_seq.c -lm

clean:
	rm -f *.o *~ core

realclean:
	rm -f *.o *~ core Odd_Even_Sort_Seq Sample_Sort_Seq