#include <stdio.h>
#include "lights.h"
static int pressed = 0, ans = 0;
static int min = 2147483647;
void find(Lights *l, int N, int now, int count)
{
	if (now == N * N)
	{
		if (!numOfLights(l, N))
		{
			if (min > count)
			{
				min = count;
				ans = pressed;
			}
		}
		return;
	}
	pressed |= (1 << now);
	flip(l, now, N);
	find(l, N, now + 1, count + 1);
	pressed &= ~(1 << now);
	flip(l, now, N);
	find(l, N, now + 1, count);
}
int main(void)
{
	int N;
	Lights l;
	init(&l);
	int num;
	scanf("%d", &N);
	while (scanf("%d", &num) == 1)
	{
		flip(&l, num, N);
	}
	find(&l, N, 0, 0);
	int i;
	for (i = 0; i < N * N; i++)
	{
		if (ans & (1 << i))
		{
			printf("%d ", i);
		}
	}
	puts("");
	return 0;
}