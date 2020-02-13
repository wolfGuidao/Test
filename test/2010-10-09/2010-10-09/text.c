#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10

int quickSortchild(int* str, int start, int end)
{
	int temp = str[start];
	while (start < end)
	{
		while (start < end&&str[end] >= temp)
		{
			end--;
		}
		str[start] = str[end];
		while (start < end&&str[start] < temp)
		{
			start++;
		}
		str[end] = str[start];
	}
	str[start] = temp;
	return start;
}
void quickSort(int *str, int start, int end)//���ŷǵݹ�,ջ���������ջ
{
	int stack[MaxSize*2];//*2��Ϊ�˱�֤�����£���ֹ���
	int top = 0;
	int mid = quickSortchild(str,start,end);//�Ƚ���һ�˿������򣬵õ�һ��mid,
	if (start + 1 < mid)//���mid��߻�������Ԫ�����ϣ��ֱ��start,mid-1��ջ
	{
		stack[top++] = start;
		stack[top++] = mid - 1;
	}
	if (end - 1 > mid)//���mid�ұ߻�������Ԫ�����ϣ��ֱ��mid+1,end��ջ
	{
		stack[top++] = mid + 1;
		stack[top++] = end;
	}
	while (top > 0)//���ջ��Ϊ�գ�ÿ�γ�ջ����Ԫ����Ϊstart,end����һ��Ҫע��˳�򣬱���
	{
		end = stack[--top];
		start = stack[--top];

		mid = quickSortchild(str, start, end);
		if (start + 1 < mid)
		{
			stack[top++] = start;
			stack[top++] = mid - 1;
		}
		if (end - 1 > mid)
		{
			stack[top++] = mid + 1;
			stack[top++] = end;
		}
	}
	//ջ�գ�����ÿ����һ�˿��ŵõ���mid���Ҹ�ֻ��һ��Ԫ�أ����������
}

void adjust(int *str ,int start,int end)//�ú����ǰ�����������Ϊ�����
{
	int temp = str[start];
	int i = 0;
	for (i = 2 * start + 1;i <= end;i = i * 2 + 1)//�˴�i�ǿ���Ҷ�ӽڵ㣬i = i * 2 + 1��Ϊ�˷�ֹ����������
	{
		if (str[i] < str[i + 1]&&(i<end))//�Ƚ�����Ҷ�ӽڵ㣬�õ�Ҷ������ֵ����±�
		{
			i++;
		}
		if (str[i] > temp)//���Ҷ�ӽڵ�ȵ�ǰ���ڵ�󣬾ͽ���
		{
			str[start] = str[i];
			start = i;//start��������Ϊ�˷�ֹ��������
		}
		else
		{
			break;
		}
	}
		str[start] = temp;
}
void DuiPaiSort(int *str,int len)//����
{
	int i = (len - 1 -1 ) >> 1;//�õ����鹹��һ���������һ���Ӹ��ڵ㣬���Ƶ���Ϊ����ѵĴ���
	int j = 0;
	for (;i >= 0;i--)
	{
		adjust(str,i,len);
	}//ѭ���������Ͱ�����������Ϊ�����
	for (j = 0;j < len-1;j++)
	{
		int temp = str[len-1-j];//�������һ���ڵ�͵�һ�����ڵ㻥��
		str[len - 1 - j] = str[0];
		str[0] = temp;
		adjust(str, 0, len - 1 - j - 1);//�ٴν��е������õ�һ������ѣ���������
	}

}

