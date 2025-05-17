#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "Array.h"
#include "postorder.h"

int main(){
    // PART-I
    printf("Part-I");
    printf("\n");

    int num, d, H, Max, i = 0;
    node* t = NULL;
    printf("Enter the number of elements to be inserted:");
    scanf("%d", &num);
    int num1 = num;
    int arr[num];
    while(num > 0){
       scanf("%d", &d);
       while(getchar()!='\n');
       arr[i] = d;
       i++;
       t = insert_node(t, d);
       num--;
    }
    i = 0;
    H = height_BST(t);
    Max = max_nodes(H);
    int A[Max];
    init_bst(A, Max);
    while(num1 > 0){
       insert_bst(A, Max, 0, arr[i]);
       i++;
       num1--;
    }
    printf("Preorder Traversal:\n");
    preorder(A, 0, Max);
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(A, 0, Max);
    printf("\n");
    printf("Inorder Traversal:\n");
    inorder(A, 0, Max);
    printf("\n");
    
    //PART-II
    printf("Part-II");
    printf("\n");
    
    int N, data;
    printf("Enter the number of elements in postorder traversal:");
    scanf("%d", &N);
    int postorder[N], n = 0;
    int start = 0, end = N;
    node *BST = NULL;
    printf("Enter the numbers in postorder traversal:\n");
    while(N > 0){
       printf("Enter the number:");
       scanf("%d", &data);
       postorder[n] = data;
       n++;
       N--;
    }
    BST = createBST(postorder, start, end-1);
    printf("Inorder Travesrsal:\n");
    Inorder_traversal(BST);
    return 0;
}
