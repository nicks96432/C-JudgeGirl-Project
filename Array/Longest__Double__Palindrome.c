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
	printf("%d\n",max__len);
#endif //DEBUG
	// palindrome__a �M�w�Ĥ@�Ӧ^�媺�}�Y
	// palindrome__b �M�w�ĤG�Ӧ^�媺�}�Y
	for (palindrome__a = 0; palindrome__a < max__len - 1; palindrome__a++)
	{
		for (palindrome__b = palindrome__a + 1; palindrome__b < max__len; palindrome__b++)
		{
			// i�M�w��Ӧ^�媺�J�I�b����
			for (i = palindrome__a; i <= palindrome__b; i++)
			{
				a__not__palindrome = 0;
				b__not__palindrome = 0;
				// j�ˬdi��m�O�_���T
				for (j = 0; j <= (i - palindrome__a) / 2 && a__not__palindrome == 0; j++)
				{
					if (A[palindrome__a + j] != A[i - j])
					{
						a__not__palindrome = 1;
					}
				}
				for (j = 0; j <= (palindrome__b - i) / 2 && b__not__palindrome == 0; j++)
				{
					if (A[i + j] != A[palindrome__b - j])
					{
						b__not__palindrome = 1;
					}
				}
				// max__double__palindrome__len �O���̤j���^�����
				// max__palindrome__a �O�� palindrome__a ���̤j��
				// max__palindrome__b �O�� palindrome__b ���̤j��
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