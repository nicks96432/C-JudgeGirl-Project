#include <stdio.h>
#include <assert.h>
#define MAX_N 32
int main(void)
{
	char filename[MAX_N][16];
	int i, n;
	int buffer[MAX_N] = {}, finish[MAX_N] = {};
	FILE *fin[MAX_N];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", filename[i]);
		fin[i] = fopen(filename[i], "rb");
		assert(fin[i] != NULL);
		fread(&buffer[i], sizeof(int), 1, fin[i]);
	}
	int min;
	int min__index;
	while (1)
	{
		min__index = -1;
		min = 2147483647;
		for (i = 0; i < n; i++)
		{
			if (finish[i] == 1)
			{
				continue;
			}
			if (buffer[i] <= min)
			{
				min = buffer[i];
				min__index = i;
			}
		}
		if (min__index == -1)
		{
			break;
		}
		printf("%d\n", buffer[min__index]);
		if (!fread(&buffer[min__index], sizeof(int), 1, fin[min__index]))
		{
			finish[min__index] = 1;
		}
	}
	for (i = 0; i < n; i++)
	{
		fclose(fin[i]);
	}
	return 0;
}