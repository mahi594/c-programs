#include <stdio.h>
int main()
{
int  firstvalue = 5, secondvalue = 15;
 int * p1, * p2;
 p1 = &firstvalue; 	// p1 = address of firstvalue
 p2 = &secondvalue; // p2 = address of secondvalue
 *p1 = 10; 	// value pointed by p1 = 10
 *p2 = *p1;	 // value pointed by p2 = value pointed by p1
  p1 = p2;	 	// p1 now points to the same address as p2 (secondvalue)
 *p1 = 20; 	   // value pointed by p1 (which is secondvalue) = 20
printf("%dfirstvalue is\n ",firstvalue);
printf("%dsecondvalue is ",secondvalue);
    return 0;
}