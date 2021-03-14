#include"contact.h"
//��ʼ��ͨѶ¼
void InitContact(struct contact* pc)
{
	assert(pc);
	memset(pc->data, 0, sizeof(pc->data));
	pc->size = 0;//����ͨѶ¼��ʼԪ�ظ���
}
//�����ϵ����Ϣ
void AddContact(struct contact* pc)
{
	assert(pc);
	if (pc->size == MAX)
		printf("ͨѶ¼����\n");
	else
	{
		printf("��������ϵ������:>");
		scanf("%s", pc->data[pc->size].name);
		printf("��������ϵ������:>");
		scanf("%d", &(pc->data[pc->size].age));
		printf("��������ϵ���Ա�:>");
		scanf("%s", pc->data[pc->size].sex);
		printf("��������ϵ�˵绰:>");
		scanf("%s", pc->data[pc->size].tele);
		printf("��������ϵ�˵�ַ:>");
		scanf("%s", pc->data[pc->size].addr);

		pc->size++;
		printf("��ӳɹ�\n");
		Sleep(1000);
		system("cls");
	}
}
//��ӡͨѶ¼
void ShowContact(const struct contact* pc)
{
	assert(pc);
	if (pc->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		int i = 0;
		//����
		printf("%-20s%-4s\t%-5s\t%-12s%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		//����
		for (i = 0; i < pc->size; i++)
		{
			printf("%-20s%-4d\t%-5s\t%-12s%-30s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
		}
	}
}

static int FindByName(const struct contact* pc, char name[MAX_name])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
			return i;//�ҵ��˷����±�
	}
	return -1;//�Ҳ�������-1
}
//ɾ��ָ����ϵ����Ϣ
void DelContact(struct contact* pc)
{
	assert(pc);
	char name[MAX_name];
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", name);
	//������ϵ��λ��
	int poc=FindByName(pc,name);
	//ɾ��
	if (poc == -1)
		printf("Ҫɾ������ϵ�˲�����\n");
	else
	{
		int j = 0;
		for (j = poc; j < pc->size - 1; j++)
			pc->data[j] = pc->data[j + 1];
		pc->size--;
		printf("ɾ���ɹ�\n");
		Sleep(1000);
		system("cls");
	}
}
//������ϵ��
void SearchContact(const struct contact* pc)
{
	assert(pc);
	char name[MAX_name];
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	int poc=FindByName(pc, name);
	if (poc == -1)
		printf("Ҫ���ҵ���ϵ�˲�����\n");
	else
	{
		printf("%-20s%-4d\t%-5s\t%-12s%-30s\n",
			pc->data[poc].name,
			pc->data[poc].age,
			pc->data[poc].sex,
			pc->data[poc].tele,
			pc->data[poc].addr);
	}
}
//�޸�ָ����ϵ����Ϣ
void ModifyContact(struct contact* pc)
{
	assert(pc);
	char name[MAX_name];
	printf("������Ҫ�޸ĵ���ϵ������:>");
	scanf("%s", &name);
	int poc=FindByName(pc, name);
	if (poc == -1)
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	else
	{
		printf("�������޸ĺ����ϵ������:>");
		scanf("%s", pc->data[poc].name);
		printf("�������޸ĺ����ϵ������:>");
		scanf("%d", &(pc->data[poc].age));
		printf("�������޸ĺ����ϵ���Ա�:>");
		scanf("%s", pc->data[poc].sex);
		printf("�������޸ĺ����ϵ�˵绰:>");
		scanf("%s", pc->data[poc].tele);
		printf("�������޸ĺ����ϵ�˵�ַ:>");
		scanf("%s", pc->data[poc].addr);

		printf("�޸ĳɹ�\n");
		Sleep(1000);
		system("cls");
	}
}

int cmp(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((struct contact*)e1)->data->name , ((struct contact*)e2)->data->name);
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

void bubble_sort(void* base, int num, int width, int (*cmp)(void* e1, void* e2))
{
	assert(base);
	int i, j;
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//����Ԫ�رȽ�
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
//����ͨѶ¼����
void SortContact(struct contact* pc)
{
	//ð������
	bubble_sort(pc->data, pc->size, sizeof(pc->data[0]), cmp);
	//��ӡͨѶ¼
	ShowContact(pc);
}