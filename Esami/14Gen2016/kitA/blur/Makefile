CC=gcc
CFLAGS=-Wall -O1 -g
LFLAGS=-pthread

blur: blur.c blur.h main.c pgm.h pgm.c
	$(CC) $(CFLAGS) blur.c main.c pgm.c -o blur $(LFLAGS)

test:
	./blur colosseo.pgm colosseo-blurred.pgm

.phony: clean

clean:
	rm -f blur
