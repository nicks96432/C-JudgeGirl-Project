#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 32768
#define MAX_K 256
typedef struct _Friendship
{
	int count;
	int friends[MAX_K];
} Friendship;
int main(void)
{
	int n, e;
	scanf("%d%d", &n, &e);
	int vi, vj;
	Friendship *student = (Friendship *)malloc(sizeof(Friendship) * n);
	bool attend[n];
	for (int i = 0; i < n; i++)
	{
		student[i].count = 0;
		attend[i] = false;
	}
	for (int i = 0; i < e; i++)
	{
		scanf("%d%d", &vi, &vj);
		student[vi].friends[student[vi].count] = vj;
		student[vj].friends[student[vj].count] = vi;
		student[vi].count++;
		student[vj].count++;
	}
	while (scanf("%d", &vi) != EOF)
	{
		attend[vi] = true;
		for (int i = 0; i < student[vi].count; i++)
		{
			attend[student[vi].friends[i]] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (attend[i] == false)
		{
			printf("%d\n", i);
		}
	}
	free(student);
	return 0;
}