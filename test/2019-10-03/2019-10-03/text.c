#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
//��������Ļ�������

#include"Slist.h"//��ͷ�����ѭ������
#include"Dlist.h"//��ͷ˫��ѭ������
int main()
{
	//��ͷ�����ѭ�������ʵ��
	/*SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPushFront(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);
	SListPushBack(&list, 9);
	SListPrint(&list);//5 4 3 2 1 6 7 8 9
	SLNode *ret = SListFind(&list, 2);
	SListInsertAfter(ret, 19);
	SListPrint(&list);//5 4 3 2 19 1 6 7 8 9
	SListInsertBefore(&list, ret, 99);
	SListPrint(&list);//5 4 3 99 2 19 1 6 7 8 9
	SListPopFront(&list);
	SListPrint(&list);//4 3 99 2 19 1 6 7 8 9
	SListPopBack(&list);
	SListPrint(&list);//4 3 99 2 19 1 6 7 8
	SListEraseAfter(ret);
	SListPrint(&list);//4 3 99 2 1 6 7 8
	SlistDestory(&list);
	*/

	//Լɪ��
	SLNode *last;
	SList *head;
	SLNode *cur;
	SListInit(&head);
	int m = 10;
	int n = 3;
	SListPushFront(&head, m);
	last = head;
	for (int i = m - 1;i >= 1;i--)
	{
		SListPushFront(&head, i);
	}
	SListPrint(head);
	last->next = head;
	cur = last;
	for (;m > 1;m--)
	{
		for (int i = 1;i < n;i++)
		{
			cur = cur->next;
			printf("%d��%d\n", cur->value, i);
			
		}
		printf("%d�ų�Ȧ\n", cur->next ->value);
		SListEraseAfter(cur);
	}
	printf("%d��ʤ��", cur->value);

	//��ͷ˫��ѭ������
	/*DList dlist;
	DListInit(&dlist);
	DListPushFront(&dlist, 1);
	DListPushFront(&dlist, 2);
	DListPushFront(&dlist, 3);
	DListPushFront(&dlist, 4);
	DListPushFront(&dlist, 5);
	DListPushFront(&dlist, 6);
	DListPrint(&dlist);
	DListPushBack(&dlist, 6);
	DListPushBack(&dlist, 7);
	DListPushBack(&dlist, 8);
	DListPushBack(&dlist, 9);
	DListPrint(&dlist);
	DListNode *ret = DListFind(&dlist, 1);
	DListInsertFront(ret, 99);
	DListPrint(&dlist);
	DListPopFront(&dlist);
	DListPrint(&dlist);
	DListPopBack(&dlist);
	DListPrint(&dlist);
	DListErase(ret);
	DListPrint(&dlist);
	DListDestroy(&dlist);*/
	system("pause");
	return 0;
}