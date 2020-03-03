#ifndef OPERATIONS_H

#define OPERATIONS_H
typedef struct Node
{
	int n;
	struct Node *left, *right;
} Node;
Node *FlipTree(Node *root);
int isIdentical(Node *tree1, Node *tree2);
void depthAvg(Node *root);

#endif /* OPERATIONS_H */