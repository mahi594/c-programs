#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q)
{
    if(q->r==q->size-1)
    return 1;
    else
    return 0;
}


int isempty(struct queue *q)
{
    if(q->r==q->f)
    return 1;
    else
    return 0;
}

void enqueue(struct queue *q,int value)
{
    if(isfull(q))
    {
        printf("queue overflow");
    }
    else{
       q->r++;
       q->arr[q->r]=value; 
    }
}

int dequeue(struct queue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("underflow");
    }
    else{
        q->f++;
        a=q->arr[q->f];

    }
    return a;
}

int main()
{
    struct queue q;
    q.size=100;
    q.f=q.r=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));

    if(isempty(&q))
    {
         printf("is empty\n");
    }
    
    //enqueue
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,13);
    enqueue(&q,14);

    printf("dequeing element %d\n",dequeue(&q));
    printf("dequeing element %d\n",dequeue(&q));

    return 0;
}