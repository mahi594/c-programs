#include<stdio.h>

int main()
{
int a[10],n,pos=0,ele;
scanf("%d",&n);
printf("enter the elements of array",n);
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);

}
printf("ele to insert");
scanf("%d",&ele);
for(int i=0;i<n;i++)  //finding pos
{
    if(ele<a[i])
    {
        break;
    }
    pos=i+1;
}
for(int i=n;i>=pos;i--)  //shifting ele
{
   a[i]=a[i-1];
   
}
a[pos]=ele;
   n=n+1;
for(int i=0;i<n;i++)
{
    printf("%d",a[i]);
}



}
