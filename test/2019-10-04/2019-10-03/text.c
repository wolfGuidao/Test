#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"SeqList.h"//˳���
#include"Slist.h"//��ͷ�����ѭ������
#include"Dlist.h"//��ͷ˫��ѭ������

void HeBing()
{
	DList dlist1;
	DList dlist2;
	DListInit(&dlist1);
	DListInit(&dlist2);
	DListPushFront(&dlist1, 9);
	DListPushFront(&dlist1, 7);
	DListPushFront(&dlist1, 5);
	DListPushFront(&dlist1, 3);
	DListPushFront(&dlist1, 1);
	DListPushFront(&dlist2, 10);
	DListPushFront(&dlist2, 8);
	DListPushFront(&dlist2, 6);
	DListPushFront(&dlist2, 4);
	DListPushFront(&dlist2, 2);
	DListPrint(&dlist1);//1 3 5 7 9
	DListPrint(&dlist2);//2 4 6 8 10
	DListMerge(&dlist1, &dlist2);
	DListPrint(&dlist1);//1 2 3 4 5 6 7 8 9 10
}

void WFD()
{
	SList list;
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
}

void YXD()
{
	DList dlist;
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
	DListDestroy(&dlist);
}
void YSF()
{
	int m = 0;
	int n = 0;
	printf("������m����,nΪ��(n<m)");
	scanf("%d%d", &m, &n);
	YueSheFu(m, n);

}

void SXB()
{
		SeqList L;
		DataType data;
		//��ʼ��˳���
		InitList(&L);
		//�ڱ��в���Ԫ��
		printf("�����ڱ��в���Ԫ��(1,2,3,4,5)��\n");
		InsList(&L, 1, 1);
		InsList(&L, 2, 2);
		InsList(&L, 3, 3);
		InsList(&L, 4, 4);
		InsList(&L, 5, 5);

		//��ӡ����Ԫ��
		printf("����Ԫ���У�\n");
		PrintList(&L);
		//ͷ��
		printf("�ڱ�ͷ���β���Ԫ�أ�6,7:\n");
		PushFront(&L, 6);
		PushFront(&L, 7);
		//β��
		printf("�ڱ�β���β���Ԫ�أ�8,9:\n");
		PushBack(&L, 8);
		PushBack(&L, 9);
		printf("����Ԫ���У�\n");
		PrintList(&L);
		//ͷɾ
		printf("ͷɾһ��Ԫ��:\n");
		PopFront(&L);
		//βɾ
		printf("βɾһ��Ԫ��:\n");
		PopBack(&L);
		//������е�4��Ԫ��ֵ
		PrintList(&L);
		printf("���е�4��Ԫ��ֵΪ��\n%d\n", GetData(&L, 4));
		//���ұ��е� i��Ԫ�ص�λ��
		printf("Ԫ��2�ڱ��е�λ��Ϊ��\n");
		printf("%d\n", Locate(&L, 2));
		//ɾ�����е�2��Ԫ�ض�Ӧ��ֵ
		printf("ɾ�����е�2��Ԫ�أ�%d\n", DelList(&L, 2, &data));
		printf("˳���ĳ���Ϊ��%d\n", LengthList(&L));
		printf("����Ԫ��Ϊ��\n");
		PrintList(&L);
		//printf("ɾ����Ԫ��ֵΪ��%d\n", data);
		//���˳���
		ClearList(&L);
		PrintList(&L);
}

int main()
{
	//Լɪ������
	//YSF();

	//��˳��ϲ�����˫����
	//HeBing();

	//��ͷ��ѭ���������������
	//WFD();

	//��ͷѭ��˫�����������
	//YSF();

	//˳���
	SXB();

	system("pause");
	return 0;
}