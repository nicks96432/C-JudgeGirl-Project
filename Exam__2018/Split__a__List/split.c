#include <stdio.h>
#define MAX_K 100000
void split(int A[], int *a[], int *head[], int k)
{
	int **tail[MAX_K];
	int i, j;
	for (i = 0; i < k; i++)
	{
		tail[i] = NULL;
	}
	for (i = 0;; i++)
	{
		j = A[i] % k;
		if (tail[j] == NULL)
		{
			head[j] = &A[i];
		}
		else
		{
			*(tail[j]) = &A[i];
		}
		tail[j] = &a[i];
		if (a[i] == NULL)
		{
			break;
		}
		a[i] = NULL;
	}
	return;
}