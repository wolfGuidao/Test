#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#include<string.h>
int main()
{


	system("pause");
	return 0;
}



#if 0
int main()
{
	int h, m;
	char *g[] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty" };
	char *s[]= { "twenty","thirty","forty","fifty" };
	printf("������Сʱ�ͷ��ӣ�\n");
	scanf("%d%d", &h, &m);
	if (h > 24 || h < 0 || m>60 || m < 0)
	{
		printf("�������ʱ�䲻�Ϸ�������������\n");
	}
	if (m == 0)//���Сʱ
	{
		if (h < 21)
		{
			printf("%s o'clock", g[h]);
		}
		else
		{
			printf("%s %s o'clock", s[h / 10 - 2], g[h % 10]);
		}
	}
	else 
	{
		if (h < 21)//���Сʱ
		{
			printf("%s ", g[h]);
		}
		else 
		{
			printf("%s %s ", s[h / 10 - 2], g[h % 10]);
		}
		if (m < 21)//�������
		{
			printf("%s ", g[m]);
		}
		else 
		{
			printf("%s %s ", s[m / 10 - 2], g[m % 10]);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
#endif