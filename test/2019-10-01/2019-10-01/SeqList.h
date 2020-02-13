#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DEFAULT_CAPACITY 3

 typedef int DataType;
 typedef unsigned int size_t;

typedef struct SeqList
{
	DataType* array;
	size_t size;	  // ��ǰ����Ч���ݸ��� 
	size_t capacity;//����
}SeqList;

void InitSeqList(SeqList* pSeq);//��ʼ��˳���

void PrintSeqList(SeqList* pSeq);//��ӡ˳���

void CheckExpandCapacity(SeqList* pSeq);//����ڴ�ռ��Ƿ��㹻�����������Զ���������ռ�洢����

void DestorySeqList(SeqList* pSeq);//�ͷſռ䣬����˳���

void PushBack(SeqList* pSeq, DataType x);//β��

void PopBack(SeqList* pSeq);//βɾ

void PushFront(SeqList* pSeq, DataType x);//ͷ��

void PopFront(SeqList* pSeq);//ͷɾ

void Insert(SeqList* pSeq, size_t index, DataType x);//�ڸ���λ�ò�������

void Remove(SeqList* pSeq, size_t index);//ɾ������λ������

int Find(SeqList* pSeq, DataType index);//���Ҹ�������

void Swap(DataType *left, DataType *right);//����������

void BubbleSort(SeqList* pSeq);//ð������