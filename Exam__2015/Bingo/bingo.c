#include <stdio.h>
#include "bingo.h"
int bingo(const unsigned long long *board, int *rowColumn)
{
	int count;
	unsigned long long i, tmp = (*board);
	for (i = 0xFF00000000000000ULL, count = 0; i > 0; i >>= 8, count++)
	{
		if ((tmp & i) == i)
		{
			(*rowColumn) = count;
			return 1;
		}
	}
	for (i = 0x8080808080808080ULL, count = 0; i >= 0x0101010101010101ULL; i >>= 1, count++)
	{
		if ((tmp & i) == i)
		{
			(*rowColumn) = count;
			return 2;
		}
	}
	if ((0x8040201008040201ULL & tmp) == 0x8040201008040201ULL)
	{
		(*rowColumn) = 0;
		return 3;
	}
	else if ((0x0102040810204080ULL & tmp) == 0x0102040810204080ULL)
	{
		(*rowColumn) = 1;
		return 3;
	}
	return 0;
}