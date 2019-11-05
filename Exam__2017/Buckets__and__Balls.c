#include <stdio.h>
int main(void)
{
	int n, m, r, w;
	scanf("%d%d%d", &n, &m, &r);
#ifdef DEBUG
	printf("%d %d %d\n", n, m, r);
#endif
	while (scanf("%d", &w) != EOF)
	{
		if (r == 1)
		{
			if (n >= w && m >= w)
			{
				if (n <= m)
				{
					n -= w;
				}
				else
				{
					m -= w;
				}
			}
			else if (n < w && m >= w)
			{
				m -= w;
			}
			else if (n >= w && m < w)
			{
				n -= w;
			}
		}
		else if (r == 0)
		{
			if (n >= w)
			{
				n -= w;
			}
			else if (m >= w)
			{
				m -= w;
			}
		}
		printf("%d %d\n", n, m);
	}
	return 0;
}