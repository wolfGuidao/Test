#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#pragma comment(lib,"Winmm.lib")
#include<time.h>
using namespace std;
int cot, flag1, flag2, flag3;//cot�ǼƲ��� flag1,2,3ָʾ�Ƿ��õ�Կ��
int x, y, i, p, q, z, book, a3, a4, a5, a6;
int a1, a2;
char ch;
char c[100][100] = { "��������������������",
					"����            ����",
					"��  ��  ��  ��  ���",
					"��      ��  ��    ��        ���߰����ǵ��õ�Կ��֮����ܴ��η�����",
					"��  ������  ��  ����         ����ʾǽ ���ʾ�� ���ʾԿ�� �d��ʾ����",
					"��    ����    ��  �d",
					"��  ��        ��  ��",
					"��  ��  ��������  ��",
					"��                ��",
					"��������������������",
};
char b[200][200] = { "������������������������������������������������������������",
				   "��    ��            ��            ��������������    ��    ��",
				   "��  ����    ��������    ����  ��  ����        ����      ����",
				   "��  ��          ��        ��        ��  ��    ����  ��    ��",
				   "��  ��������  ��    ��      ������      ��      ����    ����",
				   "��        ��        ��        ��    ��  ����          ��  �d",
				   "����              ����  ��    ������������      ������    ��",
				   "��  ��������    ��      ��  ��      ��      ����    ����  ��",
				   "��    ����  ��      ��������  ��    ��      ����    ��    ��",
				   "��          ��  ����      ��        ����        ����    ����",
				   "��������        ��    ��      ��������  ��  ��  ��    ������",
				   "��        ����          ��  ����  ��        ��      ��������",
				   "������������������������������������������������������������",
};
char a[200][300] =
{
	"������������������������������������������������������������������������������������������������������������������������",
	"��        ��                      ��                    ������              ��������                                  ��",
	"��        ��    ����������    ��      ����    ������        ��        ��            ����  ����������  ��������������  ��",
	"��        ��    ��      ��    ��  ��    ��          ��      ��        ����������              ����            ��      ��",
	"��        ��������      ��    ��  ��    ��������    ��    ����              ��        ��������        ����������  ������",
	"��    ��                ��������  ��          ��    ��      ��        ��    ��        ��    ����������    ����    ������",
	"��    ��    ��    ����        ������������    ��    ��        ������������  ������������            ��            ������",
	"��    ������        ��          ��                  ��            ��          ��      ��    ��    ����    ����  ��������",
	"��          ��        ����������    ������  ��������������������      ������������    ��    ��              ��������  �d",
	"��  ����������  ��������    ��    ����                        ����������        ��          ��    ����������          ��",
	"��  ��    ���        ��              ��������������  ����          ��        ��    ����������������    ������������  ��",
	"������      ��    ��  ��������    ��        ��          ����������  ��    ��������                            ��  ��  ��",
	"��        ����    ��        ����  ��������          ����    ��          ����      ��  ��    ������������          ��  ��",
	"��      ��        ��  ��            ��  ��    ������        ��  ��  ��    ��      ������      ��      ��      ��  ��  ��",
	"��      ��      ������������                ����      ��        ��  ��������        ��      ������      ��    ��  ��  ��",
	"��      ��                ��    ������  ������      ��������������  ��              ��      ��  ����������    ��      ��",
	"��              ������    ��        ��            ����    ��              ��        ����������  ��      ��    ��  ��  ��",
	"��      ��          ��        ��������      ��    ��            ��        ������            ��      ��        ����������",
	"������������������������������������������������������������������������������������������������������������������������",
};
void status()//״̬����
{
	void gotoxy(int x, int y);
	if (c[x][y + 1] == -17 && c[x][y] == -95 && z == 1)
	{
		flag1 = 1;//flag1��Ϊ1 �õ�Կ��
		gotoxy(11, 5);
		printf("���ߣ���ϲ�㣡�õ�����ʧ���Թ��е�Կ�ף�");
	}
	else  if (b[x][y + 1] == -17 && b[x][y] == -95 && z == 2)
	{
		flag2 = 1;//flag1��Ϊ1 �õ�Կ��
		gotoxy(14, 5);
		printf("���ߣ���ϲ�㣡�õ�����ʧ���Թ��е�Կ�ף�");
	}
	else  if (a[x][y + 1] == -17 && a[x][y] == -95 && z == 3)
	{
		flag3 = 1;//flag1��Ϊ1 �õ�Կ��
		gotoxy(20, 5);
		printf("���ߣ���ϲ�㣡�õ�����ʧ���Թ��е�Կ�ף�");
	}
}
void gotoxy(int x, int y)//��������������ƶ�
{
	COORD coord;//���ṹ��
	coord.X = y;//��������
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//ͬ��������̨/���ÿ���̨���λ��
}
void HideCursor()  //���ع�꣬��ֹ��������
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}
void getpd(char js)
{
	if (z == 1)
	{
		if (js == 'w' && ((c[x - 1][y] != -95 && c[x - 1][y] != -10) || (c[x - 1][y + 1] == -17) || (c[x - 1][y + 1] == -14)))
		{
			if (c[x - 1][y] == -123 && !flag1)//�ж��ߵ�����ʱ�Ƿ��õ�Կ��
				goto out1;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((c[x + 1][y] != -95 && c[x + 1][y] != -10) || (c[x + 1][y + 1] == -17) || (c[x + 1][y + 1] == -14)))
		{
			if (c[x + 1][y] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((c[x][y + 2] != -95 && c[x][y + 2] != -10) || (c[x][y + 3] == -17) || (c[x][y + 3] == -14)))
		{
			if (c[x][y + 2] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((c[x][y - 2] != -95 && c[x][y - 2] != -10) || (c[x][y - 1] == -17) || (c[x][y - 1] == -14)))
		{
			if (c[x][y - 1] == -123 && !flag1)
				goto out1;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(10, 10);
			printf("%d", cot);
			status();
		}
	out1:
		{
		}
	}
	if (z == 2)
	{
		if (js == 'w' && ((b[x - 1][y] != -95 && b[x - 1][y] != -10) || (b[x - 1][y + 1] == -17) || (b[x - 1][y + 1] == -14)))
		{
			if (b[x - 1][y] == -123 && !flag2)//�ж��ߵ�����ʱ�Ƿ��õ�Կ��
				goto out2;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((b[x + 1][y] != -95 && b[x + 1][y] != -10) || (b[x + 1][y + 1] == -17) || (b[x + 1][y + 1] == -14)))
		{
			if (b[x + 1][y] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((b[x][y + 2] != -95 && b[x][y + 2] != -10) || (b[x][y + 3] == -17) || (b[x][y + 3] == -14)))
		{
			if (b[x][y + 2] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((b[x][y - 2] != -95 && b[x][y - 2] != -10) || (b[x][y - 1] == -17) || (b[x][y - 1] == -14)))
		{
			if (b[x][y - 1] == -123 && !flag2)
				goto out2;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(13, 10);
			printf("%d", cot);
			status();
		}
	out2:
		{
		}
	}
	if (z == 3)
	{
		if (js == 'w' && ((a[x - 1][y] != -95 && a[x - 1][y] != -10) || (a[x - 1][y + 1] == -17) || (a[x - 1][y + 1] == -14)))
		{
			if (a[x - 1][y] == -123 && !flag3)//�ж��ߵ�����ʱ�Ƿ��õ�Կ��
				goto out3;
			gotoxy(x, y);
			printf("  ");
			x--;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 's' && ((a[x + 1][y] != -95 && a[x + 1][y] != -10) || (a[x + 1][y + 1] == -17) || (a[x + 1][y + 1] == -14)))
		{
			if (a[x + 1][y] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			x++;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'd' && ((a[x][y + 2] != -95 && a[x][y + 2] != -10) || (a[x][y + 3] == -17) || (a[x][y + 3] == -14)))
		{
			if (a[x][y + 2] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			y += 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
		if (js == 'a' && ((a[x][y - 2] != -95 && a[x][y - 2] != -10) || (a[x][y - 1] == -17) || (a[x][y - 1] == -14)))
		{
			if (a[x][y - 1] == -123 && !flag3)
				goto out3;
			gotoxy(x, y);
			printf("  ");
			y -= 2;
			gotoxy(x, y);
			printf("��");
			cot++;
			gotoxy(19, 10);
			printf("%d", cot);
			status();
		}
	out3:
		{
		}
	}
}
void time(int t, int r)//��������ƶ�����
{
	clock_t s, f;
	int a1;
	s = clock();
	f = clock();
	srand(time(NULL));
	if (z == 2)
	{
		while (1)
		{
			HideCursor();
			if (b[x][y] == -123 && flag2)//����ߵ����ڣ�����
				break;
			if (!_kbhit())
			{
				f = clock();
				if (f - s >= 200)
				{
					a1 = rand() % 100 + 1;
					if (a1 >= 1 && a1 <= 25 && b[t][r + 2] != -95 && b[t][r + 2] != -123)//���ĸ���������ƶ��Ҳ����ߵ��Ƿ�����
					{
						gotoxy(t, r);
						printf("  ");
						r += 2;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 26 && a1 <= 50 && b[t][r - 2] != -95 && b[t][r - 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r -= 2;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 51 && a1 <= 75 && b[t + 1][r] != -95 && b[t + 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t++;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 76 && a1 <= 100 && b[t - 1][r] != -95 && b[t - 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t--;
						gotoxy(t, r);
						printf("��");
					}
					if (t == x && y == r)//�������ץס����Կ�׺���ʼ�����´�ӡ
					{
						gotoxy(t, r);
						printf("  ");
						gotoxy(4, 14);
						printf("��");
						gotoxy(8, 8);
						printf("��");
						flag2 = 0;//Կ�׵���
						book = 1;
						break;
					}
					s += 200;
				}
			}
			else
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
				status();
			}
		}
	}
	else if (z == 3)
	{
		while (1)
		{
			HideCursor();
			if (a[x][y] == -123 && flag3)
				break;
			if (!_kbhit())
			{
				f = clock();
				if (f - s >= 200)
				{
					a1 = rand() % 100 + 1;
					int js1 = rand() % 100 + 1, js2 = rand() % 100 + 1;//�����ֵ�����ƶ�
					if (a1 >= 1 && a1 <= 25 && a[t][r + 2] != -95 && a[t][r + 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r += 2;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 26 && a1 <= 50 && a[t][r - 2] != -95 && a[t][r - 2] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						r -= 2;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 51 && a1 <= 75 && a[t + 1][r] != -95 && a[t + 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t++;
						gotoxy(t, r);
						printf("��");
					}
					if (a1 >= 76 && a1 <= 105 && a[t - 1][r] != -95 && a[t - 1][r] != -123)
					{
						gotoxy(t, r);
						printf("  ");
						t--;
						gotoxy(t, r);
						printf("��");
					}

					if (js1 >= 1 && js1 <= 25 && a[a3][a4 + 2] != -95 && a[a3][a4 + 2] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a4 += 2;
						gotoxy(a3, a4);
						printf("��");
					}
					if (js1 >= 26 && js1 <= 50 && a[a3][a4 - 2] != -95 && a[a3][a4 - 2] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a4 -= 2;
						gotoxy(a3, a4);
						printf("��");
					}
					if (js1 >= 51 && js1 <= 75 && a[a3 + 1][a4] != -95 && a[a3 + 1][a4] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a3++;
						gotoxy(a3, a4);
						printf("��");
					}
					if (js1 >= 76 && js1 <= 105 && a[a3 - 1][a4] != -95 && a[a3 - 1][a4] != -123)
					{
						gotoxy(a3, a4);
						printf("  ");
						a3--;
						gotoxy(a3, a4);
						printf("��");
					}

					if (js2 >= 1 && js2 <= 25 && a[a5][a6 + 2] != -95 && a[a5][a6 + 2] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a6 += 2;
						gotoxy(a5, a6);
						printf("��");
					}
					if (js2 >= 26 && js2 <= 50 && a[a5][a6 - 2] != -95 && a[a5][a6 - 2] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a6 -= 2;
						gotoxy(a5, a6);
						printf("��");
					}
					if (js2 >= 51 && js2 <= 75 && a[a5 + 1][a6] != -95 && a[a5 + 1][a6] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a5++;
						gotoxy(a5, a6);
						printf("��");
					}
					if (js2 >= 76 && js2 <= 105 && a[a5 - 1][a6] != -95 && a[a5 - 1][a6] != -123)
					{
						gotoxy(a5, a6);
						printf("  ");
						a5--;
						gotoxy(a5, a6);
						printf("��");
					}

					if ((t == x && y == r) || (x == a3 && y == a4) || (x == a5 && y == a6))
					{
						gotoxy(t, r);
						printf("  ");
						gotoxy(a3, a4);
						printf("  ");
						gotoxy(a5, a6);
						printf("  ");
						gotoxy(7, 32);
						printf("��");
						gotoxy(10, 10);
						printf("��");
						book = 1;
						flag3 = 0;//Կ�׵���
						break;
					}
					s += 200;
				}
			}
			else
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
				status();
			}
		}
	}
}
int main()
{
	HideCursor();
	printf("                                     �װ������ߣ����������ˡ� (����enter������)");
	system("color B");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                                            ʲô����������ʲô�������");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                         ������ô���㱻����͵Ϯ�ˣ���֮�����ǰѻ��Ե�������������Թ�����������");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                              �������Ҹ��˽������ҵ����η�Կ�׵�λ�ã����Գ����ڿ��뿪�����");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                         ����ϧ����������������Ǵ����ˣ������ֻ����취�ܿ�����������Ƿ���");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                      ��������˭���Ⲣ����Ҫ����Ͱ��ҵ���һ���������˵�δ���γ������ҵ�Ĵ�ѧ����");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	printf("                                            ���ˣ�������˵���쿪ʼ��");
	while (1)
	{
		char ss;
		ss = getchar();
		if (ss == '\n')
			break;
	}
	system("CLS");//����
	for (z = 1; z <= 3; z++)
	{
		if (z == 1)
		{
			//            mciSendString("open bgm1.mp3 alias bgm1", NULL, 0, NULL);//������
			//            mciSendString("play bgm1 repeat", NULL, 0, NULL);//ѭ������
			x = 1, y = 1, p = 5, q = 9;
			for (i = 0; i < 10; i++)
			{
				printf("%s", c[i]);
				printf("\n");
			}
			printf("��ǰ����: %d\n״̬: \n", cot);
			system("color B");
			x = 1, y = 2;
			while (c[x][y] != -123 || !flag1)//ֻ���ڵ�����ڵ����겢����Կ�׵�������˳�ѭ��
			{
				HideCursor();
				ch = getchar();
				getpd(ch);
			}
			system("CLS");//����
			printf("         ��ϲ�㣡���ߣ���ɹ��ӳ��˵�һ���Թ�\n");
			printf("             �밴��enter����ǰ����һ��\n");
			printf("(ע�⣡��һ�㿪ʼ��������޷����ܵ�ǿ������ע����)");
			while (1)
			{
				char ss;
				ss = getchar();
				if (ss == '\n')
					break;
			}
			system("CLS");//����
		}

		if (z == 2)
		{
			cot = 0;
			srand(time(0));
			x = 4, y = 14, p = 5, q = 57, book = 0;
			for (i = 0; i <= 12; i++)
			{
				printf("%s", b[i]);
				printf("\n");
			}
			printf("��ǰ����: %d\n״̬: \n", cot);
			system("color B");
			while (1)
			{
				a1 = rand() % 10 + 3;
				a2 = rand() % 47 + 3;
				if (!(a2 % 2))//һ��Ҫ�ù��������ż��λ
				{
					if (b[a1][a2] != -95)//�ڿ��ߵĵ�·�����������״Ϊ�������Ĺ���
					{
						gotoxy(a1, a2);
						printf("��");
						time(a1, a2);
						break;
					}
				}
			}
			if (book == 1)
			{
				system("CLS");//����
				z = 1;
				printf(" ���ź������ߣ��㱻����ץס��\n");
				printf(" (�밴��enter��������ս)\n");
			}
			else
			{
				system("CLS");//����
				printf("�治������ѡ֮�ӣ���ϲ�㣡���ߣ������ǰ������������\n");
				printf("         (�밴��enter����ǰ����һ��)\n");
			}
			while (1)
			{
				char ss;
				ss = getchar();
				if (ss == '\n')
					break;
			}
			system("CLS");//����
		}
		if (z == 3)
		{
			cot = 0;
			x = 7, y = 32, p = 8, q = 118, book = 0;
			for (i = 0; i <= 18; i++)
			{
				printf("%s", a[i]);
				if (i != 18)
					printf("\n");
			}
			printf("��ǰ����: %d\n״̬: \n", cot);
			while (1)
			{
				a1 = rand() % 17 + 1;
				a2 = rand() % 117 + 1;
				a3 = rand() % 17 + 1;
				a4 = rand() % 117 + 1;
				a5 = rand() % 17 + 1;
				a6 = rand() % 117 + 1;
				if (!(a2 % 2) && !(a4 % 2) && !(a6 % 2))
				{
					if (a[a1][a2] != -95 && a[a3][a4] != -95 && a[a5][a6] != -95)
					{
						gotoxy(a1, a2);
						printf("��");
						gotoxy(a3, a4);
						printf("��");
						gotoxy(a5, a6);
						printf("��");
						time(a1, a2);
						break;
					}
				}
			}
			if (book == 1)
			{
				system("CLS");//����
				z = 2;
				printf(" ���ź������ߣ��㱻����ץס��\n");
				printf(" (�밴��enter��������ս)\n");
				while (1)
				{
					char ss;
					ss = getchar();
					if (ss == '\n')
						break;
				}
				system("CLS");//����
			}
			else
			{
				system("CLS");//����
				printf("̫ǿ�ˣ���ϲ�㣡���ߣ���ɹ��ӳ����Թ�\n");
				printf("��Ȼ��Ҳû�����ţ��������һ����������:\n");
				system("color 2");
				printf("        *   \n");
				printf("       ***  \n");
				printf("       ***  \n");
				printf("       ***  \n");
				printf("       ***       ʥ����:��Ů��\n");
				printf("       ***  \n");
				printf("     *******\n");
				printf("       ***  \n");
				printf("       ***  \n");
				system("color 6");
				printf("��ô���������Ժ���������ͼ��������ǿ�����߰�");
				Sleep(10000);
			}
		}
	}
	return 0;
}

