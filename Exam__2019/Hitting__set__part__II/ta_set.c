#include "ta_set.h"
void initializeSet(ta_Set *set, int numberOfElement)
{
	set->elements = 0;
}
bool intersect(ta_Set set1, ta_Set set2)
{
	return (set1.elements & set2.elements) ? true : false;
}
void addElement(ta_Set *set, int element)
{
	set->elements |= (1ULL << (element - 1));
	return;
}
void removeElement(ta_Set *set, int element)
{
	set->elements ^= (1ULL << (element - 1));
	return;
}
void printSet(ta_Set set)
{
	for (int i = 0; i < 64; i++)
	{
		if (set.elements & (1ULL << i))
		{
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	return;
}
