#ifndef BUILDTREE_H
#define BUILDTREE_H

typedef struct Node
{
	int val;
	struct Node *left, *right;
} Node;
Node *BuildTree(Node *list1, Node *list2);

#endif /* BUILDTREE_H */