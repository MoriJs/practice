#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

//int main()
//{
//	int i;
//	int a[5];
//	int iTemp;
//	int iPos;
//	printf("Ϊ����Ԫ�ظ�ֵ:\n");  /*ͨ������Ϊ����Ԫ�ظ�ֵ*/
//	for (i = 0; i < 5; i++)
//	{
//		printf("a[%d]=", i);
//		scanf("%d", &a[i]);
//	}
//	/*��С��������*/
//	for (i = 1; i < 5; i++)	/*ѭ�������е�Ԫ��*/
//	{
//		iTemp = a[i];	        /*���ò���ֵ*/
//		iPos = i - 1;
//		while ((iPos >= 0) && (iTemp < a[iPos]))  /*Ѱ�Ҳ���ֵ��λ��*/
//		{
//			a[iPos + 1] = a[iPos];  /*������ֵ*/
//			iPos--;
//		}
//		a[iPos + 1] = iTemp;
//	}
//	/*�������*/
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d\t", a[i]);	/*����Ʊ�λ*/
//	}
//		return 0;	            /*�������*/
//}

void CelerityRun(int left, int right, int arr[])
{
	int i,j;
	int middle, iTemp;
	i = left;
	j = right;
	middle = arr[(left + right)/2];          /*���м�ֵ*/
	do
	{
		while ((arr[i]< middle) && (i < right))        /*������С����ֵ����*/
			i++;
		while ((arr[j] > middle) && (j > left))        /*�����Ҵ�����ֵ����*/
			j--;
		if (i <= j)                                      /*�ҵ���һ��ֵ*/
		{
			iTemp = arr[i];
			arr[i] = arr[j];
			arr[j] = iTemp;
			i++;
			j--;
		}
	} while (i <= j);                                 /*������ߵ��±꽻����ֹͣ*/
	/*�ݹ�����*/
	if (left < j)
		CelerityRun(left, j, arr);
	/*�ݹ��Ұ��*/
	if (right > i)
		CelerityRun(right, i, arr);
}

int main()
{
	int i;
	int arr[10];
	printf("Ϊ����Ԫ�ظ�ֵ:\n");
	/*ͨ������Ϊ����Ԫ�ظ�ֵ*/
	for (i = 0; i < 10; i++)
	{
		printf("a[%d]=", i);
		scanf("%d", &arr[i]);
	}
	/*��С��������*/
	CelerityRun(0, 9, arr);
	/*�������*/
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", arr[i]);	/*����Ʊ�λ*/
		if (i == 4)
			printf("\n");
	}
	return 0;	                /*�������*/
}