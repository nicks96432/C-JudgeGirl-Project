#include <stdio.h>
int main(void)
{
	int i, n, num, prev, ans;
	while (scanf("%d", &n) != EOF)
	{
		prev = -1;
		ans = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num);
			if (prev != num)
			{
				ans++;
			}
			prev = num;
		}
		printf("%d\n",ans);
	}
	return 0;
}