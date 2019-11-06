#include <stdio.h>
#define INT_MAX 2147483647
#define MAX_MACHINE 502
#define MAX_TASK 502
#define MAX_SUBTASK 502
int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int arrive__time[MAX_TASK], subtask[MAX_TASK], i, j;
	int subtask__information[MAX_TASK][MAX_SUBTASK][2];
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &arrive__time[i], &subtask[i]);
		for (j = 0; j < subtask[i]; j++)
		{
			scanf("%d %d", &subtask__information[i][j][0], &subtask__information[i][j][1]);
		}
		
	}

	return 0;
}