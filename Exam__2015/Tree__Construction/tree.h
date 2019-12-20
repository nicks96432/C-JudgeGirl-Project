#ifndef TREE_H
#define TREE_H

typedef struct Node
{
	int label;
	struct Node *left, *right;
} Node;
Node *construct(int array[], int n);

#endif /* TREE_H */