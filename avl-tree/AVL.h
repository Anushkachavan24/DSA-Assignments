#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

//typedef for avl tree
typedef struct node{
	int bf;
	char month[30];
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

typedef node* AVL;

void initAVL(AVL *);

node*newnode(char name[]);

void insertNode(AVL *,char[]);

void Adjust_bf(AVL *);

int height(AVL );

node* imbalanceNode(AVL);

void LLrotation(AVL *,node *);

void LRrotation(AVL *,node *);

void RRrotation(AVL *,node *);

void RLrotation(AVL *,node *);

void inorder(AVL );

node *smallestnode(AVL t);

void Display_Level(AVL , int, int);

void removeNode(AVL *, char[]);

void destroyTree(AVL *);
#endif // AVL_H_INCLUDED
