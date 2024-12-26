#include <stdio.h>
#include <stdlib.h>

struct Queue *f=NULL;
struct Queue *r=NULL;

struct Queue
{
    int data;
    struct Queue *next;
};

void linkedListTraversal(struct Queue *ptr)
{
    printf("printing the elements of linked list");
    while(ptr!=NULL)
    {
        printf("elements: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue( int value)
{
    struct Queue *n=(struct Queue*)malloc(sizeof(struct Queue));
    if(n==NULL)
    {
         printf("queue is full");
    }
    else{
        n->data=value;
        n->next=NULL;
        if(f==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue()
{
    int value=-1;
   struct Queue *ptr=f;
    if(f==NULL)
    {
         printf("queue is empty");
    }
    else
    {
       f=f->next;
       value= ptr->data;
       free(ptr);
       
    } 
    return value;
}
int main()
{
    
    linkedListTraversal(f);
    enqueue(12);
    enqueue(13);
    enqueue(14); 
    enqueue(15); 
    enqueue(16); 
    enqueue(17); 
    enqueue(18); 
     linkedListTraversal(f);
     printf("deleted element is %d\n",dequeue());
}
