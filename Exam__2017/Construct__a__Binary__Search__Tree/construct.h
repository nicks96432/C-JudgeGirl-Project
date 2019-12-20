#ifndef CONSTRUCT_H
#define CONSTRUCT_H

typedef struct Node
{
	char name[16];
	int height;
	int weight;
	struct Node *left, *right;
} Node;
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]);

#endif /* CONSTRUCT_H */