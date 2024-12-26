#include<stdio.h>

int main()
{
int a[10],b[10],c[10],n,m,pos,ele;
scanf("%d",&n);
printf("enter the elements of array",n);
scanf("%d",&m);
printf("enter the elements of array",m);
for(int i=0;i<n;i++)
{
    scanf("%d",&a[i]);

}
for(int i=0;i<m;i++)
{
    scanf("%d",&b[i]);
}
if(m==n)
{
    for(int i=0;i<n;i++)
    {
      c[i]=a[i]+b[i];
      printf("%d",c[i]);
    }
    
}
else
printf("elements can not be add");

}
