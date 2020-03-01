#include <stdlib.h>
#include <assert.h>
#include "construct.h"
static int comp(const void *x, const void *y)
{
	int a = *(int *)x, b = *(int *)y;
	if (a > b)
	{
		return -1;
	}
	else if (a < b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
static Node *generateNode(int value)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->value = value;
	return newnode;
}
Node *ConstructTree(int sequence[], int N)
{
	if (N == 0)
	{
		return NULL;
	}
	if (MAXLENGTH > N)
	{
		Node *root = generateNode(sequence[N - 1]);
		Node *ptr = root;
		for (int i = N - 2; i >= 0; i--)
		{
			ptr->left = generateNode(sequence[i]);
			ptr = ptr->left;
		}
		return root;
	}
	else
	{
		int tmp[N];
		for (int i = 0; i < N; i++)
		{
			tmp[i] = sequence[i];
		}
		qsort(tmp, N, sizeof(int), comp);
		int pos;
		for (int i = 0; i < N; i++)
		{
			if (sequence[i] == tmp[MAXLENGTH - 1])
			{
				pos = i;
				break;
			}
		}
		Node *root = generateNode(sequence[pos]);
		root->left = ConstructTree(sequence, pos);
		root->right = ConstructTree(sequence + pos + 1, N - pos - 1);
		return root;
	}
}