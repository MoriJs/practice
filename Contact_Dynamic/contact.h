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
//ͨѶ¼����
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

//��ϵ����Ϣ
typedef struct PeoInFo
{
	char name[MAX_Name];
	int age;
	char sex[MAX_Sex];
	char tele[MAX_Tele];
	char addr[MAX_Addr];
}PeoInFo;

//ͨѶ¼����
typedef struct Contact
{
	PeoInFo* data;//�����ϵ����Ϣ��ַ
	int size;//��¼��ǰ�Ѵ�ŵ���ϵ����Ϣ��Ŀ
	int capacity;//��ǰͨѶ¼���������
}Contact;
//��ʼ��ͨѶ¼
void InitContact(Contact* pc);
//�����ϵ����Ϣ
void AddContact(Contact* pc);
//��ӡͨѶ¼
void ShowContact(const Contact* pc);
//ɾ��ָ����ϵ����Ϣ
void DelContact(Contact* pc);
//����ָ����ϵ��
void SearchContact(const Contact* pc);
//�޸�ָ����ϵ����Ϣ
void ModifyContact(Contact* pc);
//����ͨѶ¼����
void SortContact(Contact* pc);
//����ͨѶ¼���ݣ��ͷŶ�̬�ڴ濪�ٵ��ڴ�
void DestoryContact(Contact* pc);