#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
//int main()
//{
//	int arr[] = { 1,2,3,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = 0, i;
//	for (i = 0; i < sz; i++)
//		ret ^= arr[i];
//	printf("%d", ret);
//	return 0;
//}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
//int main()
//{
//	int money, total;
//	scanf("%d", &money);
//	if (money > 0)
//		total = 2 * money - 1;
//	else
//		total = 0;
//	printf("%d", total);
//	return 0;
//}

//int main()
//{
//	int money;
//	scanf("%d", &money);
//	int empty = money;
//	int total = empty;
//	while (empty >1)
//	{
//		total += empty / 2;
//		if (empty % 2 != 0)
//			empty += 1;
//		empty /= 2;
//	}
//	printf("%d", total);
//	return 0;
//}

//3.模拟实现strcpy
#include<assert.h>
//char* my_strcpy(char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	char* cp = s1;
//	while (*s2 != '\0')
//	{
//		*cp++ = *s2++;
//	}
//	return s1;
//}
//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "ABCD";
//	my_strcpy(str1, str2);
//	printf("%s", str1);
//	return 0;
//}

//4.模拟实现strcat
#include<string.h>
char* my_strcat(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* cp = str1;
	int len = strlen(str2);
	while (*cp != '\0')
		cp++;
	while (len--)
		*cp++ = *str2++;
	return str1;
}
int main()
{
	char s1[20] = "abcd";
	char s2[] = "efgi";
	my_strcat(s1, s2);
	printf("%s", s1);
	return 0;
}