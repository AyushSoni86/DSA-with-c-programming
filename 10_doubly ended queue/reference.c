#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct Queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("\nQueue overflow !\n Cannot insert %d to the queue\n", value);
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
        printf("| %d  ", value);
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The queue is empty.\n");
        return 0;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main()
{
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // enqueue(&q, 12);
    // enqueue(&q, 1);
    // enqueue(&q, 116);
    // enqueue(&q, 212);

    // printf("\nThe Dequeued element is %d\n",dequeue(&q));
    // printf("The Dequeued element is %d\n",dequeue(&q));
    // printf("The Dequeued element is %d\n",dequeue(&q));
    // printf("The Dequeued element is %d\n",dequeue(&q));
    enqueue(&q, 312);
    enqueue(&q, 211);
    enqueue(&q, 16);
    enqueue(&q, 22);
    enqueue(&q, 152);
    enqueue(&q, 100);
    enqueue(&q, 567);
    enqueue(&q, 434);
    enqueue(&q, 512);
    enqueue(&q, 410);
    enqueue(&q, 1410);
    
    if (isEmpty(&q))
    {
        printf("The Queue is Empty.\n");
    }
    if (isFull(&q))
    {
        printf("\nThe Queue is Full.\n");
    }

    return 0;
}