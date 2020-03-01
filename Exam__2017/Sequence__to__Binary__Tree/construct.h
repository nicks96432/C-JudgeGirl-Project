#ifndef CONSTRUCT_H

#define CONSTRUCT_H
typedef struct node
{
	int value;
	struct node *left, *right;
} Node;
Node *ConstructTree(int sequence[], int N);

#endif /* CONSTRUCT_H */