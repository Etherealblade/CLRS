// MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/binary-heap/ 

#include <iostream>
#include "MinHeap.h"
using namespace std;

// Driver program to test above functions 
int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}