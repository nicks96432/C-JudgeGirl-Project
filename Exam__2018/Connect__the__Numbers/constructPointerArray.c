#include "constructPointerArray.h"
const int *D[1 << 20 + 1];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	int i, j;
	const int max = N * N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			D[A[i][j]] = &A[i][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (A[i][j] == max - 1)
			{
				B[i][j] = D[0];
			}
			else
			{
				B[i][j] = D[A[i][j] + 1];
			}
		}
	}
	return;
}