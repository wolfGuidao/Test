#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define N 10

//��ӡ�˵�
void Muse()
{
	printf("******************************\n");
	printf("*******��ӭ����ɨ������Ϸ*****\n");
	printf("*******����1��������Ϸ********\n");
	printf("*******����0���˳���Ϸ********\n");
	printf("******************************\n");
}

//��ʱ
void JiShi()
{
	printf("��һ�������ˣ�%u��\n", clock() / CLOCKS_PER_SEC);
}

//��ʼ����ά���飬��ʼ����ҿ�����ɨ�׽��棬���׵���Ϣ
void ChuShiHua(char WanJia[ROWS][COLS],int row, int col, char a)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < COLS;j++)
		{
			WanJia[i][j] = a;
		}
	}
}

//��ӡ��������
void DaYin(char WanJia[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	printf("=====================================\n");
	for (i = 0;i < row - 1;i++)
	{
		printf("%d   ", i);
	}
	printf("\n");
	for(i=1;i<row-1;i++)
	{
		printf("%d   ", i);
		for (j = 1;j < col-1;j++)
		{
			
			printf("%c   ", WanJia[i][j]);
		}
		printf("\n");
	}
	printf("=====================================\n");
}

//Ϊ��������׵�λ��
void SetLei(char LeiXinXi[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = N;
	while (count != 0)
	{
		x = rand() % row+1;
		y = rand() % col+1;
		if (LeiXinXi[x][y] == '0')
		{
			LeiXinXi[x][y] = '1';
			count--;
		}
	}
}

//�����������󣬷��ظ�������Χ�׵�����
int Lei(char LeiXinXi[ROWS][COLS], int x, int y)
{
	return LeiXinXi[x - 1][y - 1] +
		LeiXinXi[x - 1][y] +
		LeiXinXi[x - 1][y + 1] +
		LeiXinXi[x][y + 1] +
		LeiXinXi[x + 1][y + 1] +
		LeiXinXi[x + 1][y] +
		LeiXinXi[x + 1][y - 1] +
		LeiXinXi[x][y - 1] - 8 * '0';
}

//չ��:�����������Χ8��λ��û��һ���ף��Ͱ���8��λ�õ���Χ�׵���Ϣ�洢����
void ZhanKai(char LeiXinXi[ROWS][COLS], char WanJia[ROWS][COLS], int x, int y)
{
	int a = 0;
	a= Lei(LeiXinXi, x, y);
	if (a == 0)
	{
		WanJia[x - 1][y - 1] = Lei(LeiXinXi, x-1, y-1)+'0';
		WanJia[x - 1][y] = Lei(LeiXinXi, x - 1, y ) + '0';
		WanJia[x - 1][y + 1] = Lei(LeiXinXi, x - 1, y + 1) + '0';
		WanJia[x][y + 1] = Lei(LeiXinXi, x , y +1) + '0';
		WanJia[x + 1][y + 1] = Lei(LeiXinXi, x + 1, y + 1) + '0';
		WanJia[x + 1][y] = Lei(LeiXinXi, x +1, y ) + '0';
		WanJia[x + 1][y - 1] = Lei(LeiXinXi, x +1, y - 1) + '0';
		WanJia[x][y - 1] = Lei(LeiXinXi, x , y - 1) + '0';
		WanJia[x][y] = '0';
	}
	else
	{
		WanJia[x][y] = a + '0';
	}
}

//��ֹ��һ�α�ը���������һ�ξ����ף��ͰѸ�λ����Ϊû���׼���0����
void FirstDie(char WanJia[ROWS][COLS], char LeiXinXi[ROWS][COLS], int row, int col, int x, int y)
{
	int m=0;
	int n = 0;
	int a=0 ;
	if (LeiXinXi[x][y] == '1')
	{
		LeiXinXi[x][y] = '0';
		a=Lei(LeiXinXi, x, y);
		WanJia[x][y] = a + '0';
		
		ZhanKai(LeiXinXi, WanJia, x, y);
		while (1)
		{
			m = rand() % row+1;
			n = rand() % col + 1;
			if (LeiXinXi[m][n] == '0')
			{
				LeiXinXi[m][n] = '1';
				DaYin(WanJia, ROWS, COLS);
				break;
			}
		}


	}
}


//��ǣ�
void BiaoJi(char WanJia[ROWS][COLS], int x, int y)
{
	if (WanJia[x][y] == '*')
	{
		WanJia[x][y] = '!';
	}
	else
	{
		printf("�˴����ܱ��\n");
	}
}

//ȡ�����
void QXBiaoJi(char WanJia[ROWS][COLS], int x, int y)
{
	if (WanJia[x][y] == '!')
	{
		WanJia[x][y] = '*';
	}
	else
	{
		printf("�˴�����ȡ�����\n");
	}
}

//�ж�����Ƿ���Ҫ��ǻ�ȡ�����
void PDBiaoJi(char WanJia[ROWS][COLS])
{
	int count = 1;
	int input = 0;
	int x = 0;
	int y = 0;
	printf("����1����ǣ�����2��ȡ����ǣ�����0��������ǲ���\n");
	scanf("%d", &input);
	while (count)
	{
		switch (input)
		{
		case 1:
			printf("������Ҫ��ǵ����꣺\n");
			scanf("%d%d", &x, &y);
			BiaoJi(WanJia, x, y);
			count--;
			break;
		case 2:
			printf("������Ҫȡ����ǵ����꣺\n");
			scanf("%d%d", &x, &y);
			QXBiaoJi(WanJia, x, y);
			count--;
			break;
		case 0:
			printf("�����ò���\n");
			count--;
			break;
		default:
			printf("������������������������룡\n");
			count--;
			break;
		}
	}
}

//��ҿ�ʼ����
void ZhaoLei(char WanJia[ROWS][COLS], char LeiXinXi[ROWS][COLS], int row, int col)
{
	int x = 0;
	int a = 0;
	int y = 0;
	int count = 0;
	while (count < (row*col - N))
	{
		PDBiaoJi(WanJia);
		DaYin(WanJia, ROWS, COLS);
		printf("������������꣺");
		scanf("%d%d", &x, &y);
		if(x>=1&&y<=ROW&& y >= 1 && y <= COL)
		{
			if (LeiXinXi[x][y] == '0')
			{
				ZhanKai(LeiXinXi, WanJia, x, y);
				count++;
				DaYin(WanJia, ROWS, COLS);
			}
			else if(LeiXinXi[x][y] == '1')
			{
				if (count == 0)
				{
					FirstDie(WanJia, LeiXinXi, row, col, x, y);
					count++;
				}
				else
				{
					printf("���ź����㱻ը����!\n");
					break;
				}
			}
	     }
		else
		{
			printf("����������겻�Ϸ�������������");
		}
	}
	if (count == (row*col - N))
	{
		printf("��ϲ�㣬ɨ�׳ɹ���");
	}
	JiShi();
}

//��Ϸ���ĺ���
void Game()
{
	char WanJia[ROWS][COLS];
	char LeiXinXi[ROWS][COLS];
	ChuShiHua(WanJia, ROWS, COLS, '*');
	ChuShiHua(LeiXinXi, ROWS, COLS, '0');
	DaYin(WanJia, ROWS, COLS);
	SetLei(LeiXinXi, ROW, COL);
	//DaYin(LeiXinXi, ROWS, COLS);
	ZhaoLei(WanJia, LeiXinXi, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Muse();
		printf("��ѡ�������Ϸ�����˳���Ϸ:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��Ϸ�˳�\n");
			break;
		case 1:
			Game();
			break;
		default:
			printf("������������������������룻");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}