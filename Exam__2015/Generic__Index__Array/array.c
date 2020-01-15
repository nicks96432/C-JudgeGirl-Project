#include <stdio.h>
#include <stdlib.h>
#include "array.h"
void init(ARRAY *darray, int startIndex, int endIndex)
{
	darray->start = startIndex;
	darray->end = endIndex;
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		darray->value[i] = -2147483647;
	}
	return;
}
int set(ARRAY *array, int index, int value)
{
	if (index >= array->start && index <= array->end)
	{
		array->value[index - array->start] = value;
		return 1;
	}
	else
	{
		return -2147483648;
	}
}
int get(ARRAY *array, int index)
{
	if (index >= array->start && index <= array->end)
	{
		return array->value[index - array->start];
	}
	else
	{
		return -2147483648;
	}
}
void print(ARRAY *array)
{
	for (int i = 0; i <= array->end - array->start; i++)
	{
		if (array->value[i] == -2147483647)
		{
			puts("No value");
		}
		else
		{
			printf("%d\n", array->value[i]);
		}
	}
	return;
}
int comp(const void *x, const void *y)
{
	if (*(int *)x > *(int *)y)
	{
		return 1;
	}
	else if (*(int *)x < *(int *)y)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
void sort(ARRAY *array)
{
	qsort(array->value,array->end - array->start + 1, sizeof(int), comp);
	return;
}