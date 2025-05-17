#include<stdio.h>
#include<stdlib.h>
#include "minheap.h"

int main(int argc, char *argv[]){
    FILE *ptr;
    ptr = fopen(argv[1], "r");
    int MAX = atoi(argv[2]);
    int arr[MAX], array[MAX];
    int i = 0, m;
    int n = 0;
    heap *h;
    init_heap(h, MAX);
    while (fscanf(ptr, "%d", &arr[n]) == 1)
    {
        n++;
        if(MAX == n){
            break;
        }
    }
    while(i < MAX){
        insertheap(h, arr[i]);
        i++;  
    }
    printf("Inserted heap:\n");
    printheap(h);
    printf("\n\n");
    n = 0;
    while(i>0){
       m = deleteheap(h);
       array[n] = m;
       n++;
       //printf("%d ", m);
       i--;
    }
    printf("Sorted heap:\n");
    printarray(array, MAX);
    printf("\n");
    return 0;
}
