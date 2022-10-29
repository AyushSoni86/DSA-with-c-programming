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
int main()
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    printf("%d\n", isFull(sp));
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    push(sp,26);
    printf("%d\n", isFull(sp));

    return 0;
}