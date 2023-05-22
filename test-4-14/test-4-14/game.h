#define _CRT_SECURE_NO_WARNINGS
#define ROW 10
#define COL 10
#include<stdlib.h>
#include<time.h>
void InitBoard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row,int col);
void computermove(char board[ROW][COL], int row, int col);
char iswin(char board[ROW][COL],int row,int col);
int isfull(char board[ROW][COL], int row, int col);