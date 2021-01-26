#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//实例32 删除字符串中的指定字符
//int main()
//{
//	char ch,a[20];
//	int i = 0;
//	printf("请输入一个字符串->");
//	scanf("%s", a);
//	getchar();
//	printf("请输入要删除的字符->");
//	scanf("%c", &ch);
//	while (a[i] != '\0')
//	{
//		if (a[i] == ch)
//			a[i] = '0';
//		i++;
//	}
//	i = 0;
//	while (a[i] != '\0')
//	{
//		if(a[i]!='0')
//			printf("%c", a[i]);
//		i++;
//	}
//	return 0;
//}

//实例33  判断一个数是否为质数
#include<math.h>
//int main()
//{
//	int n, i,flag=1;
//	scanf("%d", &n);
//	for (i = 2; i <= (int)sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			flag = 0;
//			break;
//		}
//	}
//	if (flag)
//		printf("%d是质数", n);
//	else
//		printf("%d不是质数", n);
//	return 0;
//}

//实例34 函数调用
//void print(int n)
//{
//	if (n > 0)
//	{
//		printf("hello world!\n");
//		print(n - 1);
//	}
//}
//int main()
//{
//	int n;
//	printf("请输入打印次数:");
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}

//实例35 逆序打印字符串
#include<string.h>
//void reverse(char a[], int len)
//{
//	int left = 0, right = len - 1;
//	while (right > left)
//	{
//		char t = a[left];
//		a[left] = a[right];
//		a[right] = t;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char a[20] = "\0";
//	printf("请输入一个字符串:");
//	scanf("%s", a);
//	int len = strlen(a);
//	reverse(a, len);
//	printf("%s", a);
//	return 0;
//}

//实例36 求100以内的素数
//int main()
//{
// 	int i,j,flag;
//	for (i = 2; i <= 100; i++)
//	{
//		flag = 1;
//		for (j = 2; j <= (int)sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag)
//			printf("%d ", i);
//	}
//	return 0;
//}

//实例37 对10个数排序
//#define n 5
//void rank(int a[n])
//{
//	int i,j, k;
//	for (i = 0; i < n; i++)
//	{
//		k = i;
//		for (j = i + 1; j < n; j++)
//		{
//			if (a[k] > a[j])
//				k = j;
//		}
//		int t = a[i];
//		a[i] = a[k];
//		a[k] = t;
//	}
//}
//int main()
//{
//	int i,a[n];
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	rank(a);
//	for (i = 0; i < n; i++)
//		printf("%d ", a[i]);
//	return 0;
//}

//实例38  求矩阵对角线元素之和
//#define n 3
//int main()
//{
//	int i, j, a[n][n] = { 0 }, sum = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//			scanf("%d", &a[i][j]);
//	}
//	for (i = 0; i < n; i++)
//	{
//		j = n - 1 - i;
//		if (i + j == n - 1)
//			sum += a[i][j];
//		sum += a[i][i];
//	}
//	if (n % 2)
//		sum -= a[(n - 1) / 2][(n - 1) / 2];
//	printf("%d", sum);
//	return 0;
//}