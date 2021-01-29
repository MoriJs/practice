#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("****  1.play    0.exit****\n");
	printf("**************************\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}
void ShowBoard(char board[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		printf("---|---|---\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走 X\n");
	printf("请输入坐标：");
	//验证坐标合理性
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
				printf("该坐标被占用\n请重新输入：");
		}
		else
			printf("坐标非法\n请重新输入：");
	}
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走 O\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}
int IsFault(char board[ROW][COL], int row, int col)
{
	//返回1表示棋盘满了
	//返回0表示棋盘没满
	int i, j;
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
char IsWin(char board[ROW][COL], int row, int col)
{
	//玩家赢 'X'
	//电脑赢 'O'
	//平局   'Q'
	//继续   'C'
	int i;
	//判断是否赢
	//横行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][0];
	}
	//竖列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
			return board[0][i];
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
		return board[0][2];
	//判断是否平局
	if (1 == IsFault(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		//打印棋盘
		ShowBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL); //判断输赢
		if (ret != 'C')
			break;
		system("cls");
		ComputerMove(board, ROW, COL);  //电脑走
		ShowBoard(board, ROW, COL);
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'X')
		printf("玩家赢\n");
	else if (ret == 'O')
		printf("电脑赢\n");
	else
		printf("平局\n");
	printf("********************************\n");
	printf("****1.再来一局    0.退出游戏****\n");
	printf("********************************\n");
}