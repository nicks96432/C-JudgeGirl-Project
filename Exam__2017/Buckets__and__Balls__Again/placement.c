#include <stdbool.h>
void first(int bucket[1024], int N, int ball[16384], int M, int result[16384]);
void best(int bucket[1024], int N, int ball[16384], int M, int result[16384]);
void worst(int bucket[1024], int N, int ball[16384], int M, int result[16384]);
void place(int bucket[1024], int N, int ball[16384], int M, int method, int result[16384])
{
	if (method == 0)
	{
		first(bucket, N, ball, M, result);
	}
	else if (method == 1)
	{
		best(bucket, N, ball, M, result);
	}
	else if (method == 2)
	{
		worst(bucket, N, ball, M, result);
	}
	return;
}
void first(int bucket[1024], int N, int ball[16384], int M, int result[16384])
{
	int i, j;
	bool found;
	for (i = 0; i < M; i++)
	{
		found = false;
		for (j = 0; j < N; j++)
		{
			if (bucket[j] >= ball[i])
			{
				bucket[j] -= ball[i];
				result[i] = j;
				found = true;
				break;
			}
		}
		if (!found)
		{
			result[i] = -1;
		}
	}
	return;
}
void best(int bucket[1024], int N, int ball[16384], int M, int result[16384])
{
	int i, j, min, min__index;
	bool found;
	for (i = 0; i < M; i++)
	{
		min = 0x7fffffff;
		found = false;
		for (j = 0; j < N; j++)
		{
			if (bucket[j] < min && bucket[j] >= ball[i])
			{
				min = bucket[j];
				min__index = j;
				found = true;
			}
		}
		if (found)
		{
			bucket[min__index] -= ball[i];
			result[i] = min__index;
		}
		else
		{
			result[i] = -1;
		}
	}
	return;
}
void worst(int bucket[1024], int N, int ball[16384], int M, int result[16384])
{
	int i, j, max, max__index;
	bool found;
	for (i = 0; i < M; i++)
	{
		max = -(0x7fffffff);
		found = false;
		for (j = N - 1; j >= 0; j--)
		{
			if (bucket[j] > max && bucket[j] >= ball[i])
			{
				max = bucket[j];
				max__index = j;
				found = true;
			}
		}
		if (found)
		{
			bucket[max__index] -= ball[i];
			result[i] = max__index;
		}
		else
		{
			result[i] = -1;
		}
	}
	return;
}