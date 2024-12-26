#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int top;
    char *arr;
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
        ptr->arr[ptr->top]=value;  //arr is the struct array ptr is pointer ptr->top shows the top index value of arrray

    }
}

char  pop(struct stack* ptr)
{
    if(isEmpty(ptr))
    {
        printf("stack underflow !cannot pop");
        return '\0';
    }
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}

int match(char a,char b )
{
   if(a=='{'&&b=='}')
   {
    return 1;
   }
    if(a=='('&&b==')')
   {
    return 1;
   } 
    if(a=='['&&b==']')
   {
    return 1;
   } 
   return 0; 
   
}

int precedence(char ch)
{
    if(ch=='*'||ch=='/')
    {
        return 3;
    }
    else if(ch=='+'||ch=='-')
    {
        return 2;
    }
    else
    return 0;

}

int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
       return 1;
    }
    else 
    {
        return 0;
    }
}

char *infixToPostfix(char * infix)
{
    struct stack*sp=(struct stack*)malloc(sizeof(struct stack)); ;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));   //infix array

    char* postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));   //postfix array

    int i=0;  //track infix traversal
    int j=0;  //track postfix traversal
    
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
        while(!isEmpty(sp))
        {
            postfix[j]=pop(sp);
            j++;
        }
        postfix[j]='\0';
        return postfix;
    
}


 

int main()
{

char *infix="a-b+t/6";
printf("postfix is %s \n",infixToPostfix(infix));
return 0;
    
    
}


