#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>

//������̨����:����ֻ����1����2��̨��
int QinWa(int n)
{
	if (n == 1 || n == 2)
	{
		return n;
	}
	return (QinWa(n - 1) + QinWa(n - 2));//������������⣬����������ϵ�n��̨�ף��д�n-1��һ��̨�׺ʹ�n-2������
	//̨�׵��������n��̨�׹���QinWa(n-1)+QinWa(n-2)�ַ�����
}


//��̬������̨���⣺������n��̨�ף����ܿ�����1��2��3....n��̨��
int BTQinWa(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1 || n == 2)
	{
		return n;
	}
	/*f(0)=1��ʾһ������n��̨��
	f(1) = 1
	f(2) = 2
	f(3) = f(3 - 1) + f(3 - 2) + f(3 - 3);��3��̨�ף���һ����1��̨�ף�ʣ��2��̨����f��2���ַ������ڶ�����2��̨�ף�
	ʣ��1��̨����f��1�����ַ����������Σ���3��̨�ף����Թ���f(2)+f(1)+f(0)=2+1+1=4
	...�Դ�����
	f(n - 1) = f((n - 1) - 1) + f((n - 1) - 2) + ... + f((n - 1) - (n - 1)) = f(n - 2) + f(n - 3) + ... + f(1)=F��1)
	f(n) = f(n - 1) + f(n - 2) + f(n - 3)... + f(0) = f(n - 1) + f(n - 1) = 2 * f(n - 1) 
	*/
	return 2 * BTQinWa(n - 1);
	    
}


//��ŵ������
int tag = 0 ;//��¼�ƶ�����
void Move(int n,char a,char c)//n��¼�ƶ����Ǽ���Բ��
{
	printf("��%d���ƶ�,��%d��Բ�̴�%c-�Ƶ�->%c\n",++tag,n ,a, c);
}
void hanoi(int n,char a,char b,char c)
{
	if (n == 1)
	{
		Move(1,a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);
		Move(n, a, c);
		hanoi(n - 1, b, a, c);
	}
}

int MNiu(int year)
{
	if (year == 0)
	{
		return 0;
	}
	if (year == 1||year==2||year==3)
	{
		return year;
	}
	return MNiu(year - 3) + MNiu(year - 1);//MNiu(year - 3)����year��3��ǰ�����ĸţ������MNiu(year - 1)����year��ǰ1��ţ������
}
int main()
{
	/*
	int n = 0;
	int count = 0;
	printf("������̨�׵ĸ���n:\n");
	scanf("%d", &n);
	//count = QinWa(n);
	count = BTQinWa(n);
	printf("%d", count);
	*/

	//hanoi(3, 'A', 'B', 'C');

	printf("%d", MNiu(4));

	system("pause");
	return 0;
}


#if 0

////int main() { int a[5][5];     int(*p)[4];     p = a;     printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); system("pause");    return 0; }
//int main() { char *c[] = { "ENTER","NEW","POINT","FIRST" };  char**cp[] = { c + 3,c + 2,c + 1,c };  char***cpp = cp;  printf("%s\n", **++cpp);  printf("%s\n", *--*++cpp + 3);  printf("%s\n", *cpp[-2] + 3);  printf("%s\n", cpp[-1][-1] + 1);   system("pause");    return 0; }



int main()
{
	char *p[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve",
		"thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty" };
	char *q[] = { "twenty","thirty","forty","fifty" };
	int h = 0;
	int m = 0;
	printf("������Ҫ����ʱ�䣺\n");
	scanf("%d%d", &h, &m);
	printf("%d : %d  -->", h, m);
	if (h < 0 || h>24 || m < 0 || m>59)
	{
		printf("������Ĳ��Ϸ�");
	}
	if (m == 0)
	{
		if (h < 21)
		{
			printf("%s o'clock", p[h]);
		}
		else
		{
			printf("%s %so'clock", q[h / 10 - 2], p[h % 10]);
		}
	}
	else
	{
		if (h < 21)
		{
			printf("%s ", p[h]);
		}
		else
		{
			printf("%s %s", q[h / 10 - 2], p[h % 10]);
		}
		if (m < 21)
		{
			printf("%s ", p[m]);
		}
		else
		{
			printf("%s %s", q[m / 10 - 2], p[m % 10]);
		}
	}
	system("pause");
	return 0;
}
#endif