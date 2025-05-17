#ifndef POSTORDER_H_INCLUDED
#define POSTORDER_H_INCLUDED
#include "Array.h"
#include "postorder.h"

struct node *createnode(int);

struct node *createBST(int postorder[], int, int);

void Inorder_traversal(struct node *);

#endif //POSTORDER_H_INCLUDED
