#include "tree.h"
#include <stdio.h>
void traversal(Node *root, int N, int command[])
{
	int i, j, now = 0;
	Node *nodes[1024];
	nodes[0] = root;
	for (i = 0; i < N; i++)
	{
		switch (command[i])
		{
		case 0:
			printf("%d\n", nodes[now]->label);
			return;
			break;
		case 1:
			printf("%d\n", nodes[now]->label);
			break;
		case 2:
			if (now > 0)
			{
				now--;
			}
			else
			{
				printf("%d\n", nodes[now]->label);
				return;
			}
			break;
		case 3:
			if (nodes[now]->left == NULL)
			{
				printf("%d\n", nodes[now]->label);
				return;
			}
			else
			{
				nodes[now + 1] = nodes[now]->left;
				now++;
			}
			break;
		case 4:
			if (nodes[now]->right == NULL)
			{
				printf("%d\n", nodes[now]->label);
				return;
			}
			else
			{
				nodes[now + 1] = nodes[now]->right;
				now++;
			}
			break;
		case 5:
			if (now > 0 && nodes[now - 1]->left != NULL && nodes[now - 1]->right != NULL)
			{
				if (nodes[now - 1]->left == nodes[now])
				{
					nodes[now] = nodes[now - 1]->right;
				}
				else
				{
					nodes[now] = nodes[now - 1]->left;
				}
			}
			else
			{
				printf("%d\n", nodes[now]->label);
				return;
			}
			break;
		default:
			break;
		}
	}
}