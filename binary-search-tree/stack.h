#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "tree.h"

typedef struct Stack{
    int lenght;
    int top;
    struct node **A;
}Stack;

struct Stack *createstack(int lenght);

int isfull(Stack *S);

int isEmpty(Stack *S);

void push(Stack *S, struct node *t);

struct node* pop(Stack *S);

struct node* peek(Stack *S);

#endif // STACK_H_INCLUDED
