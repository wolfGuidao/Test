//�ǵݹ�ʵ��strlen
#include<stdio.h>
int Strlen(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}
int main()
{
	char a[] = "abcdefghijk";
	int ret = Strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}



#if 0
//�ݹ�ֱ�ʵ��strlen 
#include<stdio.h>
int Strlen(char* a)
{
	if (*a != '\0')
	{
		return 1 + mystrlen(a + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char a[] = "abcdefghijk";
	int ret = Strlen(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}




// ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//������������ʱ������if�����\0ǰ�����ĸ������������ݹ飬��������ڶ�����ֱ���ݹ������
#include<stdio.h>
void reverse_string(char *string)
{
	if ('\0' != *(++string))
		reverse_string(string);
	printf("%c", *(string - 1));
}

int main()
{
	char *a = "abcde";
	reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}


//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
#include<stdio.h>
int DigitSum(int n)
{
	if (n >0)
	{
		return n%10 + DigitSum(n / 10);
	}
	return 0;
}
int main()
{
	int n = 12;
	int a = DigitSum(n);
	printf("%d", a);
	system("pause");
	return 0;
}



//�ǵݹ�ֱ�ʵ����n�Ľ׳�
#include <stdio.h>
int main()
{
	int n = 4;
	int i = 0;
	int fac = 1;
	for (i = 1;i <= n;i++)
	{
		fac = fac * i;
	}
	printf("%d", fac);
	system("pause");
	return 0;
}


//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
#include<stdio.h>
void DaYin(int n)
{
	if (n > 9)
	{
		DaYin(n / 10);
	}
	printf("%d  ", n % 10);
}
int main()
{
	int n = 1234;
	DaYin(n);
	system("pause");
	return 0;
}


//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
#include<stdio.h>
int NK(int n, int k) 
{
	if (k == 1)
	{
		return n;
	}
	return n * NK(n, k - 1);
}
int main()
{
	int n = 2;
	int k = 10;
	int a = 0;
	a = NK(n, k);
	printf("%d", a);
	system("pause");
	return 0;
}



//�ǵݹ�ʵ�����n��쳲�������
#include<stdio.h>
int main()
{
	int n = 5;
	int f1 = 1;
	int f2 = 1;
	int f3 = 0;
	int i = 0;
	for (i = 0;i < n - 2;i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	printf("%d", f3);
	system("pause");
	return 0;
}




//�ݹ�ʵ�����n��쳲�������
#include<stdio.h>
int FeiBoNaQie(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FeiBoNaQie(n - 1) + FeiBoNaQie(n - 2);
}
int main()
{
	int a = 0;
	a = FeiBoNaQie(5);
	printf("%d", a);
	system("pause");
	return 0;
}


//�ݹ���������
#include<stdio.h>

void niarr(int arr[],int len,int left,int right)
{
	int i = 0;
	int temp = 0;
	if (left >= right)
	{
		for (i = 0;i < len;i++)
		{
			printf("%d   ", arr[i]);
		}
		return;
	}
	else 
	{
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		niarr(arr, len, ++left, --right);
	}	
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	niarr(arr, 10, 0, 9);
	system("pause");
	return 0;
}



//�ݹ����������ÿһλ
#include<stdio.h>
void Printf(int n)
{
	if (n > 9)
	{
		Printf(n / 10);
	}
	printf("%d  ", n % 10);
}
int main()
{
	int n = 2365;
	Printf(n);
	system("pause");
	return 0;
}


//n�Ľ׳˵ݹ�
#include<stdio.h>
int Fan(int n)
{
	if (n == 0||n==1)
	{
		return 1;
	}
	if (n > 1)
	{
		return n * Fan(n - 1);
	}
}
int main()
{
	int a = 0;
	int n;
	printf("������n��ֵ����׳�\n");
	scanf_s("%d", &n);
	a = Fan(n);
	printf("%d", a);
	system("pause");
	return 0;
}
#endif 