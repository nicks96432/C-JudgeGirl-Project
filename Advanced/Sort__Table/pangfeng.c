#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pangfeng.h"
void init(ExamTable *self, int n)
{
	self->countRow = 0;
	self->dim_n = n;
	return;
}
void addrow(ExamTable *self, char *name, int score[])
{
	strcpy((self->rows[self->countRow]).name, name);
	for (int i = 0; i < self->dim_n; i++)
	{
		(self->rows[self->countRow]).score[i] = score[i];
	}
	(self->countRow)++;
	return;
}
static int sortOrder[128], countSort = 0;
static int comp(const void *x, const void *y)
{
	Row *a = *(Row **)x, *b = *(Row **)y;
	for (int i = 0; i < countSort; i++)
	{
		int s = sortOrder[i];
		if (a->score[s] > b->score[s])
		{
			return -1;
		}
		else if (a->score[s] < b->score[s])
		{
			return 1;
		}
	}
	return strcmp(a->name, b->name);
}
void print(ExamTable *self, int order[])
{
	Row *tmpRow[MAX_ROW];
	for (int i = 0; i < self->countRow; i++)
	{
		tmpRow[i] = &(self->rows[i]);
	}
	for (int i = 0; i < self->dim_n; i++)
	{
		sortOrder[i] = order[i];
	}
	countSort = self->countRow;
	qsort(tmpRow, self->countRow, sizeof(Row *), comp);
	puts("----- table begin -----");
	for (int i = 0; i < self->countRow; i++)
	{
		printf("%s", tmpRow[i]->name);
		for (int j = 0; j < self->dim_n; j++)
		{
			printf(", %d", tmpRow[i]->score[j]);
		}
		puts("");
	}
	puts("----- end         -----");
	return;
}