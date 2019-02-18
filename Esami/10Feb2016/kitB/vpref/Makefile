CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

vpref: main.c vpref.c vpref.h
	$(CC) $(CFLAGS) main.c vpref.c -o vpref $(LFLAGS)

.phony: clean

clean:
	rm -rf vpref *.dSYM
