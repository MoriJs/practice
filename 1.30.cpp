#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
////1.递归和非递归分别实现求第n个斐波那契数。
//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int main()
//{
//	//递归法
//	int n;
//	scanf("%d", &n);
//	int ret=Fibonacci(n);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	//循环法
//	int n, f[3] = { 1,1 };
//	scanf("%d", &n);
//	int i;
//	for (i = 2; i < n; i++)
//	{
//		f[2] = f[0] + f[1];
//		f[0] = f[1];
//		f[1] = f[2];
//	}
//	printf("%d", f[2]);
//	return 0;
//}

////2.编写一个函数实现n^k，使用递归实现
//int my_pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	return n * my_pow(n,k - 1);
//}
//int main()
//{
//	int n, k;
//	scanf("%d%d", &n, &k);
//	int ret=my_pow(n, k);
//	printf("%d", ret);
//	return 0;
//}

////3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
////例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int DigitSum(int n)
//{
//	if (n < 10)
//		return n;
//	return n % 10 + DigitSum(n / 10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = DigitSum(n);
//	printf("%d", ret);
//	return 0;
//}

////4. 编写一个函数 reverse_string(char * string)（递归实现）
////实现：将参数字符串中的字符反向排列。
////要求：不能使用C函数库中的字符串操作函数。
//int my_strlen(char* string)
//{
//	if (*string == '\0')
//		return 0;
//	return 1 + my_strlen(string+1);
//}
//
//void reverse_string(char* string)
//{
//	int len=my_strlen(string);
//	char* right = (string + len - 1);
//	char tmp = *string;
//	*string = *right;
//	*right = '\0';
//	if (my_strlen(string + 1) >= 2)
//		reverse_string(string + 1);
//	*right = tmp;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);	
//	return 0;
//}

////5.递归和非递归分别实现strlen
//int my_strlen(char* arr)
//{
//	if (*arr == '\0')
//		return 0;
//	return 1 + my_strlen(arr + 1);
//}
//int main()
//{
//	//递归法
//	char arr[] = "abcdef";
//	int ret=my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}

//非递归
//int my_strlen(char* arr)
//{
//	//计数法
//	int count = 0;
//	while (*(arr++) != '\0')
//		count++;
//	return count;
//}

//int my_strlen(char* arr)
//{
//	//下标法
//	int len=0;
//	while (arr[len] != '\0')
//		len++;
//	return len;
//}

//int my_strlen(char* arr)
//{
//	//递归法
//	if (*arr == '\0')
//		return 0;
//	return 1 + my_strlen(arr + 1);
//}
//int main()
//{
//	char arr[] = "abcde";
//	int ret = my_strlen(arr);
//	printf("%d", ret);
//	return 0;
//}

////6.递归和非递归分别实现求n的阶乘
//int  factorial(int n)
//{
//	//递归法
//	if (n == 1)
//		return 1;
//	return n * factorial(n - 1);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	//循环法
//	int n, i, ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//		ret *= i;
//	printf("%d", ret);
//	return 0;
//}

//7.递归方式实现打印一个整数的每一位
//void print(int n)
//{
//	if(n>10)
//		print(n / 10);
//	printf("%d ", n%10);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	print(n);
//	return 0;
//}

//非递归 
//#include<math.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0, tmp = n;
//	while (tmp)
//	{
//		tmp /= 10;
//		count++;
//	}
//	int i = 0;
//	for (i = count-1; i >= 0; i--)
//	{
//		int t = n / (int)pow(10, i);
//		t %= 10;
//		printf("%d ", t);
//	}
//	return 0;
//}