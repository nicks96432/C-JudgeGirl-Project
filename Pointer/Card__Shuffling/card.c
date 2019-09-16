#include <stdio.h>
void shuffle(int *deck[])
{
	int count = 0;
	while (deck[count] != NULL)
	{
		count++;
	}
	int half;
	if (count % 2)
	{
		half = count / 2 + 1;
	}
	else
	{
		half = count / 2;
	}
	int *tmp1[half], *tmp2[count / 2];
	int i, j = 0, k = 0;
	for (i = 0; i < half; i++)
	{
		tmp1[i] = deck[i];
	}
	for (; i < count; i++)
	{
		tmp2[j] = deck[i];
		j++;
	}
	j = 0;
	for (i = 0; i < count; i++)
	{
		if (!(i % 2))
		{
			deck[i] = tmp1[j];
			j++;
		}
		else
		{
			deck[i] = tmp2[k];
			k++;
		}
	}
	return;
}
void print(int *deck[])
{
	int count = 0;
	while (deck[count] != NULL)
	{
		count++;
	}
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%d\n", *deck[i]);
	}
	return;
}
//   1 1 1 NULL
// 0 1 2 3