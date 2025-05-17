#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED
#include "Array.h"
#include "postorder.h"

typedef struct node{
   int data;
   struct node *left, *right;
}node;

struct node *newnode(int);

struct node *insert_node(node *, int);

int height_BST(node *);

int max_nodes(int);

void init_bst(int A[], int);

void insert_bst(int A[], int, int, int);

void printarray(int A[], int);

void preorder(int A[], int, int);

void postorder(int A[], int, int);

void inorder(int A[], int, int);

void isComplete(int A[], int);

#endif //ARRAY_H_INCLUDED
