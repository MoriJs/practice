#define _CRT_SECURE_NO_WARNINGS
#define ROW 3 
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);
void ShowBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);
int IsFault(char board[ROW][COL], int row, int col);