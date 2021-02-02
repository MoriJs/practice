#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//void move(int arr[], int sz)
//{
//	int left = 0, right = sz - 1;
//	while (left < right)
//	{
//		while ((left < right) && arr[left] % 2 == 1)
//			left++;
//		while ((left < right) && arr[right] % 2 == 0)
//			right--;
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr,sz);
//	int i;
//	for (i = 0; i < sz; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}

//2.
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
int search(int arr[3][3], int k, int* px, int* py)
{
	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k;
	scanf("%d", &k);
	int x = 3, y = 3;
	int ret=search(arr, k, &x, &y);
	if (ret == 1)
		printf("找到了,下标是：%d %d\n", x, y);
	else
		printf("找不到\n");
	return 0;
}