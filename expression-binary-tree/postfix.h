#ifndef POSTFIX_H_INCLUDED
#define POSTFIX_H_INCLUDED

#include "tree.h"

typedef struct node{
    char data;
    struct node *next;
}node;

char pop();

int isEmpty();

void inpost(char);

int space(char);

void print(char*);

int precedence(char);

void push(char);

char *infix_to_postfix(char *);


#endif // POSTFIX_H_INCLUDED
