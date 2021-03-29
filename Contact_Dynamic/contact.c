#include"contact.h"

//初始化通讯录
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
		//增容
		PeoInFo* ptr = (PeoInFo*)realloc(pc->data, (pc->capacity + 2) * sizeof(PeoInFo));
		if (ptr == NULL)
		{
			printf("%s\n", strerror(errno));
#ifdef DEBUG
			printf("增容失败\n");
#endif // DEBUG
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
#ifdef DEBUG
			printf("增容成功\n");
#endif // DEBUG
		}
	}
}

//添加联系人信息
void AddContact(Contact* pc)
{
	assert(pc);
	//检查当前通讯录的容量
	//1.如果满了，就进行增容
	//2.如果没满，就什么也不做
	CheckCapacity(pc);
	//增加数据
	printf("请输入联系人姓名:>");
	scanf("%s", pc->data[pc->size].name);
	printf("请输入联系人年龄:>");
	scanf("%d", &(pc->data[pc->size].age));
	printf("请输入联系人性别:>");
	scanf("%s", pc->data[pc->size].sex);
	printf("请输入联系人电话:>");
	scanf("%s", pc->data[pc->size].tele);
	printf("请输入联系人地址:>");
	scanf("%s", pc->data[pc->size].addr);

	pc->size++;
	printf("添加成功\n");
	Sleep(1000);
	system("cls");
}

//打印通讯录
void ShowContact(const Contact* pc)
{
	assert(pc);
	if (pc->size == 0)
		printf("通讯录为空\n");
	else
	{
		int i = 0;
		//标题
		printf("%-20s%-4s\t%-5s\t%-12s%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		//数据
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

//查找指定联系人
static int FindByName(const Contact* pc, char name[MAX_NAME])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (strcmp(pc->data[0].name, name) == 0)
			return i;//找到了返回下标
	}
	return -1;//找不到返回-1
} 

//删除指定联系人信息
void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要删除的联系人姓名:>");
	scanf("%s", name);
	//查找联系人位置
	int poc=FindByName(pc,name);
	//删除
	if (poc == -1)
		printf("要删除的联系人不存在\n");
	else
	{
		int j = 0;
		for (j = poc; j < pc->size - 1; j++)
			pc->data[j] = pc->data[j + 1];
		pc->size--;
		printf("删除成功\n");
		Sleep(1000);
		system("cls");
	}
}

//查找联系人
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要查找的联系人姓名:>");
	scanf("%s", name);
	int poc=FindByName(pc, name);
	if (poc == -1)
		printf("要查找的联系人不存在\n");
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

//修改指定联系人信息
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME];
	printf("请输入要修改的联系人名字:>");
	scanf("%s", &name);
	int poc=FindByName(pc, name);
	if (poc == -1)
		printf("要修改的联系人不存在\n");
	else
	{
		printf("请输入修改后的联系人名字:>");
		scanf("%s", pc->data[poc].name);
		printf("请输入修改后的联系人年龄:>");
		scanf("%d", &(pc->data[poc].age));
		printf("请输入修改后的联系人性别:>");
		scanf("%s", pc->data[poc].sex);
		printf("请输入修改后的联系人电话:>");
		scanf("%s", pc->data[poc].tele);
		printf("请输入修改后的联系人地址:>");
		scanf("%s", pc->data[poc].addr);

		printf("修改成功\n");
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
			//两个元素比较
			if (cmp_name((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

//排序通讯录内容
void SortContact(Contact* pc)
{
	//冒泡排序
	bubble_sort(pc->data, pc->size, sizeof(pc->data[0]), cmp_name);
	//打印通讯录
	ShowContact(pc);
}

//释放动态内存开辟的内存
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
}