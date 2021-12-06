CCg=gcc
CCm= mpicc
C1FLAG= -Wall -I.. -I. -std=c99 -O3
C2FLAG= -Wall -I.. -I. -std=c99 -O3
C3FLAG= -Wall -I.. -I. -std=c99 -O3

all: OE_serial OE_omp OE_mpi

new: realclean all

OE_serial: OE_serial.c
	$(CCg) $(C1LAG) -o OE_serial OE_serial.c -lm

OE_omp: OE_omp.c
	$(CCg) $(C2FLAG) -o OE_omp OE_omp.c -lm

OE_mpi: OE_mpi.c
	$(CCm) $(C3FLAG) -o OE_mpi OE_mpi.c -lm

clean:
	rm -f *.o *~ core

realclean:
	rm -f *.o *~ core OE_serial OE_omp OE_mpi