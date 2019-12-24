#include <stdio.h>
#include "lights.h"
#define ROUND 200000000
int main(void)
{
	Lights l;
	init(&l);
	int n;
	int N;
	scanf("%d", &N);
	while (scanf("%d", &n) != EOF)
	{
		flip(&l, n, N);
	}
	int num = 0;
	for (int i = 0; i < ROUND; i++)
	{
		num = numOfLights(&l, N);
	}
	printf("%d\n", num);
	return 0;
}