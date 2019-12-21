#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
typedef struct Pair
{
	int index1;
	int index2;
	int value;
} pair;
typedef struct Number
{
	int index;
	int value;
} number;
int compNum(const void *x, const void *y)
{
#ifdef INC
	return ((number *)x)->value - ((number *)y)->value;
#elif defined DEC
	return ((number *)y)->value - ((number *)x)->value;
#endif
}
int compPair(const void *x, const void *y)
{
	pair *a = (pair *)x;
	pair *b = (pair *)y;
#ifdef INC
	if (a->value > b->value)
	{
		return 1;
	}
	else if (a->value < b->value)
	{
		return -1;
	}
	else
	{
		return a->index1 - b->index1;
	}
#elif defined DEC
	if (a->value > b->value)
	{
		return -1;
	}
	else if (a->value < b->value)
	{
		return 1;
	}
	else
	{
		return b->index1 - a->index1;
	}
#endif
}
void pairPrint(int numbers[], int n)
{

	int i;
	number sortedNumbers[n];
	for (i = 0; i < n; i++)
	{
		sortedNumbers[i].value = numbers[i];
		sortedNumbers[i].index = i;
	}
	qsort((void *)sortedNumbers, n, sizeof(number), compNum);
	pair pairs[n / 2 + 1];
	for (i = 0; i < n / 2; i++)
	{
#ifdef INC
		pairs[i].index1 = min(sortedNumbers[i].index,
							  sortedNumbers[n - i - 1].index);
		pairs[i].index2 = max(sortedNumbers[i].index,
							  sortedNumbers[n - i - 1].index);
#elif defined DEC
		pairs[i].index1 = max(sortedNumbers[i].index,
							  sortedNumbers[n - i - 1].index);
		pairs[i].index2 = min(sortedNumbers[i].index,
							  sortedNumbers[n - i - 1].index);
#endif
		pairs[i].value = numbers[pairs[i].index1] +
						 numbers[pairs[i].index2];
	}
	qsort((void *)pairs, n / 2, sizeof(pair), compPair);
	for (i = 0; i < n / 2; i++)
	{
		printf("%d = numbers[%d] + numbers[%d]\n", pairs[i].value,
			   pairs[i].index1, pairs[i].index2);
	}
	return;
}