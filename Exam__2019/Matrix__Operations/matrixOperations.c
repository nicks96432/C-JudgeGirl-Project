#include "matrixOperations.h"
#include <stdio.h>
#include <stdint.h>
void printMatrix(uint64_t *matrix)
{
	int count;
	uint64_t i;
	printf("%llu\n",*matrix);
	for (i = 1ULL, count = 1; i > 0; i <<= 1, count++)
	{
		printf("%d", !(!((*(matrix)) & i)) ? 1 : 0);
		if (!(count % 8))
		{
			printf("\n");
		}
	}
	return;
}
void rotateMatrix(uint64_t *matrix)
{
	uint64_t tmp = *matrix, i, j = 1ULL << 63;
	*matrix = 0ULL;
	int count;
	for (count = 7; count >= 0; count--)
	{
		for (i = 1ULL << count; i <= 1ULL << (count + 56) && i > 0; i <<= 8)
		{
			if (tmp & i)
			{
				(*matrix) |= j;
			}
			j >>= 1;
		}
	}
	return;
}
void transposeMatrix(uint64_t *matrix)
{
	int count;
	uint64_t i, j, tmp = *matrix;
	*matrix = 0ULL;
	for (count = 0; count < 8; count++)
	{
		for (i = 1ULL << (count * 9), j = 1ULL << (count * 9); i <= (1ULL << (count * 9 + (7 - count) * 8)) && i > 0; i <<= 8, j <<= 1)
		{
			if (tmp & i)
			{
				(*matrix) |= j;
			}
			if (tmp & j)
			{
				(*matrix) |= i;
			}
		}
	}
	return;
}