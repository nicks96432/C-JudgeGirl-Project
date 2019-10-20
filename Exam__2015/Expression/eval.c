#include "eval.h"
int eval(int exp[])
{
	int i, j, ans = 0;
	for (i = 2; i <= exp[0]; i += 2)
	{
		if (exp[i] < ADD || exp[i] > DIVIDE)
		{
			return -2147483646;
		}
	}
	for (i = 2; i <= exp[0]; i += 2)
	{
		if (exp[i] == DIVIDE && exp[i + 1] == 0)
		{
			return -2147483647;
		}
	}
	int tmp = exp[1];
	for (i = 3; i <= exp[0]; i += 2)
	{
		if (exp[i - 1] == ADD)
		{
			ans += tmp;
			tmp = exp[i];
		}
		else if (exp[i - 1] == MINUS)
		{
			ans += tmp;
			tmp = -exp[i];
		}
		else if (exp[i - 1] == MULTIPLY)
		{
			tmp *= exp[i];
		}
		else
		{
			tmp /= exp[i];
		}
	}
	ans += tmp;
	return ans;
}