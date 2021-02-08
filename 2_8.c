#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//7.练习使用qsort函数排序各种类型的数据。
struct Stu
{
	char name[20];
	int age;
};

int cmp_int(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return *(int*)e1 - *(int*)e2;
}

int cmp_f(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return (int)(*(float*)e1 - *(float*)e2);
}

int cmp_stu_name(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e1)->name);
}

int cmp_stu_age(const void* e1, const void* e2)
{
	assert(e1 && e2);
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

//void test1()
//{
//	int arr[] = { 1,3,2,5,4,6,8,9,7,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//
//void test2()
//{
//	float f[] = { 1.0,3.0,2.0,6.0,5.0,4.0,8.0,7.0,9.0,10.0 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_f);
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%f ", f[i]);
//	printf("\n");
//}

//void test3()
//{
//	struct Stu s[3] = { {"zhangshan",20},{"lisi",30},{"wangwu",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_name);
//	qsort(s, sz, sizeof(s[0]), cmp_stu_age);
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%s ", s[i].name);
//	printf("\n");
//	for (i = 0; i < sz; i++)
//		printf("%d ", s[i].age);
//	printf("\n");
//}
//
//int main()
//{
//	test1();
//	test2();
//	test3();
//	return 0;
//}

//8.模仿qsort的功能实现一个通用的冒泡排序。
void Swap(char* p1, char* p2, int width)
{
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
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
		}
	}
}
int main()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz1 = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz1, sizeof(arr[0]), cmp_int);
	struct Stu s[3] = { {"zhangshan",25},{"lisi",20},{"wangwu",30} };
	int sz2 = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz2, sizeof(s[0]), cmp_stu_age);
	bubble_sort(s, sz2, sizeof(s[0]), cmp_stu_name);
	int i;
	for (i = 0; i < sz1; i++)
		printf("%d ", arr[i]);
	printf("\n");
	for (i = 0; i < sz2; i++)
		printf("%d ", s[i].age);
	printf("\n");
	for (i = 0; i < sz2; i++)
		printf("%s ", s[i].name);
	printf("\n");
	return 0;
}