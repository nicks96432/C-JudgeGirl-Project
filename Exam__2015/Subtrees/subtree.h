#ifndef SUBTREE_H
#define SUBTREE_H

typedef struct Node
{
	int label;
	struct Node *left, *right;
} Node;
int getNode(Node *root, int label[], int k);

#endif /* SUBBTREE_H */