#include <stdio.h>
#include <string.h>
#define MAX_M 16
#define MAX_N 20
int main(void)
{
	unsigned char acception;
	unsigned char pictures;
	unsigned char ones[MAX_M * MAX_M][2];
	unsigned char classifier[MAX_M][MAX_M];
	memset(classifier, 1, sizeof(classifier));
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j, k;
	int t = 2 * m * m, count, countone;
	for (i = 0; i < n; i++)
	{
		scanf("%hhu", &acception);
		memset(ones, 0, sizeof(ones));
		countone = 0;
		count = 0;
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < m; k++)
			{
				scanf("%hhu", &pictures);
				if (pictures==1)
				{
					ones[countone][0] = j;
					ones[countone][1] = k;
					countone++;
				}
				count += pictures * classifier[j][k];
			}
		}
		if (count >= t && !acception)
		{
			for (j = 0; j < countone; j++)
			{
				classifier[ones[j][0]][ones[j][1]] >>= 1;
			}
		}
		else if (count < t && acception)
		{
			for (j = 0; j < countone; j++)
			{
				classifier[ones[j][0]][ones[j][1]] <<= 1;
			}
		}
	}
	int q;
	unsigned char picture;
	scanf("%d", &q);
	for (i = 0; i < q; i++)
	{
		count = 0;
		for (j = 0; j < m; j++)
		{
			for (k = 0; k < m; k++)
			{
				scanf("%hhu", &picture);
				count += picture * classifier[j][k];
			}
		}
		printf("%d\n", count >= t);
	}
	return 0;
}
