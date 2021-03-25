// LCS_DP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int **L;

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns length of LCS for X[0...m-1], Y[0...n-1]
void LCS(char *X, char *Y, int m, int n)
{
	// Initialize L
	L = new int *[m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		L[i] = new int[n + 1];
	}

	/*
	following steps build L[m+1][n+1] in bottom up
	fashion. Note that L[i][j] contains length of LCS of
	X[0..i-1] and Y[0..j-1]
	*/
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				L[i][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1])
			{
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else
			{
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}

		}
	}

}

void printLCS(char *X, char *Y, int m, int n)
{
	int index = L[m][n];

	// Create a character array to store the lcs string
	char *lcs = new char[index + 1];
	lcs[index] = '\0';	// Set the terminating character 

	/*
	Store from the right-most & bottom-most corner and
	one by one store characters int lcs[]
	*/
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		/*
		If current character in X[] and Y[] are same, then
		current character is part of LCS
		*/
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1];	// Put current character in result
			i--;
			j--;
			index--;
		}
		else if (L[i - 1][j] > L[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}

	}

	cout << "LCS of " << X << " and "
		<< Y << " is " << lcs << endl;
	cout << "and length is: " << strlen(lcs) << endl;
}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);

	LCS(X, Y, m, n);
	printLCS(X, Y, m, n);
}

