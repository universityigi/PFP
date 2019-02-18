CC     = gcc
CFLAGS = -O2 -Wall -Wno-deprecated-declarations
LFLAGS = -l OpenCL

mirror: main.o clut.o pgm.o mirror.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o mirror.o \
        -o mirror $(LFLAGS)

main.o: main.c clut.h mirror.h pgm.h
	$(CC) $(CFLAGS) main.c -c

mirror.o: mirror.c mirror.h clut.h
	$(CC) $(CFLAGS) mirror.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

test:
	./mirror colosseo.pgm colosseo-mirror.pgm

.phony: clean

clean:
	rm -f *.o mirror colosseo-mirror.pgm
