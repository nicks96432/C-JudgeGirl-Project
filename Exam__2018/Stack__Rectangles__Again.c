#include <stdio.h>
#include <stdbool.h>
#define MAX_RECTANGLES 200
int n;
int used[MAX_RECTANGLES] = {};
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
/* a 在 b 上 */
bool check(rectangle a, rectangle b)
{
#ifdef LARGEONSMALL
	return (a.length <= b.length && a.width <= b.width) || (a.length <= b.width && a.width <= b.length);
#elif defined SMALLONLARGE
	return (a.length >= b.length && a.width >= b.width) || (a.length >= b.width && a.width >= b.length);
#endif
}
void print__solution(solution sol)
{
	printf("%d %d\n", sol.layer, sol.sum);
	return;
}
solution better__solution(solution a, solution b)
{
#ifdef LARGEONSMALL
	if (a.layer > b.layer || (a.layer == b.layer && a.sum > b.sum))
	{
		return a;
	}
	else
	{
		return b;
	}
#elif defined SMALLONLARGE
	if (a.layer < b.layer || (a.layer == b.layer && a.sum < b.sum))
	{
		return a;
	}
	else
	{
		return b;
	}

#endif
}
solution stack(rectangle rectangles[], int now, rectangle bottom, solution sol)
{
	if (now >= n)
	{
		return sol;
	}
	if (check(rectangles[now], bottom))
	{
		solution new__sol = {sol.layer + 1, sol.sum + now};
		return better__solution(stack(rectangles, now + 1, rectangles[now], new__sol), stack(rectangles, now + 1, bottom, sol));
	}
	else
	{
		return stack(rectangles, now + 1, bottom, sol);
	}
}
int main(void)
{
	rectangle rectangles[MAX_RECTANGLES];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &rectangles[i].width, &rectangles[i].length);
	}
#ifdef LARGEONSMALL
	rectangle bottom = {0x7fffffff, 0x7fffffff};
#elif SMALLONLARGE
	rectangle bottom = {0x80000000, 0x80000000};
#endif
	solution ans = {0, 0};
	print__solution(stack(rectangles, 0, bottom, ans));
	return 0;
}