#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "tree.h"
Node *generateNode(int data)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node *construct(Node *root, char instruction[])
{
	if (root == NULL)
	{
		root = generateNode(0);
	}
	int i, len = strlen(instruction);
	root->data++;
	Node *now = root;
	for (i = 0; i < len; i++)
	{
		if (instruction[i] == 'L')
		{
			if (now->left == NULL)
			{
				now->left = generateNode(1);
				now = now->left;
			}
			else
			{
				now = now->left;
				now->data++;
			}
		}
		else if (instruction[i] == 'R')
		{
			if (now->right == NULL)
			{
				now->right = generateNode(1);
				now = now->right;
			}
			else
			{
				now = now->right;
				now->data++;
			}
		}
	}
	return root;
}
int query(Node *root, char instruction[])
{
	int i, len = strlen(instruction);
	for (i = 0; i < len; i++)
	{
		if (instruction[i] == 'L')
		{
			if (root != NULL)
			{
				root = root->left;
			}
		}
		else if (instruction[i] == 'R')
		{
			if (root != NULL)
			{
				root = root->right;
			}
		}
	}
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return root->data;
	}
}