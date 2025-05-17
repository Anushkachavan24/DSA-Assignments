#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AVL.h"

//Function to initialize the avl tree
void initAVL(AVL *t){
	*t=NULL;
	return;
}

//Function to find maximum
int max(int a, int b){
    if(a > b)
       return a;
    else
       return b;
}

//Function to calculate height of a node
int height(AVL t){
    if(t == NULL)
       return 0;
    return 1+max(height(t->left), height(t->right));
}

//Function to adjust the balance factor
void Adjust_bf(AVL* t){
    if((*t)==NULL)
	return;
    (*t)->bf = (height((*t)->left))-(height((*t)->right));
    Adjust_bf(&((*t)->parent));
}

node* imbalanceNode(AVL t){
     node* p = t;
     while(p){
	if(abs(p->bf) > 1)
	    return p;
	else
	    p=p->parent;
     }
     return p;
}

//Function for LL rotation
void LLrotation(AVL *t, node *a){
	node* b= a->left;
	node *br=NULL, *ap=NULL;
	
	if (a==(*t))//if a is root node
		(*t)=b;
	if(b->right)//when b->right is present
		br = b->right;
	
	if(a->parent)//if a is not root node	
		ap = a->parent;
	if(ap){ // check if a is left or right child of ap
	     if(ap->left == a)
	        ap->left = b;
	     else
	        ap->right = b;
	}
	b->parent = ap;

	b->right = a;
	a->left = br;
	a->parent = b;
	
	if(br)//when b->right is present
		br->parent=a;
	return;	
}

//Function for RR Rotation
void RRrotation(AVL *t, node *a){
	node *b = a->right;
	node *bl=NULL, *ap=NULL;
	
	if(a==(*t))//if a is root node
		(*t)=b;
		
	if(b->left)//when b->left is present
		bl=b->left;
	
	if(a->parent)//when a is not root node
		ap=a->parent;
	if(ap){// check if a is left or right child of ap
	    if(ap->left == a)
	        ap->left = b;
	    else
	        ap->right = b;
	}
	b->parent=ap;
		
	b->left=a;
	a->right=bl;
	a->parent=b;
	
	if(bl)//when b->left is present
		bl->parent=a;
		
	return;
}

//Function for LR Rotation
void LRrotation(AVL *t, node *a){	
      node *b = a->left;
      node *c = b->right;
	
      c->parent = a;
      a->left = c;
      c->left=b;
      b->parent=c;
      b->right=NULL;
	
      LLrotation(&(*t), a);
	
      a->parent->left->bf=0;
	return;
}

//Function for RR Rotation
void RLrotation(AVL *t, node *a){
      node *b = a->right;
      node *c = b->left;
	
      c->parent = a;
      a->right = c;
      c->right = b;
      b->parent = c;
      b->left = NULL;
	
      RRrotation(&(*t), a);
	
      a->parent->right->bf=0;
      return;
}

//Function to create a newnode
node*newnode(char *name){
     node *temp = (node*)malloc(sizeof(node));

     if(temp== NULL)
         return NULL;
     strcpy(temp->month, name);
     temp->left = NULL;
     temp->right = NULL;
     temp->parent = NULL;
     temp->bf = 0;
     return temp;
};

//Function to insert the node in AVL tree
void insertNode(AVL* t, char name[]){
	node* nn=(node*)malloc(sizeof(node));
	nn = newnode(name);
	//if tree is empty 
	if((*t)==NULL){
	     nn->parent=NULL;
	     (*t)=nn;
	     return;
	}
	else{
	     node* p=(*t);
	     node* q=NULL; 
	     while(p){
		 q=p;
		 if(strcmp(name,p->month)<0)
			 p=p->left;
		 else
	       		 p=p->right;
	     }	
	     nn->parent=q;
	     if(strcmp(name, q->month)<0)
		q->left=nn;
	     else
		q->right=nn;
	}
	Adjust_bf(&(nn->parent));
	node *temp = imbalanceNode(nn->parent);
	if(temp == NULL){
	     printf("No imbalance\n");
	     printf("\n");
	     return;
	}
	else{
	     printf("Imbalance at %s -> %d\n",temp->month,temp->bf);
             if(strcmp(name,temp->month)<0){
		  if(strcmp(name,temp->left->month)<0){
		         printf("LL Imbalance\n");
			 printf("\n");
			 LLrotation(&(*t),temp);
		   }
		   else{
			 printf("LR Imbalance\n");
			 printf("\n");
			 LRrotation(&(*t),temp);
		   }
	     }
	     else{
		   if(strcmp(name,temp->right->month) >0){
			 printf("RR Imbalance\n");
			 printf("\n");
			 RRrotation(&(*t),temp);
	           }	
		   else{
			 printf("RL Imbalance\n");
			 printf("\n");
			 RLrotation(&(*t),temp);
		   }
	     }
	}
	Adjust_bf(&(temp));
	return;
}

