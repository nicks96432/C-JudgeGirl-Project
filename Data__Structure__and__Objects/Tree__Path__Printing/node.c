#include <stdio.h>
#include "node.h"
void printPath(struct node *root, int path[], int count)
{
	if (root == NULL)
	{
		return;
	}
	path[count] = root->data;
	if (root->left == NULL && root->right == NULL)
	{
		int i;
		for (i = 0; i <= count; i++)
		{
			printf("%d%c", path[i], (i == count) ? '\n' : ' ');
		}
		return;
	}
	count++;
	printPath(root->left, path, count);
	printPath(root->right, path, count);
}
void print_all_paths(struct node *root)
{
	int path[1002] = {};
	Node *head = root;
	int layer = 0;
	while (head != NULL)
	{
		head = head->left;
		layer++;
	}
	printPath(root, path, 0);
	return;
}