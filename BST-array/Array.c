#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "Array.h"
#include "postorder.h"

struct node *newnode(int d){
    node *temp = (node*)malloc(sizeof(node));
    if(temp== NULL)
        return NULL;
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

//Function to insert newnode
struct node *insert_node(node *t, int d){
    node *nn = (node*)malloc(sizeof(node));
    if (t == NULL){
        nn = newnode(d);
        return nn;
    }
    if(t->data == d)
        return t;
    if(t->data > d)
        t->left =  insert_node(t->left, d);
    if(t->data < d)
        t->right =  insert_node(t->right, d);
    return t;
};

int height_BST(node *t){
   if(t == NULL)
       return -1;
   else{
     //compute the depth of each subtree 
     int left_h = height_BST(t->left);
     int right_h = height_BST(t->right);
     //use the larger one 
     if(left_h > right_h)
        return (left_h + 1);
     else 
        return (right_h + 1);
   }
}

int max_nodes(int H){
   int max = 1;
   while(H >= 0){
      max = max*2;
      H--;
   }
   return (max-1);
}

void init_bst(int A[], int N){
   while(N > 0){
      A[N-1] = INT_MIN;
      N--;
   }
   return;
}

void insert_bst(int A[], int size, int index, int data){
   while(index < size){
      if(A[index] == INT_MIN){
         A[index] = data;
         return;
      }
      else{
         if(A[index] > data)
            index = (2*index + 1);
         else
            index = (2*index + 2);
      }
   }
   return;
}

void printarray(int A[], int N){
   int i = 0;
   while(N > i){
      printf("%d-", A[i]);
      i++;
   }
   return;
}

void preorder(int A[], int index, int N){
   if((A[index] != INT_MIN) && (N > index)){
      printf("%d-", A[index]);
      preorder(A, (2*index + 1), N);
      preorder(A, (2*index + 2), N);
   }
}

void postorder(int A[], int index, int N){
   if((A[index] != INT_MIN) && (N > index)){
      postorder(A, (2*index + 1), N);
      postorder(A, (2*index + 2), N);
      printf("%d-", A[index]);
   }
}

void inorder(int A[], int index, int N){
   if((A[index] != INT_MIN) && (N > index)){
      inorder(A, (2*index + 1), N);
      printf("%d-", A[index]);
      inorder(A, (2*index + 2), N);
   }
}

void isComplete(int A[], int N){
   while(N >= 0){
       if(A[N-1] == INT_MIN){
          printf("BST is not complete BST");
          break;
       }
       if(N == 0)
          printf("BST is complete BST");
   }
   return;
}

