#include <stdio.h>
int main(void)
{
	// i:count x1,j:count y1,k:count x2,l:count y2
	int i = 0, j = 0, k = 0, l = 0, t = 0,
		M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2, explode = 0;
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d",
		  &M, &N, &X1, &Y1, &E1, &N1, &F1, &X2, &Y2, &E2, &N2, &F2);
	while (F1 > 0 || F2 > 0)
	{
		if (i == E1 && j == N1)
		{
			i = 0;
			j = 0;
		}
		if (k == E2 && l == N2)
		{
			k = 0;
			l = 0;
		}
		if (explode)
		{
			break;
		}
		t++;
		if (F1 > 0)
		{
			F1--;
			if (j < N1)
			{
				Y1++;
				j++;
				if (Y1 > N-1)
				{
					Y1 = 0;
				}
			}
			else if (i < E1)
			{
				X1++;
				i++;
				if (X1 > M-1)
				{
					X1 = 0;
				}
			}
		}
		if (F2 > 0)
		{
			F2--;
			if (k < E2)
			{
				X2++;
				k++;
				if (X2 > M-1)
				{
					X2 = 0;
				}
			}
			else if (l < N2)
			{
				Y2++;
				l++;
				if (Y2 > N-1)
				{
					Y2 = 0;
				}
			}
		}
		if (X1 == X2 && Y1 == Y2)
		{
			explode = 1;
		}
	}
	if (explode)
	{
		printf("robots explode at time %d", t);
	}
	else
	{
		printf("robots will not explode");
	}
	return 0;
}