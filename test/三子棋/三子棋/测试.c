#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#define ROW 3
#define COL 3
void Menu()
{
	printf("****************************\n");
	printf("****��ӭ������������Ϸ******\n");
	printf("****����1��������Ϸ*********\n");
	printf("****����0���˳���Ϸ*********\n");
	printf("****************************\n");
}
void Game()
{
	int win = 0;
	char qipan[ROW][COL] = { 0 };

	ChuShiHua(qipan,3,3);

	DaYin(qipan, 3, 3);
	while (1)
	{
		WanJa(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		win = Win(qipan, 3, 3);
		if (win != ' ')
		{
			break;
		}
		printf("�����ƶ�\n");
		DianNao(qipan, 3, 3);
		DaYin(qipan, 3, 3);
		win = Win(qipan, 3, 3);
	}
	if (win == 'X')
	{
		printf("��ϲ����ʤ��!\n");
	}
	else if (win == 'O')
	{
		printf("���ź���������\n");
	}
	else if (win == 'Q')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		Menu();
		printf("���������ѡ��");
		scanf("%d", &a);
		switch(a)
		{
		case 1:
				Game();
				break;
		case 0:
				printf("�˳���Ϸ");
				break;
		default:
			printf("�����������");
			break;
		}
	} while (a);
	system("pause");
	return 0;
}