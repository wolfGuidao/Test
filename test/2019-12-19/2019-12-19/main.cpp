/*
 *Copyright(c)2018,��̨��ѧ�����ѧԺ
 *All right reserved.
 *�ļ����ƣ�bank.cpp
	 *���ߣ���Сͬ
	 *������ڣ�2018��7��6��
	 *�汾�ţ�v1.1
	 *
	 *��������������
	 *������������������
	 *������������蹦�ܵ�ʵ��
	*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define os 10
using namespace std;
void print();
#define M 3  //��������
#define N 10  //��Դ����
int p[M];
using namespace std;
int Id[M];  //���̺ţ��ⲿ��ʶ��
char State[M]; //״̬ R���� W�ȴ� E���
int Request[M][N];  //��ǰ������ 
int Max[M][N] = { {7,5,3,1,0,1,0,1,0,1},{4,3,3,0,0,1,2,1,0,0},{3,0,6,1,2,0,0,1,1,1} };
// int Max[M][N]={(7,5,3),(3,2,2),(9,0,2),(2,2,2),(4,3,3)};  //��������
int Need[M][N];   //����Ҫ��Դ����
//int Allocation[M][N]={(0,1,0),(2,0,0),(3,0,2),(2,1,1),(0,0,2)};    //�ѷ�����
int Allocation[M][N] = { {0,1,3},{4,1,1},{3,0,1} };
bool Finish[M];
int System[N];
int sum;
//int Available[N];
/*for(int p=0;p<M;p++)
{
	sum=Allocation[p][1]+Allocation[p][2]+Allocation[p][3];
	Available[p]=System[p]-sum;
}*/
int Available[N] = { 3,3,2,8,8,8,8,8,9,8 };
int Safe()
{
	int Work[N], temp[M];//temp[]������¼���̰�ȫִ�е�˳��
	int i, j, m, k = 0, count;
	for (i = 0; i < M; i++)
		Finish[i] = false;
	for (j = 0; j < N; j++)
		Work[j] = Available[j];//�ѿ�������Դ������Work[]
	for (i = 0; i < M; i++)
	{
		count = 0; //��¼������������Դ����
		for (j = 0; j < N; j++)
		{
			if (Finish[i] == false && Need[i][j] <= Work[j])
				count++;
		}
		if (count == N)//�����̸�����Դ������Need<=Workʱ
		{
			for (m = 0; m < N; m++)
			{
				Work[m] = Work[m] + Allocation[i][m]; //���ý��̵ĸ�����Դȫ���ջ�
			}
			Finish[i] = true;
			temp[k] = i;//��¼�����������Ľ���
			k++;
			i = -1;  //��i��Ϊ-1 ����i++ ��Ϊ0  ��ͷ��ʼѭ��
		}
	}
	for (i = 0; i < M; i++)
		if (Finish[i] == false)
		{
			printf("ϵͳ����ȫ!!!������Դ���벻�ɹ�!!!\n");
			return 1;
		}
	printf("\n");
	printf("����ȫ�Լ�飬ϵͳ��ȫ\n");
	printf("\n");
	printf("���ΰ�ȫ���У�");
	for (i = 0; i < M; i++)//��ӡ��ȫϵͳ�Ľ��̵���˳��
	{
		printf("����");
		printf("%d", temp[i]);
		if (i < M - 1)
			printf("->");   //��i=MʱΪ���һ�� ����Ҫ���->
	}
	printf("\n");
	return 0;
}
int Safe2()
{
	int Work[N], temp[M];//temp[]������¼���̰�ȫִ�е�˳��
	int i, j, m, k = 0, count;
	for (i = 0; i < M; i++)
		Finish[i] = false;
	for (j = 0; j < N; j++)
		Work[j] = Available[j];//�ѿ�������Դ������Work[]
	for (i = 0; i < M; i++)
	{
		count = 0; //��¼������������Դ����
		for (j = 0; j < N; j++)
		{
			if (Finish[i] == false && Need[i][j] <= Work[j])
				count++;
		}
		if (count == N)//�����̸�����Դ������Need<=Workʱ
		{
			for (m = 0; m < N; m++)
			{
				Work[m] = Work[m] + Allocation[i][m]; //���ý��̵ĸ�����Դȫ���ջ�
			}
			Finish[i] = true;
			temp[k] = i;//��¼�����������Ľ���
			k++;
			i = -1;  //��i��Ϊ-1 ����i++ ��Ϊ0  ��ͷ��ʼѭ��
		}
	}
	for (i = 0; i < M; i++)
		if (Finish[i] == false)
		{
			return 1;
		}
	printf("\n");
	return 0;
}
void InitPCB()
{
	int i, j;
	for (i = 0; i < N; i++)
		System[N] = 10;
	//Max[M][N]={(7,5,3),(4,3,3),(3,0,6)};
	//Allocation[M][N]={(0,1,3),(4,1,1),(3,0,1)};
	/*for(int p=0;p<N;p++)
	{
		for(i=0;i<M;i++)
		{
		sum=Allocation[i][p]+Allocation[i][p]+Allocation[i][p];
		}
		Available[p]=System[p]-sum;
	}
	*/
	for (i = 0; i < M; i++)
	{
		Id[i] = i;
		State[i] = 'R';
		for (j = 0; j < N; j++)
			Need[i][j] = Max[i][j] - Allocation[i][j];
	}
}
int bank()
{
	int mi, i;
	Safe();
	while (1)
	{
		cout << "����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�\n";
		cin >> mi;
		if (mi >= M)
		{
			cout << "�������" << endl;
			return 0;
		}

		cout << "���������������Դ������\n";
		for (i = 0; i < N; i++)
			cin >> Request[mi][i];
		for (i = 0; i < N; i++)
		{
			if (Request[mi][i] > Need[mi][i])
			{
				cout << "��������Դ���������̵���������\n";
				return 0;
			}
			else if (Request[mi][i] > Available[i])
			{
				cout << "��������Դ������ϵͳ���е���Դ����\n";
				return 0;
			}
		}
		for (i = 0; i < N; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}
		if (Safe() == 0)
			cout << "ͬ���������\n";
		else
		{
			cout << "����ʧ��\n";
			for (i = 0; i < N; i++)
			{
				Available[i] += Request[mi][i];
				Allocation[mi][i] -= Request[mi][i];
				Need[mi][i] += Request[mi][i];
			}
		}
		for (i = 0; i < M; i++)
			Finish[i] = 0;
		char Flag;       //��־λ
		cout << "�Ƿ��ٴ�������䣿���밴Y/y�����밴N/n";
		while (1)
		{
			cin >> Flag;
			if (Flag == 'Y' || Flag == 'y' || Flag == 'N' || Flag == 'n')
				break;
			else
			{
				cout << "�밴Ҫ����������:\n";
				continue;
			}
		}
		if (Flag == 'Y' || Flag == 'y')
		{
			print();
			continue;
		}
		else
			break;
	}
	return 0;
}
int random()
{
	int mi, i;
	while (1)
	{
		cout << "����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�\n";
		cin >> mi;
		cout << "�������������ĸ�����Դ������\n";
		for (i = 0; i < N; i++)
			cin >> Request[mi][i];
		for (i = 0; i < N; i++)
		{

			if (Request[mi][i] > Need[mi][i])
			{
				cout << "��������Դ���������̵���������\n";
				return 0;
			}
			if (Request[mi][i] > Available[i])
			{
				cout << "��������Դ������ϵͳ���е���Դ����\n";
				return 0;
			}
		}
		for (i = 0; i < N; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}
		if (Safe2() == 1)
		{
			cout << "��������\n";
			return 0;
		}
		for (i = 0; i < M; i++)
			Finish[i] = 0;
		char Flag;       //��־λ
		cout << "�Ƿ��ٴ�������䣿���밴Y/y�����밴N/n";
		while (1)
		{
			cin >> Flag;
			if (Flag == 'Y' || Flag == 'y' || Flag == 'N' || Flag == 'n')
				break;
			else
			{
				cout << "�밴Ҫ����������:\n";
				continue;
			}
		}
		if (Flag == 'Y' || Flag == 'y')
			continue;
		else
			break;
	}
}
void print()       //���   
{
	int i = 0, j = 0;
	printf("......................................................................\n");
	printf("\n��ǰ״̬:");
	cout << endl;
	cout << "��ǰ��������Դ����:" << endl;
	cout << "[";
	for (i = 0; i < N; i++)
		cout << Available[i] << " ";
	cout << "]" << endl << endl;
	cout << "���̺�" << "         " << "������Դ��" << "               " << "��������Դ��" << endl;
	for (i = 0; i < M; i++)
	{
		cout << Id[i] << "        ";
		cout << "[";
		for (j = 0; j < N; j++)
			cout << Need[i][j] << " ";
		cout << "]      ";

		cout << "[";
		for (j = 0; j < N; j++)
			cout << Max[i][j] << " ";
		cout << "]";
		cout << endl;
	}
	printf("......................................................................\n");
}
int main()
{
	//  freopen("in.txt", "r", stdin);
	int n = 9999;
	printf("                         ��Դ����                   \n");
	while (n != 0)
	{
		printf("       --------------------------------------------------\n");
		printf("      |         &*****************************&          |\n");
		printf("      |         *      1�����м��㷨          *          |\n");
		printf("      |         *      2����������㷨        *          |\n");
		printf("      |         *      0���˳�����            *          |\n");
		printf("      |         &*****************************&          |\n");
		printf("       --------------------------------------------------\n\n");

		printf("\n");

		InitPCB();
		print();
		printf("\n");
		printf("��ѡ��:");

		cin>>n;
		printf("\n");


		if (n == 1)
		{
			bank();
			print();
		}
		else if (n == 2)
		{
			random();
			print();
		}
		else if (n == 0)
		{
			printf("��лʹ��!\n");
			exit(0);
		}
		else printf("ѡ�����������ѡ��!\n");
	}
	return 0;
}