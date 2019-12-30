#include <stdio.h>
#include "set.h"

int main(void)
{
	Set s1, s2;
	int numberOfElement = 5;
	initializeSet(&s1, numberOfElement);
	initializeSet(&s2, numberOfElement);

	addElement(&s1, 1);
	addElement(&s1, 3);
	addElement(&s2, 1);
	addElement(&s2, 5);

	if (intersect(s1, s2))
	{
		printf("intersect!\n");
	}
	return 0;
}