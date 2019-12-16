#include "calArea.h"
int calArea(NODE *head)
{
	NODE *findright = head->rightPtr, *finddown = head->downPtr;
	int length = 0, width = 0;
	int rightarea = 0, downarea = 0;
	while (findright != finddown)
	{
		if (findright->downPtr != NULL)
		{
			findright = findright->downPtr;
			length++;
		}
		else if (findright->rightPtr != NULL)
		{
			findright = findright->rightPtr;
			rightarea += length;
		}
		if (finddown->downPtr != NULL)
		{
			finddown = finddown->downPtr;
			downarea += width;
		}
		else if (finddown->rightPtr != NULL)
		{
			finddown = finddown->rightPtr;
			width++;
		}
	}
	return length * width - rightarea - downarea;
}