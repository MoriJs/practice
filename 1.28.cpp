#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）
//int half_search(int* arr, int sz)
//{
//	int key, left=0, right=sz-1;
//	scanf("%d", &key);
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] == key)
//			return mid;
//		else if (arr[mid] < key)
//			left = mid + 1;
//		else if (arr[mid] > key)
//			right = mid - 1;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret=half_search(arr, sz);
//	if (ret >= 0)
//		printf("找到了下标是%d", ret+1);
//	else
//		printf("找不到");
//	return 0;
//}

//模拟三次密码输入的场景
//#include<string.h>
//int main()
//{
//	const char password[20]= "123456";
//	char ch[20] = "\0";
//	int i;
//	printf("请输入密码：");
//	for (i = 0; i < 3; i++)
//	{
//		gets_s(ch);
//		if (strcmp(ch, password) == 0)
//		{
//			printf("登陆成功");
//			break;
//		}
//		else
//			printf("密码错误，请重新输入：");
//	}
//	return 0;
//}

//int main()
//{
//	char ch[20];
//	scanf("%s", ch);
//	char* p = ch;
//	while (*p != '\0')
//	{
//		if (*p >= 'a' && *p <= 'z')
//		{
//			*p -= 32;
//			printf("%c", *p);
//		}
//		else if (*p >= 'A' && *p <= 'Z')
//		{
//			*p += 32;
//			printf("%c", *p);
//		}
//		p++;
//	}
//	return 0;
//}