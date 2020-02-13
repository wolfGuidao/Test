#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10
//ע������洢�±����ÿһ�У�����Ԫ�ش���ʺ���ÿһ�е�λ��
int hei[MaxSize];//�ڻʺ�
int bai[MaxSize];//�׻ʺ�
int chessboard[MaxSize][MaxSize];//1:�ܷ�  0:���ܷ�
int count = 0;//��¼���ж����ַŻʺ��λ��

int Check(int *str, int line)//�ú����жϻʺ��Ƿ��ܹ�������str[line]���λ��
{
	int i = 1;
	for (;i < line;i++)
	{
		int temp = str[i] - str[line];
		if (temp == 0 || temp == i - line || temp == line - i)
			//temp == 0����ʾ�ʺ���ͬһ�У�temp == i - line �� temp == line - i����ʺ��������Խ���
		{
			return 0;
		}
	}
	return 1;
}

void Whilte(int n, int line)
{
	if (line == n + 1)
	{
		count++;
	}
	else
	{
		for (int i = 1;i <= n;i++)//i��ֵ��line�е�ÿһ��
		{
			if (chessboard[line][i] == 1&&hei[line]!=i)//�жϸ�λ���Ƿ���ԷŻʺ�
			{
				bai[line] = i;//��¼��line�лʺ��λ��
				if (Check(bai, line))//�����жϣ����������͵ݹ���һ��
				{
					Whilte(n, line + 1);
				}
			}
		}
	}
}

void Black(int n, int line)//�ú����źڻʺ�
{
	if (line == n+1)//�����line����n+1;˵���ôεݹ��ҵ�һ�����кڻʺ�����������λ�ã���ȥ�Ű׻ʺ�
	{
		return Whilte(n, 1);
	}
	else
	{
		for (int i = 1;i <= n;i++)//i��ֵ��line�е�ÿһ��
		{
			if (chessboard[line][i] == 1)//�жϸ�λ���Ƿ���Էźڻʺ�
			{
				hei[line] = i;//��¼��line�кڻʺ��λ��
				if (Check(hei, line))//�����жϣ����������͵ݹ���һ��
					//ע��õݹ��Ƿ���ѭ���ڲ��ģ����Ե���i�в���������ʱ���ͻ��˻�i-1�м����жϣ�������
				{
					Black(n, line + 1);
				}
			}
		}
	}
}

int main()
{
	int n;
	printf("���������̴�Сn:\n");
	scanf("%d", &n);
	printf("����������Ԫ�أ�1����λ�ÿ��ԷŻʺ�0����λ�ò����ԷŻʺ�\n");
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			printf("%d", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(n, 1);
	printf("�ʺ���%d�ַŷ�\n", count);
	system("pause");
	return 0;
}






#if 0
int hei[MaxSize];//�ڻʺ�
int bai[MaxSize];//�׻ʺ�
int chessboard[MaxSize][MaxSize];//1:�ܷ�  0:���ܷ�
int count = 0;
int check(int queen[], int line)//�жϺ���
{
	for (int i = 1; i < line; i++)
	{
		int judge = queen[i] - queen[line];
		if (judge == 0 || judge == i - line || judge == line - i)
			//judge == 0 ��ʾ��ͬһ�У�judge == i - line || judge == line - i��ʾ��ͬһ�Խ���
		{
			return 0;
		}
	}
	return 1;
}

void White(int line, int n)//�ںڻʺ�ǰ���µݹ���ð׻ʺ�
{
	if (line == n + 1)//�ڷ���ڻʺ�ǰ���£����ð׻ʺ�ÿ�������лʺ�һ�Σ�count++;
	{
		count++;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (chessboard[line][i] == 1 && i != hei[line])
			{
				bai[line] = i;
				if (check(bai, line))
				{
					White(line + 1, n);//�ݹ���һ��
				}
			}
		}
	}
}

void Black(int line, int n)//�ݹ���úڻʺ�,ע��õݹ�����ѭ���ڲ���
{
	if (line == n + 1)//��ʾ�ڻʺ��ѷ������
	{
		White(1, n);
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			if (chessboard[line][i] == 1)
			{
				hei[line] = i;//��ʾ�ڻʺ�ÿһ�з��õ�λ��
				if (check(hei, line))//�жϷ��ûʺ�λ���Ƿ���������������͵ݹ飬������ͻ�һ��λ�÷��ûʺ󣬽���ѭ��
				{
					Black(line + 1, n);//�ݹ���һ��				
				}
			}
		}
	}
}
int main()
{
	int n;
	printf("���������̴�С��\n");
	scanf("%d", &n);
	printf("������%d�У�ÿ��%d��0��1��������\n", n, n);
	printf("���һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�\n");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &chessboard[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf(" %d ", chessboard[i][j]);
		}
		printf("\n");
	}
	Black(1, n);
	printf("�ܹ���%d�ַ��ûʺ�ķ���", count);
	system("pause");
	return 0;
}

#endif