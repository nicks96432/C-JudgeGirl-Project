#include "matrix_multiplication.h"
#define MAX_N 1000
void matrix_multiplication(int N, int **ptrA, int M, int **ptrB, int S, int *result)
{
	int i, j, k, tmp;
	int mata[MAX_N][MAX_N], matb[MAX_N][MAX_N];
	for (i = 0; i < S; i++)
	{
		for (j = 0; j < S; j++)
		{
			mata[i][j] = 0;
			matb[i][j] = 0;
		}
	}
	for (i = 0; i < S * S; i++)
	{
		result[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		mata[ptrA[1][i]][ptrA[2][i]] = ptrA[0][i];
	}
	for (i = 0; i < M; i++)
	{
		matb[ptrB[1][i]][ptrB[2][i]] = ptrB[0][i];
	}
	for (i = 0; i < S; i++)
	{
		for (j = 0; j < S; j++)
		{
			for (k = 0; k < S; k++)
			{
				result[i * S + k] += mata[i][j] * matb[j][k];
			}
		}
	}
	return;
}