int evaluate_f(int *iptr[], int n, int *index)
{
	int i;
	*index = 0;
	long long evaluate__arr;
	int max = 4 * (*iptr[i]) - 6 * (*(iptr[i] + 1));
	for (i = 0; i < n; i++)
	{
		evaluate__arr = 4 * (*iptr[i]) - 6 * (*(iptr[i] + 1));
		if (evaluate__arr > max)
		{
			max = evaluate__arr;
			*index = i;
		}
	}
	return max;
}