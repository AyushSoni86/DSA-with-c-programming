#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void printlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}
struct node *First(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = ptr;
    ptr->next = head;
    return head;
}

struct node *Last(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = ptr;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr->next;
    ptr->next = NULL;

    return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    head = First(head, 10);
    head = Last(head, 12);
    printlist(head);
    return 0;
}