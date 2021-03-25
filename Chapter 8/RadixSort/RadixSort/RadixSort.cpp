// RadixSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/radix-sort/

#include <iostream>
using namespace std;

// an utility function to get max value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
		}
	}

	return mx;
}

/*
a func to do counting sort of arr[] according
to the digit represented by exp
*/
void countingSort(int arr[], int n, int exp)
{
	int *output = new int[n];		// output array s
	int count[10] = { 0 };

	// sort count of occurrences in count[]
	for (int i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	/* 
	change count[i] so that count[i] now contains actual
	position of this digit in output[]
	*/
	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}

	// build the output array
	for (int i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	/*
	copy the output array to arr[], so that arr[] now
	contains sorts numbers according to current digit
	*/
	for (int i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

/*
the main func to that sorts arr[] of size n using
Radix sort
*/
void radixSort(int arr[], int n)
{
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n);

	/*
	do counting sort for every digit. Note that instead
	of passing digit number, exp is passed. exp is 10^i
	where i is current digit number.
	*/
	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		countingSort(arr, n, exp);
	}
}

// A utility function to print an array 
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// drive and test the code
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	print(arr, n);
	return 0;
}
