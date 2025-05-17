#include <stdio.h>
#include <stdlib.h>
#include "addition_polynomials.h"


int main()
{
    int i= 0, n =0, len1 = 0, len2 =0;
    struct polynomial*p1 = NULL;
    struct polynomial*p2 = NULL;
    struct polynomial*result = NULL;
    printf("Enter the polynomial 1:\n");
    char *str1 = calloc(1,sizeof(char));
    char *str2 = calloc(1,sizeof(char));
    scanf("%[^\n]s",str1);
    while (str1[i] != '\0')
    {
        i++;
        len1++;
    }

    p1 = init_polynomial(p1, str1, len1);
    while(getchar()!='\n');

    printf("Enter the polynomial 2:\n");
    scanf("%[^\n]s",str2);


    while (str2[n] != '\0')
    {
        n++;
        len2++;
    }

    p2 = init_polynomial(p2, str2, len2);
    result = addpolynomials(p1, p2);
    printf("Addition of polynomials:\n");
    display(result);


    return 0;
}
