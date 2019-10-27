#include <stdio.h>
int main(void)
{
	int max__len = 0, A[102];
	int palindrome__a, palindrome__b, max__double__palindrome__len = 0;
	int max__palindrome__a = 0, max__palindrome__b = 0;
	int i, j;
	_Bool a__not__palindrome, b__not__palindrome;
	while (scanf("%d", &A[max__len]) == 1)
	{
		max__len++;
	}
#ifdef DEBUG
	printf("%d\n", max__len);
#endif //DEBUG
	// palindrome__a 決定第一個回文的開頭
	// palindrome__b 決定第二個回文的結尾
	for (palindrome__a = 0; palindrome__a < max__len - 1; palindrome__a++)
	{
		for (palindrome__b = palindrome__a + 1; palindrome__b < max__len; palindrome__b++)
		{
			// i決定兩個回文的交點在哪裡
			for (i = palindrome__a; i <= palindrome__b; i++)
			{
				a__not__palindrome = 0;
				b__not__palindrome = 0;
				// j檢查i位置是否正確
				for (j = 0; j <= (i - palindrome__a) >> 1 && a__not__palindrome == 0; j++)
				{
					if (A[palindrome__a + j] != A[i - j])
					{
						a__not__palindrome = 1;
					}
				}
				for (j = 0; j <= (palindrome__b - i) >> 1 && b__not__palindrome == 0; j++)
				{
					if (A[i + 1 + j] != A[palindrome__b - j])
					{
						b__not__palindrome = 1;
					}
				}
				// max__double__palindrome__len 記錄最大雙回文長度
				// max__palindrome__a 記錄 palindrome__a 的最大值
				// max__palindrome__b 記錄 palindrome__b 的最大值
				if (a__not__palindrome == 0 && b__not__palindrome == 0 && (palindrome__b - palindrome__a) >= max__double__palindrome__len)
				{
					max__double__palindrome__len = palindrome__b - palindrome__a;
					max__palindrome__a = palindrome__a;
					max__palindrome__b = palindrome__b;
				}
			}
		}
	}
	for (i = max__palindrome__a; i < max__palindrome__b; i++)
	{
		printf("%d ", A[i]);
	}
	printf("%d", A[i]);
	return 0;
}