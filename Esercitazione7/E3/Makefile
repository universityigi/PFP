CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

e3: e3-main.c e3.c e3.h
	$(CC) $(CFLAGS) e3-main.c e3.c -o e3 $(LFLAGS)

.phony: clean

clean:
	rm -rf e3 *.dSYM
