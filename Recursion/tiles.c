#include <stdio.h>
enum directions
{
	UPRIGHT = 1,
	UPLEFT,
	DOWNLEFT,
	DOWNRIGHT
};
void tile(int, int, int, int, int);
int main(void)
{
	int l, m;
	scanf("%d%d", &l, &m);
	tile(l, m, UPRIGHT, l / 2, l / 2);
	return 0;
}
void tile(int l, int m, int direction, int x, int y)
{
	if (l == m)
	{
		return;
	}
	if (l == 2)
	{
		switch (direction)
		{
		case UPRIGHT:
			printf("%d %d %d\n", UPRIGHT, x, y);
			break;
		case UPLEFT:
			printf("%d %d %d\n", UPLEFT, x, y);
			break;
		case DOWNLEFT:
			printf("%d %d %d\n", DOWNLEFT, x, y);
			break;
		case DOWNRIGHT:
			printf("%d %d %d\n", DOWNRIGHT, x, y);
			break;
		}
		return;
	}
	if (direction == UPRIGHT)
	{
		printf("%d %d %d\n", UPRIGHT, x, y);
		tile(l / 2, 1, UPRIGHT, x - l / 4, y - l / 4);
		tile(l / 2, 1, DOWNRIGHT, x - l / 4, y + l / 4);
		tile(l / 2, 1, UPLEFT, x + l / 4, y - l / 4);
		tile(l / 2, m, UPRIGHT, x + l / 4, y + l / 4);
	}
	if (direction == UPLEFT)
	{
		printf("%d %d %d\n", UPLEFT, x, y);
		tile(l / 2, 1, UPLEFT, x + l / 4, y - l / 4);
		tile(l / 2, 1, DOWNLEFT, x + l / 4, y + l / 4);
		tile(l / 2, 1, UPRIGHT, x - l / 4, y - l / 4);
		tile(l / 2, m, UPLEFT, x - l / 4, y + l / 4);
	}
	if (direction == DOWNLEFT)
	{
		printf("%d %d %d\n", DOWNLEFT, x, y);
		tile(l / 2, 1, DOWNLEFT, x + l / 4, y + l / 4);
		tile(l / 2, 1, DOWNRIGHT, x - l / 4, y + l / 4);
		tile(l / 2, 1, UPLEFT, x + l / 4, y - l / 4);
		tile(l / 2, m, DOWNLEFT, x - l / 4, y - l / 4);
	}
	if (direction == DOWNRIGHT)
	{
		printf("%d %d %d\n", DOWNRIGHT, x, y);
		tile(l / 2, 1, DOWNRIGHT, x - l / 4, y + l / 4);
		tile(l / 2, 1, DOWNLEFT, x + l / 4, y + l / 4);
		tile(l / 2, 1, UPRIGHT, x - l / 4, y - l / 4);
		tile(l / 2, m, DOWNRIGHT, x + l / 4, y - l / 4);
	}
}