void mergeChild(int *str,int start,int mid,int end)
{
	int strtemp[MaxSize];
	int strtempIndex = start;
	int start2 = mid + 1;
	int i = start;
	while (start <= mid && start2 <= end)
	{
		if (str[start] <= str[start2])
		{
			strtemp[strtempIndex++] = str[start++];
		}
		else
		{
			strtemp[strtempIndex++] = str[start2++];
		}
	}
	while (start <= mid)
	{
		strtemp[strtempIndex++] = str[start++];
	}
	while (start2 <= end)
	{
		strtemp[strtempIndex++] = str[start2++];
	}
	while(i<=end)
	{
		str[i] = strtemp[i];
		i++;
	}
}
void mergeSort(int *str,int start,int end)
{
	if (start >= end)
	{
		return ;
	}
	int mid = (start + end) >> 1;
	mergeSort(str, start,mid);//�ֽ�
	mergeSort(str, mid + 1, start);

	mergeChild(str,start , mid ,end);//�ϲ�������
}
void Printf(int *str, int len)
{
	int i = 0;
	for (;i < len;i++)
	{
		printf("%d < ", str[i]);
	}
	printf("\n");
}

void sortTest()
{
	int str[] = { 2,34,45,6275,13,34,784,36,0,111 };
	int len = sizeof(str) / sizeof(str[0]);
	printf("���ŷǵݹ飺\n");
	quickSort(str, 0, len - 1);
	Printf(str, len);

	int str1[] = { 999999,34,5,65,19,94,4,93,99,911 };
	int len1 = sizeof(str1) / sizeof(str1[0]);
	printf("���ţ�\n");
	DuiPaiSort(str1, len1);
	Printf(str1, len1);

	int str2[] = { 2999999,34,995,65,19399,9934,9784,936,909,199911 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	printf("�鲢����\n");
	mergeSort(str2, 0,len2-1);
	Printf(str2, len2);
}
int main()
{
	sortTest();
	system("pause");
	return 0;
}

#if 0
int main()
{
	int n = 0;
	int a[2000];//�洢���
	int temp;//��ʱ�洢������
	int i = 0;
	int j = 0;
	int num;
	int weishu ;//��numһ�����������λ��λ�������鳤�ȼ�1
	while (n != EOF)
	{
		printf("������Ҫ����׳�n��ֵ��");
		scanf("%d", &n);
		a[0] = 1;
		weishu = 1;//�ó����ν��н׳����㣬����ÿ�ζ�Ҫ��Ϊ1��
		for (i = 2;i <= n;i++)
		{
			num = 0;//���ѭ����û��������¼��λֵ������һλ�ϼ�,ÿ��ѭ��ǰ��Ҫ��Ϊ0
			for (j = 0;j < weishu;j++)//��ѭ����֤����ÿһλ������n
			{
				temp = a[j] * i + num;
				a[j] = temp % 10;
				num = temp / 10;
			}
			while (num)//��ѭ���Ǳ�֤ÿ��jѭ�������һ��*n���������������λ����ֱ������������洢����λ��++
			{
				a[weishu++] = num % 10;
				num /= 10;
			}
		}
		for (i = weishu - 1;i >= 0;i--)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


int main()
{
	int a[2000];
	int n = 0;
	int i = 0;
	int j = 0;
	int num = 0;//�ж��Ƿ��λ
	int temp = 0;//��ʱ�洢���
	while (n != EOF)
	{
		int weishu = 1;//�����λ�ͼ�һ
		a[0] = 1;
		printf("������Ҫ��׳˵���:");
		scanf("%d", &n);
		for (i = 2;i <= n;i++)
		{
			num = 0;
			for (j = 0;j < weishu;j++)
			{
				temp = a[j] * i + num;
				a[j] = temp % 10;
				num = temp / 10;
			}
			while (num)
			{
				a[weishu++] = num % 10;
				num /= 10;
			}

		}
		for (i = weishu - 1;i >= 0;i--)
		{
			printf("%d", a[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}


#include<iostream>
using namespace std;
int main()
{
	int a;
	int b;
	cout << "������a,b��ֵ" << endl;
	cin >> a >> b;
	cout << a + b << endl;
	cout << a * b << endl;
	cout << "hello world!"<< endl;
	system("pause");
	return 0;
}
#endif