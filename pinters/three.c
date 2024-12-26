#include <stdio.h>
int main()
{
   char name[15];
   char *cptr=name;
   printf("Enter some word to find its length: \n");
   scanf("%s", name);
   while(*cptr!= '\0')
		cptr++;
   printf("length= %d",cptr-name);
   return 0;
}