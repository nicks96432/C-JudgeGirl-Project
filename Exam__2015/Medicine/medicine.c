#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medicine.h"
void init(Medicine *medicine)
{
	medicine->countActive = 0;
	medicine->countInactive = 0;
	return;
}
int addActive(Medicine *medicine, char *name, int weight)
{
	for (int i = 0; i < medicine->countActive; i++)
	{
		if (!strcmp(medicine->active[i].name, name))
		{
			medicine->active[i].weight += weight;
			return medicine->active[i].weight;
		}
	}
	if (medicine->countActive == 2)
	{
		return -1;
	}
	medicine->active[medicine->countActive].weight = weight;
	strcpy(medicine->active[medicine->countActive].name, name);
	medicine->countActive++;
	return weight;
}
int addInactive(Medicine *medicine, char *name, int weight)
{
	for (int i = 0; i < medicine->countInactive; i++)
	{
		if (!strcmp(medicine->inactive[i].name, name))
		{
			medicine->inactive[i].weight += weight;
			return medicine->inactive[i].weight;
		}
	}
	if (medicine->countInactive == 5)
	{
		return -1;
	}
	medicine->inactive[medicine->countInactive].weight = weight;
	strcpy(medicine->inactive[medicine->countInactive].name, name);
	medicine->countInactive++;
	return weight;
}
int compIngredientPtr(const void *x, const void *y)
{
	Ingredient *a = *(Ingredient **)x, *b = *(Ingredient **)y;
	if (a->weight > b->weight)
	{
		return -1;
	}
	else if (a->weight < b->weight)
	{
		return 1;
	}
	else
	{
		return strcmp(a->name, b->name);
	}
}
void print(Medicine *medicine)
{
	Ingredient *activePtr[2], *inactivePtr[5];
	for (int i = 0; i < medicine->countActive; i++)
	{
		activePtr[i] = &medicine->active[i];
	}
	for (int i = 0; i < medicine->countInactive; i++)
	{
		inactivePtr[i] = &medicine->inactive[i];
	}
	qsort(activePtr, medicine->countActive, sizeof(Ingredient *), compIngredientPtr);
	qsort(inactivePtr, medicine->countInactive, sizeof(Ingredient *), compIngredientPtr);
	puts("----- Active Ingredient begin   -----");
	for (int i = 0; i < medicine->countActive; i++)
	{
		printf("%d %s\n", activePtr[i]->weight, activePtr[i]->name);
	}
	puts("----- end                       -----");
	puts("----- Inactive Ingredient begin -----");
	for (int i = 0; i < medicine->countInactive; i++)
	{
		printf("%d %s\n", inactivePtr[i]->weight, inactivePtr[i]->name);
	}
	puts("----- end                       -----");
	return;
}
int totalWeight(Medicine *medicine)
{
	int total = 0;
	for (int i = 0; i < medicine->countActive; i++)
	{
		total += medicine->active[i].weight;
	}
	for (int i = 0; i < medicine->countInactive; i++)
	{
		total += medicine->inactive[i].weight;
	}
	return total;
}
char *maxIngredient(Medicine *medicine)
{
	int i, count = 0;
	Ingredient *all[10];
	for (i = 0; i < medicine->countActive; i++)
	{
		all[count] = &(medicine->active[i]);
		count++;
	}
	for (i = 0; i < medicine->countInactive; i++)
	{
		all[count] = &(medicine->inactive[i]);
		count++;
	}
	if (count == 0)
	{
		return NULL;
	}
	qsort(all, count, sizeof(Ingredient *), compIngredientPtr);
	return all[0]->name;
}