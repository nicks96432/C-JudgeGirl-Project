#include <stdio.h>
void merge(int A[], int B[], int *a[], int *b[])
{
	int i = 0, j = 0, N = 0, M = 0;
	while (a[N] != NULL)
	{
		N++;
	}
	while (b[M] != NULL)
	{
		M++;
	}
	N++;
	M++;
	while (i < N && j < M)
	{
		if (A[i] < B[j])
		{
			if (A[i + 1] < B[j])
			{
				a[i] = &A[i + 1];
			}
			else
			{
				a[i] = &B[j];
			}
			i++;
		}
		else // A[i] > B[j]
		{
			if (B[j + 1] < A[i])
			{
				b[j] = &B[j + 1];
			}
			else
			{
				b[j] = &A[i];
			}
			j++;
		}
	}
	if (i == N)
	{
		a[N - 1] = &B[j];
	}
	else if (j == M)
	{
		b[M - 1] = &A[i];
	}
	return;
}