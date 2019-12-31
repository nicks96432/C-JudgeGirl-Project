#include <stdio.h>
#include <stdbool.h>

typedef struct ta_set
{
	unsigned long long elements;
} ta_Set;

void initializeSet(ta_Set *set, int numberOfElemnet);
void addElement(ta_Set *set, int element);
void removeElement(ta_Set *set, int element);
void printSet(ta_Set set);
bool intersect(ta_Set set1, ta_Set set2);