//inorder Traversal
void inorder(AVL t){
     if(!t)
	 return;	
     inorder(t->left);
     printf("child node: %s -> %d\n",t->month,t->bf);
     if(t->parent)
	 printf("Parent node: %s -> %d\n",t->parent->month,t->parent->bf);
     else
         printf("Parent node: NULL\n");
     printf("\n");
     inorder(t->right);
}


//Display nodes at the level
void Display_Level(AVL t, int level, int current){
     if(t==NULL)
	return;
     if(t){
	if(level==current)
	    printf("%s\t%d\n",t->month,t->bf);
        else{
	    Display_Level(t->left,level,current+1);
	    Display_Level(t->right,level,current+1);
	}
     }
     return;
}
	
node *smallestnode(AVL t){
    while(t->left != NULL){
        t = t->left;
    }
    return t;
};

//Remove node from binary search tree
void removeNode(AVL *t, char name[]){
      node *imb_node = NULL;
      if((*t) == NULL)
          return;
      node *p = *t;
      node *q = NULL;
      //Search the node in AVL
      while(p != NULL){
          if(strcmp(name, p->month) == 0)
             break;
          q = p;   
          if(strcmp(name, p->month)<0)
             p = p->left;
          else
             p = p->right;
      }
      //If node not found then return
      if(p == NULL)
          return;
      //Remove a leaf node having no child
      else if(p->left == NULL && p->right == NULL){
        if((*t) == p){
           free(*t);
           *t = NULL;
           return;
        }
        if(p == q->left)
           q->left = NULL;
        else
           q->right = NULL;
        free(p);
      }	
      //Remove a node having only one left child
      else if(p->left != NULL && p->right == NULL){
          if(p == (*t)){
             (*t) = (*t)->left;
          }
          if(p == q->left)
             q->left = p->left;
          else
             q->right = p->left;
          (p->left)->parent = q;
          free(p);
      }	
      //Remove a node having only one right child
      else if(p->left == NULL && p->right != NULL){
          if(p == (*t)){
             (*t) = (*t)->right;
          }
          if(p == q->left)
             q->left = p->right;
          else
             q->right = p->right;
          (p->right)->parent = q;
          free(p);
      }
      //Remove a node having both right and left children
      else{
          node *temp = smallestnode(p->right);
          strcpy(p->month, temp->month);
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
      }
      Adjust_bf(&q);
      imb_node = imbalanceNode(q);
      if(imb_node == NULL){
	   printf("No imbalance\n");
	   printf("\n");
	   return;
	}
      else{
	   printf("Imbalance at %s -> %d\n",imb_node->month,imb_node->bf);
	   if(imb_node->bf > 1 && imb_node->left->bf >= 0){
	         printf("LL Imbalance\n");
	         LLrotation(&(*t), imb_node);
	   }
	   if(imb_node->bf > 1 && imb_node->left->bf < 0){
	         printf("LR Imbalance\n");
	         LRrotation(&(*t), imb_node);
	   }
	   if(imb_node->bf < -1 && imb_node->right->bf <= 0){
	         printf("RR Imbalance\n");
	         RRrotation(&(*t), imb_node);
	   }
	   if(imb_node->bf < -1 && imb_node->right->bf > 0){
	         printf("RL Imbalance\n");
	         RLrotation(&(*t), imb_node);
	   }
      }
      Adjust_bf(&(imb_node));
      return;	
}
	
//Function to destroy tree
void destroyTree(AVL* t){
    if((*t) != NULL){
	destroyTree(&(*t)->left);
	destroyTree(&(*t)->right);
	(*t) = NULL;
	free(*t);
    }
}

