#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void Print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("  %d  ", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int value)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("\nThe queue is Full\n");
    }
    else
    {
        n->data = value;
        n->next = NULL; //because the element is added at the last position of the linked list
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int value = -1;
    struct node *ptr=f;
    if (f == NULL)
    {
        printf("The queue is Empty\n");
    }
    else
    {
        f = f->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}
int main()
{
    Print(f);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    enqueue(12);
    Print(f);
    printf("\nDequeued element is %d\n",dequeue());
    printf("Dequeued element is %d\n",dequeue());
    printf("Dequeued element is %d\n",dequeue());
    Print(f);
    return 0;
}