#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 100
//�߾��ȼӷ��������������Ǹ�
int main()
{
	char a[MaxSize];
	char b[MaxSize];
	char c[MaxSize];
	int i = 0;
	for (;i < MaxSize;i++)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	printf("�������һ����������\n");
	scanf("%s", &a);
	printf("�������һ����������\n");
	scanf("%s", &b);
	int lena = strlen(a);
	int lenb = strlen(b);
    for (i=0;i < lena || i < lenb;i++)
	{
		/*��Ϊ�ַ���������������ʱ���Ǵ�������Ԫ�ؿ�ʼ��ģ��������0λ���������������������λ�������1λ������
		�������θ�λ���Դ����ƣ�*/
		if (i < lena)
		{
			c[i] += a[lena - 1 - i]-'0';//��Ϊ��ӵ�ʱ���Ǵ����Ϊ��ʼ��ӣ���������������һλ���ȿ�ʼ���
		}
		if (i < lenb)
		{
			c[i] += b[lenb - i - 1]-'0';
		}
		if (c[i] >= 10)
		{
			c[i + 1] = c[i] / 10;//��C�����1λ��ʼ�洢��
			c[i] = c[i] % 10;
		}
	}
	if (lena < lenb)//ȡ��������ϴ�ĳ���
	{
		lena = lenb;
	}
	if (c[lena] > 0)
	{
		printf("%d", a[lena]);
	}
	for (i = lena - 1;i >= 0;i--)//���
	{
		printf("%d", c[i]);
	}
	system("pause");
	return 0;
}