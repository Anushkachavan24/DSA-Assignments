
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
typedef struct node{
     int value;
     int r, c;
     struct node *right, *down;
}node;

typedef struct sparse{
     int nr, nc;
     struct node **row;
     struct node **column;
}sparse;

void initsparse(sparse *, int, int);

void LoadSparse(char *, sparse*);

void display(sparse *);
#endif //MATRIX_H_INCLUDED
