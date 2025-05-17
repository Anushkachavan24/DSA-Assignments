#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "tree.h"
#include "postfix.h"

int topp = -1;
tree_node *stack[100];

void inorder(tree_node *t){
    if(t == NULL)
       return;
    inorder(t->left);
    printf("%c", t->data);
    inorder(t->right);
    return;
}

tree_node *newnode(char data){
    tree_node *temp = (tree_node*)malloc(sizeof(tree_node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void push_node(tree_node **stack, tree_node *t){
    topp++;
    stack[topp] = t;
}

tree_node *pop_node(tree_node **stack){
    topp--;
    return (stack[topp+1]);
};

//Function to create a expression tree
tree_node *Inittree(char *postfix){
    char d;
    tree_node *head, *p1, *p2;
    for(int i=0; i<strlen(postfix);i++){
       if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^'){
           head = newnode(postfix[i]);
           p1 = pop_node(stack);
           p2 = pop_node(stack);
           head->left = p2;
           head->right = p1;
           push_node(stack, head);
       }
       else{
           head = newnode(postfix[i]);
           push_node(stack, head);
       }
    }
    return head;
}

//Function to evaluate expression tree
int Compute(tree_node *t){
    if(t == NULL)
       return 0;
    if(t->left == NULL && t->right == NULL)
       return ((t->data)-48);
    int l_value = Compute(t->left);
    int r_value = Compute(t->right);
    printf("Inorder Traversal of each subtree:\n");
    inorder(t);
    printf("\n");
    if(t->data == '+'){
       printf("Result : %d\n", l_value+r_value);
       return l_value+r_value;
    }
    if(t->data == '-'){
       printf("Result : %d\n", l_value-r_value);
       return l_value-r_value;
    }
    if(t->data == '*'){
       printf("Result : %d\n", l_value*r_value);
       return l_value*r_value;
    }
    if(t->data == '^'){
       printf("Result : %f\n", pow(l_value,r_value));
       return pow(l_value,r_value);
    }
    else{
       printf("Result : %d\n", l_value/r_value);
       return l_value/r_value;
    }
}






























