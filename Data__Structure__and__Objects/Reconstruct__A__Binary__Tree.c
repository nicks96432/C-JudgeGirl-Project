#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_N 1002
typedef struct Node
{
	int value;
	int layer;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} node;
int comp(const void *x, const void *y)
{
	int a = ((int *)x)[0];
	int b = ((int *)y)[0];
	if (a != b)
	{
		return a < b ? -1 : 1;
	}
	a = ((int *)x)[1];
	b = ((int *)y)[1];
	return a - b;
}
node *genTreeNode(int value, int layer)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	newnode->value = value;
	newnode->layer = layer;
	return newnode;
}
void insertNode(node *newnode, node *prev)
{
	while (prev->layer > newnode->layer)
	{
		prev = prev->parent;
		assert(prev != NULL);
	}
	if (prev->right != NULL)
	{
		prev->right->parent = newnode;
	}
	newnode->left = prev->right;
	prev->right = newnode;
	newnode->parent = prev;
	return;
}
node *findNode(node *head, int value)
{
	while (head != NULL)
	{
		if (head->value == value)
		{
			return head;
		}
		else if (head->value > value)
		{
			head = head->left;
		}
		else
		{
			head = head->right;
		}
	}
	return NULL;
}
int main(void)
{
	int n;
	int nodes[MAX_N][2], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &nodes[i][0], &nodes[i][1]);
	}
	qsort(nodes, n, sizeof(nodes[0]), comp);
	int p, a, b;
	node *root = genTreeNode(-2147483648, 1);
	node *prev = root;
	for (i = 0; i < n; i++)
	{
		node *newnode = genTreeNode(nodes[i][0], nodes[i][1]);
		insertNode(newnode, prev);
		prev = newnode;
	}
	scanf("%d", &p);
	for (i = 0; i < p; i++)
	{
		scanf("%d%d", &a, &b);
		node *nodea = findNode(root, a);
		node *nodeb = findNode(root, b);
		assert(nodea && nodeb);
		int dist = 0;
		while (nodea != nodeb)
		{
			if (nodea->layer > nodeb->layer)
			{
				nodea = nodea->parent;
			}
			else
			{
				nodeb = nodeb->parent;
			}
			dist++;
		}
		printf("%d\n", dist);
	}
	return 0;
}