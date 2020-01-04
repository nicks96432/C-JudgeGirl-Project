#include <stdio.h>
#include <stdbool.h>
#define MAX_RECTANGLES 200
typedef struct Rectangle
{
	int width;
	int length;
} rectangle;
typedef struct Solution
{
	int layer;
	int sum;
} solution;
/* a 可以放在 b 上 */
bool check(rectangle a, rectangle b)
{
#ifdef SMALLONLARGE
	return (a.length <= b.length && a.width <= b.width) ||
		   (a.length <= b.width && a.width <= b.length);
#elif defined LARGEONSMALL
	return (a.length >= b.length && a.width >= b.width) ||
		   (a.length >= b.width && a.width >= b.length);
#endif
}
void printSolution(solution sol)
{
	printf("%d %d\n", sol.layer, sol.sum);
	return;
}
solution betterSolution(solution a, solution b)
{
#ifdef MAXAREASUM
	return (a.layer > b.layer || (a.layer == b.layer && a.sum > b.sum)) ? a : b;
#elif defined MINAREASUM
	return (a.layer > b.layer || (a.layer == b.layer && a.sum < b.sum)) ? a : b;
#endif
}
solution stack(int now, int n, rectangle top, rectangle rectangles[], solution sol)
{
	if (now >= n)
	{
		return sol;
	}
	if (check(rectangles[now], top))
	{
		solution new__sol = {sol.layer + 1,
							 sol.sum + rectangles[now].width * rectangles[now].length};
		return betterSolution(stack(now + 1, n, rectangles[now], rectangles, new__sol),
							  stack(now + 1, n, top, rectangles, sol));
	}
	else
	{
		return stack(now + 1, n, top, rectangles, sol);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	rectangle rectangles[MAX_RECTANGLES];
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &rectangles[i].length, &rectangles[i].width);
	}
#ifdef SMALLONLARGE
	rectangle bottom = {0x7fffffff, 0x7fffffff};
#elif defined LARGEONSMALL
	rectangle bottom = {0x80000000, 0x80000000};
#endif
	solution zero = {0, 0};
	printSolution(stack(0, n, bottom, rectangles, zero));
	return 0;
}