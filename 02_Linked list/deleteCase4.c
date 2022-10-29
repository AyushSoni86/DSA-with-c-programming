#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void TraverseLinkedList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
}
struct node *DeletionAtValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->data != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {

        p->next = q->next;
        free(q);
    }
   
    return head;
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

    fifth->data = 47;
    fifth->next = NULL;

    printf("Linked list before deletion\n");
    TraverseLinkedList(head);
    head = DeletionAtValue(head, 3);
    printf("\nLinked list after deletion\n");
    TraverseLinkedList(head);

    return 0;
}