/*
https://www.geeksforgeeks.org/minimum-cut-in-a-directed-graph/

*/

#include <iostream>
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std;

// Number of vertices in given graph 
#define V 6 

int bfs(int rGraph[V][V], int s, int t, int parent[])
{
	/*
	returns true if there is a path from source 's' to
	sink 't' in residual graph. Also fills parent[] to store
	the path
	*/
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// create a queue, enqueue source vertex and mark source
	// as visited
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// standard bfs loop
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	// if we reached sink in bfs starting from source, then
	// return true, else false
	return (visited[t] == true);
}

void dfs(int rGraph[V][V], int s, bool visited[])
{
	/*
	a dfs based func to find all reachable vertices from s.
	The func marks visited[i] as true if i is reachable
	from s. The initial values in visited[] must be false.
	We can also use bfs to find reachable vertices
	*/
	visited[s] = true;
	for (int i = 0; i < V; i++)
	{
		if (rGraph[s][i] && !visited[i])
		{
			dfs(rGraph, i, visited);
		}
	}
}

void minCut(int graph[V][V], int s, int t)
{
	int u, v;
	/*
	Create a residual g and fill the residual g with given
	capacities in the original g as residual capacities
	in residual g
	*/
	int rGraph[V][V];
	for (u = 0; u < V; u++)
	{
		for (v = 0; v < V; v++)
		{
			rGraph[u][v] = graph[u][v];
		}
	}

	int parent[V];	// This arr is filled by bfs and to store path

	// Augment the flow while there is a path from source to sink
	while (bfs(rGraph, s, t, parent))
	{
		/*
		Find min residual capacity of the edhes along the
		path filled by bfs. Or we can say find the max flow
		through the path found.
		*/
		int path_flow = INT_MAX;
		for (v=t;v!=s;v=parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}


		/*
		update residual capacities of the edges and 
		reverse edges along the path
		*/
		for (v=t;v!=s;v=parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
	}

	// Flow is max now, find vertices reachable from s
	bool visited[V];
	memset(visited, false, sizeof(visited));
	dfs(rGraph, s, visited);

	/*
	Print all edges that are from a reachable vertex to
	non-reachable vertex in the original graph
	*/
	for (int i=0;i<V;i++)
	{
		for (int j=0;j<V;j++)
		{
			if (visited[i] && !visited[j]&&graph[i][j])
			{
				printf_s("%d-%d\n", i, j);
			}
		}
	}

	return;
}


int main()
{
	// Let us create a graph shown in the above example 
	int graph[V][V] = { {0, 16, 13, 0, 0, 0},
						{0, 0, 10, 12, 0, 0},
						{0, 4, 0, 0, 14, 0},
						{0, 0, 9, 0, 0, 20},
						{0, 0, 0, 7, 0, 4},
						{0, 0, 0, 0, 0, 0}
	};

	minCut(graph, 0, 5);

	return 0;
}

