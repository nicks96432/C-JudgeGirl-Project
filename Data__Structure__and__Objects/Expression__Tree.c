#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define MAX_TREE 1002
#define MAX_VARIABLES 52
typedef struct Node
{
	int value;
	char operator;
	struct Node *left;
	struct Node *right;
} node;
typedef struct Variable
{
	char name[35];
	int value;
} variable;
node *generateNode(int value)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->value = value;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
static char *now;
void skipblank(void)
{
	while (isblank(*now))
	{
		now++;
	}
	return;
}
void read(int character)
{
	assert((*now) == character);
	now++;
	return;
}
node *buildTree(variable *variables, int countvar)
{
	node *newnode = generateNode(0);
	skipblank();
	if ((*now) == '(')
	{
		read('(');
		skipblank();
		newnode->operator= *now;
		read(newnode->operator);
		skipblank();
		assert((newnode->operator) == '+' || (newnode->operator) == '-' ||
			   (newnode->operator) == '*' || (newnode->operator) == '/');
		newnode->left = buildTree(variables, countvar);
		newnode->right = buildTree(variables, countvar);
		skipblank();
		read(')');
	}
	else if (isdigit(*now))
	{
		sscanf(now, "%d", &(newnode->value));
		while (isdigit(*now))
		{
			now++;
		}
	}
	else
	{
		char varname[32];
		sscanf(now, "%s", varname);
		int i;
		for (i = 0; i < countvar; i++)
		{
			if (!strcmp(varname, variables[i].name))
			{
				newnode->value = variables[i].value;
				break;
			}
		}
		assert(i != countvar);
		while (isalnum(*now) || (*now) == '_' || (*now) == '$')
		{
			now++;
		}
	}
	return newnode;
}
int compute(node *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root->value;
	}
	switch (root->operator)
	{
	case '+':
		return compute(root->left) + compute(root->right);
		break;
	case '-':
		return compute(root->left) - compute(root->right);
		break;
	case '*':
		return compute(root->left) * compute(root->right);
		break;
	case '/':
		return compute(root->left) / compute(root->right);
		break;
	default:
		return 0;
	}
}
int main(void)
{
	char tree[MAX_TREE];
	fgets(tree, 1002, stdin);
	variable variables[MAX_VARIABLES];
	char declaration[64];
	int countvar = 0;
	while (fgets(declaration, 64, stdin) != NULL)
	{
		sscanf(declaration, "%s = %d", variables[countvar].name, &variables[countvar].value);
		countvar++;
	}
	now = tree;
	node *root = buildTree(variables, countvar);
	printf("%d\n", compute(root));
	return 0;
}