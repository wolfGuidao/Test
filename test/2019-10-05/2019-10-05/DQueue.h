#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode 
{
	QDataType data;
	struct QNode *next;
}	QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}	Queue;

void QueueInit(Queue *pQueue);//��ʼ��

static QNode * CreateNode(QDataType data);//�����ڵ�

void QueuePush(Queue *pQueue, QDataType data);//���

void QueuePop(Queue *pQueue);//����

QDataType QueueFront(Queue *pQueue);//�鿴����Ԫ��

int QueueSize(const Queue *pQueue);//Ԫ�ظ���