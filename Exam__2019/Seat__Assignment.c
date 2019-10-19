#include <stdio.h>
#include <stdbool.h>
#define ROW 20
#define SEATS 5
#define SINGLE 1
#define DOUBLE 2
typedef struct Last
{
	int car;
	int row;
	int seat;
}last;
int main(void)
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	bool train[n][ROW][SEATS];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < ROW; j++)
		{
			for (k = 0; k < SEATS; k++)
			{
				train[i][j][k] = false;
			}
		}
	}
	bool found__seat = false;
	int request;
	last single__seat, double__seats;
	single__seat.car = 0;
	single__seat.row = 0;
	single__seat.seat = 0;
	double__seats.car = 0;
	double__seats.row = 0;
	double__seats.seat = 0;
	while (scanf("%d", &request) != EOF)
	{
		if (request == SINGLE)
		{
			found__seat = false;
			i = single__seat.car;
			j = single__seat.row;
			k = single__seat.seat;
			for (; i < n; i++)
			{
				for (; j < ROW; j++)
				{
					for (; k < SEATS; k++)
					{
						if (train[i][j][k] == false)
						{
							train[i][j][k] = true;
							found__seat = true;
							single__seat.car = i;
							single__seat.row = j;
							single__seat.seat = k;
							printf("%d %d %d\n", single__seat.car+1, single__seat.row+1, single__seat.seat+1);
							break;
						}
					}
					if(k >= SEATS)
					{
						k = 0;
					}
					if (found__seat)
					{
						break;
					}
				}
				if (j >= ROW)
				{
					j = 0;
				}
				if (found__seat)
				{
					break;
				}
			}
		}
		else if (request == DOUBLE)
		{
			found__seat = false;
			i = double__seats.car;
			j = double__seats.row;
			k = double__seats.seat;
			for (; i < n; i++)
			{
				for (; j < ROW; j++)
				{
					if(k == SEATS-1)
					{
						k = 0;
					}
					for (; k < SEATS - 1; k++)
					{
						if (k == 2)
						{
							continue;
						}
						if (train[i][j][k] == false && train[i][j][k + 1] == false)
						{
							train[i][j][k] = true;
							train[i][j][k + 1] = true;
							found__seat = true;
							double__seats.car = i;
							double__seats.row = j;
							double__seats.seat = k + 1;
							printf("%d %d %d %d %d %d\n", double__seats.car + 1, double__seats.row + 1,\
							double__seats.seat, double__seats.car + 1, double__seats.row + 1, double__seats.seat + 1);
							break;
						}
					}
					if (found__seat)
					{
						break;
					}
				}
				if (j >= ROW)
				{
					j = 0;
				}
				if (found__seat)
				{
					break;
				}
			}
			if(found__seat == false)
			{
				i = single__seat.car;
				j = single__seat.row;
				k = single__seat.seat;
				for (; i < n; i++)
				{
					for (; j < ROW; j++)
					{
						for (; k < SEATS; k++)
						{
							if (train[i][j][k] == false)
							{
								train[i][j][k] = true;
								found__seat = true;
								single__seat.car = i;
								single__seat.row = j;
								single__seat.seat = k;
								printf("%d %d %d ", single__seat.car + 1, single__seat.row + 1, single__seat.seat + 1);
								break;
							}
						}
						if(k >= SEATS)
						{
							k = 0;
						}
						if (found__seat)
						{
							break;
						}
					}
					if (j >= ROW)
					{
						j = 0;
					}
					if (found__seat)
					{
						break;
					}
				}
				found__seat = false;
				for (; i < n; i++)
				{
					for (; j < ROW; j++)
					{
						for (; k < SEATS; k++)
						{
							if (train[i][j][k] == false)
							{
								train[i][j][k] = true;
								found__seat = true;
								double__seats.car = i;
								double__seats.row = j;
								double__seats.seat = k;
								printf("%d %d %d\n", double__seats.car + 1, double__seats.row + 1, double__seats.seat + 1);
								break;
							}
						}
						if(k >= SEATS)
						{
							k = 0;
						}
						if (found__seat)
						{
							break;
						}
					}
					if (j >= ROW)
					{
						j = 0;
					}
					if (found__seat)
					{
						break;
					}
				}
			}
		}
	}
	return 0;
}
