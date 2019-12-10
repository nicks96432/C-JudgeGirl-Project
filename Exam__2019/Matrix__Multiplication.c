#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#define MAX_N 32
int main(void)
{
	int32_t mata[MAX_N][MAX_N] = {};
	int32_t matb[MAX_N][MAX_N] = {};
	int64_t matc[MAX_N][MAX_N] = {};
	int i, j, k, len, n, ten, one;
	scanf("%d", &n);
	char filenames[3][25] = {};
	FILE *files[3][MAX_N];
	for (i = 0; i < 3; i++)
	{
		scanf("%s", filenames[i]);
		len = strlen(filenames[i]);
		for (j = 0; j < n; j++)
		{
			ten = j / 10;
			one = j % 10 + 1;
			ten += (one == 10) ? 1 : 0;
			one %= 10;
			if (ten == 0)
			{
				filenames[i][len] = one + '0';
				filenames[i][len + 1] = '\0';
			}
			else
			{
				filenames[i][len] = ten + '0';
				filenames[i][len + 1] = one + '0';
				filenames[i][len + 2] = '\0';
			}
			if (i == 2)
			{
				files[i][j] = fopen(filenames[i], "wb");
			}
			else
			{
				files[i][j] = fopen(filenames[i], "rb");
			}
			assert(files[i][j] != NULL);
		}
	}
	for (i = 0; i < n; i++)
	{
		fread(mata[i], sizeof(int32_t), n, files[0][i]);
		fread(matb[i], sizeof(int32_t), n, files[1][i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matc[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				matc[i][j] += (int64_t)mata[i][k] * (int64_t)matb[k][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		fwrite(matc[i], sizeof(int64_t), n, files[2][i]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < n; j++)
		{
			fclose(files[i][j]);
		}
	}
	return 0;
}