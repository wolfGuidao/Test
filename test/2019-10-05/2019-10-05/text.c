#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"Stack.h"//ջ
#include"DQueue.h"//����

//ջ��������
void stackvoid()
{
	Stack pStack;
	StackInit(&pStack);//��ʼ��
	//StackDestroy(pStack);//����
	StackPush(&pStack, 1);//��ջ
	StackDataType a = StackTop(&pStack);
	printf("%d ", a);

	StackPush(&pStack, 3);
	a = StackTop(&pStack);
	printf("%d ", a);

	StackPush(&pStack, 5);
	a=StackTop(&pStack);
	printf("%d\n", a);

	StackPop(&pStack);//��ջ
	 a = StackTop(&pStack);
	printf("%d ", a);

	int b= StackSize(&pStack);//ջ����
	//int c= StackFull(&pStack);//ջ��
	//int d= StackEmpty(&pStack);//ջ��
	printf("%d", b);
	//printf("%d", c);
	//printf("%d", d);
}

//���л�������
void DuiLie()
{
	Queue pQueue;
	QueueInit(&pQueue);//��ʼ��

	QueuePush(&pQueue, 1);//���
	QDataType a= QueueFront(&pQueue);//�鿴����Ԫ��
	printf("%d ", a);

	QueuePush(&pQueue, 2);//���
	 a = QueueFront(&pQueue);//�鿴����Ԫ��
	printf("%d ", a);

	QueuePush(&pQueue, 3);//���
	a = QueueFront(&pQueue);//�鿴����Ԫ��
	printf("%d\n", a);

	int b= QueueSize(&pQueue);//Ԫ�ظ���
	printf("%d ", b);

	QueuePop(&pQueue);//����
	b = QueueSize(&pQueue);//Ԫ�ظ���
	printf("%d ", b);
}

int main()
{
	//stackvoid();
	DuiLie();
	system("pause");
	return 0;
}