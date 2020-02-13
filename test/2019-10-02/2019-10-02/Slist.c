#include"Slist.h"

//��ʼ��
void SListInit(SList *list)
{
	assert(list!=NULL);
	list->first = NULL;
}

//�����ڵ�
SLNode *SListBuyNode(SLDataType value)
{
	SLNode *node = (SLNode*)malloc(sizeof(SLNode));
	assert(node!=NULL);
	node->value = value;
	node->next = NULL;
	return node;
}

//ͷ��
void SListPushFront(SList *list, SLDataType value)
{
	assert(list != NULL);
	SLNode *node = SListBuyNode(value);
	assert(node != NULL);
	node->next = list->first;
	list->first = node;
}

//β��
void SListPushBack(SList *list, SLDataType value)
{
	assert(list != NULL);
	
	if (list->first == NULL)
	{
		SListPushFront(list, value);
		return;
	}
	SLNode *cur = list->first;
	while (cur->next)
	{
		cur = cur->next;
	}
	SLNode *node = SListBuyNode(value);
	cur->next = node;
	node->next = NULL;
}

//��ӡ
void SListPrint(const SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	for (cur = list->first ;cur;cur = cur->next)
	{
		printf("%d->", cur->value);
	}
	printf("NULL\n");
}

//��pos�������value
void SListInsertAfter(SLNode *pos, SLDataType value)
{
	assert(pos != NULL);
	SLNode *node = SListBuyNode(value);
	node->next = pos->next;
	pos->next = node;
}

//ȥ�ҵ������������ĵ�һ�� value�����û�ҵ�������NULL
SLNode * SListFind(const SList *list, SLDataType value)
{
	assert(list != NULL);
	SLNode *cur;
	for (cur = list->first;cur;cur = cur->next)
	{
		if (cur->value == value)
		{
			return cur;
		}
	}
	return NULL;
}

//��posǰ�����value
void SListInsertBefore(SList *list, SLNode *pos, SLDataType value)
{
	assert(pos != NULL);
	assert(list != NULL);
	SLNode *node = SListBuyNode(value);
	SLNode *cur = list->first;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	
	cur->next = node;
    node->next = pos;
}

//ͷɾ
void SListPopFront(SList *list)
{
	assert(list!=NULL);
	assert(list->first != NULL);
	SLNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//βɾ
void SListPopBack(SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	while (cur->next->next  != NULL)
	{
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

//����
void SlistDestory(SList *list)
{
	assert(list != NULL);
	SLNode *cur = list->first;
	SLNode *right;
	while (cur != NULL) 
	{
		right = cur->next;
		free(cur);
		cur = right;
	}
	list->first = NULL;
}

//ɾ�� pos ����� value
void SListEraseAfter(SLNode *pos)
{
	SLNode *next = pos->next;
	pos->next = next->next;
	free(next);
}