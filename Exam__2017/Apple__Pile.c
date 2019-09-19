#include <stdio.h>
int main(void)
{
	int top, bottom;
	scanf("%d%d", &top, &bottom);
	int total = (top + bottom) * (bottom - top + 1) / 2, around = top + bottom + (bottom - top - 1) * 2;
	printf("%d\n%d", total, around);
	return 0;
}