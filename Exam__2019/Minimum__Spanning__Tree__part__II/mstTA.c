#include "mstTA.h"
void initTA(MSTTA *mst, int N)
{
	mst->N = N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			mst->road[i][j] = 0;
		}
	}
	return;
}
void addRoadTA(MSTTA *mst, int city1, int city2, int len)
{
	mst->road[city1][city2] = len;
	mst->road[city2][city1] = len;
	return;
}
int removeRoadTA(MSTTA *mst, int city1, int city2)
{
	int tmp = mst->road[city1][city2];
	mst->road[city1][city2] = 0;
	mst->road[city2][city1] = 0;
	return tmp;
}
bool hasPathTA(MSTTA *mst, int city1, int city2)
{
	if (mst->road[city1][city2] != 0)
	{
		return true;
	}
	for (int i = 0; i < mst->N; i++)
	{
		if (i == city1)
		{
			continue;
		}
		if (mst->road[city1][i] != 0)
		{
			int tmp = mst->road[city1][i];
			mst->road[city1][i] = 0;
			mst->road[i][city1] = 0;
			if (hasPathTA(mst, i, city2))
			{
				mst->road[city1][i] = tmp;
				mst->road[i][city1] = tmp;
				return true;
			}
			else
			{
				mst->road[city1][i] = tmp;
				mst->road[i][city1] = tmp;
			}
		}
	}
	return false;
}
bool connectedTA(MSTTA *mst)
{
	for (int i = 0; i < mst->N; i++)
	{
		for (int j = i + 1; j < mst->N; j++)
		{
			if (!hasPathTA(mst, i, j))
			{
				return false;
			}
		}
	}
	return true;
}