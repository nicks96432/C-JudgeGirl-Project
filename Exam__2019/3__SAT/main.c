#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "lock.h"
#define SENSORNUM 3
#define MAX_M 100
int countPower(bool lights[], int m)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if(lights[i])
		{
			count += (1 << i);
		}
	}
	return count;
}
void find(Locks *locks, bool lights[], bool ans[], int n, int m,
		  int now, int *power, int *unlocked)
{
	if(now == m)
	{
		int nowUnlocked = numUnlocked(locks, lights, m);
		if(nowUnlocked > *unlocked)
		{
			*unlocked = nowUnlocked;
			*power = countPower(lights, m);
			for(int i = 0; i < m; i++)
			{
				ans[i] = (lights[i] ? true: false);
			}
			
		}
		else if(nowUnlocked == *unlocked)
		{
			int nowPower = countPower(lights, m);
			if(nowPower < *power)
			{
				*power = nowPower;
				for(int i = 0; i < m; i++)
				{
					ans[i] = lights[i];
				}
			}
		}
		return;
	}
	assert(now <= m - 1);
	lights[now] = (lights[now] ? false : true);
	find(locks, lights, ans, n, m, now + 1, power, unlocked);
	lights[now] = (lights[now] ? false : true);
	find(locks, lights, ans, n, m, now + 1, power, unlocked);
}
int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	bool lights[m], ans[m];
	int lockSeq[n][SENSORNUM];
	int power = 2147483647, unlocked = -2147483648;
	for(int i = 0; i < m; i++)
	{
		lights[i] = false;
		ans[i] = false;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < SENSORNUM; j++)
		{
		  scanf("%d", &lockSeq[i][j]);
		}
	}
	Locks *locks = init(lockSeq, n);
	find(locks, lights, ans, n, m, 0, &power, &unlocked);
	for (int i = 0; i < m; i++)
	{
		printf("%d", ans[i] ? 1 : 0);
	}
	puts("");
	printf("%d\n%d\n", unlocked, power);
	return 0;
}