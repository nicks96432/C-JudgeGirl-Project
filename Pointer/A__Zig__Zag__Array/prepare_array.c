void prepare_array(int buffer[], int *array[], int row, int column[])
{
	int i, *tmp;
	tmp = buffer;
	array[0] = buffer;
	for (i = 1; i < row; i++)
	{
		tmp += column[i - 1];
		array[i] = tmp;
	}
	return;
}