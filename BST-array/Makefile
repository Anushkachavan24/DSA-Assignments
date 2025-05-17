#This is makefile for Assignment2

Assignment2: main.o Array.o postorder.o
	cc main.o Array.o postorder.o -o Assignment2

main.o: main.c Array.h postorder.h
	cc -c main.c

Array.o: Array.c Array.h 
	cc -c Array.c
	
postorder.o: postorder.c Array.h postorder.h 
	cc -c postorder.c
	
clean:
	rm * o Assignment2	

