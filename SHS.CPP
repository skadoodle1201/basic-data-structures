
#include <iostream> 
#include <stdio.h>
using namespace std; 


int shellSort(int arr[], int n) 
{ 
	
	for (int gap = n/2; gap > 0; gap /= 2) 
	{ 
		for (int i = gap; i < n; i += 1) 
		{  
			int temp = arr[i]; 

			int j;			 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 
			
			
			arr[j] = temp; 
		} 
	} 
	return 0; 
} 

void printArray(int arr[], int n) 
{ 
	for (int i=0; i<n; i++) 
		printf("%d  ", arr[i]);
} 

int main() 
{ 
	int arr[] = {12, 34, 54, 2, 3}, i; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	printf("Before Sorting array is : \t");
	printArray(arr, n); 

	shellSort(arr, n); 

	printf("\nSorted array is : \t"); 
	printArray(arr, n); 

	return 0; 
} 
