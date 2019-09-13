#include <stdio.h>
int main()
{
	int i, j, A = 0, B = 0;
	int a, b;
	int num[4], guess[4];
	scanf("%d %d", &a, &b);
	num[0] = a / 1000;
	num[1] = (a % 1000) / 100;
	num[2] = (a % 100) / 10;
	num[3] = a % 10;
	guess[0] = b / 1000;
	guess[1] = (b % 1000) / 100;
	guess[2] = (b % 100) / 10;
	guess[3] = b % 10;
	for (i = 0; i < 4; i++)
	{
		if (num[i] == guess[i])
		{
			A++;
		}
	}
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (num[i] == guess[j] && i != j)
			{
				B++;
			}
		}
	}
	printf("%dA%dB", A, B);
	return 0;
}