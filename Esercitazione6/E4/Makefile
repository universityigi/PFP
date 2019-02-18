CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

e4: e4-main.c e4.c e4.h
	$(CC) $(CFLAGS) e4-main.c e4.c -o e4 $(LFLAGS)

.phony: clean

clean:
	rm -rf e4 *.dSYM
