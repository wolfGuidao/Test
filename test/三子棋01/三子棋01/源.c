#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ӡ�˵�
void Muse()
{
	printf("******************************\n");
	printf("*******��ӭ������������Ϸ*****\n");
	printf("*******����1��������Ϸ********\n");
	printf("*******����0���˳���Ϸ********\n");
	printf("******************************\n");
}

//��ʼ�����Ķ�ά����Ϊ�ո�
void ChuShiHua(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			qipan[i][j] = ' ';
		}
	}
}

//�������̵ĸ�ʽ��ӡ��ά����
void DaYin(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			printf(" %c ", qipan[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//����ƶ�������Ϊ��X��
void WanJia(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����ƶ���\n");
		printf("������1����>3�����꣺");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= 3 && y > 0 && y <= 3)
		{
			if (qipan[x - 1][y - 1] == ' ')
			{
				qipan[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("������������������ӣ�����������:");
			}
		}
		else
		{
			printf("������������������������룺");
		}
	}
}

//�ж��������Ƿ��Ѿ�ȫ�����ӣ���������ж�
int Man(char qipan[][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (qipan[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//�ж���һ�����ƶ����Ƿ񹹳����ӣ���Ӯ��
int Win(char qipan[][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < ROW;i++)
	{
		if (qipan[i][0] == qipan[i][1] && qipan[i][1] == qipan[i][2] && qipan[i][0] != ' ')
		{
			return qipan[i][0];
		}
		if (qipan[0][i] == qipan[1][i] && qipan[1][i] == qipan[2][i] && qipan[0][i] != ' ')
		{
			return qipan[0][i];
		}
		if (qipan[0][0] == qipan[1][1] && qipan[1][1] == qipan[2][2] && qipan[0][0] != ' ')
		{
			return qipan[0][0];
		}
		if (qipan[2][0] == qipan[1][1] && qipan[1][1] == qipan[0][2] && qipan[2][0] != ' ')
		{
			return qipan[i][0];
		}//Ӯ
		if (Man(qipan, 3, 3) == 1)
		{
			return 'P';//ƽ��
		}
	}
	return 'B';//û��ӮҲûƽ�֣��Է��ƶ�
}

//�����ƶ�������Ϊ��O��
void DianNao(char qipan[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ƶ���\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (qipan[x][y] == ' ')
		{
			qipan[x][y] = 'O';
			break;
		}
	}
}

//������Ϸ�ĺ��ĺ���
void Game()
{
	int a = 0;
	char qipan[ROW][COL] = { 0 };
	ChuShiHua(qipan, 3, 3);
	DaYin(qipan, 3, 3);
	while (1)
	{

		WanJia(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		a = Win(qipan, 3, 3);
		if (a != 'B')
		{
			break;
		}
		DianNao(qipan, 3, 3);
		DaYin(qipan, 3, 3);
	}
	if (a == 'X')
	{
		printf("��ϲ����Ӯ�ˣ�");
	}
	else if (a == 'O')
	{
		printf("���ź��������ˣ�");
	}
	else if (a == 'P')
	{
		printf("ƽ��Ӵ��");
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Muse();
		printf("���������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������������������룺");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}