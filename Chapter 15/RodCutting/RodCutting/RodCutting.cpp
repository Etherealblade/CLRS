// RodCutting.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

#include <iostream>
#include <limits.h>
using namespace std;

// A utility function to get the maximum of two integers 
int max(int a, int b) {
	return (a > b) ? a : b;
}

/*
returns the best obtainable price for a rod of len n
and price[] s prices of different prices
*/
int rodCutting(int price[], int n)
{
	int *val = new int[n];
	val[0] = 0;

	/*
	build the table val[] in bottom up manner and
	return the last entry from the table
	*/
	for (int i = 1; i <= n; i++)
	{
		int max_val = INT_MIN;
		for (int j = 0; j < i; j++)
		{
			max_val = max(max_val,
				price[j] + val[i - j - 1]);
		}
		val[i] = max_val;
	}

	return val[n];
}

int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 18, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum Obtainable Value is %d\n", rodCutting(arr, size));
	getchar();
	return 0;
}
