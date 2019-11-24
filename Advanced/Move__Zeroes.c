#include <stdio.h>
#include <string.h>
#define MAXN 100005
int A[MAXN], B[MAXN];
int main(void)
{
	int n, i, count;
	while (scanf("%d", &n) == 1)
	{
		count = 0;
		memset(B, 0, sizeof(B));
		for (i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		for (i = 0; i < n; i++)
		{
			if (A[i])
			{
				B[count] = A[i];
				count++;
			}
		}
		for (i = 0; i < n; i++)
		{
			printf("%d%c", B[i], " \n"[i == n - 1]);
		}
	}
	return 0;
}