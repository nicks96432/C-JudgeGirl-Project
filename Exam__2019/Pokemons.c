#include <stdio.h>
#define attribute(x) ((x) % 3)
enum attributes
{
	WIND,
	FIRE,
	WATER
};
int main(void)
{
	int ans = 0, k, cp, first = 0, second = 0;
	int wind = 0, fire = 0, water = 0;
	if (scanf("%d", &k) == EOF)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		while (scanf("%d", &cp) != EOF)
		{
			if (wind == 0 && fire == 0 && water == 0)
			{
				first = cp;
				second = cp;
			}
			else if (cp >= first)
			{
				second = first;
				first = cp;
			}
			else if (cp > second)
			{
				second = cp;
			}
			else if (wind + fire + water == 1 && cp < second)
			{
				second = cp;
			}
			if (attribute(cp) == WIND)
			{
				wind++;
			}
			else if (attribute(cp) == FIRE)
			{
				fire++;
			}
			else if (attribute(cp) == WATER)
			{
				water++;
			}
			if (water >= k && fire >= k && wind >= k)
			{
				ans += second;
				water = 0;
				fire = 0;
				wind = 0;
				first = 0;
				second = 0;
			}
		}
	}
	ans += second;
	printf("%d\n", ans);
	return 0;
}