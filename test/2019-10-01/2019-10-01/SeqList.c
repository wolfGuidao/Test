#include"SeqList.h"

unsigned int k = 0;

void InitSeqList(SeqList* pSeq)//��ʼ��˳���
{
	assert(pSeq);
	pSeq->array = (DataType *)malloc(sizeof(DataType)*DEFAULT_CAPACITY);
	pSeq->size = 0;
	pSeq->capacity = DEFAULT_CAPACITY;
}

void PrintSeqList(SeqList* pSeq)//��ӡ˳���
{
	assert(pSeq);
	for (k = 0;k < pSeq->size;k++)
	{
		printf("%d  ", pSeq->array[k]);
	}
	printf("\n");
}

void CheckExpandCapacity(SeqList* pSeq)//����ڴ�ռ��Ƿ��㹻�����������Զ���������ռ�洢����
{
	assert(pSeq);
	if (pSeq->size >= pSeq->capacity)
	{
		DataType* tmp = (DataType*)malloc(pSeq->capacity * 2 * sizeof(DataType));
		memcpy(tmp, pSeq->array, sizeof(DataType)*pSeq->size);

		free(pSeq->array);
		pSeq->array = tmp;
		pSeq->capacity = pSeq->capacity * 2;
	}
}

void DestorySeqList(SeqList* pSeq)//�ͷſռ䣬����˳���
{	
	if (pSeq)
	{
		free(pSeq->array);
		pSeq->capacity = 0;
		pSeq->size = 0;
	}
}

void PushBack(SeqList* pSeq, DataType x)//β��
{
	assert(pSeq);
	CheckExpandCapacity(pSeq);
	pSeq->array[pSeq->size] = x;
	pSeq->size++;
}

void PopBack(SeqList* pSeq)//βɾ
{
	assert(pSeq);
	--(pSeq->size);
}

void PushFront(SeqList* pSeq, DataType x)//ͷ��
{
	assert(pSeq);
	for (k = pSeq->size;k >= 0;k--)
	{
		pSeq->array[k + 1] = pSeq->array[k];
	}
	pSeq->array[0] = x;
	pSeq->size++;
}

void PopFront(SeqList* pSeq)//ͷɾ
{
	assert(pSeq);
	for (k = 0;k < pSeq->size  ;k++)
	{
		pSeq->array[k] = pSeq->array[k + 1];
	}
	pSeq->size--;
}

void Insert(SeqList* pSeq, size_t index, DataType x)//�ڸ���λ�ò�������
{
	assert(pSeq);
	for (k = pSeq->size;k >= index;k--)
	{
		pSeq->array[k + 1] = pSeq->array[k];
	}
	pSeq->array[index-1] = x;
	pSeq->size++;
}

void Remove(SeqList* pSeq, size_t index)//ɾ������λ������
{
	assert(pSeq);
	for (k = index-1;k < pSeq->size;k++)
	{
		pSeq->array[k] = pSeq->array[k + 1];
	}
	pSeq->size--;
}

int Find(SeqList* pSeq, DataType index)//���Ҹ�������
{
	assert(pSeq);
	for (k = 0;k < pSeq->size;k++)
	{
		if (pSeq->array[k] == index)
		{
			return k + 1;
		}
	}
	return -1;
}

void Swap(DataType *left, DataType *right)//����������
{
	DataType temp=0;
	temp = *right;
	*right = *left;
	*left = temp;
}

void BubbleSort(SeqList* pSeq)//ð������
{
	assert(pSeq);
	unsigned int i = 0;
	for (i = 0;i < pSeq->size;i++)
	{
		for (k = 0;k < pSeq->size - 1 - i;k++)
		{
			if (pSeq->array[k] > pSeq->array[k + 1])
			{
				Swap(&(pSeq->array[k]), &(pSeq->array[k + 1]));
			}
		}
	}
}