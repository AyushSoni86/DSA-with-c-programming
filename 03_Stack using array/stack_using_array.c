#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top >= (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    s->arr[0] = 7;
    s->top=s->top+1;
    s->arr[1] = 12;
    s->top=s->top+1;
    s->arr[2] = 12;
    s->top=s->top+1;
    s->arr[3] = 34;
    s->top=s->top+1;
    s->arr[4] = 23;
    s->top=s->top+1;
    // s->arr[5] = 54;
    // s->top=s->top+1;
    // s->arr[6] = 99;
    // s->top=s->top+1;
    // s->arr[7] = 99;
    // s->top=s->top+1;


    //     if (isEmpty(s))
    //     {
    //         printf("The stack is empty\n");
    //     }
    //     else
    //     {
    //         printf("The stack is not empty\n");
    //     }
    //     return 0;
    // }

    if (isFull(s) == 1)
    {
        printf("The stack is Full\n");
    }
    else
    {
        printf("The stack is not Full\n");
    }
    return 0;
}