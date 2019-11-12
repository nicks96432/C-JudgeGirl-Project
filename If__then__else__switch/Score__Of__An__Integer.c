#include <stdio.h>
int main(void)
{
	int x, score;
	scanf("%d", &x);
	if (x > 0)
	{
		score = 0;
		if (!(x % 3))
		{
			score += 3;
		}
		if (!(x % 5))
		{
			score += 5;
		}
		if (x >= 100 && x <= 200)
		{
			score += 50;
		}
		else
		{
			score -= 50;
		}
	}
	else
	{
		score = -100;
	}

	printf("%d", score);
	return 0;
}