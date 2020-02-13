#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		//������Ҫ˼���ǳ������Գ������ǳ�������֮���ǳ���
		if (index < 7)
		{
			return index;
		}
		vector<int>ret;//�洢���
		//����Ҫ������ĵ�N�����������Զ�������У�ÿ����ret�зŵ�ʱ���3�����ж���Ԫ��
		//��С�ģ�Ȼ���ٰ������С�ĳ����ֱ����2��3��5�ŵ���Ӧ�Ķ�������
		queue<int>q2;//�洢����2�ĳ���
		queue<int>q3;//�洢����3�ĳ���
		queue<int>q5;//�洢����5�ĳ���

		ret.push_back(1);//1�ǳ�����ֱ�ӷŵ�ret��
		q2.push(ret[0] * 2);
		q3.push(ret[0] * 3);
		q5.push(ret[0] * 5);
		while (ret.size() < index)
		{
			int Min = min(q2.front(), min(q3.front(), q5.front()));//ȡ3������
			//����Ԫ�ؽ�С��Min�ŵ�ret��
			//ȡ�����Ǹ����е�Ԫ�ؾͰ��Ǹ����еĶ���Ԫ�س���
			if (q2.front() == Min)
			{
				q2.pop();
			}
			if (q3.front() == Min)
			{
				q3.pop();
			}
			if (q5.front() == Min)
			{
				q5.pop();
			}
			ret.push_back(Min);
			q2.push(Min * 2);//���������С��Ԫ�طֱ����2��3��5�ŵ���Ӧ�Ķ�����
			q3.push(Min * 3);
			q5.push(Min * 5);

		}
		return ret[ret.size() - 1];//�������һ��Ԫ�أ����ǵ�N������
	}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() < 1 || vin.size() < 1)
		{
			return nullptr;
		}

		vector<int>pre_right;
		vector<int>pre_left;
		vector<int>vin_right;
		vector<int>vin_left;

		TreeNode* head = new TreeNode(pre[0]);
		int flag;
		for (size_t i = 0; i < vin.size(); i++)
		{
			if (vin[i] == pre[0])
			{
				flag = i;
				break;
			}
		}

		for (size_t i = 0; i < flag; i++)
		{
			vin_left.push_back(vin[i]);
			pre_left.push_back(pre[i + 1]);
		}
		for (size_t i = flag + 1; i < vin.size(); i++)
		{
			vin_right.push_back(vin[i]);
			pre_right.push_back(pre[i]);
		}
		head->left = reConstructBinaryTree(pre_left, vin_left);
		head->right = reConstructBinaryTree(pre_right, vin_right);
		return head;
	}
};

int main()
{
	int n;

	while (cin >> n)
	{
		int a = 1;
		int b = 1;
		int c = 0;

		int num = n - 1;
		int count = abs(1 - n);
		while (num-- > 0)
		{
			c = a + b;
			if (abs(c - n) < count)
			{
				count = abs(c - n);
			}
			a = b;
			b = c;
		}
		cout << count;

	}
	return 0;
}