#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
#include<stdio.h>
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] =' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
			    printf("|");
		}
		printf("\n");
		if (i<ROW-1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while (1)
	{
		printf("请输入要下的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法请重新输入！\n");
		}
	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1 == isfull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}
