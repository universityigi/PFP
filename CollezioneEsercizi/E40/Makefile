CC     = gcc
CFLAGS = -O1 -Wall -g
LFLAGS = -msse4.2

vpal32: vpal32-main.c vpal32.c vpal32.h
	$(CC) $(CFLAGS) vpal32-main.c vpal32.c -o vpal32 $(LFLAGS)

.phony: clean

clean:
	rm -rf vpal32 *.dSYM
