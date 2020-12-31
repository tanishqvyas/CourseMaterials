#include <stdio.h>
#include <stdlib.h>


void printArray(int size, int arr[])
{
	printf("Input array is \n");

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}



void printReverseArray(int size, int arr[])
{
	printf("Reverse input array is \n");

	for (int i = size-1; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return;
}