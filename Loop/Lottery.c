#include <stdio.h>
int main()
{
	int special[3], first[3], lottery, money = 0;
	scanf("%d%d%d%d%d%d", &special[0], &special[1], &special[2], &first[0], &first[1], &first[2]);
	while (scanf("%d", &lottery) == 1)
	{
		if (lottery == special[0] || lottery == special[1] || lottery == special[2])
		{
			money += 2000000;
		}
		else if (lottery == first[0] || lottery == first[1] || lottery == first[2])
		{
			money += 200000;
		}
		else if (lottery % 10000000 == first[0] % 10000000 || lottery % 10000000 == first[1] % 10000000 || lottery % 10000000 == first[2] % 10000000)
		{
			money += 40000;
		}
		else if (lottery % 1000000 == first[0] % 1000000 || lottery % 1000000 == first[1] % 1000000 || lottery % 1000000 == first[2] % 1000000)
		{
			money += 10000;
		}
		else if (lottery % 100000 == first[0] % 100000 || lottery % 100000 == first[1] % 100000 || lottery % 100000 == first[2] % 100000)
		{
			money += 4000;
		}
		else if (lottery % 10000 == first[0] % 10000 || lottery % 10000 == first[1] % 10000 || lottery % 10000 == first[2] % 10000)
		{
			money += 1000;
		}
		else if (lottery % 1000 == first[0] % 1000 || lottery % 1000 == first[1] % 1000 || lottery % 1000 == first[2] % 1000)
		{
			money += 200;
		}
	}
	printf("%d", money);
	return 0;
}