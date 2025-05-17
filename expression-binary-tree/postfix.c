#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "postfix.h"
#include "tree.h"

node* top = NULL;

int isEmpty(){
    if (top == NULL)
        return 1;
    else
        return 0;
}

//Function to decide precedence of operators
int precedence(char symbol){ 
    switch(symbol){
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

//Function to identify spaces in input
int space(char c){         
    if (c == ' ' || c == 't')
        return 1;
    else
        return 0;
}

char pop()
{
    struct node*temp;
    char c;
    if (isEmpty(top))
    {
        printf("stack underflow");
        exit(1);
    }
    temp = top;
    c = temp->data;
    top = top->next;
    free(temp);
    temp = NULL;
    return c;
}


void push(char c){
    struct node*ptr = malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    ptr->data = c;
    ptr->next = top;
    top = ptr;
}

void print(char*postfix){
    int i = 0;
    printf("Postfix expression:\n");
    while(postfix[i]){
        printf("%c", postfix[i]);
        i++;
    }
    printf("\n");
}

char *infix_to_postfix(char *infix){
    int i = 0, j = 0, len = 0;
    char symbol, next;

    while (infix[i] != '\0')
    {
        i++;
        len++;
    }
    char*postfix = calloc(len,sizeof(char));
    for (i = 0; i<len;i++){
        symbol = infix[i];
        if (!space(symbol))
        {
            switch(symbol){
            case '(':
                push(symbol);  //push '(' in stack
                break;
            case ')':
                while ((next = pop()) != '('){
                     postfix[j] = next;   //pop all elements from stack until '('
                     j++;

                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!isEmpty() && precedence(top->data) >= precedence(symbol)){   //if precedence of infix operator is greater or equal then pop and if less then push
                    postfix[j] = pop();
                    j++;

                }
                push(symbol);
                break;
            default:
                postfix[j] = symbol;
                j++;

            }
        }

    }
    while (!isEmpty()){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
