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
//ͨѶ¼����
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

//��ϵ����Ϣ
struct PeoInfo
{
	char name[MAX_name];
	int age;
	char sex[MAX_sex];
	char tele[MAX_tele];
	char addr[MAX_addr];
};

//ͨѶ¼����
struct contact
{
	struct PeoInfo data[MAX];//�ɴ��1000����ϵ����Ϣ
	int size;//��¼��ǰ�Ѵ�ŵ���ϵ����Ϣ��Ŀ
};
//��ʼ��ͨѶ¼
void InitContact(struct contact* pc);
//�����ϵ����Ϣ
void AddContact(struct contact* pc);
//��ӡͨѶ¼
void ShowContact(const struct contact* pc);
//ɾ��ָ����ϵ����Ϣ
void DelContact(struct contact* pc);
//������ϵ��
void SearchContact(const struct contact* pc);
//�޸�ָ����ϵ����Ϣ
void ModifyContact(struct contact* pc);
//����ͨѶ¼����
void SortContact(struct contact* pc);