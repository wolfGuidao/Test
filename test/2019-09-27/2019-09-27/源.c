#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>

#if 0

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
#include<stdio.h>
void JiaoHuan(int *p, int len)
{
	int left = 0;
	int right = len - 1;
	int value = p[left];
	while (left < right)
	{
		while (left < right&&p[right] % 2 == 0)
		{
			right--;
		}
		p[left] = p[right];
		while (left < right&&p[left] % 2 != 0)
		{
			left++;
		}
		p[right] = p[left];
	}
	p[left] = value;
}
int main()
{
	int i = 0;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	JiaoHuan(a, 10);
	for (i = 0;i < 10;i++)
	{
		printf("%d  ", a[i]);
	}
	system("pause");
	return 0;
}
#endif

//2.
////���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
// px��py ��������������
#include<stdio.h>
void find(int arr[3][3], int px, int py, int key)
{
	int i = 0;
	int j = py - 1;
	while (i < px - 1 && j >= 0)
	{
		if (arr[i][j] == key)
		{
			printf("������������");
			break;
		}
		else if (arr[i][j] > key)
		{
			--j;
		}
		else
		{
			++i;
		}
	}
	printf("��������������");
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = sizeof(arr)/sizeof(arr[0]);
	int y = sizeof(arr[0])/sizeof(arr[0][0]);
	find(arr, x, y, 4);
	//printf("%d%d", x, y);
	system("pause");
	return 0;
}
