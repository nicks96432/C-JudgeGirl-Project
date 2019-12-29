#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct string_count
{
	char seen[80];
	int count;
};
int compare_and_add(char *string, struct string_count strings[])
{
	int i;
	for (i = 0; strings[i].count != 0; i++)
	{
		if (!strcmp(string, strings[i].seen))
		{
			strings[i].count++;
			return 1;
		}
	}
	strings[i].count = 1;
	strcpy(strings[i].seen, string);
	return 0;
}
int comp(const void *x, const void *y)
{
	const struct string_count *a = x, *b = y;
	if (a->count != b->count)
	{
		return a->count - b->count;
	}
	else
	{
		return strcmp(a->seen, b->seen);
	}
}
void sort(struct string_count strings[])
{
	int i = 0;
	while (strings[i].count != 0)
	{
		i++;
	}
	qsort(strings, i, sizeof(strings[0]), comp);
	return;
}
void print(struct string_count strings[])
{
	for (int i = 0; strings[i].count != 0; i++)
	{
		printf("%d %s\n", strings[i].count, strings[i].seen);
	}
	return;
}