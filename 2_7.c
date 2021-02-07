#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
//6.实现memcpy
//void* my_memcpy(void* dest, const void* src,size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (count--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[6] = { 0 };
//	int arr2[10] = { 1,2,3,4,5,6 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	my_memcpy(arr1, arr2,sizeof(arr1));
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}

//7.实现memmove
//void* my_memmove(void* dest, const void* src, size_t count)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (count--)
//	{
//		if (dest < src)
//		{
//			*(char*)dest = *(char*)src;
//			++(char*)dest;
//			++(char*)src;
//		}
//		else
//			*((char*)dest + count) = *((char*)src + count);
//	}
//	return ret;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr + 2, arr, 20);
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}

//1.模拟实现strncpy
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (count--)
//		*dest++ = *src++;
//	return ret;
//}
//int main()
//{
//	char str1[20] = "abcd";
//	char str2[] = "efgh";
//	my_strncpy(str1, str2, 3);
//	printf("%s", str1);
//	return 0;
//}

//2.模拟实现strncat
//char* my_strncat(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//		dest++;
//	while (count--)
//		*dest++ = *src++;
//	return 0;
//}
//int main()
//{
//	char str1[20] = "abcd";
//	char str2[] = "efgh";
//	my_strncat(str1, str2, 4);
//	printf("%s", str1);
//	return 0;
//}

//3.模拟实现strncmp
int my_strncmp(const char* str1, const char* str2, size_t count)
{
	assert(str1 && str2);
	while (count--)
	{
		if (*str1++ != *str2++)
			return *str1 - *str2;
	}
	return 0;
}
int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcqwe";
	int ret = my_strncmp(str1, str2, 5);
	printf("%d", ret);
	return 0;
}