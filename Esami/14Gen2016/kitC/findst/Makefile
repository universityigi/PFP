CC=gcc
CFLAGS=-Wall -O1 -g
LFLAGS=-pthread

blur: findst.c findst.h main.c
	$(CC) $(CFLAGS) findst.c main.c -o findst $(LFLAGS)

test1:
	./findst war_peace.txt "reflections"

test2:
	./findst war_peace.txt "respectfully"

.phony: clean

clean:
	rm -f findst
