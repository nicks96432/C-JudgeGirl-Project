#include <stdio.h>
#include "set.h"

int main(void)
{
	Set s;
	int numberOfElement = 5;
	initializeSet(&s, numberOfElement);
	addElement(&s, 1);
	addElement(&s, 2);
	addElement(&s, 5);
	printSet(s);
	return 0;
}