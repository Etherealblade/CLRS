#pragma once
class MinHeap
{
	int *harr;		// pointer to array of elements in heap 
	int capacity;	// maximum size of heap
	int heap_size;	// current number of elements in heap

public:

	// constructor 
	MinHeap(int);

	// to heapify a sbutree with the root at given index
	void MinHeapify(int);

	int parent(int);

	// to get index of left child of node at index i 
	int left(int);

	// to get index of right child of node at index i 
	int right(int);

	// to extract the root which is the minimum element 
	int extractMin();

	// Decreases key value of key at index i to new_val 
	void decreaseKey(int, int);

	// Returns the minimum key (key at root) from min heap 
	int getMin();

	// Deletes a key stored at index i 
	void deleteKey(int);

	// Inserts a new key 'k' 
	void insertKey(int);

};

