#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_SZ 3
#define MAX_Name 20
#define MAX_Tele 12
#define MAX_Sex 5
#define MAX_Addr 30

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>
//通讯录操作
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	INIT
};

//联系人信息
typedef struct PeoInFo
{
	char name[MAX_Name];
	int age;
	char sex[MAX_Sex];
	char tele[MAX_Tele];
	char addr[MAX_Addr];
}PeoInFo;

//通讯录类型
typedef struct Contact
{
	PeoInFo* data;//存放联系人信息地址
	int size;//记录当前已存放的联系人信息数目
	int capacity;//当前通讯录的最大容量
}Contact;
//初始化通讯录
void InitContact(Contact* pc);
//添加联系人信息
void AddContact(Contact* pc);
//打印通讯录
void ShowContact(const Contact* pc);
//删除指定联系人信息
void DelContact(Contact* pc);
//查找指定联系人
void SearchContact(const Contact* pc);
//修改指定联系人信息
void ModifyContact(Contact* pc);
//排序通讯录内容
void SortContact(Contact* pc);
//销毁通讯录内容，释放动态内存开辟的内存
void DestoryContact(Contact* pc);