#This is Makefile for Assignment-1



Assignment1: main.o tree.o stack.o
	cc main.o tree.o stack.o -o Assignment1

main.o: main.c tree.h stack.h
	cc -c main.c

tree.o: tree.c tree.h stack.h
	cc -c tree.c
	
stack.o: stack.c tree.h stack.h
	cc -c stack.c
	
clean:
	rm * o Assignment1	

