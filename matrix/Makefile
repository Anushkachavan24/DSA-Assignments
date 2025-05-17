#This is Makefile for Assignment-1



Matrix: main.o matrix.o
	cc main.o matrix.o -o Matrix

main.o: main.c matrix.h
	cc -c main.c

matrix.o: matrix.c matrix.h 
	cc -c matrix.c
	
clean:
	rm * o Matrix	
