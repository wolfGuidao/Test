#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include "Stack.h" //ջ
#include "Tree.h"  //��

//ջ��������
void stackvoid() {
	Stack pStack;
	StackInit(&pStack); //��ʼ��
	//StackDestroy(pStack);//����
	StackPush(&pStack, 1); //��ջ
	StackDataType a = StackTop(&pStack);
	printf("��1��ջ����ǰջ��Ԫ�أ�%d\n ", a);

	StackPush(&pStack, 3);
	a = StackTop(&pStack);
	printf("��3��ջ����ǰջ��Ԫ�أ�%d \n", a);

	StackPush(&pStack, 5);
	a = StackTop(&pStack);
	printf("��5��ջ����ǰջ��Ԫ��%d\n", a);

	StackPop(&pStack); //��ջ
	a = StackTop(&pStack);
	printf("��ջ����ǰջ��Ԫ��%d\n ", a);

	int b = StackSize(&pStack);  //ջ����
	int c = StackFull(&pStack);  //ջ��
	int d = StackEmpty(&pStack); //ջ��
	printf("ջ���ȣ�%d\n", b);
	printf("ջ����1Ϊ����0Ϊδ������%d\n", c);
	printf("ջ�շ�1Ϊ�գ�0Ϊδ�գ���%d\n", d);
}

void ErChaShu() 
{
	printf("���Դ���\n");
	BiTree T;
	T = (BiTree)malloc(sizeof(BiTreeNode));

	printf("�����������������ʽ�����������ֵ(�ս��Ϊ#):\n");
	CreateBiTree(&T);


	printf("����ʽ���������\n");
	PreOrderTravel(T);
	printf("\n");

	printf("����ʽ���������\n");
	InOrderTravel(T);
	printf("\n");

	printf("����ʽ���������\n");
	TailOrderTravel(T);
	printf("\n");
}

int main() {
	//stackvoid();
	ErChaShu();
	system("pause");
	return 0;
}