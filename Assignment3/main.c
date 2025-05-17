#include <stdio.h>
#include <stdlib.h>
#include "Assignment_3.h"

struct node{
    struct node*previous;
    int data;
    struct node*next;
};

int main()
{
    struct node*head = NULL;
    int N, number, i;
    printf("Enter the number of elements:\n");
    scanf("%d", &N);
    if (N != 0){
        printf("Enter the number:\n");
        scanf("%d", &number);
        head = Append_to_empty(head, number);
        for (int i =2; i<=N;i ++){
        scanf("%d", &number);
        Append(head, number);
        }
    }
    else{
        head = NULL;
        printf("Empty list\n");

    }


    printf("list before operation:\n");
    linklisttraversal(head);


    int opinion = 1;
    int choice, node, num;
    do
    {
        printf("Choose the operation that you want to perform:\n");
        int n = 0;
        printf("%d. Reverse the list\n", n+1);
        printf("%d. Insert at front\n", n+2);
        printf("%d. Insert at node\n", n+3);
        printf("%d. Insert at end\n", n+4);
        printf("%d. Insert after node\n", n+5);
        printf("%d. Delete at front\n", n+6);
        printf("%d. Delete the node\n", n+7);
        printf("%d. Delete at end\n", n+8);
        printf("%d. Delete after node\n", n+9);
        printf("%d. Delete the number\n", n+10);
        printf("%d. Search\n", n+11);

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Reverse list:\n");
                reverseList(&head);
                linklisttraversal(head);
                break;
            case 2:
                printf("Enter the number:\n");
                scanf("%d", &num);
                head = insert_first(head,num);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 3:
                printf("Enter the number:\n");
                scanf("%d", &num);
                printf("Enter the node you want to insert:\n");
                scanf("%d", &node);
                insert_between(head, num, node);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 4:
                printf("Enter the number:\n");
                scanf("%d", &num);
                head = insert_end(head, num);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 5:
                printf("Enter the number:\n");
                scanf("%d", &num);
                printf("Enter the node you want to insert:\n");
                scanf("%d", &node);
                insert_after(head, node, num);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 6:
                head = delete_first(head);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 7:
                printf("Enter the node you want to delete:\n");
                scanf("%d", &node);
                head = delete__between_element(head, node);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 8:
                head = delete_last_element(head);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 9:
                printf("Enter the node you want to delete:\n");
                scanf("%d", &node);
                head = delete_after_element(head, node);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 10:
                printf("Enter the number:\n");
                scanf("%d", &num);
                deleteNode(&head, num);
                printf("List after operation:\n");
                linklisttraversal(head);
                break;
            case 11:
                printf("Enter the number which you want to search:\n");
                scanf("%d", &num);
                head = search_element(head, num);
                if (head != 1){
                printf("Element is not found\n");
                }
                linklisttraversal(head);
                break;
            default:
                printf("You have not chosen the given operation\n");
        }
        printf("would you like to try again? (1/0)\n");
        scanf("%d", &opinion);
    }
    while(opinion == 1);


    return 0;
}
