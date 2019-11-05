#include <stdio.h>
#include <stdlib.h>
#include "count.h"
#define MAX 512
#pragma region "comp__int"
static int comp__int(const void *x, const void *y)
{
	int *a = (int *)x, *b = (int *)y;
	if (a[1] != b[1])
	{
		return a[1] < b[1] ? -1 : 1;
	}
	else
	{
		return a[0] < b[0] ? -1 : 1;
	}
}
#pragma endregion
#pragma region "comp__pointer"
static int comp__pointer(const void *x, const void *y)
{
	int *a = *(int **)x, *b = *(int **)y;
	if (a < b)
	{
		return -1;
	}
	else if (a == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
#pragma endregion
void count(int **p[])
{
	int *A[MAX], n;
	for (n = 0; p[0] != NULL; p++, n++)
	{
		A[n] = **p;
	}
	qsort(A, n, sizeof(int *), comp__pointer);
	int B[MAX][2], m = 0, i, j, count;
	for (i = 0; i < n;)
	{
		count = 0;
		j = i;
		while (j < n && A[i] == A[j])
		{
			j++;
			count++;
		}
		B[m][0] = *A[i];
		B[m][1] = count;
		m++;
		i = j;
	}
	qsort(B, m, sizeof(int) * 2, comp__int);
	for (i = 0; i < m; i++)
	{
		printf("%d %d\n", B[i][0], B[i][1]);
	}
	return;
}