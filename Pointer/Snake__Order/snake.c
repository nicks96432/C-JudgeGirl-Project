void snake(const int *ptr_array[100][100], int m)
{
	int i, j, count = 0;
	int *tmparray[m * m], *tmp;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			tmparray[count] = ptr_array[i][j];
			count++;
		}
	}
	for (i = 0; i < m * m; i++)
	{
		for (j = i + 1; j < m * m; j++)
		{
			if (*tmparray[i] > *tmparray[j])
			{
				tmp = tmparray[i];
				tmparray[i] = tmparray[j];
				tmparray[j] = tmp;
			}
		}
	}
	count = 0;
	for (i = 0; i < m; i += 2)
	{
		for (j = 0; j < m; j++)
		{
			ptr_array[i][j] = tmparray[count];
			count++;
		}
		if (i == m - 1)
		{
			break;
		}
		for (j = m - 1; j >= 0; j--)
		{
			ptr_array[i + 1][j] = tmparray[count];
			count++;
		}
	}
	return;
}