#include <stdio.h>
int main(void)
{
	int arrival__time, time__a, time__b, ready__a = 0, ready__b = 0;
	while (scanf("%d%d%d", &arrival__time, &time__a, &time__b) != EOF)
	{
		if (arrival__time >= ready__a)
		{
			ready__a = arrival__time + time__a;
		}
		else
		{
			ready__a += time__a;
		}
		if (ready__a >= ready__b)
		{
			ready__b = ready__a + time__b;
		}
		else
		{
			ready__b += time__b;
		}
		printf("%d\n", ready__b);
	}
	return 0;
}