#include"Stack.h"

void StackInit(Stack* pStack)//��ʼ��
{
	pStack->pop = 0;
}

void StackDestroy(Stack* pStack)//����
{
	pStack->pop = 0;
}

void StackPush(Stack* pStack, StackDataType data)//��ջ
{
	assert(pStack != NULL);
	pStack->array[pStack->pop] = data;
	pStack->pop++;
}

void StackPop(Stack* pStack)//��ջ
{
	assert(pStack != NULL);
	pStack->pop--;
}


StackDataType StackTop(Stack* pStack)//�鿴��ջ��Ԫ��
{
	assert(pStack != NULL);
	return pStack->array[pStack->pop-1];
}

int StackSize(const Stack *pStack)//ջ����
{
	return pStack->pop;
}

int StackFull(const Stack *pStack)//ջ��
{
	return pStack->pop >= MAX_SIZE;
}

int StackEmpty(const Stack *pStack)//ջ��
{
	return pStack->pop <= 0;
}