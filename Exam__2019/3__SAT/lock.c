#include <stdbool.h>
#include <stdlib.h>
#include "lock.h"
Locks* init(int lockSeq[][3], int n)
{
	Locks *l = (Locks*)malloc(sizeof(Locks));
	l->countLock = n;
	int i, j;
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < 3;j++)
		{
			l->Lock[i].trigger[j] = lockSeq[i][j];
		}
	}
	return l;
}
int numUnlocked(Locks *locks, bool lights[], int m)
{
	int i,j,k,count = 0;
	bool unlocked;
	for(i = 0; i < locks->countLock; i++)
	{
		unlocked = false;
		for(j=0;j<3;j++)
		{
			for(k=0;k<m;k++)
			{

				if(locks->Lock[i].trigger[j] > 0)
				{
					if(lights[locks->Lock[i].trigger[j] - 1] == true)
					{
						unlocked = true;
						count++;
						break;
					}
				}
				else if(locks->Lock[i].trigger[j] < 0)
				{
					if(lights[-(locks->Lock[i].trigger[j]) - 1] == false)
					{
						unlocked = true;
						count++;
						break;
					}
				}
			}
			if(unlocked)
			{
				break;
			}
		}
	}
	return count;
}