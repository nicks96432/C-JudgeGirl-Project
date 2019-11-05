#include <stdlib.h>
int ***constructTable(int A[], int B[])
{
	int i, j, ***ans, count = 0;
	for (i = 0;; i++)
	{
		if (A[i] == 0)
		{
			break;
		}
	}
	int N = i;
	ans = (int ***)malloc(sizeof(int **) * (N + 1));
	ans[N] = NULL;
	for (i = 0; i < N; i++)
	{
		ans[i] = (int **)malloc(sizeof(int *) * (A[i] + 1));
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < A[i]; j++)
		{
			ans[i][j] = &B[count];
			for (;; count++)
			{
				if (B[count] == 0)
				{
					break;
				}
			}
			count++;
		}
		ans[i][j] = NULL;
	}
	return ans;
}