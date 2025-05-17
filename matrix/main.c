#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"

int main(int argc, char *argv[]){
    sparse S1;
    LoadSparse(argv[1], &S1);
    display(&S1);
    printf("fejsf");
    return 0;
}
