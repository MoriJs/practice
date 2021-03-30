#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MALLOC(num,type) malloc(num*sizeof(type))

//int main()
//{
	//int i = 0;
	////int* p = (int*)malloc(10*sizeof(int));
	//int* p = MALLOC(10, int);
	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//else
	//{
	//	for (i = 0; i < 10; i++)
	//	{
	//		*(p + i) = i;
	//	}
	//	for (i = 0; i < 10; i++)
	//	{
	//		printf("%d ", *(p + i));
	//	}
	//	free(p);
	//	p = NULL;
	//}

	//int i;
	//int* p = (int*)calloc(10, 4);
	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//else
	//{
	//	for (i = 0; i < 10; i++)
	//	{
	//		printf("%d ", *(p + i));
	//	}
	//	for (i = 0; i < 10; i++)
	//	{
	//		*(p + i) = i;
	//	}
	//	for (i = 0; i < 10; i++)
	//	{
	//		printf("%d ", *(p + i));
	//	}
	//	free(p);
	//	p = NULL;
	//}

	//int i;
	//int* p = (int*)malloc(10 * (sizeof(int)));
	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//int* ptr = (int*)realloc(p, 5 * sizeof(int));
	//if (ptr == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//else
	//{
	//	p = ptr;
	//	for (i = 0; i < 5; i++)
	//	{
	//		*(p + i) = i;
	//		printf("%d ", *(p + i));
	//	}
	//	free(p);
	//	p = NULL;
	//}

	//int* p = (int*)malloc(INT_MAX);
	//if (p == NULL)
	//{
	//	printf("%s\n", strerror(errno));
	//	return 0;
	//}
	//else
	//{
	//	free(p);
	//	p = NULL;
	//}
	//return 0;
//}

struct S
{
	int n;
	int arr[];//柔性数组-未知大小-数组大小可以调整
}; 

//int main()
//{
//	struct S s;
//	//printf("%d\n", sizeof(s));//结构体大小不包括柔性数组成员大小
//	struct S* p = (struct S*)malloc(4 + 5 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		p->n = 100;
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			p->arr[i] = i;
//			printf("%d ", p->arr[i]);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	struct S* p = (struct S*)malloc(4 + 10 * sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		p->n = 100;
//		for (i = 0; i < 10; i++)
//		{
//			p->arr[i] = i;
//			printf("%d ", p->arr[i]);
//		}
//	}
//	struct S* ptr = (struct S*)realloc(p, 24);
//	if (ptr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	else
//	{
//		p = ptr;
//		p->n = 50;
//		for (i = 0; i < 5; i++)
//		{
//			p->arr[i] = i;
//			printf("%d ", p->arr[i]);
//		}
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void GetMemory(char** p)
//{
//	*p = (char*)malloc(10);
//}
//
//void test(void)
//{
//	char* p = NULL;
//	GetMemory(&p);
//	strcpy(p, "abcdef");
//	printf(p);
//	free(p);
//	p = NULL;
//}
//
//int main()
//{
//	test();
//	return 0;
//}

