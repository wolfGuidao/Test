//
//#if 0
//class Solution {
//public:
//	int QuickShortchild(vector<int>&str, int left, int right)
//	{
//		int temp = str[left];//Ĭ��ѡ�����һ��Ԫ����Ϊ��׼����temp = str[left]
//		while (left < right)//ѡ�û�׼������ʱright�洢�������һ��Ԫ���±꣬left�洢������Ԫ���±�
//		{
//			while (left < right&&str[right] >= temp)//ÿ��ѭ�����ǴӺ���ǰ���У������right����Ԫ��С�ڻ�׼���ͰѸ�ֵ����left����Ԫ��
//			{
//				right--;//����rightλ��ǰ��
//			}
//			str[left] = str[right];
//			while (left < right&&str[left] <= temp)//Ȼ���ǰ������У����left����Ԫ�ش��ڻ�׼����Ѹ�ֵ����right����Ԫ��
//			{
//				left++;//����left����
//			}
//			str[right] = str[left];
//		}
//		str[left] = temp;
//		return left;//��Ϊһ�˿������򣬷��ػ�׼λ�ã�����ݹ�ʱ������ָ
//	}
//	void QuickSort(vector<int>&str, int left, int right)
//	{
//		if (left < right)
//		{
//			int mid = QuickShortchild(str, left, right);//�õ���׼λ�ã��������и�λ��ǰ��Ԫ�ض�����С�������Ԫ�ض�������
//			QuickSort(str, left, mid - 1);//�Ի�׼�󲿽��еݹ�����
//			QuickSort(str, mid + 1, right);	//�Ի�׼�Ҳ����еݹ�����
//		}
//	}
//	vector<int> sortArray(vector<int>& nums) {
//		/*
//		sort(nums.begin(),nums.end());
//		return nums;
//		*/
//		QuickSort(nums, 0, nums.size() - 1);
//		return nums;
//	}
//};
//
//#endif
#include<iostream>
using namespace std;
///*
//int main()
//{
//	int arr[10];
//	int m = 5;
//	int i = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		arr[i] = 1;
//
//	}
//	arr[9] = 999;
//	for (i = 0; i < m; i++)
//	{
//		if (arr[i] == 1)
//		{
//			m++;
//		}
//	}
//	cout << i << endl;
//	system("pause");
//	return 0;
//}
//*/
//class Solution {
//public:
//	int LastRemaining_Solution(int n, int m)
//	{
//		/*
//		//ע�������ӵĵط��Ǳ���Ǵ�0��ʼ��ģ��ͱ����Ǵ�0��ʼ���ģ�ע��
//		if(n<1||m<0)
//		{
//			return -1;
//		}
//		list<int>l;
//		//ѭ����list�зű��
//		for(int i=0;i<n;i++)
//		{
//			l.push_back(i);
//		}
//		//curÿ������������������¼Ҫɾ���Ľڵ�
//		auto cur=l.begin();
//		//���list��Ԫ�صĸ�������1�ͼ���ѭ����ֱ��ֻʣ��һ��
//		while(l.size()>1)
//		{
//			//ѭ������
//			for(int i=1;i<m;i++)
//			{
//				cur++;
//				//ע��++����ܻ�Խ�磬���Ա�����listѭ������
//				if(cur==l.end())
//				{
//					cur=l.begin();
//				}
//			}
//			//��¼����ɾ������һ���ڵ�
//			auto next=++cur;
//			//ͬ��Ҫ��listѭ������
//			if(next==l.end())
//			{
//				next=l.begin();
//			}
//			//֮ǰΪ�˼�¼nextִ����++���͵�--����
//			cur--;
//			//ɾ��cur�Ľڵ�
//			l.erase(cur);
//			//����
//			cur=next;
//		}
//		return *cur;
//		*/
//		if (n < 0 || m < 0)
//		{
//			return -1;
//		}
//		int* arr = new int[n];
//		int index = -1;
//		int length = n;
//		//int sss = m;
//		for (int i = 0; i < n; i++)
//		{
//			arr[i] = i;
//		}
//		while (n > 0)
//		{
//			while (m)
//			{
//				index = (index + 1) % length;
//				if (arr[index] == -1)
//				{
//					m++;
//				}
//				m--;
//			}
//			
//
//			//int index1 = (index + 1) % length;
//			/*
//			while (arr[index1] == -1)
//			{
//				index1 = (index1 + 1) % length;
//
//			}
//			*/
//			//index = (index + 1)%length;
//			//m = arr[index];
//			arr[index] = -1;
//
//			//m = sss;
//			n--;
//		}
//		for (int i = 0; i < n; i++)
//		{
//			if (arr[i] != -1)
//			{
//				return i;
//			}
//		}
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout<<s.LastRemaining_Solution(5, 3);
//	system("pause");
//	return 0;
//}

//#include<stdio.h> 
int main()
{
	int n, m, i, k;
	int a[99] = { 0 };
	cin >> n >> m;
	for (i = 0; i < n; i++)
		//scanf("%d", &a[i]);
		a[i] = i;
	i = -1; k = n;
	while (n>1)
	{
		while (m)
		{
			i = (i + 1) % k;
			if (a[i] == -1)
				m++;
			m--;
		}
		printf("%d", i + 1);
		m = a[i];
		a[i] = -1;
		n--;
	}
	return 0;
}
