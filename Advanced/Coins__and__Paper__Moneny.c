#include <stdio.h>
int main(void)
{
	int n;
	int thousand, fivehundred, hundred, fifty, ten, five, one;
	while (scanf("%d", &n) != EOF)
	{
		thousand = n / 1000;
		n %= 1000;
		fivehundred = n / 500;
		n %= 500;
		hundred = n / 100;
		n %= 100;
		fifty = n / 50;
		n %= 50;
		ten = n / 10;
		n %= 10;
		five = n / 5;
		one = n % 5;
		printf("%d %d %d %d %d %d %d\n", thousand, fivehundred, hundred, fifty, ten, five, one);
	}
	return 0;
}