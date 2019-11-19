#include <stdint.h>
#include "BubbleSort.h"
void BubbleSort(uint64_t input, uint64_t output[63])
{
	int count;
	uint64_t i, j;
	for (j = 1ULL, count = 0; j <= 1ULL << 63 && j > 0 && count < 63; count++, j <<= 1)
	{
		for (i = 0x8000000000000000ULL; i > j; i >>= 1)
		{
			if ((input & i) && (!(input & (i >> 1))))
			{
				input &= (~i);
				input |= (i >> 1);
			}
		}
		output[count] = input;
	}
	return;
}