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
    if (ptr->top == - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow ! Can't Pop.\n");
        return -1;
    }
    else
    {
        int val =ptr -> arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int main()
{
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size = 6;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    
    printf("%d\n", isEmpty(sp));
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    pop(sp);
    printf("%d\n", isEmpty(sp));

    return 0;
}