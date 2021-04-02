#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	int i;
//	int a[5];
//	int iTemp;
//	int iPos;
//	printf("为数组元素赋值:\n");  /*通过键盘为数组元素赋值*/
//	for (i = 0; i < 5; i++)
//	{
//		printf("a[%d]=", i);
//		scanf("%d", &a[i]);
//	}
//	/*从小到大排序*/
//	for (i = 1; i < 5; i++)	/*循环数组中的元素*/
//	{
//		iTemp = a[i];	        /*设置插入值*/
//		iPos = i - 1;
//		while ((iPos >= 0) && (iTemp < a[iPos]))  /*寻找插入值的位置*/
//		{
//			a[iPos + 1] = a[iPos];  /*插入数值*/
//			iPos--;
//		}
//		a[iPos + 1] = iTemp;
//	}
//	/*输出数组*/
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d\t", a[i]);	/*输出制表位*/
//	}
//		return 0;	            /*程序结束*/
//}

void CelerityRun(int left, int right, int arr[])
{
	int i,j;
	int middle, iTemp;
	i = left;
	j = right;
	middle = arr[(left + right)/2];          /*求中间值*/
	do
	{
		while ((arr[i]< middle) && (i < right))        /*从左找小于中值的数*/
			i++;
		while ((arr[j] > middle) && (j > left))        /*从右找大于中值的数*/
			j--;
		if (i <= j)                                      /*找到了一对值*/
		{
			iTemp = arr[i];
			arr[i] = arr[j];
			arr[j] = iTemp;
			i++;
			j--;
		}
	} while (i <= j);                                 /*如果两边的下标交错，就停止*/
	/*递归左半边*/
	if (left < j)
		CelerityRun(left, j, arr);
	/*递归右半边*/
	if (right > i)
		CelerityRun(right, i, arr);
}

int main()
{
	int i;
	int arr[10];
	printf("为数组元素赋值:\n");
	/*通过键盘为数组元素赋值*/
	for (i = 0; i < 10; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &arr[i]);
	}
	/*从小到大排序*/
	CelerityRun(0, 9, arr);
	/*输出数组*/
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);	/*输出制表位*/
		if (i == 4)
			printf("\n");
	}
	return 0;	                /*程序结束*/
}