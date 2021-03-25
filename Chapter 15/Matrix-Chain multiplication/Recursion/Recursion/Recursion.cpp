// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <iostream>
using namespace std;

/*
A naive recursive implementation,
Matrix Ai has dimension p[i-1] x p[i]
*/
int matrixChainOrder(int p[], int i, int j)
{
	if (i == j)
	{
		return 0;
	}

	int min = INT_MAX;
	int count;

	for (int k = i; k < j; k++)
	{
		count = matrixChainOrder(p, i, k) +
			matrixChainOrder(p, k + 1, j) +
			p[i - 1] * p[k] * p[j];

		if (count < min)
		{
			min = count;
		}
	}
	return min;
}


int main()
{
	int arr[] = { 30,35,15,5,10,20,25 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is: "
		<< matrixChainOrder(arr, 1, n - 1) << endl;

}

