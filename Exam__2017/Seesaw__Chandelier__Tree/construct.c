#include <stdio.h>
#include <stdlib.h>
#include "construct.h"
Node *generateNode(int value, Node *left, Node *right)
{
	Node *newnode = malloc(sizeof(Node));
	newnode->left = left;
	newnode->right = right;
	newnode->value = value;
	return newnode;
}
Node *ConstructTree(int T[], int N)
{
	int i;
	unsigned long long sum = 0, torque = 0;
	for (i = 0; i < N; i++)
	{
		sum += T[i];
		torque += T[i] * i;
	}
	if (N > 2 && sum != 0 && torque % sum == 0)
	{
		unsigned long long point = torque / sum;
		Node *newnode = generateNode(T[point], ConstructTree(T, point),
									 ConstructTree(T + point + 1, N - point - 1));
		return newnode;
	}
	else if (N > 0)
	{
		Node *newnode;
		Node *prev = NULL;
		for (i = 0; i < N; i++)
		{
			newnode = generateNode(T[i], prev, NULL);
			prev = newnode;
		}
		return newnode;
	}
	return NULL;
}