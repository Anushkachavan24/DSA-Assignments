#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "stack.h"


void init_stack(stack*S, int s){
    S->max_size = s;
    S->top = -1;
    S->A = (int*)malloc(sizeof(int) *S->max_size);
    return;
}

void push(stack *S, int d){
    if(isFull_stack(*S))
       return;
    S->top++;
    S->A[S->top] = d;
    return;
}

int pop(stack*S){
    if(isEmpty_stack(*S))
       return INT_MIN;
    int n = S->A[S->top];
    S->top--;
    return n;
}

int peek(stack S){
    if(isEmpty_stack(S))
       return INT_MIN;
    int n = S.A[S.top];
    return n;
}

int isFull_stack(stack S){
    if(S.top == S.max_size-1)
       return 1;
    else
       return 0;
}

int isEmpty_stack(stack S){
    if(S.top == -1)
       return 1;
    else
       return 0;
}


void printstack(stack S){
    if(isEmpty_stack(S))
       return;
    for(int i = 0;i<=S.top; i++){
       printf("%d ", S.A[i]);
    }
    return;

}
