#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXS 70
void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
	int from, to, ans;
	memset(A, 0, sizeof(A[0]) * a);
	memset(B, 0, sizeof(B[0]) * b);
	static char instruction[MAXS], tmp1[MAXS], tmp2[MAXS], tmp3[MAXS];
	while (fgets(instruction, MAXS, stdin) != NULL)
	{
		ans = sscanf(instruction, "%s%d%s%d%s", tmp1, &from, tmp2, &to, tmp3);
		if (ans != 4 || from < 0 || to < 0)
		{
			ans = 0;
		}
		if (ans)
		{
			if (!(strcmp(tmp1, "A")) && !(strcmp(tmp2, "B")) && from < a && to < b)
			{
				A[from] = &B[to];
			}
			else if (!(strcmp(tmp1, "B")) && !(strcmp(tmp2, "C")) && from < b && to < c)
			{
				B[from] = &C[to];
			}
			else
			{
				ans = 0;
			}
		}
		puts(ans ? "1" : "0");
	}
	return;
}