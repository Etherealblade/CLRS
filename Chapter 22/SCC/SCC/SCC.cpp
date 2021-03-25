/*
https://www.geeksforgeeks.org/strongly-connected-components/
find all strongly connected components in O(V+E)
time using Kosaraju’s algorithm
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;    // An array of adjacency lists

	/*
	Fills stack with vertices in increasing of finish times.
	The top element of stack has the maximum finish time
	*/
	void fillOder(int v, bool visited[], stack<int> &Stack);

	// A recursive func to print dfs starting from v
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);

	/*
	The main func that finds and prints scc
	*/
	void printSCCs();

	// Func that returns reverse(or tranpose) of this graph
	Graph getTranspose();

};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

// A recursive func to print dfs starting from v
void Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent to this vertex
	//list<int>::iterator i;
	//for (i = adj[v].begin(); i != adj[v].end(); ++i)
	//{
	//	if (!visited[*i])
	//	{
	//		DFSUtil(*i, visited);
	//	}
	//}

	// 如下写法更精简, 类似于python的range_based style
	for (auto& i : adj[v])
	{
		if (!visited[i])
		{
			DFSUtil(i, visited);
		}
	}
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); i++)
		{
			g.adj[*i].push_back(v);		// 这里面到底存着什么数据
		}
	}

	return g;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

void Graph::fillOder(int v, bool visited[],
	stack<int> &Stack)
{
	// Mark the current node as visited and print it
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex
	for (auto& i : adj[v])
	{
		if (!visited[i])
		{
			fillOder(i, visited, Stack);
		}
	}

	// All vertices reachable from v are processed by now,
	// push v
	Stack.push(v);	// 此处就是为了修改caller func传进来的Stack
}

/*
The main function that finds and prints all
strongly connected components
*/
void Graph::printSCCs()
{
	stack<int> Stack;

	// Mark all the vertices as not visited for first dfs
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Fill vertices in stack according to their finishing time
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == false)
		{
			fillOder(i, visited, Stack);
		}
	}

	// Create a reversed graph
	Graph gr = getTranspose();

	// Mark all the vertices as not visited for second dfs
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	// Now process all vertices in order defined by Stack
	while (Stack.empty() == false)
	{
		// Pop a vertex from stack
		int v = Stack.top();
		Stack.pop();

		// Print scc of the popped vertex
		if (visited[v] == false)
		{
			gr.DFSUtil(v, visited);
			cout << endl;
		}

	}
}

int main()
{
	// Create a graph given in the above diagram 
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(0, 3);
	g.addEdge(3, 4);

	cout << "Following are strongly connected components in "
		"given graph \n";
	g.printSCCs();

	return 0;
}
