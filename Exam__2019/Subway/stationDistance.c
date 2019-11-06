/* startStation[0]:路線名, startStation[1]:站牌名 */
/* endStation[0]:路線名, endStation[1]:站牌名 */
/* R:0, G:1, B:2 */
#include <stdio.h>
int stationDistance(int R_distance[], int G_distance[], int B_distance[], int G_origin, int G_destination, int startStation[], int endStation[])
{
	int ans = 0, i, tmp;
	if ((startStation[0] == 0 && endStation[0] == 1) || (startStation[0] == 1 && endStation[0] == 0))
	{
		if (startStation[0] == 1)
		{
			startStation[0] = 0;
			endStation[0] = 1;
			tmp = startStation[1];
			startStation[1] = endStation[1];
			endStation[1] = tmp;
		}
		if (startStation[1] <= G_origin)
		{
			for (i = startStation[1]; i < G_origin; i++)
			{
				ans += R_distance[i - 1];
			}
		}
		else
		{
			for (i = G_origin; i < startStation[1]; i++)
			{
				ans += R_distance[i - 1];
			}
		}
		for (i = 1; i < endStation[1]; i++)
		{
			ans += G_distance[i - 1];
		}
	}
	else if ((startStation[0] == 1 && endStation[0] == 2) || (startStation[0] == 2 && endStation[0] == 1))
	{
		if (startStation[0] == 2)
		{
			startStation[0] = 1;
			endStation[0] = 2;
			tmp = startStation[1];
			startStation[1] = endStation[1];
			endStation[1] = tmp;
		}
		for (i = startStation[1]; G_distance[i - 1] != 0; i++)
		{
			ans += G_distance[i - 1];
		}
		if (endStation[1] <= G_destination)
		{
			for (i = endStation[1]; i < G_destination; i++)
			{
				ans += B_distance[i - 1];
			}
		}
		else
		{
			for (i = G_destination; i < endStation[1]; i++)
			{
				ans += B_distance[i - 1];
			}
		}
	}
	else if ((startStation[0] == 0 && endStation[0] == 2) || (startStation[0] == 2 && endStation[0] == 0))
	{
		if (startStation[0] == 2)
		{
			startStation[0] = 0;
			endStation[0] = 2;
			tmp = startStation[1];
			startStation[1] = endStation[1];
			endStation[1] = tmp;
		}
		if (startStation[1] <= G_origin)
		{
			for (i = startStation[1]; i < G_origin; i++)
			{
				ans += R_distance[i - 1];
			}
		}
		else
		{
			for (i = G_origin; i < startStation[1]; i++)
			{
				ans += R_distance[i - 1];
			}
		}
		for (i = 0; G_distance[i] != 0; i++)
		{
			ans += G_distance[i];
		}
		if (endStation[1] <= G_destination)
		{
			for (i = endStation[1]; i < G_destination; i++)
			{
				ans += B_distance[i - 1];
			}
		}
		else
		{
			for (i = G_destination; i < endStation[1]; i++)
			{
				ans += B_distance[i - 1];
			}
		}
	}
	else if (startStation[0] == endStation[0])
	{
		if (startStation[1] > endStation[1])
		{
			tmp = startStation[1];
			startStation[1] = endStation[1];
			endStation[1] = tmp;
		}
		if (startStation[0] == 0)
		{
			for (i = startStation[1]; i < endStation[1]; i++)
			{
				ans += R_distance[i - 1];
			}
		}
		else if (startStation[0] == 1)
		{
			for (i = startStation[1]; i < endStation[1]; i++)
			{
				ans += G_distance[i - 1];
			}
		}
		else if (startStation[0] == 2)
		{
			for (i = startStation[1]; i < endStation[1]; i++)
			{
				ans += B_distance[i - 1];
			}
		}
	}
	return ans;
}