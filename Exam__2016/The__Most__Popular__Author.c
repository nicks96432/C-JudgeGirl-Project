#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_M 100
#define MAX_LEN 64
typedef struct _Book
{
	char name[MAX_LEN];
	char author[MAX_LEN];
	int sell;
} Book;
int compBook(const void *x, const void *y)
{
	Book *a = (Book *)x, *b = (Book *)y;
	int comp = strcmp(a->author, b->author);
	if (comp == 0)
	{
		return strcmp(a->name, b->name);
	}
	else
	{
		return comp;
	}
}
int main(void)
{
	int m;
	scanf("%d", &m);
	Book books[MAX_M];
	for (int i = 0; i < m; i++)
	{
		scanf("%s%s", books[i].author, books[i].name);
		books[i].sell = 0;
	}
	int sell;
	char name[MAX_LEN];
	for (int i = 0; i < m; i++)
	{
		scanf("%s%d", name, &sell);
		for (int j = 0; j < m; j++)
		{
			if (!strcmp(name, books[j].name))
			{
				books[j].sell += sell;
				break;
			}
		}
	}
	qsort(books, m, sizeof(Book), compBook);
	int max = 0, count = 0;
	char maxName[MAX_LEN] = {};
	for (int i = 0; i < m; i++)
	{
		if (strcmp(name, books[i].author) != 0)
		{
			strcpy(name, books[i].author);
			count = books[i].sell;
		}
		else
		{
			count += books[i].sell;
		}
		if (count > max)
		{
			max = count;
			strcpy(maxName, name);
		}
	}
	printf("%s %d\n", maxName, max);
	return 0;
}