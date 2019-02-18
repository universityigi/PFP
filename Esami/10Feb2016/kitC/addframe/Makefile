CC     = gcc
CFLAGS = -O2 -Wall -Wno-deprecated-declarations -g
LFLAGS = -l OpenCL

addframe: main.o clut.o pgm.o addframe.o
	$(CC) $(CFLAGS) main.o clut.o pgm.o addframe.o \
        -o addframe $(LFLAGS)

main.o: main.c clut.h addframe.h pgm.h
	$(CC) $(CFLAGS) main.c -c

addframe.o: addframe.c addframe.h clut.h
	$(CC) $(CFLAGS) addframe.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

pgm.o: pgm.c pgm.h
	$(CC) $(CFLAGS) pgm.c -c

test1:
	./addframe colosseo.pgm colosseo-addframe-190-10.pgm 190 10

test2:
	./addframe colosseo.pgm colosseo-addframe-64-7.pgm 64 7

.phony: clean

clean:
	rm -f *.o addframe colosseo-addframe*.pgm
