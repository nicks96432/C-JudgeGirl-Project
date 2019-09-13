#include <stdio.h>
typedef struct Circles
{
	long long int x;
	long long int y;
	long long int r;
} circles;
int main(void)
{
	int k, n, ans = 0, count = 0, tmp, list[1003][2], count__list = 0, in__list = 0;
	long long int i, j;
	circles circle[3];
	scanf("%d", &n);
	for (; n > 0; n--)
	{
		ans = 0;
		count = 0;
		count__list = 0;
		for (i = 0; i < 1003; i++)
		{
			for (j = 0; j < 2; j++)
			{
				list[i][j] = 0x7fffffff;
			}
		}
		for (i = 0; i < 3; i++)
		{
			scanf("%lld %lld %lld", &circle[i].x, &circle[i].y, &circle[i].r);
		}
		for (i = circle[0].x - circle[0].r; i <= circle[0].x + circle[0].r; i++)
		{
			for (j = circle[0].y - circle[0].r; j <= circle[0].y + circle[0].r; j++)
			{
				count = 0;
				in__list = 0;
				if ((i - circle[0].x) * (i - circle[0].x) + (j - circle[0].y) * (j - circle[0].y) <= circle[0].r * circle[0].r)
				{
					count++;
				}
				if ((i - circle[1].x) * (i - circle[1].x) + (j - circle[1].y) * (j - circle[1].y) <= circle[1].r * circle[1].r)
				{
					count++;
				}
				if ((i - circle[2].x) * (i - circle[2].x) + (j - circle[2].y) * (j - circle[2].y) <= circle[2].r * circle[2].r)
				{
					count++;
				}
				if ((count % 2) != 0)
				{
					// find if the point is in the list
					for (k = 0; k <= count__list; k++)
					{
						if (i == list[k][0] && j == list[k][1])
						{
							in__list = 1;
							break;
						}
					}
					if (!in__list)
					{
						list[count__list][0] = i;
						list[count__list][1] = j;
						count__list++;
						ans++;
					}
				}
			}
		}
		for (i = circle[1].x - circle[1].r; i <= circle[1].x + circle[1].r; i++)
		{
			for (j = circle[1].y - circle[1].r; j <= circle[1].y + circle[1].r; j++)
			{
				count = 0;
				in__list = 0;
				if ((i - circle[0].x) * (i - circle[0].x) + (j - circle[0].y) * (j - circle[0].y) <= circle[0].r * circle[0].r)
				{
					count++;
				}
				if ((i - circle[1].x) * (i - circle[1].x) + (j - circle[1].y) * (j - circle[1].y) <= circle[1].r * circle[1].r)
				{
					count++;
				}
				if ((i - circle[2].x) * (i - circle[2].x) + (j - circle[2].y) * (j - circle[2].y) <= circle[2].r * circle[2].r)
				{
					count++;
				}
				if ((count % 2) != 0)
				{
					// find if the point is in the list
					for (k = 0; k <= count__list; k++)
					{
						if (i == list[k][0] && j == list[k][1])
						{
							in__list = 1;
							break;
						}
					}
					if (!in__list)
					{
						list[count__list][0] = i;
						list[count__list][1] = j;
						count__list++;
						ans++;
					}
				}
			}
		}
		for (i = circle[2].x - circle[2].r; i <= circle[2].x + circle[2].r; i++)
		{
			for (j = circle[2].y - circle[2].r; j <= circle[2].y + circle[2].r; j++)
			{
				count = 0;
				in__list = 0;
				if ((i - circle[0].x) * (i - circle[0].x) + (j - circle[0].y) * (j - circle[0].y) <= circle[0].r * circle[0].r)
				{
					count++;
				}
				if ((i - circle[1].x) * (i - circle[1].x) + (j - circle[1].y) * (j - circle[1].y) <= circle[1].r * circle[1].r)
				{
					count++;
				}
				if ((i - circle[2].x) * (i - circle[2].x) + (j - circle[2].y) * (j - circle[2].y) <= circle[2].r * circle[2].r)
				{
					count++;
				}
				if ((count % 2) != 0)
				{
					// find if the point is in the list
					for (k = 0; k <= count__list; k++)
					{
						if (i == list[k][0] && j == list[k][1])
						{
							in__list = 1;
							break;
						}
					}
					if (!in__list)
					{
						list[count__list][0] = i;
						list[count__list][1] = j;
						count__list++;
						ans++;
					}
				}
			}
		}
		printf("%d\n", count__list);
	}
	return 0;
}