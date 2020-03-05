#ifndef CONSTRUCT_H

#define CONSTRUCT_H
typedef struct node
{
	int small, large;
	struct node *left, *mid, *right;
} Node;
Node *ConstructTree(int sequence[], int N);

#endif /* CONSTRUCT_H */