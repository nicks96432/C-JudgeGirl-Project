#include <stdio.h>
void count(int, int[], int);
int n, k, num[20], ans[1024] = {};
int main(void)
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	count(0, num, 0);
	while (scanf("%d", &k) != EOF)
	{
		printf("%d\n", ans[k]);
	}
	return 0;
}
void count(int index, int num[], int sum)
{
	printf("%d %d\n", index, sum);
	if (index == n)
	{
		ans[sum]++;
		return;
	}
	count(index + 1, num, sum);//不拿第index個
	count(index + 1, num, sum + num[index]);//拿第index個
}