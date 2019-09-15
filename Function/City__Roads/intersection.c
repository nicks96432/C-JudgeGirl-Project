void intersection(int map[100][100], int result[4])
{
	int i, j, count;
	int tmp[102][102] = {0};
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			tmp[i][j] = map[i - 1][j - 1];
		}
	}
	for (i = 0; i < 4; i++)
	{
		result[i] = 0;
	}
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			count = 0;
			if (tmp[i][j] == 1)
			{
				count = tmp[i + 1][j] + tmp[i - 1][j] + tmp[i][j + 1] + tmp[i][j - 1];
				switch (count)
				{
				case 1:
					result[3]++;
					break;
				case 2:
					if (tmp[i + 1][j] != tmp[i - 1][j] && tmp[i][j + 1] != tmp[i][j - 1])
					{
						result[2]++;
					}
					break;
				case 3:
					result[1]++;
					break;
				case 4:
					result[0]++;
					break;
				default:
					break;
				}
			}
		}
	}
	return;
}