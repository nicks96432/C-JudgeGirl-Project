#include <stdio.h>
#include "snake.h"
int main(void)
{
	int travel[1024] = {0}, row = 0, column = 0, res = 0;
	scanf("%d %d", &travel[0], &travel[1]);
	for (int i = 1; travel[i]; i++)
	{
		scanf("%d", &travel[i + 1]);
	}
	res = snake(travel, &row, &column);
	if (res)
	{
		printf("%d %d\n", row, column);
	}
	else
	{
		printf("err %d %d\n", row, column);
	}
	return 0;
}