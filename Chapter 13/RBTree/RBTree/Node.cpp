#include <iostream>
#include "Node.h"

Node::Node(int val) : val(val) {
	parent = left = right = NULL;

	// Node is created during insertion 
	// Node is red at insertion 
	color = RED;
}

Node* Node::uncle()
{
	// If no parent or grandparent, then no uncle 
	if (parent == NULL or parent->parent == NULL)
		return NULL;

	if (parent->isOnLeft())
		// uncle on right 
		return parent->parent->right;
	else
		// uncle on left 
		return parent->parent->left;
}

// check if node is left child of parent 
bool Node::isOnLeft()
{
	return this == parent->left;
}

Node* Node::sibling() {
	// sibling null if no parent 
	if (parent == NULL)
		return NULL;

	if (isOnLeft())
		return parent->right;

	return parent->left;
}

// moves node down and moves given node in its place 
void Node::moveDown(Node *nParent) {
	if (parent != NULL) {
		if (isOnLeft()) {
			parent->left = nParent;
		}
		else {
			parent->right = nParent;
		}
	}
	nParent->parent = parent;
	parent = nParent;
}

bool Node::hasRedChild()
{
	return (left != NULL and left->color == RED) or
		(right != NULL and right->color == RED);

}
