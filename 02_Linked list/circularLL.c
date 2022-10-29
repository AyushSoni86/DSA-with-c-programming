#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void TraverseLinkedList(struct node *ptr)
{
    int head;
    do
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node *));
    second = (struct node *)malloc(sizeof(struct node *));
    third = (struct node *)malloc(sizeof(struct node *));
    fourth = (struct node *)malloc(sizeof(struct node *));
    fifth = (struct node *)malloc(sizeof(struct node *));

    head->data = 7;
    head->next = second;

    second->data = 17;
    second->next = third;

    third->data = 27;
    third->next = fourth;

    fourth->data = 37;
    fourth->next = fifth;
dgh
    fifth->next = head;
dgh
    fifth->data = 47;
    fifth->next = head;
    fifth->next = head;
    TraverseLinkedList(head);
    return 0;
}