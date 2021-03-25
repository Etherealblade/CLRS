#pragma once

// A structure to represent an edge in graph
class Edge
{
public:
	int src, dest;
};

// A structure to represent a graph
class Graph
{
public:
	int V, E;	// V-> number of vertices, E-> number of edges

	Edge *edge;	// graph is represented as an array of edges
};
