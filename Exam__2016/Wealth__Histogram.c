#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#define NAME_LEN 12
#define MAX_N (1 << 10)
typedef struct Person
{
	char name[NAME_LEN];
	unsigned int wealth;
} person;
int comp(const void *x, const void *y)
{
	person *a = (person *)x, *b = (person *)y;
	if (a->wealth > b->wealth)
	{
		return 1;
	}
	else if (a->wealth < b->wealth)
	{
		return -1;
	}
	else
	{
		return (strcmp(a->name, b->name) > 0) ? 1 : -1;
	}
}
int main(int argc, char const *argv[])
{
	assert(argc >= 2);
	FILE *input = fopen(argv[1], "rb");
	assert(input != NULL);
	person people[MAX_N];
	int n = fread(people, sizeof(person), MAX_N, input);
	fclose(input);
	qsort(people, n, sizeof(person), comp);
	int diagram[MAX_N];
	for (int i = 0; i < n; i++)
	{
		diagram[i] = people[i].wealth / 1000;
	}
	for (int i = 0; i < n;)
	{
		int count = 0, now = diagram[i];
		while (i < n && now == diagram[i])
		{
			count++;
			i++;
		}
		printf("%d\n", count);
	}
	int last = n - 1;
	while (last - 1 >= 0 && people[last - 1].wealth == people[last].wealth)
	{
		last--;
	}
	unsigned int median = 0;
	if (n % 2 == 0)
	{
		median = (people[n / 2].wealth + people[n / 2 - 1].wealth) / 2;
	}
	else
	{
		median = people[n / 2].wealth;
	}
	printf("%s\n%s\n%u\n", people[0].name, people[last].name, median);
	return 0;
}