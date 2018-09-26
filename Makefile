
#DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS=-c -g #-I$(DIRSDL)/include -I$(DIRSDL)/include/SDL -I/usr/local/include -I/usr/local/include/SDL -I/usr/include/SDL

LFLAGS=-lm #-L$(DIRSDL)/lib -lSDLmain -lSDL -lSDL_ttf -lSDL_image  -lSDL_sound -lSDL_phelma -lSDL_draw -lm

all : main

main: main.o LIST.o QUEUE.o
	gcc -o $@ $^  $(LFLAGS)


%.o : %.c
	gcc $(CFLAGS) $<

clean: rm -rf *.o a b
