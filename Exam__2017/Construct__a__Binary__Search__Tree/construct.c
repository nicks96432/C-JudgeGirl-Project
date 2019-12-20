#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "construct.h"
Node *generateNode(char *name, int height, int weight)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->height = height;
	newnode->weight = weight;
	strcpy(newnode->name, name);
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
Node *insertTree(Node *root, char *name, int height, int weight)
{
	if (root == NULL)
	{
		root = generateNode(name, height, weight);
	}
	else
	{
#ifdef HEIGHT
		if (height < root->height)
		{
			root->left = insertTree(root->left, name, height, weight);
		}
		else
		{
			root->right = insertTree(root->right, name, height, weight);
		}
#endif
#ifdef WEIGHT
		if (weight < root->weight)
		{
			root->left = insertTree(root->left, name, height, weight);
		}
		else
		{
			root->right = insertTree(root->right, name, height, weight);
		}
#endif
	}
	return root;
}
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[])
{
	int i = 0;
	Node *root = NULL;
	for (i = 0; i < N; i++)
	{
		root = insertTree(root, name[i], height[i], weight[i]);
	}
	return root;
}