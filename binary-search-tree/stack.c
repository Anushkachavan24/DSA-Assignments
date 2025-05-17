#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

struct Stack *createstack(int length){
    Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    S->lenght = length;
    S->top = -1;
    S->A = (struct node **)malloc(S->lenght *sizeof(struct node*));
    return S;
};

int isfull(Stack *S){
    return S->top - 1 == S->lenght;
}

int isEmpty(Stack *S){
    return S->top == -1;
}

void push(Stack *S, struct node *t){
    if(isfull(S))
        return;
    S->A[++S->top] = t;
}
struct node* pop(Stack *S){
    if(isEmpty(S))
        return NULL;
    return S->A[S->top--];
};

struct node* peek(Stack *S){
    if(isEmpty(S))
        return NULL;
    return S->A[S->top];
};

//Postorder traversal
void postorder(BST t){
    Stack *S = createstack(100);
    node* current = t;
    node* prev = NULL;
    //while current is not null and stack is not empty push to stack
    //and set current = current->left
    while(current != NULL || !isEmpty(S)){
        if(current != NULL){
            push(S, current);
            current = current->left;
        }
        //if current is null and stack is not empty
        //then look at the current->right, if it is NULL or prev
        //then print in postorder traversal and if not then set current = current->right
        else{
            current = peek(S);
            if(current->right == NULL || current->right == prev){
                printf("Child node - %d : %s\n", current->MIS, current->Name);
                if(current->parent == NULL)
                   printf("NULL\n");
                else
                   printf("Parent node - %d : %s\n", (current->parent)->MIS, (current->parent)->Name);
                pop(S);
                prev = current;
                current = NULL;
            }
            else{
                current = current->right;
            }
        }
    }
    return;
}
