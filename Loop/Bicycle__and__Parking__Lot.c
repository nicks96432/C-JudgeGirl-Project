#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : (-(x)))
int distance(int, int, int, int);
int find__lot(int[][3], int[], int[], int);
int main(void)
{
	/* 0:x, 1:y, 2:capacity */
	int lot[10][3];
	int i, n, m, bicycle__x, bicycle__y, lot__bicycle[10] = {0};
	int dist[10] = {2147483647}, nearest__x, nearest__y;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &lot[i][0], &lot[i][1], &lot[i][2]);
	}
	scanf("%d", &m);
	while (scanf("%d%d", &bicycle__x, &bicycle__y) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			dist[i] = distance(bicycle__x, bicycle__y, lot[i][0], lot[i][1]);
		}
		lot__bicycle[find__lot(lot, dist, lot__bicycle, n)]++;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d\n", lot__bicycle[i]);
	}
	return 0;
}
int find__lot(int lot[][3], int dist[], int lot__bicycle[], int n)
{
	int i, j, min = 2147483647, index = 0;
	int tmp[n], tmplot[n][2], swap;
	for (i = 0; i < n; i++)
	{
		tmp[i] = dist[i];
		tmplot[i][0] = lot[i][0];
		tmplot[i][1] = lot[i][1];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (tmp[j] > tmp[j + 1] || (tmp[j] == tmp[j + 1] && tmplot[j][0] > tmplot[j + 1][0]) || (tmp[j] == tmp[j + 1] && tmplot[j][0] == tmplot[j + 1][0] && tmplot[j][1] > tmplot[j + 1][1]))
			{
				swap = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = swap;
				swap = tmplot[j][0];
				tmplot[j][0] = tmplot[j + 1][0];
				tmplot[j + 1][0] = swap;
				swap = tmplot[j][1];
				tmplot[j][1] = tmplot[j + 1][1];
				tmplot[j + 1][1] = swap;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (tmplot[i][0] == lot[j][0] && tmplot[i][1] == lot[j][1])
			{
				tmp[index] = j;
				index++;
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (lot[tmp[i]][2] > lot__bicycle[tmp[i]])
		{
			break;
		}
	}
	return tmp[i];
}
int distance(int x1, int y1, int x2, int y2)
{
	return (abs(x1 - x2) + abs(y1 - y2));
}