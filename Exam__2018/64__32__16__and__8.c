#include <stdio.h>
int main(void)
{
	unsigned int L;
	unsigned short S;
	unsigned char C[3];
	unsigned long long LL, SL, CL[2], ans = 0, and;
	int i, count = 64, count__C = 0, n, count__or;
	char command[6];
	scanf("%d", &n);
	if (n == 0)
	{
		while (scanf("%s%u%hu%s", command, &L, &S, C) != EOF)
		{
			ans = 0;
			count = 64, count__C = 0;
			LL = (unsigned long long)L;
			SL = (unsigned long long)S;
			CL[0] = (unsigned long long)C[0];
			CL[1] = (unsigned long long)C[1];
			for (i = 0; i < 4; i++)
			{
				if (command[i] == 'L')
				{
					ans |= (LL << (count - 32));
					count -= 32;
				}
				else if (command[i] == 'S')
				{
					ans |= (SL << (count - 16));
					count -= 16;
				}
				else if (command[i] == 'C')
				{
					ans |= (CL[count__C] << (count - 8));
					count -= 8;
					count__C++;
				}
			}
			printf("%llu\n", ans);
		}
	}
	else if (n == 1)
	{
		while (scanf("%s%llu", command, &LL) != EOF)
		{
			L = 0;
			S = 0;
			C[0] = 0;
			C[1] = 0;
			count__C = 0;
			and = 1ULL << 63;
			count = 64;
			for (i = 0; i < 4; i++)
			{
				if (command[i] == 'L')
				{
					for (and = 1ULL << (count - 1), count__or = 31; and >= 1ULL << (count - 32); and >>= 1, count__or--)
					{
						if (LL & and)
						{
							L |= (1 << count__or);
						}
					}
					count -= 32;
				}
				else if (command[i] == 'S')
				{
					for (and = 1ULL << (count - 1), count__or = 15; and >= 1ULL << (count - 16); and >>= 1, count__or--)
					{
						if (LL & and)
						{
							S |= (1 << count__or);
						}
					}
					count -= 16;
				}
				else if (command[i] == 'C')
				{
					for (and = 1ULL << (count - 1), count__or = 7; and >= 1ULL << (count - 8); and >>= 1, count__or--)
					{
						if (LL & and)
						{
							C[count__C] |= (1 << count__or);
						}
					}
					count -= 8;
					count__C++;
				}
			}
			printf("%u %hu %c%c\n", L, S, C[0], C[1]);
		}
	}
	return 0;
}