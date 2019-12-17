#include <stdio.h>
#include "BuildTree.h"
int countlen(Node *list)
{
	if (list == NULL)
	{
		return 0;
	}
	return (1 + countlen(list->left));
}
Node *split(Node *list, int len)
{
	int half = (len / 2) + (len % 2);
	int count = 0;
	Node *prev = NULL;
	if (list == NULL || len <= 1)
	{
		return NULL;
	}
	while (count < half)
	{
		prev = list;
		list = list->left;
		count++;
	}
	prev->left = NULL;
	return list;
}
Node *BuildTree(Node *list1, Node *list2)
{
	if (list1 == NULL && list2 == NULL)
	{
		return NULL;
	}
	else if (list2 == NULL)
	{
		return list1;
	}
	else if (list1 == NULL)
	{
		return list2;
	}
	Node *root = list1->val < list2->val ? list1 : list2;
	if (root == list1)
	{
		list1 = list1->left;
	}
	else
	{
		list2 = list2->left;
	}
	int len1 = countlen(list1);
	int len2 = countlen(list2);
	Node *new1 = split(list1, len1);
	Node *new2 = split(list2, len2);
	root->left = BuildTree(list1, list2);
	root->right = BuildTree(new1, new2);
	return root;
}