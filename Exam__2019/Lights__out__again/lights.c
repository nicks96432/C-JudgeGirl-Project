#include <stdio.h>
#include "lights.h"
void init(Lights *l)
{
	int i;
	for (i = 0; i < MAX_N * MAX_N; i++)
	{
		l->isOpen[i] = false;
		l->isPressed[i] = false;
		l->pressedNum[i] = 0;
		l->countLights = 0;
		l->countFlip = 0;
	}
	return;
}
int numOfLights(Lights *l, int N)
{
	return l->countLights;
}
void flip(Lights *l, int i, int N)
{
	l->isOpen[i] = l->isOpen[i] ? false : true;
	if (i / N - 1 >= 0)
	{
		l->isOpen[i - N] = l->isOpen[i - N] ? false : true;
	}
	if (i / N + 1 < N)
	{
		l->isOpen[i + N] = l->isOpen[i + N] ? false : true;
	}
	if (i % N - 1 >= 0)
	{
		l->isOpen[i - 1] = l->isOpen[i - 1] ? false : true;
	}
	if (i % N + 1 < N)
	{
		l->isOpen[i + 1] = l->isOpen[i + 1] ? false : true;
	}
	int j, k;
	l->countLights = 0;
	for (j = 0; j < N * N; j++)
	{
		l->countLights += l->isOpen[j] == true;
	}
	return;
}
void printLights(Lights *l, int N)
{
	int i, j;
	for (i = 0; i < N * N; i++)
	{
		printf("%d ", l->isOpen[i] == true);
		if (i % 4 == 3)
		{
			puts("");
		}
	}
	return;
}