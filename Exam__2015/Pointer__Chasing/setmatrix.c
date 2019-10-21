#include <stdio.h>
#include "setmatrix.h"
void processSetMatrix(int ***ptr)
{
	int i, j, k;
	for (i = 0; ptr[i + 1] != NULL; i++)
	{
		for (j = 0; ptr[i][j] != NULL; j++)
		{
			for (k = 0; ptr[i][j][k] != 0; k++)
			{
				printf("%d ", ptr[i][j][k]);
			}
		}
	}
	for (j = 0; ptr[i][j + 1] != NULL; j++)
	{
		for (k = 0; ptr[i][j][k] != 0; k++)
		{
			printf("%d ", ptr[i][j][k]);
		}
	}
	for (k = 0; ptr[i][j][k + 1] != 0; k++)
	{
		printf("%d ", ptr[i][j][k]);
	}
	printf("%d\n", ptr[i][j][k]);
}