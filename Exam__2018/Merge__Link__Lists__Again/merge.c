#include <stdio.h>
#include "merge.h"
int findnext(Node *list[], int now, int n, int direction)
{
	while (now >= 0 && now < n)
	{
		if (list[now] != NULL)
		{
			return now;
		}
		now += direction;
	}
	return -1;
}
Node *merge(Node *list[], int K)
{
	int now, next;
#if defined ZIGZAG || defined TOPDOWN
	/* 1:下 -1:上 */
	int direction = 1;
	int last = 0;
#elif defined BOTTOMUP
	int direction = -1;
	int last = K - 1;
#endif
	Node *prev = NULL, *head = NULL;
	while ((now = findnext(list, last, K, direction)) != -1)
	{
		if (prev == NULL)
		{
			head = list[now];
		}
		else
		{
			prev->next = list[now];
		}
		while ((next = findnext(list, now + direction, K, direction)) != -1)
		{
			Node *nowPtr = list[now];
			list[now] = list[now]->next;
			nowPtr->next = list[next];
			now = next;
		}
#ifdef ZIGZAG
		last = now;
		direction = -direction;
#elif defined TOPDOWN
		last = 0;
#elif defined BOTTOMUP
		last = K - 1;
#endif
		prev = list[now];
		list[now] = list[now]->next;
	}
	return head;
}