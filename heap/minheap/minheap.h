#ifndef MINHEAP_H_INCLUDED
#define MINHEAP_H_INCLUDED

typedef struct heap{
    int max_size;
    int top;
    int *arr;
}heap;

void init_heap(heap *, int);

void swap(int*, int*);

void insertheap(heap *, int);

int deleteheap(heap *h);

void printheap(heap *);

void printarray(int A[], int);

#endif // MINHEAP_H_INCLUDED
