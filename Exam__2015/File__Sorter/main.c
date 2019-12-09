#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "fs.h"
#define MAX_N 65536
Account accounts[MAX_N];
int isvalid(Account *a)
{
	if (a->gender != 0 && a->gender != 1)
	{
		return 0;
	}
	if (a->balance < 0)
	{
		return 0;
	}
	int i, len = strlen(a->name);
	for (i = 0; i < len; i++)
	{
		if (a->name[i] != ' '&& !isalpha(a->name[i]))
		{
			return 0;
		}
	}
	return 1;
}
int comp(const void *x, const void *y)
{
	return strcmp(((Account *)x)->name, ((Account *)y)->name);
}
int main(void)
{
	int i, len, count = 0;
	char invalid, namein[32], nameout[32];
	scanf("%s%s", namein, nameout);
	FILE *fin = fopen(namein, "rb");
	FILE *fout = fopen(nameout, "wb");
	assert(fin && fout);
	Account tmp;
	while (fread(&tmp, sizeof(Account), 1, fin) == 1)
	{
		if (!isvalid(&tmp))
		{
			continue;
		}
		accounts[count++] = tmp;
	}
	qsort((void *)accounts, count, sizeof(Account), comp);
	fwrite(accounts, sizeof(Account), count, fout);
	fclose(fin);
	fclose(fout);
	return 0;
}