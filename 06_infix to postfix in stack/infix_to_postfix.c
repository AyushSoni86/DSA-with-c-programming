#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !.\n %d element cannot be pushed. ", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow ! Connot pop element from the stack");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int IsOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

char *InfixToPostfix(char *infix)
{
    //initializing our stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // track infix traversal
    int j = 0; // track postfix addition

    while (infix[i] != '\0')
    {
        if (!IsOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(StackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a*b+k*f";
    printf("\nThe postfic conversion is %s \n\n", InfixToPostfix(infix));
    return 0;
}