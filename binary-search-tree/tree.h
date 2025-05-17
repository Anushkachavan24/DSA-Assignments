#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "stack.h"

typedef struct node{
    int MIS;
    char *Name;
    struct node *parent;
    struct node *left;
    struct node *right;
}node;

typedef node *BST;

void init(BST *t);

struct node*newnode(int data, char *n);

struct node *insert_node(BST t, int data, char *n);

struct node *smallestnode(BST t);

void removenode(BST t, int data);

int searchnode(BST t, int data);

void postorder(BST t);

void Display_Level(node* root, int currentLevel, int level);

void destroyTree(BST t);

void inorder(BST t);

#endif // TREE_H_INCLUDED
