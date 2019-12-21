#ifndef TREE_H
#define TREE_H

#define MAXN 128
typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;
Node *construct(Node *root, char instruction[MAXN]);
int query(Node *root, char instruction[MAXN]);

#endif /* TREE_H */