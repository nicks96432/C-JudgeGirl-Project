#include <stdio.h>
#include "construct.h"
#define MAXN 16384
void PrintTree(Node *root)
{
	if (root == NULL)
	{
		printf("N\n");
		return;
	}
	printf("%d\n", root->value);
	PrintTree(root->left);
	PrintTree(root->right);
	return;
}
int main(void)
{
	int N;
	int T[MAXN];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &T[i]);
	}
	Node *tree = ConstructTree(T, N);
	PrintTree(tree);
	return 0;
}