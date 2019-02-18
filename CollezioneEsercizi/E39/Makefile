CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2         # modificare se serve AVX

veq32: veq32-main.c veq32.c veq32.h
	$(CC) $(CFLAGS) veq32-main.c veq32.c -o veq32 $(LFLAGS)

.phony: clean

clean:
	rm -rf veq32 *.dSYM
