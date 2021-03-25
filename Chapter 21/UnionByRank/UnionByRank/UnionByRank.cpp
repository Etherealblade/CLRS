// UnionByRank.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/

#include <iostream>
#include "E:\Project\VC\CLRS\Chapter 21\UnionFind\UnionFind\Graph.h"

struct subset
{
	int parent;
	int rank;	// significant
};

// Creates a graph with V vertices and E edges
Graph* createGraph(int V, int E)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->E = E;

	graph->edge = (Edge*)malloc(graph->E * sizeof(Edge));

	return graph;
}

/*
A utility func to find set of an element i
using path compression technique
*/
int Find(subset subsets[], int i)
{
	// Find root and make root as parent of i (path compression)
	if (subsets[i].parent != i)
	{
		subsets[i].parent = Find(subsets,
			subsets[i].parent);

	}

	return subsets[i].parent;
}

/*
A func that does union of 2 sets of x and y
using union by rank
*/
void Union(subset subsets[], int x, int y)
{
	int xroot = Find(subsets, x);
	int yroot = Find(subsets, y);

	/*
	Attach smaller rank tree under root of high rank tree
	(Union by Rank)
	*/
	if (subsets[xroot].rank < subsets[yroot].rank)
	{
		subsets[xroot].parent = yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank)
	{
		subsets[yroot].parent = xroot;
	}
	else
	{
		// ranks are same
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

// The main function to check whether a given graph contains cycle or not 
int isCycle(Graph *graph)
{
	int V = graph->V;
	int E = graph->E;

	// Allocate memory for creating V sets
	subset *subsets =
		(subset*)malloc(V * sizeof(subset));

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	/*
	Iterate through all edges of graph, find sets of both
	vertices of every edge, if sets are same, then there is
	cycle in graph.
	*/
	for (int e = 0; e < E; ++e)
	{
		int x = Find(subsets, graph->edge[e].src);
		int y = Find(subsets, graph->edge[e].dest);

		if (x == y)
		{
			return 1;
		}

		Union(subsets, x, y);
	}

	return 0;
}


int main()
{
	/*
	Let us create the following graph
		 0
		|  \
		|   \
		1----2
	*/
	int V = 3, E = 3;
	struct Graph* graph = createGraph(V, E);

	// add edge 0-1 
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	// add edge 1-2 
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	// add edge 0-2 
	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		printf("Graph contains cycle");
	else
		printf("Graph doesn't contain cycle");

	return 0;
}

