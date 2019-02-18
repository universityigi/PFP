CC     = gcc
CFLAGS = -O1 -Wall -g -pthread
LFLAGS = 

findstr: main.o findstr.o
	$(CC) $(CFLAGS) main.o findstr.o -o findstr $(LFLAGS)

main.o: main.c findstr.h
	$(CC) $(CFLAGS) main.c -c

findstr.o: findstr.c findstr.h
	$(CC) $(CFLAGS) findstr.c -c

test1:
	./findstr war_peace.txt "reflections"

test2:
	./findstr war_peace.txt "respectfully"

.phony: clean

clean:
	rm -f *.o findstr
