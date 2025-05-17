#include <stdio.h>
#include <stdlib.h>
#include "Assignment_3.h"

struct node{
    struct node*previous;
    int data;
    struct node*next;
};

void linklisttraversal(struct node*ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr ->data);
        ptr = ptr ->next;
    }
}

void reverseList(struct node **head)
{
    struct node *p = NULL;
    struct node *q = *head;
    while (q != NULL)
    {
        p = q->previous;
        q->previous = q->next;
        q->next = p;
        q = q->previous;
    }
    if(p != NULL )
        *head = p->previous;
}

struct node* Append_to_empty(struct node*head, int number)
{
    struct node*p = (struct node*)malloc(sizeof(struct node));
    p->previous = NULL;
    p->data = number;
    p->next = NULL;
    head = p;
    return head;
};

void Append(struct node*head, int number)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*p = head;
    struct node*q = head->next;
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->previous = p;
    ptr->data = number;
    ptr->next = NULL;
};

void insert_after(struct node*head, int after, int number)
{
    struct node*t = head;
    for(int i=0;i<after;i++)
    {
        t = t->next;
        if(t == NULL)
        {
            printf("There are less than %d elements\n", after);
            return head;
        }
    }
    if (head == NULL){
        printf("Empty list\n");
    }
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*p = head;
    struct node*q = head->next;
    int i = 1;
    while (i != after)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = ptr;
    ptr->data = number;
    ptr->previous = p;
    ptr->next = q;
};

void insert_between(struct node*head, int number, int index)
{
    if (head == NULL){
        printf("Empty list\n");
    }
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*t = head;
    struct node*p = head;
    struct node*q = head->next;

    for(int i=0;i<index;i++)
    {
        t = t->next;
        if(t == NULL)
        {
            printf("There are less than %d elements\n", index);
            return;
        }
    }
    int i = 1;
    while (i != (index-1))
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = ptr;
    ptr->data = number;
    ptr->previous = p;
    ptr->next = q;
};

struct node* insert_end(struct node*head, int number)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        ptr->next = NULL;
        ptr->previous = NULL;
        ptr ->data = number;
        head = ptr;

    }
    else{
        struct node*ptr = (struct node*)malloc(sizeof(struct node));
        struct node*p = head;
        struct node*q = head->next;
        while (q != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = ptr;
        ptr->previous = p;
        ptr->data = number;
        ptr->next = NULL;
    }
    return head;

};

struct node* insert_first(struct node*head, int number)
{
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
       ptr->next = NULL;
       ptr->previous=NULL;
       ptr->data=number;
    }
    else{
        ptr->next = head;
        head->previous = ptr;
        ptr->data = number;
        ptr->previous = NULL;
    }
    return ptr;
};

struct node* delete_first(struct node*head)
{
    if(head == NULL)
    {
        printf("Empty list\n");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("node deleted\n");
    }
    else{
        struct node*p = head;
        head = head->next;
        free(p);
        return head;
    }
}

struct node* delete_last_element(struct node*head){
    if(head == NULL)
    {
        printf("Empty list\n");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("node deleted\n");
    }
    else{
        struct node*ptr = (struct node*)malloc(sizeof(struct node));
    struct node*p = head;
    struct node*q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p ->next = NULL;
    free(q);
    return head;
    }


};

struct node* delete__between_element(struct node*head, int index){
    struct node*t = head;
    for(int i=0;i<index;i++)
    {
        t = t->next;
        if(t == NULL)
        {
            printf("There are less than %d elements\n", index);
            return head;
        }
    }
    if(head == NULL)
    {
        printf("Empty list\n");
    }
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    int i = 1;
    struct node*p = head;
    struct node*q = head->next;
    while (i < index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    ptr = q->next;
    ptr->previous = p;
    free(q);
    return head;

};

struct node* delete_after_element(struct node*head, int index){
    struct node*t = head;
    for(int i=0;i<index;i++)
    {
        t = t->next;
        if(t == NULL)
        {
            printf("There are less than %d elements\n", index);
            return head;
        }
    }
    if (head == NULL){
        printf("Empty list\n");
    }
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    int i = 1;
    struct node*p = head;
    struct node*q = head->next;
    while (i < index)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    ptr = q->next;
    ptr->previous = p;
    free(q);
    return head;

};

void deleteNode(struct node** head, int number)
{
    struct node *p = *head, *q;
    if (p != NULL && p->data == number) {
        *head = p->next;
        free(p);
        return;
    }
    while (p != NULL && p->data != number) {
        q = p;
        p = p->next;
    }
    if (p == NULL){
        printf("number is not present in list\n");
        return;
    }
    q->next = p->next;
    free(p);
}


struct node* search_element(struct node*head, int number){
    struct node*p = head;
    int i = 1;
    if (head == NULL){
        printf("Empty list\n");
    }
    while (p != NULL)
    {
        if (p->data == number)
        {
            printf("%d is present at %d node", number, i);
            return 1;

        }
        i++;
        p = p->next;
    }
};



