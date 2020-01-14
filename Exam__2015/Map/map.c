#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
void init(Map *map)
{
	map->countPair = 0;
	return;
}
int map(Map *map, const int key, const char *value)
{
	int i, mapped = 1;
	for (i = 0; i < map->countPair; i++)
	{
		if (map->pairs[i].key == key)
		{
			mapped = 0;
			break;
		}
	}
	map->pairs[i].key = key;
	strcpy(map->pairs[i].value, value);
	if (mapped)
	{
		map->countPair++;
	}
	return mapped;
}
int numPairs(Map *map)
{
	return map->countPair;
}
int compPair(const void *x, const void *y)
{
	Pair *a = (Pair *)x, *b = (Pair *)y;
	if (a->key > b->key)
	{
		return 1;
	}
	else if (a->key < b->key)
	{
		return -1;
	}
	else
	{
		return strcmp(a->value, b->value);
	}
}
void print(Map *map)
{
	qsort(map->pairs, map->countPair, sizeof(Pair), compPair);
	puts("----- map begin -----");
	for (int i = 0; i < map->countPair; i++)
	{
		printf("%d %s\n", map->pairs[i].key, map->pairs[i].value);
	}
	puts("----- end       -----");
	return;
}
const char *getValue(Map *map, const int key)
{
	for (int i = 0; i < map->countPair; i++)
	{
		if (map->pairs[i].key == key)
		{
			return map->pairs[i].value;
		}
	}
	return NULL;
}
int unmap(Map *map, const int key)
{
	for (int i = 0; i < map->countPair; i++)
	{
		if (map->pairs[i].key == key)
		{
			for (int j = i; j < map->countPair; j++)
			{
				map->pairs[j] = map->pairs[j + 1];
			}
			map->countPair--;
			return 1;
		}
	}
	return 0;
}
int compInt(const void *x, const void *y)
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
int reverseMap(Map *map, const char *value, int keys[])
{
	int count = 0;
	for (int i = 0; i < map->countPair; i++)
	{
		if (!strcmp(map->pairs[i].value, value))
		{
			keys[count] = map->pairs[i].key;
			count++;
		}
	}
	qsort(keys, count, sizeof(int), compInt);
	return count;
}