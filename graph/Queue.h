#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "graph.h"


typedef struct Queue{
     int max_size;
     int rear;
     int front;
     int *array;
}Queue;

void init_queue(Queue *, int);

void enqueue(Queue *, int);

int dequeue(Queue *);

int peek_Queue(Queue *);

int isEmpty(Queue);

int isFull(Queue );

void printqueue(Queue );

#endif //QUEUE_H_INCLUDED
