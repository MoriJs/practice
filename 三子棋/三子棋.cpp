#include"game.h"
int main()
{
	int input;
	srand((unsigned int)time(NULL));
	menu();
	printf("请选择：");
	do
	{
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}
	} while (input);
	return 0;
}