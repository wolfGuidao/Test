#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<stdio.h>
#define MaxSize 10//�鲢����Ͱ���������ʱ��Ҫ�����ԭ����һ����С�Ŀռ�ʱ�õ��������޸�

//����
int QuickShortchild(int *str, int left, int right)//ʱ�临�Ӷ�Ϊ��nlogn
{
	int temp = str[left];//Ĭ��ѡ�����һ��Ԫ����Ϊ��׼����temp = str[left]
	while (left < right)//ѡ�û�׼������ʱright�洢�������һ��Ԫ���±꣬left�洢������Ԫ���±�
	{
		while (left<right&&str[right]>=temp)//ÿ��ѭ�����ǴӺ���ǰ���У������right����Ԫ��С�ڻ�׼���ͰѸ�ֵ����left����Ԫ��
		{
			right--;//����rightλ��ǰ��
		}
			str[left] = str[right];
		while (left < right&&str[left] <= temp)//Ȼ���ǰ������У����left����Ԫ�ش��ڻ�׼����Ѹ�ֵ����right����Ԫ��
		{
			left++;//����left����
		}
			str[right] = str[left];
	}
	str[left] = temp;
	return left;//��Ϊһ�˿������򣬷��ػ�׼λ�ã�����ݹ�ʱ������ָ
}
void QuickSort(int *str,int left,int right)
{
	if (left < right)
	{
		int mid = QuickShortchild(str, left, right);//�õ���׼λ�ã��������и�λ��ǰ��Ԫ�ض�����С�������Ԫ�ض�������
		QuickSort(str,left, mid-1);//�Ի�׼�󲿽��еݹ�����
        QuickSort(str, mid + 1, right);	//�Ի�׼�Ҳ����еݹ�����
	}
}

//����   
void adjust(int *str,int start,int end)//ת��Ϊ�����
{
	int i = 0;
//��֪���Ƹ�������Ϊn,��Ϊ(n-1)/2;
//��֪������:����Ϊn,����Ϊ2n+1\2n+2;
//һ�ε���Ϊ�����ʱ�临�Ӷȣ�log2n;
//����������Ϊ�����ʱ�临�Ӷȣ�n*log2n;
	int temp = str[start];
	for (i = 2 * start + 1;i <= end;i = i * 2 + 1)
	{
		if ((i < end) && str[i] < str[i + 1])
		{
			i++;
		}
		if (str[i] > temp)
		{
			str[start] = str[i];
			start = i;
		}
		else if (str[i] < temp)
		{
			//str[start] = temp;
			break;

		}
	}
	str[start] = temp;
}
void heapSort(int *str,int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = (len - 1 - 1) / 2;i >= 0;i--)//������������Ϊ�����
	{
		adjust(str, i, len - 1);
	}
	for (j = 0;j < len - 1;j++)//���н�����ÿ����һ�Σ�����һ�Σ���֤ÿ�ζ��Ǵ���ѣ�ע��ÿ������һ�Σ����õ�һ�����������������԰�����������Ϊ�����Ԫ����һ��
	{
		tmp = str[len - 1 - j];
		str[len - 1 - j] = str[0];
		str[0] = tmp;
		adjust(str, 0, len - 1-j-1);//len-1-j-1:��len-1):���鳤�ȣ�-j:��Ϊ�˽���ѭ����-1����Ϊ�Ѿ�����һ�ν������������׶˵������򣬽��е���Ϊ����Ѳ���������һ����
	}
}

