//�����⣬����ϵ WeChat:God_Father_LZ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <conio.h>

////////�궨��//////////////////////////////
#define MAPWIDTH 60
#define MAPHEIGHT 30
#define SNAKESIZE 100
///////�������/////////////////////////////
struct
{
	int x;
	int y;		//ʳ������
}food;

struct
{
	int x[SNAKESIZE];    //�ߵĽ���������
	int y[SNAKESIZE];
	int length;         //�ߵĳ���
	int speed;          //�ߵ��ٶ�
}snake;
/////////////ȫ�ֱ���//////////////////////
int changeflag = 0; //�ߵ�������־.
char  key = 's'; //��ʼ���������˶�

/////////////////ģ�黯���/////////////////
//1. ����ͼ
void DrawMap();
//2. ����ʳ��
void CreateFood();
//3. ��������
void KeyDown();
//4. �ߵ�״̬:�ж��Ƿ������Ϸ
int SnakeStatus();
//5. ��������: ����ƶ�
void gotoxy(int x, int y);

int main(void)
{
	DrawMap();
	while (1)
	{
		CreateFood();
		gotoxy(MAPWIDTH + 2, MAPHEIGHT / 2);
		printf("score: %d", snake.length - 3);
		Sleep(snake.speed); //sleep����,ִ�й���һ��ʱ��
		KeyDown();
		if (!SnakeStatus())
			break;
	}
	gotoxy(MAPWIDTH / 2 - 10, MAPHEIGHT / 2);
	printf("Game Over!");
	system("pause");
	return 0;
}

////////////////////////////////1. ����ͼ/////////////////////////////////////////////
// #: ʳ�� @: ��ͷ, �߿�  *:����
void DrawMap()
{
	//��Ϸ����
	gotoxy(MAPWIDTH + 2, MAPHEIGHT / 2 - 3);
	printf("Tab 'a','d','s','w' to move.");
	srand((unsigned int)time(NULL)); //����ʱ��仯������

	//1. Ȧ��
		//1.1��ӡ���߿�
	for (int i = 0; i <= MAPHEIGHT; i++)
	{
		gotoxy(0, i); //��������ϵ
		printf("��");
		gotoxy(MAPWIDTH, i);
		printf("��");
	}
	//1.2��ӡ��߿�
	for (int i = 0; i <= MAPWIDTH; i += 2) // ��ռ�������ַ�.
	{
		gotoxy(i, 0);
		printf("��");
		gotoxy(i, MAPHEIGHT);
		printf("��");
	}
	//2. ����
		//2.1ȷ���ߵĳ���,�ٶ�
	snake.length = 3;
	snake.speed = 300;
	//2.2ȷ����ͷ������(��ͼ����)
	snake.x[0] = MAPWIDTH / 2;
	snake.y[0] = MAPHEIGHT / 2;
	//2.3����ͷ
	gotoxy(snake.x[0], snake.y[0]);
	printf("@");
	//2.3��ʣ������
	for (int i = 1; i < snake.length; i++)
	{
		snake.x[i] = snake.x[i - 1] + 1;
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf("*");
	}
	//3. ��ʳ��
	//3.1 ����ʳ������
	food.x = rand() % (MAPWIDTH - 4) + 2; //�������.[2-57] 
	food.y = rand() % (MAPHEIGHT - 2) + 1; //�����Χ�ڵ�ͼ���Ϳ���, ��ƽ������ͼ��[1 28]
		//3.2 ��ӡʳ��
	gotoxy(food.x, food.y);
	printf("#");
}
//2. ����ʳ��
void CreateFood()
{
	//�߳�ʳ��----��ͷ��ʳ�������غ�
	if (snake.x[0] == food.x && snake.y[0] == food.y)
	{
		//������ʳ������������(1)ʳ�ﲻ��������, (2)������Ϊż��(��Ϊ����һ��ռ���ַ�)
		srand((unsigned int)time(NULL));
		while (1)
		{
			int flag = 1;
			food.x = rand() % (MAPWIDTH - 4) + 2; //[2 - 57]
			food.y = rand() % (MAPHEIGHT - 2) + 1; //[1 28]

			for (int k = 0; k < snake.length; k++)
			{
				if (snake.x[k] == food.x && snake.y[k] == food.y) {
					flag = 0;
					break;               //flag--�ж�ʳ��λ���Ƿ���ȷ�ı�־
				}
			}
			if (flag == 1) {
				break;
			}
		}
		gotoxy(food.x, food.y);
		printf("#");
		snake.length++;
		snake.speed -= 10;
		changeflag = 1;
	}
	//������ʳ��
}
//////////////////////////3. ��������///////////////////////////////////////
void KeyDown()
{
	char temp;
	//1.���հ���
	if (_kbhit()) //keyboard hit ����Ƿ��а���;
	{
		fflush(stdin); //���������
		key = _getch();
	}
	//�ް�������,�������ƶ�
	/*
	*���ƶ�ʱ���Ȳ�ȥ��β��һ��
	*changeFlagΪ0������ʱû�гԵ�ʳ����ÿ��һ����Ҫ��������β���Դ�Ӫ��һ���ƶ���Ч��
	*Ϊ1�����Ե���ʳ��Ͳ���Ҫ������β���Դ�Ӫ��һ������������Ч��
	*/
	if (!changeflag)
	{
		//�������һ������
		gotoxy(snake.x[snake.length - 1], snake.y[snake.length - 1]);
		printf(" ");
	}
	//����������ƶ�
	for (int i = snake.length - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
		//�������Ϊ'*'
		gotoxy(snake.x[i], snake.y[i]);
		printf("*");
	}

	//2.�а���
	switch (key)
	{
	case 'w':
		snake.y[0]--;
		break;
	case 's':
		snake.y[0]++;
		break;
	case 'a':
		snake.x[0] = snake.x[0] - 1; //һ��@ռ1���ַ�
		break;
	case 'd':
		snake.x[0] = snake.x[0] + 1;
		break;
	default:
		break;
	}
	gotoxy(snake.x[0], snake.y[0]);
	printf("@");   //��ӡ����ͷ(ǰ��)
	changeflag = 0;
	//��ӡ������󽫹���Ƶ���Ļ���Ϸ���������������һֱ��˸
	gotoxy(MAPWIDTH + 2, 0);

}
//4. �ߵ�״̬:�ж��Ƿ������Ϸ
int SnakeStatus()
{
	//ײǽ�ж�
	if (snake.x[0] == 0 || snake.x[0] == MAPWIDTH - 1 || snake.y[0] == 0 || snake.y[0] == MAPHEIGHT)//?????????????????
		return 0;
	//�ж�ײ�Լ�
	for (int i = 1; i < snake.length; i++)
	{
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			return 0;
	}
	return 1;   //�ǵ÷���1.		
}
//5. ��������: ����ƶ�
void gotoxy(int x, int y)
{
	//����APIȥ���ÿ���̨�Ĺ��λ��(�Դ�ӡ����)
	//1. �ҵ�����̨�Ĵ���
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	//2. ���ṹ��
	COORD coord;
	//3. ���ù�������
	coord.X = x;
	coord.Y = y;
	//4. ͬ��������̨ set console cursor position
	SetConsoleCursorPosition(handle, coord);
}
