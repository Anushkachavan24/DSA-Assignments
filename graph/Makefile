#This is Makefile for Assignment-6



Assignment6: main.o graph.o Queue.o stack.o 
	cc main.o graph.o Queue.o stack.o -o Assignment6

main.o: main.c graph.h Queue.h stack.h
	cc -c main.c

graph.o: graph.c graph.h Queue.h stack.h 
	cc -c graph.c
	
Queue.o: Queue.c graph.h Queue.h
	cc -c Queue.c
	
stack.o: stack.c graph.h stack.h
	cc -c stack.c
	
clean:
	rm * o Assignment6	

