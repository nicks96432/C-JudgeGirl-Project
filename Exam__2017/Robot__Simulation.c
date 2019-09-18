#include <stdio.h>
int main(void)
{
	int i, n, m, x = 0, y = 0;
	scanf("%d%d", &n, &m);
	printf("0\n0\n");
	while (scanf("%d", &i) != EOF)
	{
		switch (i % 5)
		{
		case 0:
			break;
		case 1:
			if (x + i >= n)
			{
				continue;
			}
			else
			{
				x += i;
				printf("%d\n", x);
				printf("%d\n", y);
			}
			break;
		case 2:
			if (x - i < 0)
			{
				continue;
			}
			else
			{
				x -= i;
				printf("%d\n", x);
				printf("%d\n", y);
			}
			break;
		case 3:
			if (y + i >= m)
			{
				continue;
			}
			else
			{
				y += i;
				printf("%d\n", x);
				printf("%d\n", y);
			}
			break;
		case 4:
			if (y - i < 0)
			{
				continue;
			}
			else
			{
				y -= i;
				printf("%d\n", x);
				printf("%d\n", y);
			}
			break;
		}
	}
	return 0;
}