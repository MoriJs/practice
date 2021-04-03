#define _CRT_SECURE_NO_WARNINGS

//#define DEBUG

#define DEFAULT_SZ 3
#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_SEX 5
#define MAX_ADDR 30

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
	FORMAT,
	SAVE
};

//��ϵ����Ϣ
typedef struct PeoInFo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
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

//��ʽ��ͨѶ¼
void FormatContact(Contact* pc);

//����ͨѶ¼���ݣ��ͷŶ�̬�ڴ濪�ٵ��ڴ�
void DestoryContact(Contact* pc);

//����ͨѶ¼����
void SaveContact(Contact* pc);