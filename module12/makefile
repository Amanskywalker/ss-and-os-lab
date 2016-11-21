CC=gcc
CFLAGS=
RM=rm -rf
OUT=mod12

all: build

build: main.o vector.o adv.o
	$(CC) $(CFLAGS) main.c vector.c adv.c -o $(OUT)
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -std=gnu99 -c vector.c

adv.o: adv.c adv.h
	$(CC) $(CFLAGS) -c adv.c

main.o: main.c vector.h adv.h
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) *.o $(OUT)
