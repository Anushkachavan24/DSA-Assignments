#This is makefile for Assignment-5

Assignment5: main.o maxheap.o
	cc main.o maxheap.o -o Assignment5
main.o: main.c maxheap.h
	cc -c main.c 
maxheap.o: maxheap.c maxheap.h
	cc -c maxheap.c
clean:
	rm * o Assignment5
