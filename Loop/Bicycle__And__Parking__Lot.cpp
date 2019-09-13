#include <iostream>
#include <algorithm>
#include <bits/ios_base.h>
using namespace std;
int abs(int);
bool comp(int, int);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i, j, k, l, m, n, put = 0, *result1, *result2;
	//lot[][0]:x ,lot[][1]:y ,lot[][2]:capacity ,lot[][3]=bikes
	cin >> n;
	int lot[n][4], flag1[n], flag2[n];
	for (i = 0; i < n; i++)
	{
		cin >> lot[i][0] >> lot[i][1] >> lot[i][2];
		lot[i][3] = 0;
	}
	cin >> m;
	int bike[m][2];
	for (i = 0; i < m; i++)
	{
		cin >> bike[i][0] >> bike[i][1];
	}
	int **dist = new int *[m], **dist__sorted = new int *[m],
		**index__after__sorted = new int *[m], **used__flag = new int *[m];
	// initialize
	for (i = 0; i < m; i++)
	{
		dist[i] = new int[n];
		dist__sorted[i] = new int[n];
		index__after__sorted[i] = new int[n];
		used__flag[i] = new int[n];
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			used__flag[i][j] = 0;
		}
	}
	// calculate distance
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			dist[i][j] = abs(bike[i][0] - lot[j][0]) + abs(bike[i][1] - lot[j][1]);
		}
	}

	// sort distance
	for (i = 0; i < m; i++)
	{
		partial_sort_copy(dist[i], dist[i] + n, dist__sorted[i], dist__sorted[i] + n, comp);
	}

	// find the index of the sorted distance
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (dist__sorted[i][j] == dist[i][k] && used__flag[i][k] != 0)
				{
					// FIXME:if distance is the same-->check
					for (l = 0; l < n; l++)
					{
						result1 = find(dist[i] + l, dist[i] + n, dist__sorted[i][j]);
						result2 = find(dist__sorted[i] + l, dist__sorted[i] + n, dist__sorted[i][j]);
						flag1[result1 - dist[i]] = result1 - dist[i] + 1;
						flag2[result2 - dist__sorted[i]] = result2 - dist__sorted[i] + 1;
						// cout<<flag1[l]<<"\t"<<flag2[l]<<"\n";
					}
					for (l = 0; l < n && flag1[l] != 0; l++)
					{
						if (lot[flag1[l]][0] < lot[flag1[l + 1]][0])
						{
							index__after__sorted[i][flag2[l] - 1] = index__after__sorted[i][j] - 1;
							index__after__sorted[i][flag2[l]] = index__after__sorted[i][flag2[l] - 1] + 1;
						}
						else if (lot[flag1[l]][0] == lot[flag1[l+1]][0])
						{
							if (lot[flag1[l]][1] < lot[flag1[l+1]][1])
							{
							index__after__sorted[i][flag2[l] - 1] = index__after__sorted[i][j] - 1;
							index__after__sorted[i][flag2[l]] = index__after__sorted[i][flag2[l] - 1] + 1;
							}
							else
							{
							index__after__sorted[i][flag2[l]] = index__after__sorted[i][j] - 1;
							index__after__sorted[i][flag2[l]-1] = index__after__sorted[i][flag2[l]] + 1;
							}
						}
						else
						{
							index__after__sorted[i][flag2[l]] = index__after__sorted[i][j] - 1;
							index__after__sorted[i][flag2[l]-1] = index__after__sorted[i][flag2[l]] + 1;
						}
					}
				}
				else if (dist__sorted[i][j] == dist[i][k] && used__flag[i][k] == 0)
				{
					index__after__sorted[i][j] = k;
					used__flag[i][k] = 1;
				}
				k++;
			}
		}
	}
	// put bicycles into the lot
	for (i = 0; i < m; i++)
	{
		if (lot[index__after__sorted[i][put]][3] >= lot[index__after__sorted[i][put]][2])
		{
			put++;
			continue;
		}
		else
		{
			lot[index__after__sorted[i][put]][3]++;
		}
		put = 0;
	}
	// test
	/* for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << dist[i][j] << "\t";
		}
		cout << "\n";
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << dist__sorted[i][j] << "\t";
		}
		cout << "\n";
	} */
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << index__after__sorted[i][j] << "\t";
		}
		cout << "\n";
	}
	/* for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << used__flag[i][j] << "\t";
		}
		cout << "\n";
	} */
	for (i = 0; i < n; i++)
	{
		cout << lot[i][3] << "\n";
	}
	delete[] dist;
	delete[] dist__sorted;
	delete[] index__after__sorted;
	delete[] used__flag;
	return 0;
}
// int abs(int x)
// {
// 	return x > 0 ? x : -x;
// }
bool comp(int i, int j)
{
	return i < j;
}