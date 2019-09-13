#include <stdio.h>
int main(void)
{
	// chessboard: 0:nothing, 1:black, 2:white
	int i, j, n, move[1002][2], chessboard[3][3] = {0}, black__win = 0, white__win = 0, moves = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf("%d", &move[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		if (move[i][0] >= 0 && move[i][0] <= 2 && move[i][1] >= 0 && move[i][1] <= 2)
		{
			if (chessboard[move[i][0]][move[i][1]] == 0)
			{
				if (moves % 2 == 1)
				{
					chessboard[move[i][0]][move[i][1]] = 1;
					moves++;
				}
				else
				{
					chessboard[move[i][0]][move[i][1]] = 2;
					moves++;
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
		if ((chessboard[0][0] == 1 && chessboard[0][1] == 1 && chessboard[0][2] == 1) || (chessboard[1][0] == 1 && chessboard[1][1] == 1 && chessboard[1][2] == 1) || (chessboard[2][0] == 1 && chessboard[2][1] == 1 && chessboard[2][2] == 1) || (chessboard[0][0] == 1 && chessboard[1][0] == 1 && chessboard[2][0] == 1) || (chessboard[0][1] == 1 && chessboard[1][1] == 1 && chessboard[2][1] == 1) || (chessboard[0][2] == 1 && chessboard[1][2] == 1 && chessboard[2][2] == 1) || (chessboard[0][0] == 1 && chessboard[1][1] == 1 && chessboard[2][2] == 1) || (chessboard[2][0] == 1 && chessboard[1][1] == 1 && chessboard[0][2] == 1))
		{
			black__win = 1;
			// break;
		}
		else if ((chessboard[0][0] == 2 && chessboard[0][1] == 2 && chessboard[0][2] == 2) || (chessboard[1][0] == 2 && chessboard[1][1] == 2 && chessboard[1][2] == 2) || (chessboard[2][0] == 2 && chessboard[2][1] == 2 && chessboard[2][2] == 2) || (chessboard[0][0] == 2 && chessboard[1][0] == 2 && chessboard[2][0] == 2) || (chessboard[0][1] == 2 && chessboard[1][1] == 2 && chessboard[2][1] == 2) || (chessboard[0][2] == 2 && chessboard[1][2] == 2 && chessboard[2][2] == 2) || (chessboard[0][0] == 2 && chessboard[1][1] == 2 && chessboard[2][2] == 2) || (chessboard[2][0] == 2 && chessboard[1][1] == 2 && chessboard[0][2] == 2))
		{
			white__win = 1;
			// break;
		}
	}
	if (black__win)
	{
		printf("Black wins.");
	}
	else if (white__win)
	{
		printf("White wins.");
	}
	else
	{
		printf("There is a draw.");
	}
	return 0;
}
// 奇數次移動:黑子; 偶數次移動:白子
// 非法操作不計算在移動次數裡面