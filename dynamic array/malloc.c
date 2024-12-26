#include <stdio.h>
#include <stdlib.h>


int main()
{
	//Creating the int pointer to store the address  return by malloc
	int *ptr=NULL;

	//Declaring the variable i for array index to use in for loop
	//to access the array elements. len will be used to calculate
	//size of array and in for loop condition.
	int i,len=0;

	//Prompt user to enter the size of array
	printf("ENTER THE SIZE OF ARRAY:");

//Reading the array size and storing in len variable 
	scanf("%d",&len);

	//allocating the dynamic memory and store the address
	//returned by malloc. malloc returns address keeping in 
	//void pointer. Since, we want to store int type of 
	//data so, type cast it into int pointer.
	//
	ptr=(int*)malloc(len*sizeof(int));
//Ask the user to enter all the elements
	printf("ENTER THE ELEMENTS:");
	//assigning the  values to the array
	for(i=0;i<len;++i){
		//write the values in memory location
		scanf("%d", &ptr[i]);
	}

	//Read the values from the memory location and 
	//display on the screen
	
	printf("Array elements are \n");
	for(i=0;i<len;++i)
	{		
		printf("%d,", ptr[i]);
	}

	// free the memory
	free(ptr);
	return 0;
}
