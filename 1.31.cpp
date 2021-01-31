#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//1.写一个函数返回参数二进制中 1 的个数
//int count_one_bits(unsigned n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n & 1)
//			count++;
//		n >>= 1;
//	}
//	return count;
//}
//优化版
//int count_one_bits(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		count++;
//		n = n & (n - 1);
//	}
//	return count;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = count_one_bits((unsigned)n);
//	//int ret = count_one_bits(n);
//	printf("%d", ret);
//	return 0;
//}

////2.获取一个数二进制序列中所有的偶数位和奇数位，
////分别输出二进制序列。
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i;
//	printf("二进制序列的偶数位：");
//	for (i = 31; i >= 0; i-=2)
//		printf("%d ",(n >> i) & 1);
//	printf("\n");
//	printf("二进制序列的奇数位：");
//	for (i = 30; i >= 0; i-=2)
//		printf("%d ", (n >> i) & 1);
//	return 0;
//}

////3. 输出一个整数的每一位。
//void print(int n)
//{
//	//递归法
//	if (n > 10)
//		print(n / 10);
//	printf("%d ",n % 10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}

////非递归
//#include<math.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0, tmp = n;
//	while (tmp)
//	{
//		count++;
//		tmp /= 10;
//	}
//	int i;
//	for (i = count - 1; i >= 0; i--)
//	{
//		int t = n / (int)pow(10, i);
//		printf("%d ", t % 10);
//	}
//	return 0;
//}

////4.编程实现：
////两个int（32位）整数m和n的二进制表达中，
////有多少个位(bit)不同
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//	int a = m ^ n;
//	int count = 0;
//	while (a)
//	{
//		count++;
//		a &= (a - 1);
//	}	
//	printf("%d", count);
//	return 0;
//}