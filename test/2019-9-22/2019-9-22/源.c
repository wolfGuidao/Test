#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#if 0
//1.
//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
#include<stdio.h>
int main()
{
	int a, b, c, d, e;
	for (a = 1;a <= 5;a++)
	{
		for (b= 1;b<= 5;b++)
		{
			for (c = 1;c <= 5;c++)
			{
				for (d = 1;d <= 5;d++)
				{
					for (e = 1;e <= 5;e++)
					{
						if (((b == 2 && a != 3) || (b != 2 && a == 3)) == 1)
						{
							if (((b == 2 && e != 4) || (b != 2 && e == 4))==1)
							{
								if (((c == 1 && d != 2) || (c != 1 && d == 2))==1)
								{
									if (((c == 5 && d != 3) || (c != 5 && d == 3)) == 1)
									{
										if (((e == 4 && a != 1) || (e != 4 && a == 1)) == 1)
										{
											if ((a*b*c*d*e == 120)&&((a+b+c+d+e)==15))
											{
												printf("A=%d,B=%d,C=%d,D=%d,E=%d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

//2.
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4����
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

#include<stdio.h>
int main()
{
	int xongshou = 0;
	for (xongshou = 'A';xongshou <= 'D';xongshou++)
	{
		if (((xongshou != 'A') + (xongshou == 'C') + (xongshou == 'D') + (xongshou != 'D')) == 3)
		{
			printf("������%c", xongshou);
		}
	}
	system("pause");
	return 0;
}


//3.����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1

#include<stdio.h>
int main()
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;//��һ�е�1
			}
			if (i == j)
			{
				arr[i][j] = 1;//�Խ��ߵ�1
			}
			if (i > 1)
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}
	for (i = 0; i < 10; i++)//��ӡ�ո�
	{
		for (j = 0; j < 10 - i; j++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)//��ӡ��
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}



//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
    int sum = 0;
	for (i = 0;i < 32;i++)
	{
		if ((value >> i) & 1)
		{
			sum += (1<<(31-i));
		}
	}
	return sum;
}
int main()
{
	int n = 25;
	int a = 0;
	a = reverse_bit(n);
	printf("%u", a);
	system("pause");
	return 0;
}




//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	printf("%d", (a + b) >> 1);
	system("pause");
	return 0;
}


//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩


#include<stdio.h>
int main()
{
	int a[9] ={ 1, 5, 5, 1, 7, 6, 7, 8, 8};
	int i = 0;
	int j = a[0];
	for (i = 1;i < 9;i++)
	{
		j ^= a[i];
	}
	printf("%d", j);
	system("pause");
	return 0;
}
#endif

//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
#include<stdio.h>
void JiaoHuan(char a[], int len)
{
	int left = 0;
	int right = len - 1;
	char b;
	while (left <= right)
	{
		b = a[left];
		a[left] = a[right];
		a[right] = b;
		left++;
		right--;
	}
}

int main()
{
	int temp=0;
	int i = 0;
	int left = 0;
	int right = 0;
	char a[] = "student a am i";
	int len = strlen(a);
	JiaoHuan(a, len);
	while(a[i]!='\0')
	{
		left = i;
		while (a[i] != ' '&&a[i]!='\0')
		{
			i++;
		}
		
		right = i-1;
		while (left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
		if (a[i] != '\0')
		{
			i++;
		}
		
	}

		printf("%s", a);
	system("pause");
	return 0;
}