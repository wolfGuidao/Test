#include<iostream>
#include<Windows.h>
using namespace std;

//namespace wolf
//{
//
//}
//void Testpriority()
//{
//
//}
#if 0

void adjustDown(int* str,int len,int parent)//���µ�������֤���ڵ���С
{
	int child = 2 * parent + 1;
	while (child < len)//��֤�Һ��Ӵ���
	{
		if (child + 1 < len && str[child + 1] < str[child])//���ȱ�֤�Һ��Ӵ��ڲ����Һ��ӱ�����С������child����Һ��ӣ�ʹchildʼ�ձ�ǽ�С���ӵ��±�
		{
			child += 1;
		}
		if (str[parent] > str[child])//���˫�ױȺ��Ӵ󣬾ͽ��н���
		{
			swap(str[parent], str[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//������Ǹ��ڵ㱾���ͱȺ��ӽڵ�С��˵���ø��ڵ����¶��Ѿ�����С����������������µ�����ֱ�ӷ��أ�������һ�����ڵ�
		{
			return;
		}
	}
}

void adjustUp(int* str, int child)//Ϊ��ʵ��priority_queue�����β����һ��Ԫ���ұ�֤С�ѵ�����
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (str[child] < str[parent])
		{
			swap(str[child], str[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}

void Test()
{
	int arr[] = { 3,1,5,2,6,7,8,4,9,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int parent = (len - 1 - 1) / 2;//��һ����1����Ϊ�����ǰ�������ķ�ʽ�����ģ���0��ʼ���ڶ�����1��Ϊ�������һ�����ڵ��λ��
	for(;parent >= 0;parent--)//ѭ�������ѣ�ʹ�ѵĽṹΪС��
	{
		adjustDown(arr,len ,parent);
	}
	for (int i = 0;i < len - 1;i++)
	{
		swap(arr[0], arr[len - 1 - i]);//�ѶԶ�Ԫ�غͶ������һ��Ԫ�ؽ��н����������������һ��Ԫ�ؾ�����С��
		adjustDown(arr, len - 1 - i - 1, 0);//���е�������Ϊ�������һ��Ԫ���Ѿ�����С�ģ��Ͳ��þ��ѵ���������ÿ����һ�Σ�����һ�������Գ���lenÿ�ξͼ�һ��
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}

#endif
#if 0

void adjustDown(int* str, int len, int parent)//���µ�������֤���ڵ����
{
	int child = 2 * parent + 1;
	while (child < len)//��֤�Һ��Ӵ���
	{
		if (child + 1 < len && str[child + 1] > str[child])//���ȱ�֤�Һ��Ӵ��ڲ����Һ��ӱ����Ӵ󣬲���child����Һ��ӣ�ʹchildʼ�ձ�ǽϴ��ӵ��±�
		{
			child += 1;
		}
		if (str[parent] < str[child])//���˫�ױȺ���С���ͽ��н���
		{
			swap(str[parent], str[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else//������Ǹ��ڵ㱾���ͱȺ��ӽڵ��˵���ø��ڵ����¶��Ѿ���������������������µ�����ֱ�ӷ��أ�������һ�����ڵ�
		{
			return;
		}
	}
}

//void adjustUp(int* str, int child)//Ϊ��ʵ��priority_queue�����β����һ��Ԫ���ұ�֤С�ѵ�����
//{
//	int parent = (child - 1) / 2;
//	while (child)
//	{
//		if (str[child] < str[parent])
//		{
//			swap(str[child], str[parent]);
//			child = parent;
//			parent = (child - 1) >> 1;
//		}
//		else
//		{
//			return;
//		}
//	}
//}

void Test()
{
	int arr[] = { 3,1,5,2,6,7,8,4,9,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int parent = (len - 1 - 1) / 2;//��һ����1����Ϊ�����ǰ�������ķ�ʽ�����ģ���0��ʼ���ڶ�����1��Ϊ�������һ�����ڵ��λ��
	for (;parent >= 0;parent--)//ѭ�������ѣ�ʹ�ѵĽṹΪС��
	{
		adjustDown(arr, len, parent);
	}
	for (int i = 0;i < len - 1;i++)
	{
		swap(arr[0], arr[len - 1 - i]);//��Ϊ��ѶԶ�Ԫ�������ģ��ѶԶ�Ԫ�غͶ������һ��Ԫ�ؽ��н����������������һ��Ԫ�ؾ�������
		adjustDown(arr, len - 1 - i - 1, 0);//���е�������Ϊ�������һ��Ԫ���Ѿ������ģ��Ͳ��ý��е���������ÿ����һ�Σ�����һ�������Գ���lenÿ�ξͼ�һ��
	}
	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}
#endif
#include<vector>
#include<queue>

#if 0

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>avg;
		if (!root)
		{
			return avg;
		}
		queue<TreeNode*>q;//�洢�ڵ�
		q.push(root);//�ȰѸ�������
		double sum;//��ʱ�洢ÿһ��ĺ�
		while (!q.empty())
		{
			sum = 0.0;//ÿ�ζ�Ҫ��Ϊ0
			int count = q.size();//��¼ÿһ��Ԫ�ظ���
			for (int i = 0;i < count;i++)
			{
				TreeNode* cur = q.front();//curÿ�ζ�ָ���ͷ�ڵ�
				sum += cur->val;//��ÿһ��val�ĺ�
				q.pop();//����
				if (cur->left)//���
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}

			}
			avg.push_back(sum / count);//��ƽ��ֵ��β�嵽avg��
		}
		return avg;
	}
};

#endif

#if 0
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int>max;
		if (!root)
		{
			return max;
		}
		queue<TreeNode*>q;
		q.push(root);
		while (!q.empty())
		{
			int count = q.size();
			int max1 = q.front()->val;//�洢��ͷ�ڵ��val
			for (int i = 0;i < count;i++)
			{
				TreeNode* cur = q.front();//ʼ��ָ���ͷ�ڵ�
				if (cur->val > max1) //�ȴ�С������max1��ֵ
				{
					max1 = cur->val;
				}
				q.pop();
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}

			}
			max.push_back(max1);
		}
		return max;
	}
};
#endif

int main()
{
	//Test();
	//cout << max(1, 45, 99) << endl;
	system("pause");
	return 0;
}