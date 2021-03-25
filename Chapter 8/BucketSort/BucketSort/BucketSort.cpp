// BucketSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/bucket-sort-2/ 

#include <iostream>
#include <algorithm> 
#include <vector> 
using namespace std;

// func to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n)
{
	// 1. create n empty buckets 
	vector<float> *b = new vector<float>[n];	// 此行有点意思

	// 2. put array elements in different buckets
	for (int i = 0; i < n; i++)
	{
		int bi = n * arr[i];	// index i bucket
		b[bi].push_back(arr[i]);
	}

	// 3. sort individual buckets
	for (int i = 0; i < n; i++)
	{
		sort(b[i].begin(), b[i].end());
	}

	// 4. concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			arr[index++] = b[i][j];
		}
	}
}

int main()
{
	float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

