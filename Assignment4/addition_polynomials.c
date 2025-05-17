#include <stdio.h>
#include <stdlib.h>
#include "addition_polynomials.h"

struct polynomial {
    int coefficient;
    int exponent;
    struct polynomial*next;
};

struct polynomial* append(struct polynomial* head, int coefficient, int exponent)
{
    struct polynomial* temp;
    struct polynomial* newpoly = (struct polynomial*)malloc(sizeof(struct polynomial));
    newpoly->coefficient = coefficient;
    newpoly->exponent = exponent;
    newpoly->next = NULL;

    if (head == NULL || exponent > head->exponent){
        newpoly->next = head;
        head = newpoly;
    }
    else
    {
        temp = head;
        while (temp->next != NULL && temp->next->exponent >exponent){
            temp = temp->next;
        }
        newpoly->next = temp->next;
        temp->next = newpoly;

    }
    return head;
};


void display(struct polynomial*head)
{
    struct polynomial*ptr = malloc(sizeof(struct polynomial));

    if (head == NULL){
        printf("No polynomial");
    }
    else{
        ptr = head;
        while (ptr != NULL)
        {
            printf("(%dx^%d)", ptr->coefficient, ptr->exponent);
            ptr = ptr->next;
            if (ptr != NULL){
               printf("+");
            }
            else{
                printf("\n");
            }

        }
    }

}

struct polynomial* addpolynomials(struct polynomial* ptr1, struct polynomial* ptr2)
{
    struct polynomial*head = NULL;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->exponent == ptr2->exponent){
            head = append(head, ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

        }
        else if (ptr1->exponent > ptr2->exponent){
            head = append(head, ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        else if (ptr1->exponent < ptr2->exponent){
            head = append(head, ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1!= NULL)
    {
        head = append(head, ptr1->coefficient, ptr1->exponent);
        ptr1 = ptr1->next;
    }
    while(ptr1!= NULL)
    {
        head = append(head, ptr2->coefficient, ptr2->exponent);
        ptr2 = ptr2->next;
    }
    return head;
};


struct polynomial* init_polynomial(struct polynomial* p, char *s, int n)
{
    int ncoe = 0, nexp = 0, digit;
    char character;
    for (int i = 0 ; i <= n ; ++i){
        if (s[i] >= '0' && s[i] <= '9'){
            digit = s[i] - '0';
            ncoe = ncoe*10 + digit;
        }
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            character = s[i];
        }
        if (s[i] == '^'){
            character = s[i];
            i++;
            while (s[i] >= '0' && s[i] <= '9'){
            digit = s[i] - '0';
            nexp = nexp*10 + digit;
            i++;
            }
        }
        if (s[i] == ' '){
            character = s[i];
        }
        if (s[i] == '+'){
            character = s[i];
            p = append(p, ncoe, nexp);
            ncoe = 0;
            nexp = 0;
        }
     }
     p = append(p, ncoe, nexp);
     return p;
};
