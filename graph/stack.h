#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "graph.h"


typedef struct stack{
     int max_size;
     int *A;
     int top;
     struct stack *next;
}stack;

void init_stack(stack*, int);

void push(stack*, int);

int pop(stack*);

int peek(stack);

int isFull_stack(stack);

int isEmpty_stack(stack);

void printstack(stack );

#endif //STACK_H_INCLUDED
