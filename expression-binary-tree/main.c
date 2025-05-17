#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postfix.h"
#include "tree.h"

int main()
{
    int result;
    char *postfix;
    char infix[200];
    tree_node *T;
    
    printf("Enter the infix expression:");
    scanf("%[^\n]s",infix);

    postfix = infix_to_postfix(infix);
    //print(postfix);
    
    T = Inittree(postfix);
    printf("Inorder Traversal:\n");
    inorder(T);
    printf("\n");
    printf("\nFinal Result : %d\n", Compute(T));

    return 0;
}
