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
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct node *DeletionAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

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
    head = DeletionAtIndex(head, 2);
    printf("\nLinked list after deletion\n");
  
    TraverseLinkedList(head);

    return 0;
}