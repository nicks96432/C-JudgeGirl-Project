// ptr[0]指向arr[0]，ptr[n-1]指向arr最末端
void fill_array(int *ptr[], int n)
{
	int i, *tmpptr, arrsize = 0;
	for (tmpptr = ptr[0]; tmpptr <= ptr[n - 1]; tmpptr++)
	{
		*tmpptr = -1;
		arrsize++;
	}
	for (i = 0; i < n; i++)
	{
		*ptr[i] = i;
	}
	int tmparr[arrsize], tmparr2[arrsize];
	for (i = 0, tmpptr = ptr[0]; i < arrsize, tmpptr <= ptr[n - 1]; i++, tmpptr++)
	{
		tmparr[i] = *tmpptr;
		tmparr2[i] = tmparr[i];
	}
	int tmpleft, tmpright, j;
	for (i = 0; i < arrsize; i++)
	{
		if (tmparr[i] == -1)
		{
			for (j = i; j >= 0; j--)
			{
				if (tmparr2[j] != -1)
				{
					tmpleft = tmparr2[j];
					break;
				}
			}
			for (j = i; j < arrsize; j++)
			{
				if (tmparr2[j] != -1)
				{
					tmpright = tmparr2[j];
					break;
				}
			}
			tmparr[i] = tmpleft + tmpright;
		}
	}
	for (i = 0, tmpptr = ptr[0]; i < n, tmpptr <= ptr[n - 1]; i++, tmpptr++)
	{
		*tmpptr = tmparr[i];
	}
	return;
}