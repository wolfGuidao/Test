#include"SeqList.h"
void InsList(SeqList * L, int i, ElemType e)//˳���Ĳ���
{
	int k;
	if (i<1 || i>L->last + 2)
	{
		printf("������λ�ò��Ϸ�");
	}
	if (L->last + 2 > MaxSize)
	{
		printf("��˳�������");
	}
	for (k = L->last;k >= i-1;k--)
	{
		L->elem[k + 1] = L->elem[k];
	}
		L->elem[i - 1] = e;
		L->last++;
}

void PrintfList(SeqList *L)//��ӡ
{
	int i = 0;
	for (;i <= L->last-1;i++)
	{
		printf("%d ", L->elem[i]);
	}
	printf("\n");
}

void InSeqList(SeqList *L)
{
	L->last = 0;
	L->elem[MaxSize];
}

void mergeList(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i <= LA->last-1 && j <= LB->last-1)
	{
		if (LA->elem[i] <= LB->elem[j])
		{
			LC->elem[k++] = LA->elem[i++];
		}
		else
		{
			LC->elem[k++] = LB->elem[j++];
		}
	}
	while (i <= LA->last-1)
	{
		LC->elem[k++] = LA->elem[i++];
	}
	while (j <= LB->last-1)
	{
		LC->elem[k++] = LB->elem[j++];
	}
	LC->last = LA->last + LB->last;
}
