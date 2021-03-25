// LCS.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
using namespace std;

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// returns len of LCS for x[0...m-1], Y[0...n-1]
int LCS(char *X, char *Y, int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (X[m - 1] == Y[n - 1])
	{
		return 1 + LCS(X, Y, m - 1, n - 1);
	}
	else
	{
		return max(LCS(X, Y, m, n - 1),
			LCS(X, Y, m - 1, n));
	}
}

// drive and test the code
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is " << LCS(X, Y, m, n) << endl;
}
