#include <stdio.h>
#include <string.h>
#include "transmission.h"
#define MAX_BUF 1048576
void shiftword(long long belt[], int N, int n)
{
	static long long buffer[MAX_BUF];
	memcpy(buffer, belt, sizeof(long long) * n);
	memmove(belt, belt + n, sizeof(long long) * (N - n));
	memcpy(belt + N - n, buffer, sizeof(long long) * n);
	return;
}
void shiftlast(long long belt[], int N, int n)
{
	if (n == 0)
	{
		return;
	}
	long long shiftleft = (long long)n;
	long long shiftright = 64LL - shiftleft;
	long long last = (unsigned long long)belt[0] >> shiftright;
	int i;
	for (i = 0; i < N - 1; i++)
	{
		belt[i] <<= shiftleft;
		belt[i] |= (unsigned long long)belt[i + 1] >> shiftright;
	}
	belt[i] <<= shiftleft;
	belt[i] |= last;
	return;
}
void transmission(long long int belt[], int N, int T)
{
	shiftword(belt, N, (T >> 6) % N);
	shiftlast(belt, N, T & 63 /* T & 63 == T % 64 */);
	return;
}