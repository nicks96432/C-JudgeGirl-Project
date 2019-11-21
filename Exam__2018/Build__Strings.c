#include <stdio.h>
#include <string.h>
#define MAX_L 1025
#define abs(x) ((x) > 0 ? (x) : (-(x)))
static int K, L, N, countN = 0;
static char C, ans[MAX_L];
void build(int count)
{
	if (ans[0] != 0 && ans[0] != C)
	{
		return;
	}
	if (countN >= N)
	{
		return;
	}
	if (count == L)
	{
		countN++;
		printf("%s\n", ans);
		return;
	}
	int i;
	for (i = 'a'; i <= 'z'; i++)
	{
		if (i >= ans[count - 1] && i - ans[count - 1] > K)
		{
			continue;
		}
		else if (i <= ans[count - 1] && i + 26 - ans[count - 1] > K)
		{
			continue;
		}
		ans[count] = (i - 'a') % 26 + 'a';
		build(count + 1);
	}
	return;
}
int main(void)
{
	memset(ans, 0, sizeof(ans));
	scanf("%c %d %d %d", &C, &K, &L, &N);
	ans[0] = C;
	build(1);
	return 0;
}