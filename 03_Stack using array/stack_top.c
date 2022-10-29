#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

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

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow ! Can't Push %d \n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 16;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    // printf("%d\n", isFull(sp));
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    push(sp, 7);
    push(sp, 8);
    push(sp, 9);
    push(sp, 10);
    push(sp, 11);
    push(sp, 12);
    // printf("%d\n", isFull(sp));
   printf( "The top most element of the stack is %d\n",stackTop(sp));
    return 0;
}