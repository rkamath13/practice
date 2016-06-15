CC=gcc
CFLAGS=-c -Wall

all: output

output: bst.o main.o 
	$(CC) bst.o main.o -o output 

bst.o: bst.c
	$(CC) $(CFLAGS) bst.c
main.o: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *o output
