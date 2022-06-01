#include <stdio.h>
#include <stdlib.h>

struct cicularqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct cicularqueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct cicularqueue *q)
{
    if ((q->r+1)%q->size == q->f)
    {
        return 1;
    }
    return 0;
}

void encicularqueue(struct cicularqueue *q, int val)
{
    if (isFull(q))
    {
        printf("This cicularqueue is full\n");
    }
    else
    {    
        printf("enqueued element :%d\n",val);
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = val;
        
    }
}

int decicularqueue(struct cicularqueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This cicularqueue is empty\n");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct cicularqueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Encicularqueue few elements
    encicularqueue(&q, 12);
    encicularqueue(&q, 15);
    encicularqueue(&q, 1);
    // encicularqueue(&q, 5); we reservwe the space for the 0 
    printf("Dequeuing element %d\n", decicularqueue(&q));
    printf("Dequeuing element %d\n", decicularqueue(&q));
    printf("Dequeuing element %d\n", decicularqueue(&q));
    // printf("Dequeuing element %d\n", decicularqueue(&q));
    encicularqueue(&q, 32);
    encicularqueue(&q, 45);
    encicularqueue(&q, 1);

    if (isEmpty(&q))
    {
        printf("cicularqueue is empty\n");
    }
    if (isFull(&q))
    {
        printf("cicularqueue is full\n");
    }

    return 0;
}