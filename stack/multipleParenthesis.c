#include<stdio.h>
#include<stdlib.h>

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



int paranthesisMatch(char *exp)
{
    //create and intialize stack
    struct stack*sp= (struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for(int i=0;exp[i]!='\0';i++)
    {
       if(exp[i]=='('|| exp[i]=='{'|| exp[i]=='[')
       {
          push(sp,exp[i]);
       }
       else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']')
       {
         if(isEmpty(sp))
         {
            return 0;
         }
         else{
            popped_ch=pop(sp);
            if(!match(popped_ch,exp[i]))
            {
               return 0;
            }
         }
       }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    
    else 
    return 0;
    free(sp->arr);
    free(sp);
}
 

int main()
{

    char exp[100];
    printf("Enter an expression: ");
    scanf("%s",exp);
    printf("expression is %s\n",exp);
    if(paranthesisMatch(exp))
    {
        printf("the paraenthesis is matching");
    }
    else
    {
        printf("the paraenthesis is not matching");
    }
    return 0;
    

    
}


