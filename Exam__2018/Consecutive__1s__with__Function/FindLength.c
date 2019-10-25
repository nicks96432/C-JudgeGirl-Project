#include <stdio.h>
int findLength(int array[][256], int N, int r, int c, int dr, int dc)
{
	int ans = 0, count = 0;
	while (1)
	{
		if (r < 0 || c < 0 || r >= N || c >= N)
		{
			return ans;
		}
		if (array[r][c])
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (ans < count)
		{
			ans = count;
		}
		r += dr;
		c += dc;
	}
	return ans;
}