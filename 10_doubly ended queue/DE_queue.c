#include <stdio.h>
#include <stdlib.h>

struct DE_queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct DE_queue *q)
{
    if (q->f == q->r)
        return 1;
    return 0;
}

int isFull(struct DE_queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

void enqueueF(struct DE_queue *q, int value)
{
    if (isFull(q))
    {
        printf("The queue is Full\n");
    }
    else
    {
        if (q->f == -1)
        {
            printf("cannot insert %d \n", value);
        }
        else
        {
            q->arr[q->f] = value;
            q->f--;
            // printf("| %d |", value);
        }
    }
}

void enqueueR(struct DE_queue *q, int value)
{
    if (isFull(q))
    {
        printf("The queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
        //  printf("| %d |", value);
    }
}

int dequeueF(struct DE_queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int dequeueR(struct DE_queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty\n");
    }
    else
    {
        a = q->arr[q->r];
        q->r--;
    }
    return a;
}

void print(struct DE_queue *q)
{
    if (isEmpty(q))
    {
        printf("\nThe queue is empty\n");
    }
    else
    {
        printf("\nThe queue is : ");
        for (int i = (q->f + 1); i <= q->r; i++)
        {
            printf("  %d  ", q->arr[i]);
        }
    }
}

int main()
{
    struct DE_queue q;
    q.size = 20;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueueR(&q, 18);
    enqueueR(&q, 8);
    enqueueR(&q, 14);
    enqueueR(&q, 33);

    print(&q); //printing the queue

    printf("\nDequeued element from front is %d\n", dequeueF(&q));
    printf("Dequeued element from front is %d\n", dequeueF(&q));
    printf("Dequeued element from front is %d\n", dequeueF(&q));

    print(&q); //printing the queue

    enqueueF(&q, 15);
    enqueueF(&q, 29);

    print(&q); //printing the queue

    printf("\nDequeued element from Rear is %d\n", dequeueR(&q));
    printf("Dequeued element from Rear is %d\n", dequeueR(&q));

    print(&q); //printing the queue

    enqueueR(&q, 15);
    enqueueR(&q, 29);

    print(&q); //printing the queue

    printf("\nDequeued element from front is %d\n", dequeueF(&q));
    printf("Dequeued element from front is %d\n", dequeueF(&q));
    printf("Dequeued element from front is %d\n", dequeueF(&q));

    print(&q); //printing the queue
    return 0;
}