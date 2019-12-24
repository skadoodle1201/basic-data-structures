#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int array[5] = {64, 25, 12, 22, 11};		
	int length = 5;		
	int i, j;
	int temp;
	printf("Before Sorting array is : \n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}

	for(i = 0; i < (length -1); i++)
	{
		for (j=(i + 1); j < length; j++)
		{
			if (array[i] < array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	printf("\nSorted array: \n");
	for (i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}
