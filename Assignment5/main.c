#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "postfix.h"

int main()
{
    int result;
    char *postfix;
    char *infix = calloc(1,sizeof(char));
    printf("Enter the infix expression:");
    scanf("%[^\n]s",infix);

    postfix = infix_to_postfix(infix);
    print(postfix);

    result  = postfix_evalution(postfix);
    printf("Result of the expression:\n");
    printf("%d", result);

    return 0;
}
