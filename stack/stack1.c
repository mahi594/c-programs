#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
};

int isEmpty(struct stack  *ptr)
{
    if(ptr->top==-1)
    {
       return 1;
    }
    else{
        return 0;
    }
}



int isfull(struct stack  *ptr)
{
    if(ptr->top==ptr->size-1)
    {
         return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, int value)
{
    if(isfull(ptr))
    {
        printf("stack full");
        return ;

    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=value;

    }
}

int  pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack underflow !cannot pop");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp,int i)
{
    int arrInd=sp->top-i+1;
    if(arrInd<0||arrInd>sp->top)
    {
        printf("incalid position");
        return -1;
    }
    else{
       return sp->arr[arrInd];   
    }
}

int stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}

int stackBottom(struct stack* sp)
{
    return sp->arr[0];
}
 

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }

    push(s, 30);
    push(s, 31);
    push(s, 32);
    push(s, 33);
    push(s, 34);
    push(s, 35);
    push(s, 36);

    printf("Pop element is %d\n", pop(s));
    printf("Pop element is %d\n", pop(s));

    if (isEmpty(s))
    {
        printf("After popping, the stack is empty\n");
    }
    else
    {
        printf("After popping, the stack is not empty\n");
    }

    for(int i=0;i<s->top+1;i++)
    {
        printf("the value at position %d id %d\n ",i,peek(s,i+1)); 
    }

    printf("top element is %d\n",stackTop(s));
    printf("bottom element is %d\n",stackBottom(s));

    // Free allocated memory
    free(s->arr);
    free(s);

    return 0;

}


