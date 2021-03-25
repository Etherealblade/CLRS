// DP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <iostream>
using namespace std;

/*
for simplicity of the program, one extra row and
one extra column are allocated in m[][]. 0th and
0th are not used.
*/
int matrixChainOrder(int p[], int n)
{
	/*
	m[i,j] = Minimum number of scalar multiplications
	needed to compute the matrix A[i]A[i+1]...A[j] =
	A[i..j] where dimension of A[i] is p[i-1] * p[i]
	*/
	int **m = new int *[n];	// https://blog.csdn.net/u014546553/article/details/53644898
	for (int i = 0; i < n; i++)
		m[i] = new int[n];

	// cost is zero when multiplying one matrix
	for (int i = 1; i < n; i++)
	{
		m[i][i] = 0;
	}

	int j, q;
	// L is chain length
	for (int l = 2; l < n; l++)
	{
		for (int i = 1; i < n - l + 1; i++)
		{
			j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++)
			{
				q = m[i][k] + m[k + 1][j] +
					p[i - 1] * p[k] * p[j];

				if (q < m[i][j])
				{
					m[i][j] = q;
				}
			}
		}
	}

	return m[1][n - 1];
}



// Driver Code 
int main()
{
	int arr[] = { 30,35,15,5,10,20,25 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Minimum number of multiplications is "
		<< matrixChainOrder(arr, size) << endl;

	return 0;
}
