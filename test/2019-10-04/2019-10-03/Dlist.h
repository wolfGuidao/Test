#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>

typedef int DLDataType;
typedef struct DListNode
{
	DLDataType value;
	struct DListNode *prev;
	struct DListNode *next;
}DListNode;
typedef struct DList
{
	DListNode *head;
}DList;

//��ʼ��
void DListInit(DList *dlist);

//����ڵ�
static DListNode* DListBuyNode(DLDataType value);

//ͷ��
void DListPushFront(DList *dlist, DLDataType value);

//��ӡ
void DListPrint(DList *dlist);

//β��
void DListPushBack(DList *dlist, DLDataType value);

//�� 
DListNode* DListFind(const DList* dlist, DLDataType value);

//�� pos ǰ����в��� value
void DListInsertFront(DListNode* pos, DLDataType value);

//ͷɾ
void DListPopFront(DList *dlist);

//βɾ
void DListPopBack(DList *dlist);

//ɾ�� pos λ�õĽ��
void DListErase(DListNode* pos);

//������������
void DListDestroy(DList *dlist);

//��˳��ϲ�����˫����
void DListMerge(DList *list1, DList *list2);