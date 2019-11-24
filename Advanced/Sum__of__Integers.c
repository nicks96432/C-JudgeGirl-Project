#include <stdio.h>
int main(void)
{
	int n, ans = 0;
	while (scanf("%d", &n) != EOF)
	{
		ans += n;
	}
	printf("%d\n", ans);
	return 0;
}