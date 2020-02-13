#include"DQueue.h"

void QueueInit(Queue *pQueue)//��ʼ��
{
	pQueue->front = pQueue->rear = NULL;
}

static QNode * CreateNode(QDataType data)//�����ڵ�
{
	QNode *node= (QNode *)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

void QueuePush(Queue *pQueue, QDataType data)//���
{
    QNode * node=CreateNode(data);
	if (pQueue->front == NULL)
	{
		pQueue->front = pQueue->rear = node;
	}
	pQueue->rear->next  = node;
	pQueue->rear = node;
}

void QueuePop(Queue *pQueue)//����
{
	if (pQueue->front == NULL)
	{
		pQueue->rear = NULL;
	}
	QNode * cur = pQueue->front;
	pQueue->front = cur->next;
	free(cur);
}

QDataType QueueFront(Queue *pQueue)//�鿴����Ԫ��
{
	return pQueue->front->data;
}

int QueueSize(const Queue *pQueue)//Ԫ�ظ���
{
	QNode *cur=pQueue->front ;
	int count = 0;
	while (cur )
	{
		count++;
		cur = cur->next;
	}
	return count;
}