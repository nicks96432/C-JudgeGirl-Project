#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_INPUT 4200
typedef struct Node
{
	int num;
	struct Node *left;
	struct Node *right;
} node;
node *generateNode(int num)
{
	node *newnode = malloc(sizeof(node));
	newnode->num = num;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
static char *now;
node *generateTree(void)
{
	node *newnode = generateNode(0);
	while (isspace(*now))
	{
		now++;
	}
	if ((*now) == '(')
	{
		now++;
		newnode->left = generateTree();
		now++;
		newnode->right = generateTree();
		now++;
		newnode->num = newnode->left->num + newnode->right->num;
	}
	else
	{
		int num;
		sscanf(now, "%d", &num);
		while (isdigit(*now) || (*now) == '-')
		{
			now++;
		}
		newnode->num = num;
	}
	return newnode;
}
/* mode 0: HLHR, mode 1: HRHL */
void printTree(node *root, int mode)
{
	if (root == NULL)
	{
		return;
	}
	if (mode == 0)
	{
		printf("%d\n", root->num);
		printTree(root->left, 1);
		printf("%d\n", root->num);
		printTree(root->right, 1);
	}
	else
	{
		printf("%d\n", root->num);
		printTree(root->right, 0);
		printf("%d\n", root->num);
		printTree(root->left, 0);
	}
}
void freeTree(node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
int main(void)
{
	char input[MAX_INPUT];
	scanf("%s", input);
	now = input;
	node *root = generateTree();
	printTree(root, 0);
	freeTree(root);
	return 0;
}