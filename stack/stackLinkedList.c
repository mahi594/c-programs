#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* next;
  
};

void LinkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *n= (struct Node *) malloc (sizeof(struct Node ));
    if(n==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
}

struct Node *push(struct Node *top,int x)
{
    if(isFull(top))
    {
       printf("stack overflow\n");
    }
    else{
         struct Node *n= (struct Node *) malloc (sizeof(struct Node ));
         n->data=x;
         n->next=top;
         top=n;
         return top;
    }
}

int pop(struct Node **top)
{
    if(isEmpty(*top))
    {
        printf("stack underflow");
        return -1;
    }
    else
    {
        struct Node *temp=*top;
        *top=(*top)->next;
        int x=temp->data;
        free(temp);
        return x;
    }
}

int peek(struct Node *top,int pos)
{
    struct Node *ptr=top;
    for(int i=0;(i<pos-1&&ptr!=NULL);i++)
    {
        ptr=ptr->next;

    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    return -1;
}

int stackTop(struct Node *top)
{
    return top->data;
}

int stackBottom(struct Node *top)
{
    struct Node *ptr=top;
     while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}




int main() 
{
    struct Node *top=NULL;
    top=push(top,7);
    top=push(top,8);
    top=push(top,9);
     LinkedListTraversal(top);
    int element=pop(&top);
    printf("popped elemenyt is: %d\n",element);
    LinkedListTraversal(top);
    for(int i=1;i<=3;i++)
    printf("value at position %d is:%d\n ",i,peek(top,i));
    printf("Stack top is: %d\n", stackTop(top));
    printf("Stack bottom is: %d\n", stackBottom(top));

    return 0;
  
}