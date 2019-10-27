#include <stdio.h>
int main(void)
{
	int x, prev = 0, prevprev = 0;
	int index = 0, start = 1, max = 0, max__left = 0, start__find = 0;
	int left = 0, right = 0;//right負責暫存左半邊，等right固定再存到left
	while (scanf("%d", &x) != EOF)
	{
		index++;
		if ((x - prev) * (prev - prevprev) > 0) //山或谷左半邊
		{
			right++;
		}
		if ((x - prev) * (prev - prevprev) < 0)//山或谷右半邊
		{
			left = right;
			right = 2;
			if (index > 2)
			{
				start__find = 1;
			}
		}
		if (max < left + right - 1)
		{
			max__left = left;
			max = left + right - 1;
			start = index - max + 1;
		}
		else if (max == left + right - 1 && max__left < left)
		{
			max__left = left;
			start = index - max + 1;
		}
		prevprev = prev;
		prev = x;
	}
	if (start__find)
	{
		printf("%d %d", max, start);
	}
	else
	{
		printf("0");
	}
	return 0;
}