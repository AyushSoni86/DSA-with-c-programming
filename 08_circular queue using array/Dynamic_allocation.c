#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circular_queue *cq)
{
    if (cq->r == cq->f)
    {
        return 1;
    }
    return 0;
}
int isFull(struct circular_queue *cq)
{
    if ((cq->r + 1) % (cq->size)==cq->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct circular_queue *cq, int value)
{
    if (isFull(cq))
    {
        printf("Queue overflow !\nThe circular queue is full.\n");
    }
    else
    {
        cq->r = (cq->r + 1) % cq->size;
        cq->arr[cq->r] = value;
         printf("|  %d  |", value);
    }
}
int dequeue(struct circular_queue *cq)
{
    int a = -1;
    if (isEmpty(cq))
    {
        printf("Queue Underflow!\n The circular queue is empty\n");
    }
    else
    {
        cq->f = (cq->f + 1) % cq->size;
        a = cq->arr[cq->f];
    }
}
int main()
{
    struct circular_queue *q;
    q=(struct circular_queue *)malloc(sizeof(struct circular_queue ));
    q->size = 1+15;
    q->f = q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("\ndequeued element is %d\n", dequeue(q));
    printf("dequeued element is %d\n", dequeue(q));
    printf("dequeued element is %d\n", dequeue(q));
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    printf("\ndequeued element is %d\n", dequeue(q));
    printf("dequeued element is %d\n", dequeue(q));

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    return 0;
}