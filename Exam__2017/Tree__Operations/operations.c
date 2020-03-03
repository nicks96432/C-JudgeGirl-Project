#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "operations.h"
static Node *generateNode(int n)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->n = n;
	return newnode;
}
Node *FlipTree(Node *root)
{
	if (root == NULL)
	{
		return NULL;
	}
	Node *newnode = generateNode(root->n);
	newnode->left = FlipTree(root->right);
	newnode->right = FlipTree(root->left);
	return newnode;
}
int isIdentical(Node *tree1, Node *tree2)
{
	if (tree1 == NULL && tree2 == NULL)
	{
		return 1;
	}
	if ((tree1 == NULL && tree2 != NULL) || (tree1 != NULL && tree2 == NULL))
	{
		return 0;
	}
	if (tree1->n != tree2->n)
	{
		return 0;
	}
	return isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right);
}
static void trace(Node *root, int *totalDepth, int *countLeaf, int nowDepth)
{
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)
	{
		(*countLeaf)++;
		(*totalDepth) += nowDepth;
		return;
	}
	if (root->left != NULL)
	{
		trace(root->left, totalDepth, countLeaf, nowDepth + 1);
	}
	if (root->right != NULL)
	{
		trace(root->right, totalDepth, countLeaf, nowDepth + 1);
	}
	return;
}
void depthAvg(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	int totalDepth = 0, countLeaf = 0;
	trace(root, &totalDepth, &countLeaf, 0);
	printf("%d/%d\n", totalDepth, countLeaf);
	return;
}