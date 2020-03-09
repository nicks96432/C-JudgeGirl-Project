#include <stdio.h>
#include <string.h>
#include "tct.h"
static void printBlank(int n, int gap[], Directory *path[])
{
	putchar(' ');
	for (int i = 1; i < n; i++)
	{
		int toPrint = gap[i] - gap[i - 1];
		while (toPrint--)
		{
			putchar(' ');
		}
		if (path[i + 1] != NULL && path[i + 1]->silbingDir != NULL)
		{
			putchar('|');
		}
		else
		{
			putchar(' ');
		}
	}
	return;
}
static void print(int depth, int blank, Directory *dir, int gap[], Directory *path[])
{
	Directory *ptr = dir->childDir;
	gap[depth] = blank;
	path[depth] = dir;
	if (ptr != NULL)
	{
		printBlank(depth, gap, path);
		puts("  |");
	}
	while (ptr != NULL)
	{
		printBlank(depth, gap, path);
		printf("  +- %s\n", ptr->name);
		print(depth + 1, blank + 2, ptr, gap, path);
		ptr = ptr->silbingDir;
		if (ptr != NULL)
		{
			printBlank(depth, gap, path);
			puts("  |");
		}
	}
	return;
}
void tree(Directory *fs)
{
	printf("+- %s\n", fs->name);
	int gap[256] = {2};
	Directory *path[256] = {NULL};
	print(1, 4, fs, gap, path);
	return;
}
Directory *cd(Directory *fs, char path[])
{
	Directory *ans = fs;
	char *start = strtok(path, "/");
	while (start != NULL)
	{
		Directory *ptr = ans->childDir;
		while (ptr != NULL)
		{
			if (!strcmp(start, ptr->name))
			{
				break;
			}
			ptr = ptr->silbingDir;
		}
		if (ptr == NULL)
		{
			return NULL;
		}
		ans = ptr;
		start = strtok(NULL, "/");
	}
	return ans;
}