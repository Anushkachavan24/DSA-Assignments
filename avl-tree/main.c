#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

int main(){
	AVL T;

	int i=0;
	char name[20]={'\0'};
	int choice;
	
	while(1){
	
	     printf("1. Initialize the tree\n");
	     printf("2. Add a new node to the tree\n");
	     printf("3. Remove a node from a tree\n");
	     //printf("4. Display all nodes of ith order\n");
	     printf("4. Inorder Traversal\n");
	     printf("5. Delete all the nodes from tree\n");
	     printf("6. Exit\n");
	     printf("Enter your choice\n");
	     scanf("%d",&choice);
	
	     switch (choice){
	           case 1:
	                initAVL(&T);
	                break;
	
		   case 2:
			printf("Enter the month name:\n");
			scanf("%s",name);
			insertNode(&T, name);
			break;
			
		   case 3:
			printf("Enter the month name:\n");
			scanf("%s",name);
			removeNode(&T, name);
			break;
			
		   /*case 4:
			printf("Enter the level:\n");
			scanf("%d",&i);
			Display_Level(T, i,0);
			break;*/
			
		   case 4:
			inorder(T);
			break;
			
		   case 5:
			destroyTree(&T);
			break;
			
		   case 6:
			exit(1);
			break;
			
	     }
	}	
	return 0;
}
