#include <stdio.h>
#include "set.h"
void init(Set *set)
{
	*set = 0ULL;
	return;
}
void add(Set *set, int i)
{
	Set tmp = 1ULL << (i);
	Set tmp2 = *set;
	tmp2 |= tmp;
	*set = tmp2;
	return;
}
void has(Set set, int i)
{
	Set tmp = 1ULL << i;
	if (set & tmp)
	{
		printf("set has %d\n", i);
	}
	else
	{
		printf("set does not have %d\n", i);
	}
	return;
}
Set setUnion(Set a, Set b)
{
	Set ans, tmp;
	init(&ans);
	init(&tmp);
	for (tmp = 1ULL; tmp <= 1ULL << 63 && tmp > 0; tmp <<= 1)
	{
		if (a & tmp || b & tmp)
		{
			ans |= tmp;
		}
	}
	return ans;
}
Set setIntersect(Set a, Set b)
{
	Set ans, tmp;
	init(&ans);
	init(&tmp);
	for (tmp = 1ULL; tmp <= 1ULL << 63 && tmp > 0; tmp <<= 1)
	{
		if (tmp & a && tmp & b)
		{
			ans |= tmp;
		}
	}
	return ans;
}
Set setDifference(Set a, Set b)
{
	Set ans, tmp;
	init(&ans);
	init(&tmp);
	for (tmp = 1ULL; tmp <= 1ULL << 63 && tmp > 0; tmp <<= 1)
	{
		if (((a & tmp) && !(b & tmp)) || (!(a & tmp) && (b & tmp)))
		{
			ans |= tmp;
		}
	}
	return ans;
}