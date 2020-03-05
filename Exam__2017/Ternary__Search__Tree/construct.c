#include <stdlib.h>
#include <assert.h>
#include "construct.h"
static Node *generateNode(int small, int large)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->large = large;
	newnode->small = small;
	newnode->left = NULL;
	newnode->mid = NULL;
	newnode->right = NULL;
	return newnode;
}
static Node *insertTree(Node *root, int n)
{
	if (root == NULL)
	{
		return generateNode(-1, n);
	}
	if (root->small < 0)
	{
		if (n > root->large)
		{
			root->small = root->large;
			root->large = n;
		}
		else
		{
			root->small = n;
		}
	}
	else
	{
		if (n > root->large)
		{
			root->right = insertTree(root->right, n);
		}
		else if (n < root->small)
		{
			root->left = insertTree(root->left, n);
		}
		else
		{
			root->mid = insertTree(root->mid, n);
		}
	}
	return root;
}
Node *ConstructTree(int sequence[], int N)
{
	Node *root = NULL;
	for (int i = 0; i < N; i++)
	{
		root = insertTree(root, sequence[i]);
	}
	return root;
}