int max(int *iptr[], int n)
{
	int i, maxnum = 0;
	for (i = 0; i < n; i++)
	{
		if (*iptr[i] > maxnum)
		{
			maxnum = *iptr[i];
		}
	}
	return maxnum;
}