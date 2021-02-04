#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//void reverse(char* start, char* end)
//{
//	while (start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void reverse_str(char* arr)
//{
//	assert(arr);
//	int len = strlen(arr);
//	char* left = arr;
//	char* right = arr + len - 1;
//	int k;
//	scanf("%d", &k);
//	char* start = arr;
//	char* end = arr + k - 1;
//	reverse(start, end);
//	reverse(end + 1, right);
//	reverse(left, right);
//}
//int main()
//{
//	char arr[] = "ABCD";
//	reverse_str(arr);
//	printf("%s", arr);
//	return 0;
//}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
int is_right_move(char* s1, char* s2)
{
	assert(s1 && s2);//判断指针是否为空
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)
		return 0;
	strncat(s1, s1, len1);//在s1字符串后追加s1字符串
	char* ret=strstr(s1, s2);//判断s2是否为s1的子串
	if (ret == NULL)
		return 0;
	else
		return 1;
}
int main()
{
	char s1[20] = "AABCD";
	char s2[] = "BCDAA";
	int ret = is_right_move(s1, s2);
	if (ret == 1)
		printf("s2是s1字符串旋转之后的字符串\n");
	else
		printf("s2不是s1字符串旋转之后的字符串\n");
	return 0;
}