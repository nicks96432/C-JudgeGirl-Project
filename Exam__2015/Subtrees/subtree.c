#include <stdio.h>
#include "subtree.h"
int findNode(Node *root, int k, int **now)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = findNode(root->left, k, now);
	int right = findNode(root->right, k, now);
	if (left && right && root->label != k)
	{
		(*now)[0] = root->label;
		(*now)++;
	}
	return left || right || root->label == k;
}
int getNode(Node *root, int label[], int k)
{
	int *now = label;
	findNode(root, k, &now);
	return now - label;
}
