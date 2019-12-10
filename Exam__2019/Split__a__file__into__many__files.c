#include <stdio.h>
#include <string.h>
#include <assert.h>
#define MAX_N 10
int main(void)
{
	char namein[52], nameout[52];
	int n;
	memset(nameout, 0, sizeof(nameout));
	scanf("%s%d%s", namein, &n, nameout);
	int i, outlen = strlen(nameout);
	FILE *fin = fopen(namein, "r");
	FILE *fout[MAX_N];
	int len[MAX_N] = {};
	int ten, one;
	assert(fin != NULL);
	for (i = 0; i < n; i++)
	{
		ten = i / 10;
		one = i % 10 + 1;
		ten += one == 10;
		one %= 10;
		if (ten > 0)
		{
			nameout[outlen] = ten + '0';
			nameout[outlen + 1] = one + '0';
		}
		else
		{
			nameout[outlen] = one + '0';
		}
		fout[i] = fopen(nameout, "wb");
	}
	int minlen, minlen__index;
	unsigned char byte = 0;
	while (!feof(fin))
	{
		minlen = 2147483647;
		minlen__index = -1;
		for (i = 0; i < n; i++)
		{
			if (len[i] < minlen)
			{
				minlen = len[i];
				minlen__index = i;
			}
		}
		while ((byte = fgetc(fin)) != EOF)
		{
			if (byte == 255)
			{
				break;
			}
			fputc(byte, fout[minlen__index]);
			len[minlen__index]++;
		}
	}
	fclose(fin);
	for (i = 0; i < n; i++)
	{
		fclose(fout[i]);
	}
	return 0;
}