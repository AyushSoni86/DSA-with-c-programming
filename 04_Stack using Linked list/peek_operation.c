#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("|__%d__|\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow !\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int peek(int pos)
{
    struct node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int main()
{

   
    printf("\n\n");
    top = push(top, 1); //  6
    top = push(top, 2); //  5
    top = push(top, 3); //  4
    top = push(top, 4); //  3
    top = push(top, 5); //  2
    top = push(top, 6); //  1
    // top = push(top, 7);
    // top = push(top, 8);
    // top = push(top, 9);

    LinkedListTraversal(top);
    printf("\n\n");
    printf("The Element at third position is %d \n", peek(3));
    return 0;
}