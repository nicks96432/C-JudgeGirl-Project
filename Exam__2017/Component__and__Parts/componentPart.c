#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "componentPart.h"
#define MAX_N 128
int compute(ComponentPart list[], int index)
{
	if (list[index].price == 0)
	{
		int i;
		for (i = 0; i < list[index].numComponent; i++)
		{
			list[index].price += compute(list, list[index].componentPartList[i]);
		}
	}
	return list[index].price;
}
int comp(const void *x, const void *y)
{
	return strcmp((*(ComponentPart **)x)->name, (*(ComponentPart **)y)->name);
}
void findPrice(int N, ComponentPart list[])
{
	int i, com;
	ComponentPart *sort[MAX_N];
	for (i = 0; i < N; i++)
	{
		if (list[i].price == 0)
		{
			com = compute(list, i);
		}
		sort[i] = &list[i];
	}
	qsort((void *)sort, N, sizeof(sort[0]), comp);
	for (i = 0; i < N; i++)
	{
		printf("%s %d\n", sort[i]->name, sort[i]->price);
	}
	return;
}