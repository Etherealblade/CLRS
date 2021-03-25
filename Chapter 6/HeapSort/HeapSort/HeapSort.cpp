// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/heap-sort/ 

#include <iostream>
using namespace std;

/*
To  heapify a subtree rooted with node i which is
an index in arr[]. n is size of heap
*/
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// if left child is larger that than root
	if (l<n &&
		arr[l]>arr[largest])
	{
		largest = l;
	}

	// if right child is larger than largest so far
	if (r<n &&
		arr[r]>arr[largest])
	{
		largest = r;
	}

	// if largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}

}

void heapSort(int arr[], int n)
{
	// build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		// 这句有意思, 书中有说明
	{
		heapify(arr, n, i);
	}

	// one by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/*
An utility func to print array of size n
*/
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

// driver program 
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, n);

	cout << "Sorted array is \n";
	printArr(arr, n);
}

