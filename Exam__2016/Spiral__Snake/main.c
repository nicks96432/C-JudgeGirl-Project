#include <stdio.h>
#include "SpiralSnake.h"
#include <assert.h>
#define MAXLEN 1000
static int snake[MAXLEN * MAXLEN];
static int result[MAXLEN * MAXLEN];
int main(void)
{
	int N;
	while (scanf("%d", &N) != EOF)
	{
		for (int i = 0; i < N * N; i++)
		{
			assert(scanf("%d", &snake[i]) == 1);
		}
		SpiralSnake(N, snake, result);
		for (int i = 0; i < N * N; i++)
		{
			printf("%d%c", result[i], " \n"[i == N * N - 1]);
		}
	}
	return 0;
}