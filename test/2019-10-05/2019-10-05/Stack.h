#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_SIZE 100
typedef int StackDataType;
typedef struct Stack
{
	StackDataType array[MAX_SIZE];
	int pop;
   
}Stack;

void StackInit(Stack* pStack);//��ʼ��

void StackDestroy(Stack* pStack);//����

void StackPush(Stack* pStack, StackDataType data);//��ջ

void StackPop(Stack* pStack);//��ջ

StackDataType StackTop(Stack* pStack);//�鿴ջ��Ԫ��

int StackSize(const Stack *pStack);//ջ����

int StackFull(const Stack *pStack);//ջ��

int StackEmpty(const Stack *pStack);//ջ��
