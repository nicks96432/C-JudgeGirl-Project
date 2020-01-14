#include <stdio.h>
#include "sub.h"
void substring(Node *text, Node *pattern)
{
	int now = 0, sum = 0;
	Node *ptr = pattern;
	while (text->next != NULL && ptr != NULL)
	{
		if (text->c != ptr->c)
		{
			ptr = pattern;
			sum = 0;
		}
		if (text->c == ptr->c)
		{
			ptr = ptr->next;
			sum += now;
		}
		text = text->next;
		now++;
	}
	printf("%d\n", sum);
	return;
}
void subsequence(Node *text, Node *pattern)
{
	int now = 0, sum = 0;
	while (text->next != NULL && pattern != NULL)
	{
		if (text->c == pattern->c)
		{
			pattern = pattern->next;
			sum += now;
		}
		text = text->next;
		now++;
	}
	printf("%d\n", sum);
	return;
}