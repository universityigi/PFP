ifeq ($(shell uname -s),Linux)
		LFLAGS = -lOpenCL
endif

ifeq ($(shell uname -s),Darwin)
		LFLAGS = -framework OpenCL
endif

CC     = gcc
CFLAGS = -O2 -Wall

es4: main.c clut.c pgm.c shear45.c
	$(CC) $(CFLAGS) main.c clut.c pgm.c shear45.c \
        -o es4 $(LFLAGS)

.phony: clean

clean:
	rm -f es4 results/*
