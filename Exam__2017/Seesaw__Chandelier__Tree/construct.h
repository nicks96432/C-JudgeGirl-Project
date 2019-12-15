#ifndef CONSTRUCT_H
#define CONSTRUCT_H

typedef struct Node
{
	int value;
	struct Node *left, *right;
} Node;
Node *ConstructTree(int T[], int N);

#endif /* CONSTRUCT_H */