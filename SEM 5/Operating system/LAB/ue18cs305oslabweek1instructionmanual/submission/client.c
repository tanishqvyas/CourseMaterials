#include "header.h"

int main()
{
	int size;
	printf("Enter size of the array : ");
	scanf("%d", &size);

	int myArray[size];

	printf("Enter the elements of array : \n\n");
	for (int i = 0; i < size; ++i)
	{
		scanf("%d", &myArray[i]);
	}


	printArray(size, myArray);	
	printReverseArray(size, myArray);


	return 0;
}