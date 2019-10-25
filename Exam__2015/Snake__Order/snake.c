#include "snake.h"
int snake(int *ptr, int *row, int *column)
{
	int i, count = 0;
	_Bool reverse = 1;
	for ((*column) = 0;; (*column)++)
	{
		if (ptr[*column] != count)
		{
			break;
		}
		count++;
	}
	(*row)++;
	while (1)
	{
		if (!reverse)
		{
			for (i = 0; i < *column; i++)
			{
				if (ptr[(*row) * (*column) + i] == 0)
				{
					return 1;
				}
				else if (ptr[(*row) * (*column) + i] != count)
				{
					*column = i;
					return 0;
				}
				count++;
			}
			(*row)++;
			reverse = 1;
		}
		else
		{
			for (i = *column - 1; i >= 0; i--)
			{
				if (ptr[(*row) * (*column) + i] == 0)
				{
					return 1;
				}
				else if (ptr[(*row) * (*column) + i] != count)
				{
					*column -= i + 1;
					return 0;
				}
				count++;
			}
			(*row)++;
			reverse = 0;
		}
	}
	return 1;
}