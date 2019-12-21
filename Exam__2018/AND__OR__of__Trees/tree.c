#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
Node *generateNode(int value)
{
	Node *newnode = (Node *)malloc(sizeof(Node));
	assert(newnode != NULL);
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->val = value;
	return newnode;
}
Node *treeAND(Node *root1, Node *root2)
{
	if (root1 == NULL || root2 == NULL)
	{
		return NULL;
	}
	Node *root = generateNode(root1->val * root2->val);
	root->left = treeAND(root1->left, root2->left);
	root->right = treeAND(root1->right, root2->right);
	return root;
}
Node *treeOR(Node *root1, Node *root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return NULL;
	}
	Node *root;
	if (root1 == NULL)
	{
		root = generateNode(root2->val);
		root->left = treeOR(NULL, root2->left);
		root->right = treeOR(NULL, root2->right);
	}
	else if (root2 == NULL)
	{
		root = generateNode(root1->val);
		root->left = treeOR(root1->left, NULL);
		root->right = treeOR(root1->right, NULL);
	}
	else
	{
		root = generateNode(root1->val + root2->val);
		root->left = treeOR(root1->left, root2->left);
		root->right = treeOR(root1->right, root2->right);
	}
	return root;
}