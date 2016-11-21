CC=gcc
CFLAGS=
RM=rm -rf
OUT=mod12

all: build

build: main.o vector.o adv.o
    $(CC) $(CFLAGS) -o $(OUT) main.c vector.c
    $(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c vector.h adv.h
    $(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h
    $(CC) $(CFLAGS) -c vector.c

adv.o: adv.c adv.h
		$(CC) $(CFLAGS) -c adv.c 

clean:
    $(RM) *.o $(OUT)
