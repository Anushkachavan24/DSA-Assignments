#This is Makefile for Assignment-3



Assignment3: main.o postfix.o tree.o
	cc main.o postfix.o tree.o -o Assignment3 -lm

main.o: main.c postfix.h tree.h
	cc -c main.c

postfix.o: postfix.c postfix.h tree.h 
	cc -c postfix.c
	
tree.o: tree.c tree.h postfix.h
	cc -c tree.c
	
clean:
	rm * o Assignment3	

