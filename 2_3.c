#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值是value的二进制位模式从左到右翻转后的值。
//unsigned int reverse_bit(int value)
//{
//	int a = 0, b = 0, i = 0;
//	while (value)
//	{
//		a = value & 1;
//		b = a | b;
//		b <<= 1;
//		i++;
//		value >>= 1;
//	}
//	return b <<= (31 - i);
//}
//int main()
//{
//	int value;
//	scanf("%d", &value);
//	unsigned int ret = reverse_bit(value);
//	printf("%u", ret);
//	return 0;
//}

//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	int c = a + b;
//	printf("%d", c >> 1);
//	return 0;
//}

//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//int main()
//{
//	int arr[] = { 1,2,3,4,1,2,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i,ret=0;
//	for (i = 0; i < sz; i++)
//		ret ^= arr[i];
//	//  ^ 二进制位相同为0，相异为1
//	// 1001
//	// 1010
//	// 0011
//	//当0与两相同的数异或为0
//	printf("%d", ret);
//	return 0;
//}

//有一个字符数组的内容为:"student a am i",
//请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。

//student a am i
//i ma a tneduts
//i am a student
//void reverse(char* left,char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void reverse_str(char arr[], int sz)
//{
//	char* left = arr;
//	char* right = arr + sz - 1;
//	char* start = arr;
//	char* end = arr;
//	reverse(left, right);
//	while (*end != '\0')
//	{
//		while ((*end != ' ') && (*end != '\0'))
//			end++;
//		reverse(start, end - 1);
//		if (*end != '\0')
//		{
//			start = end + 1;
//			end += 1;
//		}
//	}
//}
//int main()
//{
//	char arr[] = "student a am i";
//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
//	reverse_str(arr,sz);
//	printf("%s", arr);
//	return 0;
//}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。
int main()
{
	int money, total;
	scanf("%d", &money);
	if (money > 0)
		total = 2 * money - 1;
	else
		total = 0;
	printf("%d", total);
	return 0;
}