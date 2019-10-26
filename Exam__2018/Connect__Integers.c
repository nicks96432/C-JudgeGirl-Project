#include <stdio.h>
#include <string.h>
int main(void)
{
	int prev__lsb = -1, count = 1, max = 0, len;
	char n[12];
	while (scanf("%s", n) != EOF)
	{
		len = strlen(n);
		if (prev__lsb == n[0])
		{
			count += len;
		}
		else
		{
			count = len;
		}
		if (count > max)
		{
			max = count;
		}
		prev__lsb = n[len - 1];
	}
	printf("%d\n", max);
	return 0;
}