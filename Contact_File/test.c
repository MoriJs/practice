#include "contact.h"

//通讯录菜单
void menu()
{
	printf("***********************************************************\n");
	printf("************  1.add               2.del         ***********\n");
	printf("************  3.search            4.modify      ***********\n");
	printf("************  5.show              6.sort        ***********\n");
	printf("************  7.format            8.save        ***********\n");
	printf("************  0.exit                            ***********\n");
	printf("***********************************************************\n");
}

int main()
{
	int input=0;
	//创建通讯录
	Contact con;//con就是通讯录，里边包含:data指针,size和capacity
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case FORMAT:
			FormatContact(&con);
			printf("格式化通讯录成功\n");
			Sleep(1000);
			system("cls");
			break;
		case EXIT:
			//退出前保存
			SaveContact(&con);
			//销毁通讯录内容，释放动态内存开辟的内存
			DestoryContact(&con);
			printf("退出通讯录\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}