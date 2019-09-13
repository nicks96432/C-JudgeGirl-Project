#include <stdio.h>
int main(void)
{
	int a[1003], i, j = 0, k = 0, n, even[1003], odd[1003];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2)
		{
			odd[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!(a[i] % 2))
		{
			even[k] = a[i];
			k++;
		}
	}
	for (i = 0; i < j - 1; i++)
	{
		printf("%d ", odd[i]);
	}
	printf("%d\n", odd[i]);
	for (i = 0; i < k - 1; i++)
	{
		printf("%d ", even[i]);
	}
	printf("%d", even[i]);
	return 0;
}