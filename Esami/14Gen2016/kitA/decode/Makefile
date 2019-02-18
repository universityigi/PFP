CC=gcc
CFLAGS=-Wall -O1 -g
LFLAGS=-mavx2

decode: decode.c decode.h main.c
	$(CC) $(CFLAGS) decode.c main.c -o decode $(LFLAGS)

.phony: clean

clean:
	rm -f decode