//ѡ������
void selectSort(int *str  ,int len)
{
//ÿ��ѡ����С������Ԫ�ط���������Ԫ��λ�ã��ڼ䷢�������ͺ���
//ʱ�临�Ӷ�Ϊ��n2;
//�ռ临�Ӷ�Ϊ��1��
	int i = 0;
	int j = 0;
	int temp;
	for (i = 0;i < len ;i++)
	{
		for (j = i+1;j < len;j++)
		{
			if (str[i] <= str[j])
			{
				j++;
			}
			else
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}

//ð������
void bubbleSort(int *str, int len)
{
//ð������, ��������
//���鵱�бȽ�С����ֵ���³�����ֵ�Ƚϴ�����ϸ���
	int i = 0;
	int temp = 0;
	int j = 0;
	for (i = 0;i < len;i++)
	{
		for (j = i + 1;j < len;j++)
		{
			if (str[i] < str[j])
			{
				j++;
			}
			else
			{
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}
//�鲢����
void mergeChild(int *str,int start,int mid,int end)//��һ��һ�����������򲢺ϲ���һ��
{
	int tempstr[MaxSize];
	int tempIndex = start;
	int start2 = mid + 1;
	int i = start;
	while (start <= mid && start2 <= end)//�����鲢�ζ������ݵ�ʱ��
	{
		if (str[start] <= str[start2])
		{
			tempstr[tempIndex] = str[start];
			start++;
			tempIndex++;
		}
		else
		{
			tempstr[tempIndex] = str[start2];
			start2++;
			tempIndex++;
		}
	}
	while (start <= mid)
	{
		tempstr[tempIndex] = str[start];
		start++;
		tempIndex++;
	}
	while (start2 <=  end)
	{
		tempstr[tempIndex] = str[start2];
		start2++;
		tempIndex++;
	}
	while (i <= end)//��ÿ�κϲ�������ɵ�Ԫ�ؿ�����ԭ������
	{
		str[i] = tempstr[i];
		i++;
	}
}
void mergeSort(int *str, int start,int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;//�ù����ǰ�����ֽ�Ϊһ��һ��������
	mergeSort(str,start, mid);
	mergeSort(str, mid+1 , end);

	mergeChild(str,start,mid ,end);//�ϲ����������
}

//�����Ż�������ȡ��ѡ��׼��
void Swap(int *str,int start,int end)
{
	int temp = str[start];
	str[start] = str[end];
	str[end] = temp;
}
void medianOfThree(int * str,int low,int hight)//��֤str[mid]<=str[low]<=str[hight];���ƻ�׼��ѡ��
{
	int mid = (low + hight) >> 1;
	if (str[mid] > str[low])
	{
		Swap(str, mid, low);
	}
	if (str[mid] > str[hight])
	{
		Swap(str, mid, hight);
	}
	if (str[low] > str[hight])
	{
		Swap(str, low, hight);
	}
}
void quickSort2(int *str,int left,int right)
{
	if (left < right)
	{
		medianOfThree(str, left, right);
		int mid = QuickShortchild(str, left, right);//�õ���׼λ�ã��������и�λ��ǰ��Ԫ�ض�����С�������Ԫ�ض�������
		QuickSort(str, left, mid - 1);//�Ի�׼�󲿽��еݹ�����
		QuickSort(str, mid + 1, right);	//�Ի�׼�Ҳ����еݹ�����
	}
}

//��������ǵݹ飨���������ջ��
void quickSort3(int *str, int len)
{
	int stack[MaxSize * 2];
	int top = 0;
	int low = 0;
	int hight = len - 1;
	int mid = QuickShortchild(str, low, hight);//�Ƚ���һ�˿��ţ��õ�һ���ֽ�㣬
	//�ж�mid���������Ƿ������������ϣ�����У��ֱ����������Ԫ���±���ջ
	if (mid > low + 1)
	{
		stack[top++] = low;
		stack[top++] = mid - 1;
	}
	if (mid < hight - 1)
	{
		stack[top++] = mid + 1;
		stack[top++] = hight;
	}
	//���ϴ���ִ����ϣ�˵���±���ջ���
	//�ж�ջ�Ƿ�Ϊ�գ������Ϊ�գ�ȡ�������±긳��hight,low�������ѭ����ֱ��ջΪ�ա�
	while (top > 0)
	{
		hight = stack[--top];
		low = stack[--top];

		mid = QuickShortchild(str, low, hight);
		if (mid > low + 1)
		{
			stack[top++] = low;
			stack[top++] = mid - 1;
		}
		if (mid < hight - 1)
		{
			stack[top++] = mid + 1;
			stack[top++] = hight;
		}
	}
}

//ֱ�Ӳ�������
void InsertSort(int *str, int len) 
{               
	int i=0;
	int j=0;                                    
	int temp;                                     
	for (i = 1; i < len; i++)
	{
		temp = str[i];
		for (j = i;j > 0&&str[j-1]>temp;j--)
		{
			str[j] = str[j - 1];//�����������Ͱ�j֮ǰԪ��һ��һ�����󸲸�
		}
		str[j] = temp;//����temp�ŵ�����λ��
	}
}

//ϣ������
void shellSort(int *str, int len)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp;
	int gap = len / 2;//gap�������������Ƿֵõ�����
	for (;gap>0;gap/=2)
	{
		for (k = 0;k < gap;k++)

		{
			for (i = k+gap; i < len; i += gap)
			{
				temp = str[i];
				for (j = i;j > 0 && str[j - gap] > temp;j-=gap)
				{
					str[j] = str[j - gap];
				}
				str[j] = temp;
			}
		}
	}
}

//��������
int Max(int *str, int len)//�����������Ԫ�أ���������λ��
{
	int i = 0;
	int max = str[0];
	int temp = 0;
	int d = 0;
	for (i = 1;i < len;i++)
	{
		if (str[i] > max)
		{
			max = str[i];
		}
	}
	while (max != 0)
	{
		max = max / 10;
		d++;
	}
	return d;
}
void radixSort(int *str, int len) //
{
	int d = Max(str, len);
	int tmp[MaxSize];
	int count[MaxSize]; //������
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //����d������
	{
		for (j = 0; j < 10; j++)
		{
			count[j] = 0; //ÿ�η���ǰ��ռ�����
		}
		for (j = 0; j < len; j++)
		{
			k = (str[j] / radix) % 10; //ͳ��ÿ��Ͱ�еļ�¼��
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			count[j] = count[j - 1] + count[j]; //��tmp�е�λ�����η����ÿ��Ͱ
		}
		for (j = len - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (str[j] / radix) % 10;
			tmp[count[k] - 1] = str[j];
			count[k]--;
		}
		for (j = 0; j < len; j++) //����ʱ��������ݸ��Ƶ�str��
		{
			str[j] = tmp[j];
		}
		radix = radix * 10;
	}
}

//��������
void CountSort(int *str, int len)
{
	int i, j, count;
	int temp = 0;
	int data_p[MaxSize];
	for (i = 0;i < len;i++)//��ʼ��data_p
	{
		data_p[i] = 0;
	}
	for (i = 0;i < len;i++)
	{
		count = 0;
		for (j = 0;j < len;j++)//ɨ�����������
			if (str[j] < str[i])//ͳ�Ʊ�data[i]ֵС��ֵ�ĸ���
				count++;
		while (data_p[count] != 0)//������ȷ�0�����ݣ�Ӧ����һλ������Ϊ0ʱ��������data_p����ʼ��Ϊ0���ʲ���Ӱ�졣
		/* ע��˴�Ӧʹ��whileѭ�������жϣ�����if�����򳬹������ظ�ֵ����0���� */
			count++;
		data_p[count] = str[i];//��ŵ�data_p�еĶ�Ӧλ��
	}
	//���ڼ�鵱�ж������ͬʱ�����
	i = 0, j = len;
	while (i < j)
	{
		if (data_p[i] == 0)
		{
			temp = i - 1;
			data_p[i] = data_p[temp];
		}
		i++;
	}
	for (i = 0;i < len;i++)//������������ݸ��Ƶ�data��
	{
		str[i] = data_p[i];
	}
}

//Ͱ������
typedef struct node {
	int key;
	struct node* next;
}KeyNode;
void bucketSort(int *str, int len, int bucket_size)
{
	KeyNode **bucket_table = (KeyNode**)malloc(bucket_size * sizeof(KeyNode*));
	for (int i = 0;i < bucket_size;i++)
	{    //��ʼ��Ͱ
		bucket_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		bucket_table[i]->key = 0;
		bucket_table[i]->next = NULL;
	}
	for (int i = 0;i < len;i++)
	{
		KeyNode* node = (KeyNode*)malloc(sizeof(KeyNode));
		node->key = str[i];
		node->next = NULL;
		int index = str[i] / 10;//�����ݷ���ķ�������ϵ�������ٶȣ�����Ҫ��
		KeyNode *p = bucket_table[index];
		if (p->key == 0)
		{
			p->next = node;
			p->key++;
		}
		else 
		{
			while (p->next != NULL && p->next->key <= node->key) 
			{//=��ʱ�������Ԫ�ػ����ں���
				p = p->next;
			}
			node->next = p->next;
			p->next = node;
			(bucket_table[index]->key)++;
		}
	}
	KeyNode* k = NULL;
	for (int i = 0;i < bucket_size;i++) 
	{
		for (k = bucket_table[i]->next;k != NULL;k = k->next)
		{
			printf("%d < ", k->key);
		}
	}
	printf("\n");
}

//��ӡ����
void Printf(int *str,int len)
{
	int i = 0;
	for (i = 0;i < len; i++)
	{
		printf("%d < ", str[i]);
	}
	printf("\n");
}

//���Ժ���
void text()
{
	int str[] = { 10,9,8,7,6,5,4,3,2,1 };
	int len = sizeof(str) / sizeof(str[0]);
	printf("������������\n");
	QuickSort(str, 0, len-1);
	Printf(str, len);

	int str1[] = { 10,9,85,70,63,5,4,33,32,91 };
	int len1 = sizeof(str1) / sizeof(str1[0]);
	printf("������������\n");
	heapSort(str1,len1);
	Printf(str1, len1);

	int str2[] = { 10,96,85,47,63,35,24,31,12,11 };
	int len2 = sizeof(str2) / sizeof(str2[0]);
	printf("ֱ��ѡ����������\n");
	selectSort(str2,len2);
	Printf(str2, len2);

	int str3[] = { 101,91,18,27,26,35,43,34,24,16 };
	int len3 = sizeof(str3) / sizeof(str3[0]);
	printf("ð����������\n");
	bubbleSort(str3, len3);
	Printf(str3, len3);

	int str4[] = { 10,29,82,97,86,58,46,3,62,1 };
	int len4 = sizeof(str4) / sizeof(str4[0]);
	printf("�鲢��������\n");
	mergeSort(str4, 0,len4-1);
	Printf(str4, len4);

	int str5[] = { 109,19,82,73,64,45,99,43,52,11 };
	int len5 = sizeof(str5) / sizeof(str5[0]);
	printf("���������Ż�����������\n");
	quickSort2(str5, 0, len5 - 1);
	Printf(str5, len5);

	int str6[] = { 10,9,88,77,69,5,99,3,2,1 };
	int len6 = sizeof(str6) / sizeof(str6[0]);
	printf("��������ǵݹ���������\n");
	quickSort3(str6, len6);
	Printf(str6, len6);

	int str7[] = { 100,1999,58,67,60,51,29,13,25,18 };
	int len7 = sizeof(str7) / sizeof(str7[0]);
	printf("ֱ�Ӳ���������������\n");
	InsertSort(str7, len7);
	Printf(str7, len7);

	int str8[] = { 10,999,48,67,70,11,21,43,55,98 };
	int len8 = sizeof(str8) / sizeof(str8[0]);
	printf("ϣ��������������\n");
	shellSort(str8, len8);
	Printf(str8, len8);

	int str9[] = { 110,999,8,6,17,31,31,93,55,99998 };
	int len9 = sizeof(str9) / sizeof(str9[0]);
	printf("����������������\n");
	radixSort(str9, len9);
	Printf(str9, len9);

	int str10[] = { 110,999,8,6,17,31,31,93,55,99998 };
	int len10 = sizeof(str10) / sizeof(str10[0]);
	printf("����������������\n");
	CountSort(str10, len10);
	Printf(str10, len10);

	int str11[] = { 10,96,85,47,63,35,24,31,12,11 };
	int len11 = sizeof(str11) / sizeof(str11[0]);
	printf("Ͱ����������\n");
	bucketSort(str11, len11,MaxSize);//Ͱ�������ӡ�����ں����ڲ�����Ϊ���ӡ��ʽ�����������������
}

int main()
{
	text();
	system("pause");
	return 0;
}