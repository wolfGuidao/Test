#pragma once
#include<stdio.h>

#define MaxSize 100
#define ElemType int

typedef struct
{
	ElemType elem[MaxSize];
	int last;//��¼���Ա����һ��Ԫ���������е��±�ֵ��ע���Ǵ��㿪ʼ
}SeqList;

void InsList(SeqList * L, int i, ElemType e);//��˳���i��ǰ�����һ��Ԫ��

void PrintfList(SeqList *L);//��ӡ

void InSeqList(SeqList *L);//��ʼ��

void mergeList(SeqList* LA, SeqList* LB, SeqList* LC);