#define _CRT_SECURE_NO_WARNINGS
//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
#include<stdio.h>
int main()
{
	int m = 1;
	int n = 7;
	int a = 0;
	int count = 0;
	a = m ^ n;
	for (int i = 0;i < 32;i++)
	{
		if ((a >> i) & 1 == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;
}
#if 0
//���һ��������ÿһλ��
#include<stdio.h>
void DaYin(int n)
{
	if (n > 9)
	{
		DaYin(n / 10);
	}
	printf("%d " ,n % 10);
}
int main()
{
	int n = 123784;
	DaYin(n);
	system("pause");
	return 0;
}


//��ȡһ�������������������е�ż��λ������λ��
//�ֱ�������������С�
#include<stdio.h>
int main()
{
	int a = 7;
	int i = 0;
	int b[32] = { 0 };
	for (i = 0;i < 32;i++)
	{
		b[i] = ((a >> i) & 1);
	}
	printf("����λΪ��\n");
	for (i = 15;i >=0;i--)
	{
		printf("%d ",b[2*i]);
	}
	printf("\nż��λΪ��\n");
	for (i = 15;i >= 0;i--)
	{
		printf("%d ", b[2 * i +1]);
	}
	system("pause");
	return 0;
}


//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
#include<stdio.h>
/*
int count_one_bits(int a)//��һ�ַ���
{
	int i = 0;
	int count = 0;
	for (i = 0;i < 32;i++)
	{
		if (((a >> i) & 1) == 1)
		{
			count++;
		}
	}
	return count;
}
*/

/*
int count_one_bits(int a)//�ڶ��ַ���
{
	int count = 0;
	while (a != 0)
	{
		a=a&(a - 1);
		count++;
	}
	return count;
}
*/

int count_one_bits(int a)
{
	int count = 0;
	while (a != 0)
	{
		if (a % 2 == 1)
		{
			count++;
		}
		a = a / 2;
	}
	return count;
}
int main()
{





	int a = 4;
	int b = 0;
	b=count_one_bits(a);
	printf("%d", b);
	system("pause");
	return 0;
}
#endif