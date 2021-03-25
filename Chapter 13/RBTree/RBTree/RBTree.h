#pragma once
#include "Node.h"

class RBTree
{
	Node *root;

	void leftRotate(Node*);
	void rightRotate(Node*);
	void swapColors(Node*, Node*);
	void swapValues(Node*, Node*);
	void fixRedRed(Node*);
	Node *successor(Node*);
	Node *BSTreplace(Node*);
	void deleteNode(Node*);
	void fixDoubleBlack(Node*);
	void levelOrder(Node*);
	void inorder(Node*);

public:
	RBTree();
	Node *getRoot();
	Node *search(int n);
	void insert(int n);
	void deleteByVal(int n);
	void printInOrder();
	void printLevelOrder();
};

