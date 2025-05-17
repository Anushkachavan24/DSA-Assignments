#ifndef MAXHEAP_H_INCLUDED
#define MAXHEAP_H_INCLUDED

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

#endif // MAXHEAP_H_INCLUDED
