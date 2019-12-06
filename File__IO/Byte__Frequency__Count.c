#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	char filename[202];
	short numlist[65536] = {0};
	scanf("%s", filename);
	FILE *fin;
	fin = fopen(filename, "rb");
	int n;
	fread(&n, sizeof(int), 1, fin);
	int i, count = 0, j, found;
	short num;
	for (i = 0; i < n; i++)
	{
		fread(&num, sizeof(short), 1, fin);
		numlist[num + 32768]++;
	}
	int max = -2147483648, maxnum = -1;
	for (i = 0; i < 65536; i++)
	{
		if (numlist[i] > max || (numlist[i] == max && i > maxnum))
		{
			max = numlist[i];
			maxnum = i - 32768;
		}
	}
	printf("%d\n%d\n", maxnum, max);
	fclose(fin);
	return 0;
}