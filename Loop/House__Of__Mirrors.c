#include <stdio.h>
int main(void)
{
	// direction: 0:up, 1:left, 2:down, 3:right
	// now: 0:column, 1:row
	int i, j, w, d, direction, now[2];
	scanf("%d %d", &w, &d);
	int house[d + 2][w + 2];
	for (i = 1; i <= d; i++)
	{
		for (j = 1; j <= w; j++)
		{
			scanf("%d", &house[i][j]);
		}
	}
	house[0][0] = 2147483647;
	house[d + 1][w + 1] = 2147483647;
	house[0][w + 1] = 2147483647;
	house[d + 1][0] = 2147483647;
	for (i = 0; i < 2 * (w + d); i++)
	{
		if (i < w)
		{
			house[d + 1][i + 1] = i;
		}
		else if (i < w + d)
		{
			house[w + d - i][w + 1] = i;
		}
		else if (i < 2 * w + d)
		{
			house[0][2 * w + d - i] = i;
		}
		else
		{
			house[i - 2 * w - d + 1][0] = i;
		}
	}
	for (i = 0; i < 2 * (w + d); i++)
	{
		if (i < w)
		{
			now[0] = d + 1;
			now[1] = i + 1;
			direction = 0;
		}
		else if (i < w + d)
		{
			now[0] = w + d - i;
			now[1] = w + 1;
			direction = 1;
		}
		else if (i < 2 * w + d)
		{
			now[0] = 0;
			now[1] = 2 * w + d - i;
			direction = 2;
		}
		else
		{
			now[0] = i - 2 * w - d + 1;
			now[1] = 0;
			direction = 3;
		}
		do
		{
			if (direction == 0)
			{
				now[0]--;
			}
			else if (direction == 1)
			{
				now[1]--;
			}
			else if (direction == 2)
			{
				now[0]++;
			}
			else
			{
				now[1]++;
			}
			if (house[now[0]][now[1]] == 1)
			{
				if (direction == 0)
				{
					direction = 3;
				}
				else if (direction == 3)
				{
					direction = 0;
				}
				else if (direction == 1)
				{
					direction = 2;
				}
				else if (direction == 2)
				{
					direction = 1;
				}
			}
		} while (now[0] <= d && now[0] >= 1 && now[1] <= w && now[1] >= 1);
		printf("%d\n", house[now[0]][now[1]]);
	}
	return 0;
}