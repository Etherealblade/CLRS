#pragma once

enum COLOR { RED, BLACK };

class Node
{
public:
	int val;
	COLOR color;
	Node *left, *right, *parent;

	Node(int);
	Node *uncle();
	bool isOnLeft();
	Node *sibling();
	void moveDown(Node*);
	bool hasRedChild();

};

