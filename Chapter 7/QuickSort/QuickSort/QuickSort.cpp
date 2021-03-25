// QuickSork.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/quick-sort/ 

#include <iostream>
using namespace std;

// A utility function to swap two elements  
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
This func takes last element as pivot, places the pivot
at its correct position in sorted array, and places all
smaller elements to left of pivot and all greater elements
to right of pivot.
*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// pivot
	int i = (low - 1);		// index of smaller element

	for (int j = low; j <= high - 1; j++)
		// 这里经常容易错:把j写成i
	{
		// if current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++;	// increment index of smaller elements
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
The main func that implements QuickSort
arr[]->Array to be sorted,
low->Starting index,
high->Ending index
*/
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/*
		p is partitioning index, index p contains
		the corresponding element after calling partition
		*/
		int p = partition(arr, low, high);

		// separately sort elements before p and after p
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// drive&test the code
int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

