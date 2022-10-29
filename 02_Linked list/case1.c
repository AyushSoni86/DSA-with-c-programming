// Insertion at the Head node

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// function to print/traverse our linked list
void TraverseLinkedList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
// case 1
struct node *InsertionAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->data = data;
    ptr->next = head;

    return ptr;
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
    printf("Linked list before insertion\n");
    TraverseLinkedList(head);
    head = InsertionAtFirst(head, 14);
    printf("\nLinked list after insertion\n");
    TraverseLinkedList(head);

    return 0;
}