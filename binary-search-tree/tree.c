#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

//Function for initialization of BST
void init(BST *t){
    *t = NULL;
    return;
};

//Function to create a newnode
struct node*newnode(int data, char *name){
    char *str = calloc(1,sizeof(char));
    node *temp = (node*)malloc(sizeof(node));

    if(temp== NULL)
        return NULL;
    temp->MIS = data;
    strcpy(str, name);
    temp->Name = str;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
};

//Function to insert newnode
struct node *insert_node(BST t, int data, char *name){
    node *nn = malloc(sizeof(struct node));
    if (t == NULL){
        nn = newnode(data, name);
        return nn;
    }
    if(t->MIS == data)
        return t;
    if(t->MIS > data){
        node *left_child =  insert_node(t->left, data, name);
        t->left = left_child;
        left_child->parent = t;
    }
    if(t->MIS < data){
        node *right_child =  insert_node(t->right, data, name);
        t->right = right_child;
        right_child->parent = t;
    }
    return t;
};

//Function to find inorder successor
struct node *smallestnode(BST t){
    while(t->left != NULL){
        t = t->left;
    }
    return t;
};

//Function to remove a node from BST
void removenode(BST t, int data){
    //If tree is empty then return
    if(t == NULL)
        return;
    node *p = t;
    node *q = NULL;
    //Search the node in BST
    while(p != NULL){
        if(p->MIS == data)
           break;
        q = p;   
        if(p->MIS > data)
           p = p->left;
        else
           p = p->right;
    }
    //If node not found then return
    if(p == NULL)
        return;
    //Remove a node having 0 child
    else if(p->left == NULL && p->right == NULL){
        if(p == t){
           free(t);
           return;
        }
        if(p == q->left)
           q->left = NULL;
        else
           q->right = NULL;
        free(p);
        return;
    }
    //Remove a node having only one left child
    else if(p->left != NULL && p->right == NULL){
        if(p == t){
           t = t->left;
        }
        if(p == q->left)
           q->left = p->left;
        else
           q->right = p->left;
        (p->left)->parent = q;
        free(p);
        return;
    }
    //Remove a node having only one right child
    else if(p->left == NULL && p->right != NULL){
        if(p == t){
           t = t->right;
        }
        if(p == q->left)
           q->left = p->right;
        else
           q->right = p->right;
        (p->right)->parent = q;
        free(p);
        return;
    }
    //Remove a node having both right and left children
    else{
        node *temp = smallestnode(p->right);
        p->MIS = temp->MIS;
        char *name = calloc(1,sizeof(char));
        strcpy(name, temp->Name);
        p->Name = name;
        q = temp->parent;
        if(temp->right){
           if(temp == q->left)
              q->left = temp->right;
           else
              q->right = temp->right;
           (temp->right)->parent = q;
        }
        else{
           if(temp == q->left)
              q->left = NULL;
           else
              q->right = NULL;
        }
        free(temp);  
        return;
    }
    return;
}

//Function to search a node in BST
int searchnode(BST t, int data){
    if(!t)
        return 0;
    if(t->MIS == data)
        return 1;
    if(t->MIS> data)
        return searchnode(t->left, data);
    return searchnode(t->right, data);
}

//Function to display all nodes present at ith level
void Display_Level(node* t, int currentLevel, int level){
    if(t == NULL) {
        return;
    }
    if(currentLevel == level) {
       printf(" %d ", t->MIS);
       return;
    }

    Display_Level(t->left, currentLevel+1, level);
    Display_Level(t->right, currentLevel+1, level);
}

//Function to remove all the nodes from BST
void destroyTree(BST t){
    if(t == NULL)
        return;
    destroyTree(t->left);
    destroyTree(t->right);
    free(t);
    return;
}

//Function for inorder traversal
void inorder(BST t){
   if(t == NULL)
      return;
   inorder(t->left);
   printf("%d", t->MIS);
   inorder(t->right);
}
