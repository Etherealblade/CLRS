/*
https://www.geeksforgeeks.org/max-flow-problem-introduction/
https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
*/

#include <iostream>
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std;

// Number of vertices in given graph 
#define V 6 

/*
Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills parent[] to store the path
*/
bool bfs(int rGraph[][V], int s, int t, int parent[])
{
	// Create a visited array and mark all vertices as not visited
	bool visited[V];
	memset(visited, 0, sizeof(visited));

	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	// Standard bfs loop
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

	// If we reached sink in bfs starting from source,
	// then return true, else false
	return visited[t] == true;
}

// Returns the maximum flow from s to t in the given graph 
int FordFulkerson(int graph[V][V], int s, int t)
{
	int u, v;

	// Create a residual graph and fill the residual graph with 
	// given capacities in the original graph as residual capacities 
	// in residual graph 
	int rGraph[V][V];	// Residual graph where rGraph[i][j] indicates  
						// residual capacity of edge from i to j (if there 
						// is an edge. If rGraph[i][j] is 0, then there is not)
	for (u = 0; u < V; u++)
	{
		for (v = 0; v < V; v++)
		{
			rGraph[u][v] = graph[u][v];
		}
	}

	// This array is filled by BFS and to store path 
	int parent[V];
	int max_flow = 0;	// There is no flow initially 

	// Augment the flow while there is path from 
	// source to sink
	while (bfs(rGraph, s, t, parent))
	{
		// Find minimum residual capacity of the edges 
		// along the path filled by BFS. 
		// Or we can say find the maximum flow 
		// through the path found. 
		int path_flow = INT_MAX;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

// Driver program to test above functions 
int main()
{
	/* 
	Let us create a graph shown in the above example
	下面给出的数据对应clrs p425, 这里的数据很好理解.
	但是同级目录下的那张图片就不好理解: 先说了greedy的错误,然后添加
	一条原本不存在的逆路径!?

	<挑战程序设计竞赛> P209也是先greedy, 然后说greedy不对, 接着就
	添加一条原本不存在的逆路径.
	
	geeksforgeeks 和 clrs给的数据不好理解, clrs 在这一整章的编排
	也极其的烂, <挑战程序设计竞赛>给的数据和解释更好理解.

	但是最后还是在clrs p425完全理解了过程, geeksforgeeks 的图是
	不完整的(缺乏过程变化), 而clrs的过程则非常清晰
	*/
	int graph[V][V] = { {0, 16, 13, 0, 0, 0},
						{0, 0, 10, 12, 0, 0},
						{0, 4, 0, 0, 14, 0},
						{0, 0, 9, 0, 0, 20},
						{0, 0, 0, 7, 0, 4},
						{0, 0, 0, 0, 0, 0}
	};	//clrs p425的data

	cout << "The maximum possible flow is " << 
		FordFulkerson(graph, 0, 5) << endl;

	return 0;
}