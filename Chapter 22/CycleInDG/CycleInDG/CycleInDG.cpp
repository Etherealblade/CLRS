/*
https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
A C++ Program to detect cycle in a directed graph
*/

#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V;			// No. of vertices
	list<int> *adj;	// Pointer to an array containing adjacency lists
	bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
	Graph(int V);	// Constructor
	void addEdge(int v, int w);
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];	// 有点意思, adj指向V个list,相当于二维数组
							// 而line13 中却是一个"指向 list 的指针",
							
	// https://blog.csdn.net/u014546553/article/details/53644898
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list. 
}

/*
This function is a variation of DFSUtil() in
https://www.geeksforgeeks.org/archives/18212
*/
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if (visited[v] == false)
	{
		// Mark the current node as visited 
		// and part of recursion stack
		visited[v] = true;
		recStack[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i] &&
				isCyclicUtil(*i, visited, recStack))
			{
				return true;
			}
			else if (recStack[*i])
			{
				return true;
				// 此处的true是返回给line54的!!!
			}
		}
	}
	recStack[v] = false;	// remove the vertex from recursion stack
							// equaling pop, this vertex traverse completely

	// 这里难在于,在递归过程中会隐式地调用stack,很难组合对应的数据
	return false;
}

/*
Returns true if the graph contains a cycle, else false.
This function is a variation of DFS() in
https://www.geeksforgeeks.org/archives/18212
*/
bool Graph::isCyclic()
{
	/*
	Mark all every vertex as not visited and it's
	not part of recursion stack
	*/
	bool *visited = new bool[V];
	bool *recStack = new bool[V];

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	/*
	Call the recursive helper function to detect cycle
	in different dfs trees
	*/
	for (int i = 0; i < V; i++)
	{
		if (isCyclicUtil(i, visited, recStack))
		{
			// 数据简单,所以容易且快速的见到结果
			// 若数据复杂, 进入单步调试人会疯掉
			return true;
		}
	}
	return false;
}

/*
To detect a back edge, keep track of vertices currently 
in recursion stack of function for DFS traversal. 
If a vertex is reached that is already in the recursion 
stack, then there is a cycle in the tree. The edge that 
connects current vertex to the vertex in the recursion 
stack is a back edge. Use recStack[] array to keep track 
of vertices in the recursion stack
*/
int main()
{
	// Create a graph given in the above diagram 
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	// 新的测试数据:
	//g.addEdge(0, 1);
	//g.addEdge(0, 2);
	//g.addEdge(1, 2);
	//g.addEdge(2, 3);
	//g.addEdge(3, 1);	// 图片在同级目录

	if (g.isCyclic())
	{
		cout << "Graph contains a cycle";
	}
	else
	{
		cout << "Graph doesn't contain any cycle";
	}

	return 0;
}

