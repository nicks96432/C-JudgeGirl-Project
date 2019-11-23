#include "subset.h"

int subset(int numbers[], int n, int K, int S)
{
	if (S == 0 && K == 0)
	{
		return 1;
	}
	if (S > n || n == 0)
	{
		return 0;
	}
	if (K < 0 || S < 0)
	{
		return 0;
	}
	return subset(numbers + 1, n - 1, K - numbers[0], S - 1) || subset(numbers + 1, n - 1, K, S);
}