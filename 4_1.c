#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>

//int main()
//{
//	int command[4] = { 0,1,2,3 };								 /*����һ������*/
//	int num;
//	struct tm* sysTime;
//	printf("�����������������0!\n"); 							 /*����ַ���*/
//	printf("�����������:\n");									/*����ַ���*/
//
//	while (1)
//	{
//		scanf("%d", &num);										/*�����������*/
//		/*�ж�����������ַ�*/
//		if (command[0] == num)									/*�����������O*/
//		{
//			/*���������Ϣ*/
//			printf("��������1��ʾϵͳ���ڣ���������2��ʾϵͳʱ�䣬��������3�˳�ϵͳ!\n");
//		}
//		else if (command[1] == num)                             /*�������������1*/
//		{
//			time_t nowTime;                        		        /*��ȡϵͳ����*/
//			time(&nowTime);
//			sysTime = localtime(&nowTime);                      /*ת��Ϊϵͳ����*/
//			printf("ϵͳ����: %d - %d - %d\n",
//				1900 + sysTime->tm_year,
//				sysTime->tm_mon + 1,
//				sysTime->tm_mday);                              /*�����Ϣ*/
//		}
//		else if (command[2] == num)                            /*�������������2*/
//		{
//			time_t nowTime;
//			time(&nowTime);                                    /*��ȡϵͳʱ��*/
//			sysTime = localtime(&nowTime);                     /*ת��Ϊϵͳʱ��*/
//			printf("ϵͳʱ��: %d:%d:%d\n",
//				sysTime->tm_hour,
//				sysTime->tm_min,
//				sysTime->tm_sec);		                       /*�����Ϣ*/
//		}
//		else if (command[3] == num)
//		{
//			return 0;    		                              /*�˳�ϵͳ*/
//		}
//		printf("�����������:\n");     	                      /*����ַ���*/
//	}
//
//	return 0;                                                 /*�������*/
//}

//char* GetString(char* ps);
//void ShowString(char* ps);
//
//int main()
//{
//	char* ps = NULL;
//	ps = GetString("Hello!");
//	ShowString(ps);
//	return 0;
//}

////�ֲ���������������
//int main()
//{
//	int num = 1;								//�����һ������num
//	printf("%d\n", num);						//�������ֵ
//
//	if (num)
//	{
//		int num = 2;							//����ڶ�������num
//		printf("%d\n", num);					//�������ֵ
//
//		if (num)
//		{
//			int num = 3;						//�������������num
//			printf("%d\n", num);				//�������ֵ
//		}
//
//		printf("%d\n", num);					//�������ֵ
//	}
//
//	printf("%d\n", num);						//�������ֵ
//	return 0;
//}

//int	GobalPrice = 100;

//int main()
//{
//	printf("the chain store's original price is:%d\n", GobalPrice);
//	return 0;
//}

#include<ctype.h>

//int main()
//{
//	int i = 97;
//	if (isalpha(i))
//	{
//		printf("hello\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	if (isdigit(i))
//	{
//		printf("%d\n", i);
//	}
//	else
//	{
//		printf("...\n");
//	}
//	if (isalnum(i))
//	{
//		printf("%c\n", i);
//	}
//	else
//	{
//		printf("111\n");
//	}
//	return 0;
//}

int main()
{
	int arr[3][4];
	int (*p)[4] = arr;
	int i,j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			*(*(p + i) + j) = i;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
	}
	return 0;
}