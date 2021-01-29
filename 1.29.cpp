#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
////1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
////输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//int main()
//{
//	int line;
//	scanf("%d", &line);
//	int i, j;
//	for (i = 1; i <= line; i++)
//	{
//		for (j = 1; j <= i; j++)
//			printf("%2d*%-2d=%-2d ", j, i, j * i);
//		printf("\n");
//	}
//	return 0;
//}

////2.使用函数实现两个数的交换。
//void swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

////3.实现一个函数判断year是不是润年。
//int leap_year(int year)
//{
//	//是闰年返回1，不是闰年返回0
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int year;
//	scanf("%d", &year);
//	int ret=leap_year(year);
//	if (ret == 1)
//		printf("%d年是闰年", year);
//	else
//		printf("%d年不是闰年", year);
//	return 0;
//}

////4.创建一个数组，
////实现函数init（）初始化数组、
////实现empty（）清空数组、
////实现reverse（）函数完成数组元素的逆置。
////要求：自己设计函数的参数，返回值。
//void init(int arr[],int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//		scanf("%d", &arr[i]);
//}
//void reverse(int arr[],int sz)
//{
//	int left = 0, right = sz - 1;
//	while (left < right)
//	{
//		int tmp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void empty(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//		arr[i] = 0;
//}
//void print(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//}
//int main()
//{
//	int arr[10];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入%d个数字：\n",sz);
//	init(arr,sz);
//	reverse(arr,sz);
//	print(arr, sz);
//	empty(arr,sz);
//	print(arr, sz);
//	return 0;
//}

////5.实现一个函数，判断一个数是不是素数。
//#include<math.h>
//int  prime_number(int x)
//{
//	//是素数返回1，不是返回0
//	int i,flag=1;
//	for (i = 2; i <= (int)sqrt(x); i++)
//	{
//		if (x % i == 0)
//			flag = 0;
//	}
//	return flag;
//}
//int main()
//{
//	int num;
//	printf("请输入一个数字：");
//	scanf("%d", &num);
//	int ret=prime_number(num);
//	if (ret == 1)
//		printf("%d是素数", num);
//	else
//		printf("%d不是素数", num);
//	return 0;
//}

