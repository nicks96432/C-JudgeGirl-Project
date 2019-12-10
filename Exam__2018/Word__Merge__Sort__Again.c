#include <stdio.h>
#include <string.h>
#define MAX_FILE 21
int main(void)
{
	int n;
	scanf("%d", &n);
	FILE *fin[MAX_FILE], *fout;
	char filename[25];
	char buffer[MAX_FILE][3];
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%s", &filename);
		fin[i] = fopen(filename, "r");
		fread(buffer[i], sizeof(char), 3, fin[i]);
	}
	scanf("%s", &filename);
	fout = fopen(filename, "w");
	int min, tmp, min__id;
	int finish[MAX_FILE] = {};
	while (1)
	{
		min = 2147483647;
		min__id = -1;
		for (i = 0; i < n; i++)
		{
			if (finish[i])
			{
				continue;
			}
			tmp = 1000000 * buffer[i][0] + 1000 * buffer[i][1] + buffer[i][2];
			if (tmp < min)
			{
				min = tmp;
				min__id = i;
			}
		}
		if (min__id==-1)
		{
			break;
		}
		fwrite(buffer[min__id], sizeof(char), 3, fout);
		if (!fread(buffer[min__id], sizeof(char), 3, fin[min__id]))
		{
			finish[min__id] = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		fclose(fin[i]);
	}
	fclose(fout);
	return 0;
}