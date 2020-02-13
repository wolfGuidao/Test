#include<iostream>
#include<Windows.h>
using namespace std;

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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*>s;
		vector<int>s1;
		TreeNode* cur = root;
		TreeNode* top1;//��¼ջ��Ԫ��
		while (!s.empty() || cur)
		{
			while (cur)//������������ڣ���cur��ǣ������е�������ջ
			{
				s1.push_back(cur->val);//�Ѹ�����ֵ�ŵ�vector<int>s1��
				s.push(cur);//�Ѹ������ջ
				cur = cur->left;//Ѱ�ҵ�ǰ����������
			}
			top1 = s.top();//�õ����һ��������top1���
			s.pop();//��Ϊ���һ����������һ��ѭ�����Ѿ���ӡ�ˣ����԰�ջ��Ԫ��ֱ�ӳ�ջ
			cur = top1->right;//�������Һ���
		}
		return s1;
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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>ret;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* topp;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			topp = s.top();
			s.pop();
			ret.push_back(topp->val);
			cur = topp->right;
		}
		return ret;
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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*>s;
		vector<int>ret;
		TreeNode* cur = root;
		TreeNode* top1;//��¼ջ��Ԫ��
		TreeNode* top2 = nullptr;//��������Ƿ��Ѿ��ŵ�ret��
		while (cur || !s.empty())
		{
			while (cur)//ѭ��һֱ��������ջ
			{
				s.push(cur);
				cur = cur->left;
			}
			top1 = s.top();//��û������ʱ����top1ȡջ��Ԫ��
			if (top1->right == nullptr || top1->right == top2)//ֻ�е��ýڵ���Һ���Ϊ�ջ��Һ��ӱ�top2��ǣ����ܰѵ�ǰ�����ŵ�ret��
			{
				ret.push_back(top1->val);
				s.pop();
				top2 = top1;//��top2��¼top1�ڵ��Ѿ��ŵ�ret��
				top1 = nullptr;//û��Ҫ������ü��ϣ���ֹ�ڴ�й©����
			}
			else
			{
				cur = top1->right;
			}
		}
		return ret;

	}
};
#endif


int main()
{
	system("pause");
	return 0;
}