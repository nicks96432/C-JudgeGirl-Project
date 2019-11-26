#include "compute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_JOURNAL 1024
typedef struct
{
	char name[64];
	int countpaper;
	int countcited;
} Journal;
int comp(const void *x, const void *y)
{
	Journal *a = (Journal *)x, *b = (Journal *)y;
	return strcmp(a->name, b->name);
}
void compute(paper p[], int N)
{
	int i, j, k, countjournal = 0;
	Journal journal[MAX_JOURNAL];
	for (i = 0; i < MAX_JOURNAL; i++)
	{
		memset(journal[i].name, 0, sizeof(journal[i].name));
		journal[i].countpaper = 0;
		journal[i].countcited = 0;
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < MAX_JOURNAL; j++)
		{
			if (!strcmp(journal[j].name, p[i].journalName))
			{
				journal[j].countpaper++;
				break;
			}
		}
		if (j == MAX_JOURNAL)
		{
			strcpy(journal[countjournal].name, p[i].journalName);
			journal[countjournal].countpaper++;
			countjournal++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < p[i].numCitedPaper; j++)
		{
			for (k = 0; k < MAX_JOURNAL; k++)
			{
				if (!(strcmp(p[p[i].citedPaperIndex[j]].journalName, journal[k].name)))
				{
					journal[k].countcited++;
					break;
				}
			}
		}
	}
	qsort((void *)journal,countjournal,sizeof(Journal),comp);
	for (i = 0; i < MAX_JOURNAL; i++)
	{
		if (journal[i].name[0] == 0)
		{
			break;
		}
		printf("%s %d/%d\n", journal[i].name, journal[i].countcited, journal[i].countpaper);
	}
	return;
}