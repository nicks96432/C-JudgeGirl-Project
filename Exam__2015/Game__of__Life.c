#include <stdio.h>
#include <stdbool.h>
#include <string.h>
enum state
{
	A,
	B
};
int main(void)
{
	int i, j, n, k;
	scanf("%d%d", &n, &k);
	bool stateA[n + 2][n + 2], stateB[n + 2][n + 2];
	bool switch__state = A;
	int longest__x = -2147483647, longest__y = -2147483647, longest = -2147483647;
	int alive__times[n + 2][n + 2];
	for (i = 0; i < n + 2; i++)
	{
		memset(stateA[i], 0, sizeof(bool) * (n + 2));
		memset(stateB[i], 0, sizeof(bool) * (n + 2));
		memset(alive__times[i], 0, sizeof(int) * (n + 2));
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &stateA[i][j]);
			alive__times[i][j] = stateA[i][j];
		}
	}
	int now = 0, count;
	while (now < k)
	{
		now++;
		if (switch__state == A)
		{
			switch__state = B;
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					count = stateA[i - 1][j - 1] + stateA[i - 1][j] + stateA[i - 1][j + 1] + stateA[i][j - 1] + stateA[i][j + 1] + stateA[i + 1][j - 1] + stateA[i + 1][j] + stateA[i + 1][j + 1];
					if (count == 3 && stateA[i][j] == false)
					{
						stateB[i][j] = true;
					}
					else if ((count < 2 || count > 3) && stateA[i][j] == true)
					{
						stateB[i][j] = false;
					}
					else
					{
						stateB[i][j] = stateA[i][j];
					}
				}
			}
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (stateB[i][j] == true)
					{
						alive__times[i][j]++;
					}
				}
			}
		}
		else if (switch__state == B)
		{
			switch__state = A;
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					count = stateB[i - 1][j - 1] + stateB[i - 1][j] + stateB[i - 1][j + 1] + stateB[i][j - 1] + stateB[i][j + 1] + stateB[i + 1][j - 1] + stateB[i + 1][j] + stateB[i + 1][j + 1];
					if (count == 3 && stateB[i][j] == false)
					{
						stateA[i][j] = true;
					}
					else if ((count < 2 || count > 3) && stateB[i][j] == true)
					{
						stateA[i][j] = false;
					}
					else
					{
						stateA[i][j] = stateB[i][j];
					}
				}
			}
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (stateA[i][j] == true)
					{
						alive__times[i][j]++;
					}
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (alive__times[i][j] > longest)
			{
				longest = alive__times[i][j];
				longest__x = i;
				longest__y = j;
			}
			if (alive__times[i][j] == longest && i > longest__x)
			{
				longest = alive__times[i][j];
				longest__x = i;
				longest__y = j;
			}
			if (alive__times[i][j] == longest && i == longest__x && j > longest__y)
			{
				longest = alive__times[i][j];
				longest__x = i;
				longest__y = j;
			}
		}
	}
	if (switch__state == A)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j < n; j++)
			{
				printf("%d ", stateA[i][j]);
			}
			printf("%d\n", stateA[i][j]);
		}
	}
	else if (switch__state==B)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j < n; j++)
			{
				printf("%d ", stateB[i][j]);
			}
			printf("%d\n", stateB[i][j]);
		}
	}
	printf("%d %d", longest__x, longest__y);
	return 0;
}