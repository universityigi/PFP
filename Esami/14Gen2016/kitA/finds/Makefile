CC     = gcc
CFLAGS = -O1 -Wall -Wno-deprecated-declarations
LFLAGS = -l OpenCL

finds: main.o clut.o finds.o
	$(CC) $(CFLAGS) main.o clut.o finds.o \
        -o finds $(LFLAGS)

main.o: main.c clut.h finds.h
	$(CC) $(CFLAGS) main.c -c

finds.o: finds.c finds.h clut.h
	$(CC) $(CFLAGS) finds.c -c

clut.o: clut.c clut.h
	$(CC) $(CFLAGS) clut.c -c

test1:
	./finds war_peace.txt "reflections"

test2:
	./finds war_peace.txt "respectfully"

.phony: clean

clean:
	rm -f *.o finds
