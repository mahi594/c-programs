#include <stdio.h>		
int main()
{
      int var1 = 11; 
 	int var2 = 22; 
 	int var3 = 33;

//print the addresses of these variables
	 printf("%d   ",&var1);      
	 printf("%x   ",&var2);
	 printf("%x   ",&var3);
  
  


int quantity, *p, n;     // 2 int variables & 1 integer pointer 
quantity =50;              // assigns value 50 to quantity
p=&quantity;           // assigns the address of quantity to p
n=*p; 
printf("%d",n); 

return 0;
}