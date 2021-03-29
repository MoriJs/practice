#include"contact.h"

//��ʼ��ͨѶ¼
void InitContact(Contact* pc)
{
	assert(pc);
	pc->data = (PeoInFo*)malloc(3 * sizeof(PeoInFo));
	if (pc->data == NULL)
	{
		printf("%s\n", strerror(errno));
		return ;
	}
	pc->size = 0;
	pc->capacity = DEFAULT_SZ;
}

void CheckCapacity(Contact* pc)
{
	if (pc->size == pc->capacity)
	{
		//����
		PeoInFo* ptr = (PeoInFo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInFo));
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
#ifdef DEBUG
			printf("����ʧ��\n");
#endif // DEBUG
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
#ifdef DEBUG
			printf("���ݳɹ�\n");
#endif // DEBUG
		}
	}
}

//�����ϵ����Ϣ
void AddContact(Contact* pc)
{
	assert(pc);
	//��鵱ǰͨѶ¼������
	//1.������ˣ��ͽ�������
	//2.���û������ʲôҲ����
	CheckCapacity(pc);
	//��������
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

//��ӡͨѶ¼
void ShowContact(const Contact* pc)
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

//����ָ����ϵ��
static int FindByName(const Contact* pc, char name[MAX_NAME])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[0].name, name) == 0)
			return i;//�ҵ��˷����±�
	}
	return -1;//�Ҳ�������-1
} 

//ɾ��ָ����ϵ����Ϣ
void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
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
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
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
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
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

int cmp_name(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((PeoInFo*)e1)->name , ((PeoInFo*)e2)->name);
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

void bubble_sort(void* base, int num, int width, int (*cmp_name)(const void* e1, const void* e2))
{
	assert(base);
	int i, j;
	for (i = 0; i < num-1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//����Ԫ�رȽ�
			if (cmp_name((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

//����ͨѶ¼����
void SortContact(Contact* pc)
{
	//ð������
	bubble_sort(pc->data, pc->size, sizeof(pc->data[0]), cmp_name);
	//��ӡͨѶ¼
	ShowContact(pc);
}

//�ͷŶ�̬�ڴ濪�ٵ��ڴ�
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
}