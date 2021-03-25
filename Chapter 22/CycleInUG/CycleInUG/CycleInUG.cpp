// CycleInUG.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/detect-cycle-undirected-graph/

// A C++ Program to detect cycle in an undirected graph 
#include <iostream>
#include <list>
#include <limits.h>
using namespace std;


// Class for an undirected graph
class Graph
{
	int V;	// No. of vertices
	list<int> *adj; // Point to an array containing adjacency lists 
	bool isCyclicUtil(int v, bool visited[], int parent);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();	// returns true if there is a cycle
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
	adj[w].push_back(v); // Add v to w’s list. 
}

/*
A recursive func that uses visited[] and parent
to detect cycle in subgraph reachable from vertex x
*/
bool Graph::isCyclicUtil(int v, bool visited[], int parent)
{
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		// If an adjacent is not visited, then recur for that adjacent
		if (!visited[*i])
		{
			if (isCyclicUtil(*i, visited, v))
				return true;	// 为何这里能返回true? 此处仅仅继续递归而已
		}

		else if (*i != parent)
		{
			/*
			If an adjacent is visited and not parent
			of current vertex, then there is a cycle.
			*/
			return true;	// 为何这里能返回true?
			// 这里的true是返回给line52的if!!!
		}
	}

	return false;
}

// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic()
{
	// Mark all the vertices as not visited 
	// and not part of recursion stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	/*
	Call the recursive helper func to detect cycle in
	different DFS trees
	*/
	for (int u = 0; u < V; u++)
	{
		if (!visited[u])
			// Don't recur for u if it is already visited 
		{
			if (isCyclicUtil(u, visited, -1))
			{
				return true;
			}
		}
	}
	return false;
}


/*
There is a cycle in a graph only if there
is a back edge present in the graph
*/
int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";

	return 0;

}
