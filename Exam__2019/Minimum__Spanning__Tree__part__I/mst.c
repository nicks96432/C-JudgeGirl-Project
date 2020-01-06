#include "mst.h"
void init(MST *mst, int N)
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
void addRoad(MST *mst, int city1, int city2, int len)
{
	mst->road[city1][city2] = len;
	mst->road[city2][city1] = len;
	return;
}
int removeRoad(MST *mst, int city1, int city2)
{
	int tmp = mst->road[city1][city2];
	mst->road[city1][city2] = 0;
	mst->road[city2][city1] = 0;
	return tmp;
}
bool hasPath(MST *mst, int city1, int city2)
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
			if (hasPath(mst, i, city2))
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
bool connected(MST *mst)
{
	for (int i = 0; i < mst->N; i++)
	{
		for (int j = i + 1; j < mst->N; j++)
		{
			if (!hasPath(mst, i, j))
			{
				return false;
			}
		}
	}
	return true;
}