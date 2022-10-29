#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

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
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow !,\nPop cannot be performed\n");
    }
    else
    {
        struct node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        printf("Pop operation performed successfully ! :) \n");
        return x;
    }
}
int main()
{
    struct node *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    // top = push(top, 6);
    printf("\n\n");

    LinkedListTraversal(top);
    printf("\n\n");

    //  printf("Pop operation performed successfully ! :) \n");
    int element = pop(&top);
    LinkedListTraversal(top);
    printf("\n\n");

    printf("The popped element is %d \n", element);
    printf("\n\n");

    return 0;
}