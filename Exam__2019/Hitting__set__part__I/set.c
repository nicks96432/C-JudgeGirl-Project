#include "set.h"
void initializeSet(Set *set, int numberOfElement)
{
	set->elements = 0;
}
bool intersect(Set set1, Set set2)
{
	return (set1.elements & set2.elements) ? true : false;
}
void addElement(Set *set, int element)
{
	set->elements |= (1ULL << (element - 1));
	return;
}
void removeElement(Set *set, int element)
{
	set->elements ^= (1ULL << (element - 1));
	return;
}
void printSet(Set set)
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
