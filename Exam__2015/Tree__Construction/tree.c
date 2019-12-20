#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
Node *generateNode(int label)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->label = label;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node *insertNode(int array[], int now, int n)
{
	if (now >= n)
	{
		return NULL;
	}
	else
	{
		Node *newnode = generateNode(array[now]);
		newnode->left = insertNode(array, now * 2 + 1, n);
		newnode->right = insertNode(array, now * 2 + 2, n);
		return newnode;
	}
}
Node *construct(int array[], int n)
{
	return insertNode(array, 0, n);
}