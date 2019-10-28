#include <stdio.h>
#include "blockmover.h"
#define uint64_t unsigned long long
void printBlock(uint64_t *block)
{
	int i, j;
	for (i = 0; i < 8; i++, puts(""))
	{
		for (j = 0; j < 8; j++)
		{
			printf("%"
				   "llu"
				   "",
				   (*block) >> ((i << 3) | j) & 1);
		}
	}
	return;
}
void initialize(uint64_t *block, int row, int column, int size)
{
	uint64_t tmp = (1LLU << size) - 1, square = 0;
	int i;
	for (i = 0; i < size; i++)
	{
		square |= tmp;
		tmp <<= 8;
	}
	(*block) = square << ((row << 3) | column);
	return;
}
int moveLeft(uint64_t *block)
{
	uint64_t v = *block;
	if (v & 0x0101010101010101LLU)
	{
		return 0;
	}
	(*block) >>= 1;
	return 1;
}
int moveRight(uint64_t *block)
{
	uint64_t v = *block;
	if (v & 0x8080808080808080LLU)
	{
		return 0;
	}
	(*block) <<= 1;
	return 1;
}
int moveUp(uint64_t *block)
{
	uint64_t v = *block;

	if (v & 0x00000000000000FFLLU)
	{
		return 0;
	}
	(*block) >>= 8;
	return 1;
}
int moveDown(uint64_t *block)
{
	uint64_t v = *block;
	if (v & 0xFF00000000000000LLU)
	{
		return 0;
	}
	(*block) <<= 8;
	return 1;
}
#undef uint64_t