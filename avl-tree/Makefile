#This is makefile for Assignment-4

Assignment4: main.o AVL.o
	cc main.o AVL.o -o Assignment4
main.o: main.c AVL.h
	cc -c main.c 
AVL.o: AVL.c AVL.h
	cc -c AVL.c
clean:
	rm * o Assignment4
