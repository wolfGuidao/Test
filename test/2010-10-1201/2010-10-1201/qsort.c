#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>

int int_cmp(const void *elem1, const void *elem2)//�Ƚϴ�С
{
	return (*(int *)elem1) - (*(int *)elem2);
}

void _Swap(void *p1, void *p2, int size)//һ��һ���ֽڽ���
{
	for (int i = 0;i < size;i++)
	{
		char temp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = temp;
	}
}

Myqsort(void *base, int num, size_t width, int(__cdecl *compare)(const void *elem1, const void *elem2))//����
{
	int i = 0;
	int j = 0;
	for (i = 0;i < num-1;i++)
	{
		for (j = 0;j < num - i - 1;j++)
		{
			if (int_cmp((char*)base + j * width, (char *)base + (j + 1)*width) > 0)
			{
				_Swap((char*)base + j * width, (char*)base + (j + 1)* width, width);
			}
		}
	}
}

void Show(int *str, int len)//��ӡ
{
	for (int i = 0;i < len;i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");
}


int main()
{
	int a[] = { 100,22,32,53,43,94,74,55,32,20 };
	int len = sizeof(a) / sizeof(a[0]);
	Myqsort(a,len,sizeof(int),int_cmp);//���ûص������ķ�ʽ������������
	Show(a, len);
	system("pause");
	return 0;
}