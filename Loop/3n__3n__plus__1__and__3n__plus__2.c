#include <stdio.h>
int main()
{
	int i, n, n0 = 0, n1 = 0, n2 = 0;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] % 3 == 0)
		{
			n0++;
		}
		else if (a[i] % 3 == 1)
		{
			n1++;
		}
		else
		{
			n2++;
		}
	}
	printf("%d %d %d", n0, n1, n2);
	return 0;
}