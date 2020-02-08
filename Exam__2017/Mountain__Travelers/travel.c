#include <stdio.h>
#include <stdbool.h>
#include "travel.h"
#define A 1
#define B 2
static int find(int map[1024][1024], char visited[1024][1024], int N, int M,
				int r, int c, int name)
{
	const int direction[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	int choice = -1, height = map[r][c];
	int tmp_r, tmp_c;
	if (name == A)
	{
		for (int i = 0; i < 8; i++)
		{
			tmp_c = c + direction[i][1];
			tmp_r = r + direction[i][0];
			if (tmp_r >= N || tmp_r < 0 || tmp_c >= M || tmp_c < 0)
			{
				continue;
			}
			if (map[tmp_r][tmp_c] > height)
			{
				height = map[tmp_r][tmp_c];
				choice = i;
			}
		}
	}
	else if (name == B)
	{
		for (int i = 0; i < 8; i++)
		{
			tmp_c = c + direction[i][1];
			tmp_r = r + direction[i][0];
			if (tmp_r >= N || tmp_r < 0 || tmp_c >= M || tmp_c < 0)
			{
				continue;
			}
			if (map[tmp_r][tmp_c] < height)
			{
				height = map[tmp_r][tmp_c];
				choice = i;
			}
		}
	}
	return choice;
}
void travel(int map[1024][1024], int N, int M, int A_r,
			int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
	const int direction[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
	int countA = 0, countB = 0;
	int findA, findB;
	bool stopA = false, stopB = false;
	char visited[1024][1024] = {0};
	visited[A_r][A_c] = A;
	visited[B_r][B_c] = B;
	while (!(stopA && stopB))
	{
		if (!stopA)
		{
			findA = find(map, visited, N, M, A_r, A_c, A);
			directionA[countA] = findA;
			A_r += (findA == -1) ? 0 : direction[findA][0];
			A_c += (findA == -1) ? 0 : direction[findA][1];
			if (findA == -1)
			{
				stopA = true;
			}
			countA++;
			if (visited[A_r][A_c])
			{
				directionA[countA] = -1;
				stopA = true;
			}
			else
			{
				visited[A_r][A_c] = A;
			}
		}
		if (!stopB)
		{
			findB = find(map, visited, N, M, B_r, B_c, B);
			directionB[countB] = findB;
			B_r += (findB == -1) ? 0 : direction[findB][0];
			B_c += (findB == -1) ? 0 : direction[findB][1];
			if (findB == -1)
			{
				stopB = true;
			}
			countB++;
			if (visited[B_r][B_c])
			{
				directionB[countB] = -1;
				stopB = true;
			}
			else
			{
				visited[B_r][B_c] = B;
			}
		}
		if (A_c == B_c && A_r == B_r)
		{
			directionA[countA] = -1;
			directionB[countB] = -1;
			stopA = true;
			stopB = true;
		}
	}
	return;
}