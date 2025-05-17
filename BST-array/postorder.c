#include<stdio.h>
#include<stdlib.h>
#include "Array.h"
#include "postorder.h"

struct node *createBST(int postorder[], int start, int end){
     if(start > end)
        return NULL;
     node *nn = newnode(postorder[end]);
     int i;
     for(i = end-1; i >= start; i--){
         if(postorder[i] < nn->data)
            break;
     }
     nn->left = createBST(postorder, start, i);
     nn->right = createBST(postorder, i+1, end-1);
     return nn;
};

void Inorder_traversal(node *BST){
     if(BST == NULL)
        return;
     Inorder_traversal(BST->left);
     printf("%d-",BST->data);
     Inorder_traversal(BST->right);
     return;
}

