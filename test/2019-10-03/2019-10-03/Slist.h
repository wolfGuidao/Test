#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;
typedef struct SLNode
{
	SLDataType value;
	struct SLNode *next;
}SLNode;
typedef struct
{
	SLNode *first;
}SList;

//��ʼ��
void SListInit(SList *list);

//�����ڵ�
SLNode *SListBuyNode(SLDataType value);

//ͷ��
void SListPushFront(SList *list, SLDataType value);

//β��
void SListPushBack(SList *list, SLDataType value);

//��ӡ
void SListPrint( SList *list);

//��pos�������value
void SListInsertAfter(SLNode *pos, SLDataType value);

//ȥ�ҵ������������ĵ�һ�� value�����û�ҵ�������NULL
SLNode * SListFind(const SList *list, SLDataType value);

//��posǰ�����value
void SListInsertBefore(SLNode *list, SLNode *pos, SLDataType value);

//ͷɾ
void SListPopFront(SList *list);

//βɾ
void SListPopBack(SList *list);

//����
void SlistDestory(SList *list);

//ɾ�� pos ����� value
void SListEraseAfter(SLNode *pos);