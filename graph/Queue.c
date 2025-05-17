#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "Queue.h"

void init_queue(Queue *Q, int s){
    Q->max_size = s;
    Q->front = -1;
    Q->rear = -1;
    Q->array = (int*)malloc(sizeof(int));
    return;
}

void enqueue(Queue *Q, int a){
    if(isFull(*Q))
       return;
    if(Q->front == -1)
       Q->front++;
    Q->rear = (Q->rear+1)%Q->max_size;
    Q->array[Q->rear] = a;
    return;
}

int dequeue(Queue *Q){
    if(isEmpty(*Q))
       return INT_MIN;
    int n = Q->array[Q->front];
    if(Q->front == Q->rear){
        Q->front = Q->rear = -1;
        return n;
    }
    Q->front = (Q->front+1)%Q->max_size;
    return n;
}

int peek_Queue(Queue *Q){
   if(isEmpty(*Q))
      return INT_MIN;
   int n = Q->array[Q->front];
   return n;
}

int isEmpty(Queue Q){
   if(Q.front == -1)
       return 1;
   else
       return 0;
}

int isFull(Queue Q){
   if((Q.front = Q.rear+1) || (Q.front == 0 && Q.rear == Q.max_size-1))
       return 1;
   else
       return 0;
}

void printqueue(Queue Q){
   if(!isEmpty(Q)){
       for(int i = Q.front;i<=Q.rear;i++){
           printf("%d ", Q.array[i]);
       }
   }
   
}
