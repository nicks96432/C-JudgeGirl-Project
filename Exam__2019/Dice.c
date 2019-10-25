#include <stdio.h>
#include <string.h>
int main(void)
{
	int r, c, ans = 0;
	scanf("%d%d", &r, &c);
	int array[r][c];
	int i, j, k, l;
	memset(array, -1, sizeof(array));
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	for (i = 1; i < r - 1; i++)
	{
		for (j = 0; j <= c - 4; j++)
		{
			if (array[i][j] == array[i][j + 1]||array[i][j]==array[i][j+3])
			{
				continue;
			}
			else if (array[i][j] + array[i][j + 2] == 7 && array[i][j + 1] + array[i][j + 3] == 7)
			{
				for (k = 0; k < 4; k++)
				{
					for (l = 0; l < 4; l++)
					{
						if (array[i - 1][j + k] + array[i + 1][j + l] == 7)
						{
							if (array[i - 1][j + k] != array[i][j] && array[i - 1][j + k] != array[i][j + 1] && array[i - 1][j + k] != array[i][j + 2] && array[i - 1][j + k] != array[i][j + 3] && array[i + 1][j + l] != array[i][j] && array[i + 1][j + l] != array[i][j + 1] && array[i + 1][j + l] != array[i][j + 2] && array[i + 1][j + l] != array[i][j + 3])
							{
								ans++;
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}