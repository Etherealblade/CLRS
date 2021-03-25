// https://www.geeksforgeeks.org/disjoint-set-data-structures/

#include <iostream>
#include "DisjointSet.h"
using namespace std;

int main()
{
	DisjSet obj(5);
	obj.Union(0, 2);
	obj.Union(4, 2);
	obj.Union(3, 1);

	if (obj.find(4) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";


	if (obj.find(1) == obj.find(0))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}