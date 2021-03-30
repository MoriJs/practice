#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct S //结构体
{
	char name[10];
	char sex[5];
	int age;
}S;

typedef struct S1 //位段
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
}S1;

typedef enum E //枚举--一一列举
{
	red,
	yellow=5,
	green
}E;

typedef union U //共用/联合体
{
	short a;
	char arr[2];
}U;

//int main()
//{
	//S s = { "zhangshan","男",20 };
	//int sz = sizeof(s);
	//printf("%d\n", sz);
	//S* ps = &s;
	//scanf("%s", ps->name);
	//scanf("%s", ps->sex);
	//scanf("%d", &(ps->age));
	//printf("%s\n", ps->name);
	//printf("%s\n", ps->sex);
	//printf("%d\n", ps->age);

	//S1 s1 = { 0 };
	//s1.a = 10;
	//s1.b = 20;
	//s1.c = 30;
	//s1.d = 40;
	//printf("%d\n", sizeof(s1));

	//int a, b, c;
	//a = red;
	//b = yellow;
	//c = green;
	//printf("%d\n", a);
	//printf("%d\n", b);
	//printf("%d\n", c);

	//U u = { 0 };
	//u.arr[0] = 10;
	//u.arr[1] = 20;
	//printf("%d\n", u.a);
	//printf("%d\n", u.arr[0]);
	//printf("%d\n", u.arr[1]);

	//return 0;
//}

#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>

typedef struct Info
{
	char name[10];
	char sex[5];
	int age;
}Info;

typedef struct Con
{
	Info* data;
	int size;
	int capacity;
}Con;

typedef struct Con2
{
	Info data[3];
	int size;
	int capacity = 3;
}Con2;

void InitCon(Con* pc)
{
	assert(pc);
	pc->data = (Info*)malloc(3 * sizeof(Info));
	if (pc->data == NULL)
	{
		printf("InitCon::%s\n", strerror(errno));
		return;
	}
	pc->size = 0;
	pc->capacity = 3;
}

void AddCon(Con* pc)
{
	assert(pc);
	int i;
	for(i=0;i<pc->capacity;i++)
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[i].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[i].sex);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[i].age));
		pc->size++;
		//Sleep(1000);
		//system("cls");
	}
}

void Swap(char* p1, char* p2, int width)
{
	assert(p1 && p2);
	while (width--)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

int cmp(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return (strcmp(((Info*)e1)->name, ((Info*)e2)->name));
}

void bubble_sort(Info* base, int num, int width, int (*cmp)(const void* e1, const void* e2))
{
	assert(base);
	int i, j;
	for (i = 0; i < num - 1; i++) //趟数
	{
		for (j = 0; j < num - 1 - i; j++) //次数
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
		}
	}
}

void SortCon(Con* pc)
{
	assert(pc);
	bubble_sort(pc->data, pc->size, sizeof(Info), cmp);
}

void ShowCon(Con* pc)
{
	assert(pc);
	int i;
	for(i=0;i<pc->size;i++)
	{
		printf("%s\n", pc->data[i].name);
		printf("%s\n", pc->data[i].sex);
		printf("%d\n", pc->data[i].age);
	}
}

int main()
{
	Con con;
	InitCon(&con);
	AddCon(&con);
	SortCon(&con);
	ShowCon(&con);
	return 0;
}