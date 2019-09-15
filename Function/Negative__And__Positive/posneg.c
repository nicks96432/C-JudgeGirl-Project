void posneg(int array[5][5], int result[2])
{
	result[0] = 0;
	result[1] = 0;
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (array[i][j] < 0)
			{
				result[0]++;
			}
			if (array[i][j] > 0)
			{
				result[1]++;
			}
		}
	}
	return;
}