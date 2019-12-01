#include <stdio.h>
#define MAX_N 16384
int n;
int sequence[MAX_N];
void seesaw(int left, int right)
{
	if (right - left + 1 < 3)
	{
		return;
	}
	/* 算重心 */
	int i;
	long long sum = 0, middle, torque = 0;
	for (i = left; i <= right; i++)
	{
		sum += sequence[i];
		/* 以sequence[0]為原點 */
		torque += sequence[i] * (i - left);
	}
	if (torque % sum != 0)
	{
		return;
	}
	middle = torque / sum + left;
	/* 中序遍歷 */
	seesaw(left, middle - 1);
	printf("%d\n", middle);
	seesaw(middle + 1, right);
	return;
}
int main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &sequence[i]);
	}
	seesaw(0, n - 1);
	return 0;
}