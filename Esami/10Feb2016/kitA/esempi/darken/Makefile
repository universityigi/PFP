CC     = gcc
CFLAGS = -O3 -Wall
LFLAGS = -l OpenCL


darken: main.o clut.o pgm.o darken.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o darken.o \
        -o darken $(LFLAGS)

main.o: main.c clut.h darken.h pgm.h
	$(CC) $(CFLAGS) main.c -c

darken.o: darken.c darken.h clut.h
	$(CC) $(CFLAGS) darken.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

.phony: clean

clean:
	rm -f darken *.o results/*
