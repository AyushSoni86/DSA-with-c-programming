#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack overflow !\n %d cannot be pushed.\n", value);
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
        printf("Stack Underflow !\nElement cannot be popped.\n");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int Match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int Multiple_PM(char * exp)
{
    struct stack *sp;
    sp->top = -1;
    sp->size = 20;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_char = pop(sp);
            if (!Match(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "[][{[{}6*(56)34]}]";
    if (Multiple_PM(exp))
    {
        printf("\nParenthesis are matching successfully\n\n");
    }
    else
    {
        printf("\nParenthesis are not matching\n\n");
    }

    return 0;
}