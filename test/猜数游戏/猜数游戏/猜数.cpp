#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Menu()
{
	printf("********************************************\n");
	printf("*************������Ϸ��ʼ*******************\n");
	printf("*************����1��ʼ��Ϸ******************\n");
	printf("*************����0�˳���Ϸ******************\n");
	printf("********************************************\n");
}
void Game()
{
	int n;
	int shuijishu = rand() % 100 + 1;
	for (;;)
	{
		scanf_s("%d", &n);
		if (shuijishu > n)
		{
			printf("��µ���С��,����������\n");
		}
		if (shuijishu < n)
		{
			printf("��µ������ˣ�����������\n");
		}
		if (shuijishu == n)
		{
			printf("��¶���");
			break;
		}
	}
}
int main()
{
	int i;
	Menu();
	srand((unsigned int)time(NULL));
	printf("���������ѡ��1��0��\n");
	scanf_s("%d", &i);
	if (i == 0)
	{
		printf("�ݰ�");
	}
	if (i == 1)
	{
		printf("��������µ�����\n");
		Game();
	}
	system("pause");
	return 0;
}