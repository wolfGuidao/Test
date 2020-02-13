#include"heap.h"

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		HeapDown(hp, i);
	}

}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = nullptr;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_a = (HPDataType*)malloc(hp->_capacity * 2 * sizeof(HPDataType));
		hp->_capacity *= 2;
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	HeapUp(hp, hp->_size - 1);
}

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		Down(a, n, i);
	}
	/*
	for (int i = 0; i < n ; i++)
	{
		swap(a[0], a[n - 1 - i]);

		Down(a, n - i, 0);
	}
	*/
	int end = n - 1;
	while (end)
	{
		swap(a[0], a[end]);
		Down(a, end, 0);
		end--;
	}

}

void Up(int * arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if(child>0&& arr[parent]>arr[child])
		{
			swap(arr[child],arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void PPrint(int * a,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}
	cout << endl;
}
void HeapDown(Heap* hp, int index)
{
	HPDataType child = index * 2 + 1;
	while (child < hp->_size)
	{
		if ((index * 2 + 2) < hp->_size && hp->_a[child] > hp->_a[child + 1])
		{
			child = child + 1;
		}

		if (hp->_a[index] > hp->_a[child])
		{
			swap(hp->_a[index], hp->_a[child]);
			index = child;
			child = index * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapUp(Heap* hp, int index)
{
	HPDataType parent = (index - 1) / 2;
	while (index > 0)
	{
		if (hp->_a[index] < hp->_a[parent])
		{
			swap(hp->_a[index], hp->_a[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void Print(Heap * hp)
{
	for(int i = 0; i < hp->_size; i++)
	{
		cout << hp->_a[i] << " ";
	}
	cout << endl;
}

void Down(HPDataType* arr, int len ,int parent)
{
	int child = (parent-1) / 2 + 1;
	while (child > 0)
	{
		if (child + 1 < len && arr[child] > arr[child + 1])
		{
			//swap(arr[child], arr[child + 1]);
			child = child + 1;
		}
		if(arr[parent]>arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

