#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "postfix.h"

typedef struct tree_node{
    char data;
    struct tree_node *left;
    struct tree_node *right;
}tree_node;

tree_node *newnode(char);

void push_node(tree_node **, tree_node *);

tree_node *pop_node(tree_node **);

tree_node *Inittree(char *);

void inorder(tree_node *);

int Compute(tree_node *);

#endif // TREE_H_INCLUDED
