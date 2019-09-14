#include <stdio.h>
int main(void)
{
	int point[102][2] = {0}, i = 0;
	int up = -10001, down = 10001, left = 10001, right = -10001;
	while (scanf("%d %d", &point[i][0], &point[i][1]) != EOF)
	{
		if (point[i][0] > up)
		{
			up = point[i][0];
		}
		if (point[i][0] < down)
		{
			down = point[i][0];
		}
		if (point[i][1] > right)
		{
			right = point[i][1];
		}
		if (point[i][1] < left)
		{
			left = point[i][1];
		}
		i++;
	}
#ifdef DEBUG
	for (size_t j = 0; j < i; j++)
	{
		printf("%d %d\n", point[j][0], point[j][1]);
	}
#endif // DEBUG
	int area = (up - down) * (right - left);
	printf("%d", area);
	return 0;
}