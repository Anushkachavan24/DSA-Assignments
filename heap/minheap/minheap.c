#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "minheap.h"

void heapify(heap *);

//function to initialize the heap
void init_heap(heap *h, int max){
    h->max_size = max;
    h->top = -1;
    h->arr = (int*)malloc(sizeof(int));
    return;
};


//Function to swap two numbers
void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
    return;
}


//Function for heapify while inserting elements to heap
void heapify(heap *h){
    int i = h->top;
    while(i >= 0){
        int p = (i-1)/2;//find parent
        if(h->arr[p] > h->arr[i]){
        //Swap the current element with its parent if parent is greater than current element
            swap(&(h->arr[p]), &(h->arr[i]));
            i = p;
        }
        else
           return;
    }
}



//
void insertheap(heap *h, int a){
    if(h->top == h->max_size)
         return;
    if(h->top < h->max_size){
    //Increment the top and insert element to it
         h->top++;
         h->arr[h->top] = a;
         if(h->top == 0)//if top == 0, then no heapify required
              return;
         else{
         //if parent is greater than inserted element then call heapify
              int p = (h->top -1)/2;
              if(h->arr[p] > h->arr[h->top])
                  heapify(h);
              else
                  return;
         }
         
    }
    return;
}



//Function to print heap
void printheap(heap *h){
    int i = 0;
    if(h->top < h->max_size){
         while(i <= h->top){
             printf("%d ", h->arr[i]);
             i++;
         }     
    }
    return;
}



//Function to print sorted array
void printarray(int A[], int n){
    int i = 0;
    for(i = 0; i<n;i++){
       printf("%d ", A[i]);
    }
}


//Function to delete heap
int deleteheap(heap *h){
    //Swap the first and last element in the heap
    swap(&(h->arr[0]), &(h->arr[h->top]));
    int n = h->arr[h->top];//Set n as last element of heap
    h->top--;//decreament top
    int i = 0;
    int il, ir, min;
    while(i<h->top){
         il = 2*i+1; //left child
         ir = 2*i+2; //right child
         //if il is less than top  
         if(il <= h->top){
              //if ir is not present then min = il
              if(ir > h->top){
                  min = il;         
              }
              //if ir is present then compare il and ir and set min
              else if(ir <= h->top){
                  if(h->arr[il]<h->arr[ir])
                       min = il;
                 else
                      min = ir;
              }
              //if min is larger than i then swap
              if(h->arr[min] < h->arr[i]){
                   swap(&(h->arr[i]), &(h->arr[min]));
                   i = min;
              }  
              else
                   return n;
        }
        else
              return n;
   }
   return n;
}

