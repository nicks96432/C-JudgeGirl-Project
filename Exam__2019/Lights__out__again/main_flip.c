#include <stdio.h>
#include "lights.h"
int main()
{
	Lights l;
	init(&l);
	int n;
	int index;
	int N;

	scanf("%d", &N);
	while (scanf("%d", &n) != EOF)
	{
		flip(&l, n, N);
	}
	printLights(&l, N);
	return 0;
}