#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#define MAX_name 20
#define MAX_tele 12
#define MAX_sex 5
#define MAX_addr 30

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
	SORT
};

//联系人信息
struct PeoInfo
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
	char addr[MAX_addr];
};

//通讯录类型
struct contact
{
	struct PeoInfo data[MAX];//可存放1000个联系人信息
	int size;//记录当前已存放的联系人信息数目
};
//初始化通讯录
void InitContact(struct contact* pc);
//添加联系人信息
void AddContact(struct contact* pc);
//打印通讯录
void ShowContact(const struct contact* pc);
//删除指定联系人信息
void DelContact(struct contact* pc);
//查找联系人
void SearchContact(const struct contact* pc);
//修改指定联系人信息
void ModifyContact(struct contact* pc);
//排序通讯录内容
void SortContact(struct contact* pc);