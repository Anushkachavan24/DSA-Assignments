#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"


int main()
{
    int choice;
	while(1)
	{
		printf("1. Initialize the tree\n");
		printf("2. Add a new node to the tree\n");
		printf("3. Remove a node from a tree\n");
		printf("4. Search for a node\n");
		printf("5. Postorder Traversal\n");
		printf("6. Display all nodes of ith order\n");
		printf("7. Delete all the nodes from tree\n");
		printf("8. Inorder TraversaL\n");
		printf("9. Exit\n");

		printf("\n");
		printf("Enter your choice : ");

		scanf("%d",&choice);
		BST T1;

		int N, MIS, rem, ser, level;

		switch(choice)
		{
		      case 1:
                          init(&T1);
			  break;
		      case 2:
                          printf("Enter the number of elements:");
                          scanf("%d", &N);
                          while(N != 0){
                               char name[40];
                               printf("Enter the MIS No:");
                               scanf("%d", &MIS);
                               while(getchar()!='\n');
                               printf("Enter the Name:");
                               scanf("%[^\n]s",name);
                               T1 = insert_node(T1, MIS, name);
                               while(getchar()!='\n');
                               N--;
                          }
		          break;
		      case 3:
			  printf("Enter the element to be removed:");
			  scanf("%d", &rem);
			  removenode(T1, rem);
			  break;
		      case 4:
			  printf("Enter the element to be search:");
			  scanf("%d", &ser);
		          printf("\nfound /not found %d\n", searchnode(T1, ser));
		          break;
		      case 5:
			  printf("Postorder traversal:\n");
                          postorder(T1);
			  break;
                      case 6:
                          printf("Enter the level:");
                          scanf("%d", &level);
                          Display_Level(T1, 0, level);
                          printf("\n");
                          break;
                      case 7:
                          destroyTree(T1);
                          printf("Tree is deleted\n");
                          printf("\n");
                          break;
                      case 8:
                          inorder(T1);
                          printf("\n");
                          break;
		      case 9:
		          exit(1);
		      default:
			  printf("Wrong choice\n");
		}
	}
    return 0;
}
