#include <stdio.h>
#include <stdbool.h>
#include "lock.h"
 
#define SENSORNUM 3
 
int main(void)
{
  int m, n;
  scanf("%d%d", &m, &n);
  bool lights[m];
  int lockSeq[n][SENSORNUM];
  for(int i = 0; i < m; i++)
  {
    int tmp;
    scanf("%d", &tmp);
    lights[i] = (tmp == 1);
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < SENSORNUM; j++)
    {
      scanf("%d", &lockSeq[i][j]);
    }
  }
  Locks *locks = init(lockSeq, n);
  printf("%d\n", numUnlocked(locks, lights, m));
  return 0;
}