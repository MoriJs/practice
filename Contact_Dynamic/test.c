#include "contact.h"

//ͨѶ¼�˵�
void menu()
{
	printf("***********************************************************\n");
	printf("************  1.add               2.del         ***********\n");
	printf("************  3.search            4.modify      ***********\n");
	printf("************  5.show              6.sort        ***********\n");
	printf("************  7.init              0.exit        ***********\n");
	printf("***********************************************************\n");
}

int main()
{
	int input=0;
	//����ͨѶ¼
	Contact con;//con����ͨѶ¼����߰���:dataָ��,size��capacity
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
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
		case INIT:
			InitContact(&con);
			printf("��ʼ��ͨѶ¼�ɹ�\n");
			Sleep(1000);
			system("cls");
			break;
		case EXIT:
			//����ͨѶ¼���ݣ��ͷŶ�̬�ڴ濪�ٵ��ڴ�
			DestoryContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}