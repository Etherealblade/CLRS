#pragma once

class DisjSet
{
public:
	DisjSet(int);	// Constructor
	void makeSet();
	int find(int);
	void Union(int, int);

private:
	int *rank, *parent, n;
};

